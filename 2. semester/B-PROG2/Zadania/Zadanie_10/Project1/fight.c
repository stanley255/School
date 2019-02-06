#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#include "helpers.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int isThereRole(Hrac hrac, char *hladanaRola) {
	for (int i = 0; i < SIZEOFPLAYERARMY; i++) {
		if ((hrac.armadaHraca->vojisko[i].hp > 0) && (strcmp(hrac.armadaHraca->vojisko[i].role, hladanaRola) == 0)) {
			return 1;
		}
	}
	return 0;
}

int isRoleFighting(Hrac hrac, char *hladanaRola, int indexVojaka) {
	if (strcmp(hrac.armadaHraca->vojisko[indexVojaka].role, hladanaRola) == 0)
		return 1;
	return 0;
}

int numberOfCertainRoleInTeam(Hrac hrac, char *hladanaRola) {
	int counter = 0;
	for (int i = 0; i < SIZEOFPLAYERARMY; i++) {
		if ((hrac.armadaHraca->vojisko[i].hp > 0) && (strcmp(hrac.armadaHraca->vojisko[i].role, hladanaRola) == 0))
			counter++;
	}
	return counter;
}

void priestBuff(Hrac *hrac) {
	int randomVojak;
	if (hrac->armadaHraca->pocet == 0)
		return;
	do {
		randomVojak = rand() % SIZEOFPLAYERARMY;
	} while (hrac->armadaHraca->vojisko[randomVojak].hp<1);
	hrac->armadaHraca->vojisko[randomVojak].hp += 1;
	printf("\nHrac %s ma vo svojom vojsku priest-a, ktory oliecuje %s z %i na %i.\n",
		hrac->meno,hrac->armadaHraca->vojisko[randomVojak].meno,
		(hrac->armadaHraca->vojisko[randomVojak].hp)-1,
		hrac->armadaHraca->vojisko[randomVojak].hp);
}

void tankBuff(Hrac *hrac, int indexVojaka) {
	hrac->armadaHraca->vojisko[indexVojaka].def += 1;
	printf("\n%s ma v teame tank-a, ktory zvysuje obranu na %i\n", hrac->meno, hrac->armadaHraca->vojisko[indexVojaka].def);
}

void warriorBuff(Hrac *hrac, int indexVojaka) {
	if (rand() % 2)
		hrac->armadaHraca->vojisko[indexVojaka].att += 1;
	else
		hrac->armadaHraca->vojisko[indexVojaka].def += 1;
}

void rogueBuff(Hrac *hrac) {
	printf("\n%s-va skupina rogue-ov si zvysuje hodnotu svojho utoku o 1\n", hrac->meno);
	for (int i = 0; i < SIZEOFPLAYERARMY; i++) {
		if ((hrac->armadaHraca->vojisko[i].hp > 0) && (strcmp(hrac->armadaHraca->vojisko[i].role, "rogue") == 0))
			hrac->armadaHraca->vojisko[i].att += 1;		
	}
}

void buffy(Hrac *hracA, Hrac *hracB, int indexVojakaA, int indexVojakaB, int cisloKola) {
	//TANK BUFF
	if ((cisloKola > 5) && (isRoleFighting(*hracA, "tank", indexVojakaA)) && (hracA->armadaHraca->vojisko[indexVojakaA].hp>0)) {
		tankBuff(hracA, indexVojakaA);
	}
	if ((cisloKola > 5) && (isRoleFighting(*hracB, "tank", indexVojakaB)) && (hracB->armadaHraca->vojisko[indexVojakaB].hp>0))
		tankBuff(hracB, indexVojakaB);
	//PRIEST BUFF
	if (isThereRole(*hracA, "priest"))
		priestBuff(hracA);
	if (isThereRole(*hracB, "priest"))
		priestBuff(hracB);
	//ROGUE BUFF
	if (numberOfCertainRoleInTeam(*hracA, "rogue") > 1)
		rogueBuff(hracA);
	if (numberOfCertainRoleInTeam(*hracB, "rogue") > 1)
		rogueBuff(hracB);
}

int vyberVojaka(Hrac *hrac) {
	int volba;
	vypisVojiskoHraca(*hrac->armadaHraca);
	printf("%s, zvol si svojho bojovnika:\n",hrac->meno);
	do {
		volba = nacitajVstup(1, SIZEOFPLAYERARMY);
	} while (hrac->armadaHraca->vojisko[volba].hp<1);
	vypisKonkretnehoVojaka(*hrac->armadaHraca,volba);
	getchar();
	CLEAR_SCREEN();
	return volba;
}

int subojVojakov(Hrac *hrac1, Hrac *hrac2, int index1, int index2) {
	int att1 = hrac1->armadaHraca->vojisko[index1].att;
	int def2 = hrac2->armadaHraca->vojisko[index2].def;
	int hodnotaUtoku;
	int damageDealt = 0;
	//VYPIS STATISTIK UTOCNIKA A OBRANCU
	printf("\nUctocnik: \n%s-ov vojak:\n\n",hrac1->meno);
	vypisKonkretnehoVojaka(*hrac1->armadaHraca, index1);
	printf("\nObranca: \n%s-ov vojak:\n\n", hrac2->meno);
	vypisKonkretnehoVojaka(*hrac2->armadaHraca, index2);
	//VYPIS HODNOTY UTOKU UTOCNIKA A OBRANY OBRANCU
	hodnotaUtoku = rand() % (att1 + def2) + 1;
	printf("\nHodnota utoku: %i\n",hodnotaUtoku);
	printf("Hodnota obrany: %i\n",def2);
	if (hodnotaUtoku > def2) {
		printf("Zasah! %s-ov vojak sposobuje poskodenie %i\n",hrac1->meno,att1);
		hrac2->armadaHraca->vojisko[index2].hp -= att1;
		damageDealt += att1;
		printf("%s-emu vojakovi zostava HP: %i", hrac2->meno, hrac2->armadaHraca->vojisko[index2].hp);
	}
	else {
		printf("%s-ov vojak sa ubranil a prechadza do protiutoku!\n",hrac2->meno);
	}
	return damageDealt;
}

void vypisCas(FILE *log, int startOrEnd) {
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	if (startOrEnd)
		fprintf(log, "END TIME:");
	else 
		fprintf(log, "START TIME:");
	fprintf(log, "%d.%d.%d %d:%d:%d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
	fprintf(log,"**********************************************************\n");
};

void writeResults(Hrac *hracA, Hrac *hracB, int totalDamageDealt[], FILE *fin, int najkratsieKolo, int najdlhsieKolo, int pocetKol, int vytrvalec[], int zbabelec[]) {
	vypisCas(fin,1);
	fprintf(fin, "\n\n*****ZVITAZIL HRAC %s*****\n\n\n", hracA->meno);
	IOvypisVojiskoHraca(*hracA->armadaHraca, fin);
	fprintf(fin, "---------%s-va armada---------\n", hracA->meno);
	fprintf(fin, "   Total damage dealt: %3.i\n", totalDamageDealt[0]);
	fprintf(fin, "   Pocet vojakov po bitke: %i\n\n", hracA->armadaHraca->pocet);

	fprintf(fin, "---------%s-va armada---------\n", hracB->meno);
	fprintf(fin, "   Total damage dealt: %3.i\n", totalDamageDealt[1]);
	fprintf(fin, "   Pocet vojakov po bitke: %i\n\n", hracB->armadaHraca->pocet);
	fprintf(fin, "Dalsie statistiky:\n");
	fprintf(fin, "   Celkovy pocet kol: %i\n", pocetKol);
	fprintf(fin, "   Najkratsie kolo(pocet tahov): %i\n",najkratsieKolo);
	fprintf(fin, "   Najdlhsie kolo(pocet tahov): %i\n", najdlhsieKolo);
	fprintf(fin, "   \nVojak, ktory vydrzal najviac kol:\n");
	if (vytrvalec[0]==0)
		IOvypisKonkretnehoVojaka(*hracA->armadaHraca, vytrvalec[1],fin);
	else 
		IOvypisKonkretnehoVojaka(*hracB->armadaHraca, vytrvalec[1], fin);
	fprintf(fin, "   \nVojak, ktory vydrzal najmenej kol:\n");
	if (zbabelec[0]==0)
		IOvypisKonkretnehoVojaka(*hracA->armadaHraca, zbabelec[1], fin);
	else
		IOvypisKonkretnehoVojaka(*hracB->armadaHraca, zbabelec[1], fin);
}

void vojnaHracov(Hrac *hracA, Hrac *hracB, char *argv[], int vstupy[]) {
	srand(time(NULL));
	int vypadol = 2, indexVojakaA, indexVojakaB, cisloTahu, pocetKol = 0;
	int najdlhsieKolo = 0, najkratsieKolo = 100, vytrvalec[2], zbabelec[2];
	int totalDamageDealt[] = { 0,0 };

	FILE *log = fopen("log.txt","a");
	vypisCas(log,0);
	fprintf(log,"\nVOJSKO HRACA: %s\n", hracA->meno);
	IOvypisVojiskoHraca(*hracA->armadaHraca, log);
	fprintf(log, "\nVOJSKO HRACA: %s\n", hracB->meno);
	IOvypisVojiskoHraca(*hracB->armadaHraca, log);
	
	do {
		fprintf(log,"\n%i. kolo\n",++pocetKol);
		cisloTahu = 1;
		printf("------------VOJNA------------\n");
		//VYBER VOJAKOV
		if (vypadol == 1)
			indexVojakaA = vyberVojaka(hracA);
		else if (vypadol == 0)
			indexVojakaB = vyberVojaka(hracB);
		else {
			indexVojakaA = vyberVojaka(hracA);
			indexVojakaB = vyberVojaka(hracB);
		}

		fprintf(log,"\n%s si zvolil: \n",hracA->meno);
		IOvypisKonkretnehoVojaka(*hracA->armadaHraca, indexVojakaA, log);
		fprintf(log, "\n%s si zvolil: \n", hracB->meno);
		IOvypisKonkretnehoVojaka(*hracB->armadaHraca, indexVojakaB, log);

		//WARRIOR BUFF
		if (isRoleFighting(*hracA, "warrior", indexVojakaA))
			warriorBuff(hracA, indexVojakaA);
		if (isRoleFighting(*hracB, "warrior", indexVojakaB))
			warriorBuff(hracB, indexVojakaB);
		//SAMOTNY SUBOJ 2 VOJAKOV
		do {
			printf("---------%i.TAH---------\n", cisloTahu);
			if (cisloTahu % 2 == 1)
				totalDamageDealt[0] += subojVojakov(hracA, hracB, indexVojakaA, indexVojakaB);
			else
				totalDamageDealt[1] += subojVojakov(hracB, hracA, indexVojakaB, indexVojakaA);
			cisloTahu++;
			getchar();
			CLEAR_SCREEN();
		} while ((hracA->armadaHraca->vojisko[indexVojakaA].hp > 0) && (hracB->armadaHraca->vojisko[indexVojakaB].hp > 0));
		//LOG PO SUBOJI 1V1
		printf("----------VYSLEDOK PO SUBOJI---------\n");
		//BUFFY
		buffy(hracA,hracB,indexVojakaA,indexVojakaB, cisloTahu);
		//VYHODNOTENIE PADLEHO VOJAKA
		if (cisloTahu % 2 == 1) {
			vypadol = 1;
			hracA->armadaHraca->pocet -= 1;
			printf("\nHrac %s stratil bojovnika :(\n\n", hracA->meno);
			fprintf(log, "\nSuboj vyhral %s s: \n", hracB->meno);
			IOvypisKonkretnehoVojaka(*hracB->armadaHraca, indexVojakaB, log);
			fprintf(log, "\n********************************************\n");
		}
		else {
			vypadol = 0;
			hracB->armadaHraca->pocet -= 1;
			printf("\nHrac %s stratil bojovnika :(\n\n", hracB->meno);
			fprintf(log, "\nSuboj vyhral %s s: \n", hracA->meno);
			IOvypisKonkretnehoVojaka(*hracA->armadaHraca, indexVojakaA, log);
			fprintf(log, "\n********************************************\n");
		}
		//STATISTICKA CAST
		if (cisloTahu > najdlhsieKolo) {
			najdlhsieKolo = cisloTahu;
			if (vypadol) {
				vytrvalec[0] = 1;
				vytrvalec[1] = indexVojakaB;
			}
			else {
				vytrvalec[0] = 0;
				vytrvalec[1] = indexVojakaA;
			}				
		}
		if (cisloTahu < najkratsieKolo) {
			najkratsieKolo = cisloTahu;
			if (vypadol) {
				zbabelec[0] = 0;
				zbabelec[1] = indexVojakaA;
			}
			else {
				zbabelec[0] = 1;
				zbabelec[1] = indexVojakaB;
			}
		}	

		getchar();
		CLEAR_SCREEN();
	} while ((hracA->armadaHraca->pocet>0)&&(hracB->armadaHraca->pocet));
	//VYPIS VYSLEDKY
	printf("---------%s-va armada---------\n",hracA->meno);
	printf("   Total damage dealt: %3.i\n", totalDamageDealt[0]);
	printf("   Pocet vojakov po bitke: %i\n\n",hracA->armadaHraca->pocet);

	printf("---------%s-va armada---------\n", hracB->meno);
	printf("   Total damage dealt: %3.i\n", totalDamageDealt[1]);
	printf("   Pocet vojakov po bitke: %i\n\n", hracB->armadaHraca->pocet);

	if (hracA->armadaHraca->pocet != 0) {
		printf("\n\n\n\n\n*****ZVITAZIL HRAC %s*****\n\n\n\n\n", hracA->meno);
	}
	else {
		printf("\n\n\n\n\n*****ZVITAZIL HRAC %s*****\n\n\n\n\n", hracB->meno);
	}
	if (vstupy[1]!=-1) {
		FILE *fout = fopen(argv[vstupy[1]],"w");
		if ((fout) == NULL) {
			fprintf(stderr, "FAILED TO LOAD FILES.");
			exit(-1);
		}			
		writeResults(hracA, hracB, totalDamageDealt, fout, --najkratsieKolo, --najdlhsieKolo, pocetKol, vytrvalec, zbabelec);
		fclose(fout);
	}		
	fclose(log);
	getchar();
}