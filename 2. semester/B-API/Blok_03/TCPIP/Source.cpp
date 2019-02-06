#include <iostream>
#include <WS2tcpip.h>
#include <string>
#include <sstream>

#pragma comment (lib, "ws2_32.lib")

#define DLZKA_SPRAVY 3000
#define MOJ_PORT 600
using namespace std;

int main()
{
	// Inicializacia winsock-u
	WSADATA wsData;
	WORD ver = MAKEWORD(2, 2);

	int wsOk = WSAStartup(ver, &wsData);
	if (wsOk != 0)
	{
		cerr << "Nemozem inicializovat winsock." << endl;
		return 0;
	}

	// Vytvorenie socketu
	SOCKET listening = socket(AF_INET, SOCK_STREAM, 0);
	if (listening == INVALID_SOCKET)
	{
		cerr << "Nemozem vytvorit socket" << endl;
		return 0;
	}

	// Pripojenie portu a IP adresy k socketu
	sockaddr_in adresa;
	adresa.sin_family = AF_INET;
	adresa.sin_port = htons(MOJ_PORT);
	adresa.sin_addr.S_un.S_addr = INADDR_ANY;

	bind(listening, (sockaddr*)&adresa, sizeof(adresa));

	// Oznamenie Winsock-u, ze socket je pouzivany na pocuvanie
	listen(listening, SOMAXCONN); // MAXCONN hovori o tom, kolko pripojeni mozeme spravit

	// Vytvorenie file descriptora a jeho nasledne vynulovanie
	fd_set master;
	FD_ZERO(&master);

	// Pridanie prveho socketu, aby mal referenciu
	FD_SET(listening, &master);

	// premenna urcujuca koniec konverzacie
	bool spusteny = true;

	while (spusteny)
	{
		// Sktrukturu master treba v kazdom cykle skopirovat kvoli destruktivnosti select commandu
		fd_set copy = master;

		// Nastavenie poctu aktivnych socketov
		int pocetSocketov = select(0, &copy, nullptr, nullptr, nullptr);

		// For cyklus prechadzajuci vsetkymi aktivnymi socketami
		for (int i = 0; i < pocetSocketov; i++)
		{
			// Ziskanie socketu z Winsock struktury
			SOCKET sock = copy.fd_array[i];

			// Je to listening socket s ktorym chcem nadviazat spojenie
			if (sock == listening)
			{
				// Prijatie spojenia
				SOCKET client = accept(listening, nullptr, nullptr);

				// Pridanie spojenia do handle-u
				FD_SET(client, &master);

				// Zaslanie uvodnej spravy
				string welcomeMsg = "Bol si pripojeny do chatovacej miestnosti, teraz mozes pisat spravy.\r\n";
				send(client, welcomeMsg.c_str(), welcomeMsg.size() + 1, 0);
			}
			else // Je to uz aktivne spojenie -> zaslanie spravy
			{
				char buf[DLZKA_SPRAVY];
				memset(buf, 0, DLZKA_SPRAVY);

				// Ziskanie spravy
				int bytesIn = recv(sock, buf, DLZKA_SPRAVY, 0);
				if (bytesIn <= 0)
				{
					// Zmazanie klient-a
					closesocket(sock);
					FD_CLR(sock, &master);
				}
				else
				{
					// Overenie pre \quit commandu
					if (buf[0] == '\\')
					{
						string cmd = string(buf, bytesIn);
						if (cmd == "\\quit")
						{
							spusteny = false;
							break;
						}
						// Nespoznany prikaz
						continue;
					}

					// Zaslanie ziskanej spravy vsetkym socketom okrem odosielatela

					for (int i = 0; i < master.fd_count; i++)
					{
						SOCKET outSock = master.fd_array[i];
						if (outSock != listening && outSock != sock)
						{
							ostringstream sprava;
							sprava << "ID " << sock << ": " << buf << "\r\n";
							string odoslanaSprava = sprava.str();

							send(outSock, odoslanaSprava.c_str(), odoslanaSprava.size() + 1, 0);
						}
					}
				}
			}
		}
	}

	// Vymazanie listening socketu z master HANDLE-u (aby nemohlo nastat nove spojenie)
	FD_CLR(listening, &master);
	closesocket(listening);

	while (master.fd_count > 0)
	{
		// Ziskanie cislo socketu
		SOCKET sock = master.fd_array[0];

		// Vymazanie udajov z handle-u v master HANDLE-i
		FD_CLR(sock, &master);
		closesocket(sock);
	}

	// Vymazanie winsocku
	WSACleanup();
	system("pause");
	return 0;
}