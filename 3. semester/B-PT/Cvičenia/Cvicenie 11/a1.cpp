#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
#include <list>
#include <initializer_list>
#include <utility>
#include <tuple>
#include <stack>
#include <queue>
#include <map>
#include <limits>
#include <functional>
#include <algorithm>

// hlavickove subory s definiciami vynimkovych tried
#include "graph_exceptions.h"
#include "path_exceptions.h"

// hlavickovy subor s definiciou triedy 'Path', ktora
// reprezentuje cestu v grafe
#include "path.h"

using namespace std;

// Tema: Graf
// Typ grafu: orientovany, hranovo-ohodnoteny, zakazane viacnasobne 
// hrany a duplicitne vrcholy.
// Styl implementacie: zoznam susedov (z angl. adjacency list)

// Vyhody:
//		* pridavanie/odstranovanie vrcholov je efektivne
//		* rychle zistenie vsetkych susedov vrcholu
//		* setri pamat, zabera priestor O(|V|+|E|), matica susednosti zabera
//		* rychly vypocet vystupneho stupna vrcholu
// Nevyhody:
//		* neefektivne operacie ako pridanie/odstranenie hrany
//		* neefektivne zistenie, ci medzi 2 vrcholmi existuje hrana


class GraphAsAdjacencyList {
	struct Vertex; // forward deklaracia struktury 'Vertex'

	// struktura reprezentujuca vystupnu hranu v grafe
	struct EdgeTo {
		Vertex * endVertex; // koncovy vrchol hrany
		int length; // dlzka hrany
		EdgeTo(Vertex * endVertex, int length) :
			endVertex(endVertex), length(length)
		{};
		bool operator ==(const EdgeTo& other) {
			return (this->endVertex == other.endVertex && this->length == other.length);
		}
	};

	// struktura reprezentujuca vrchol grafu, v ktorej je uvedeny
	// jeho nazov a zoznam vystupnych hran
	struct Vertex {
		string name; // nazov vrcholu
		list<EdgeTo> edges; // zoznam vystupnych hran
		Vertex(string name) :
			name(name)
		{};
		bool operator ==(const Vertex& other) {
			return (this->name == other.name);
		}
	};

	list<Vertex> vertices; // zoznam vsetkych vrcholov grafu

	// TODO 0.1
	// Funkcia vrati referenciu na vrchol
	// s menom 'vertexName'. Ak sa dany vrchol 
	// v grafe nenajde, vyhodi sa vynimka typu
	// 'VertexMissingException'.
	//
	// Vyhadzuje vynimky:
	//		* VertexMissingException
	//
	Vertex& getVertex(string vertexName) {
		auto result = find_if(
			this->vertices.begin(),
			this->vertices.end(),
			[&vertexName](const Vertex& v) {return v.name == vertexName; }
		);
		if (result != this->vertices.end()) {
			return *result;
		}
		throw VertexMissingException(vertexName);
	}

	// TODO 0.2
	// Funkcia vrati referenciu na vystupnu hranu
	// z vrcholu 'vertexName1' do vrcholu 'vertexName2'.
	// Ak sa v grafe 'vertexName1' alebo 'vertexName2' 
	// nenachadza, vyhodi sa vynimka typu 'VertexMissingException'. 
	// Ak uvedene vrcholy nie su spojene hranou, vyhodi sa 
	// vynimka typu 'EdgeMissingException'.
	//
	// Vyhadzuje vynimky:
	//		* VertexMissingException
	//		* EdgeMissingException
	//
	EdgeTo& getEdge(string vertexName1, string vertexName2) {
		Vertex& source = this->getVertex(vertexName1); // moze vyhodit 'VertexMissingException'
		Vertex& destination = this->getVertex(vertexName2); // moze vyhodit 'VertexMissingException'
		auto result = find_if(
			source.edges.begin(),
			source.edges.end(),
			[&](const EdgeTo& edge) { return edge.endVertex == &destination; }
		);
		if (result != source.edges.end()) {
			return *result;
		}
		throw EdgeMissingException(vertexName1, vertexName2);
	}

public:

	// default konstruktor
	GraphAsAdjacencyList() {

	}

	// TODO 1
	// Funkcia vrati true/false, podla toho,
	// ci vrchol 'vertexName' v grafe existuje/neexistuje.
	//
	// Vyhadzuje vynimky: ziadne
	//
	bool containsVertex(string vertexName) {
		try {
			this->getVertex(vertexName);
			return true;
		}
		catch (VertexMissingException& e) {
			return false;
		}
	}

	// TODO 2
	// Funkcia vrati true/false, podla toho,
	// ci hrana z 'vertexName1' do 'vertexName2' existuje/neexistuje.
	//
	// Vyhadzuje vynimky: ziadne
	//
	bool containsEdge(string vertexName1, string vertexName2) {
		try {
			this->getEdge(vertexName1, vertexName2);
			return true;
		}
		catch (VertexMissingException& e) {
			return false;
		}
		catch (EdgeMissingException& e) {
			return false;
		}
	}

	// TODO 3
	// Funkcia prida vrchol 'vertexName' do grafu.
	// Ak sa vrchol v grafe uz nachadza, tak vyhodi 
	// vynimku typu 'VertexDuplicateException'.
	//
	// Vyhadzuje vynimky:
	//		* VertexDuplicateException
	//
	void addVertex(string vertexName) {
		if (!this->containsVertex(vertexName)) {
			this->vertices.push_back(Vertex(vertexName));
			return;
		}
		throw VertexDuplicateException(vertexName);
	}

	// TODO 4
	// Funkcia prida hranu z vrcholu 'vertexName1' do 
	// 'vertexName2' s dlzkou 'length'.
	// Ak sa vrchol 'vertexName1' alebo 'vertexName2' v 
	// grafe nenachadza, vyhodi sa vynimka 'VertexMissingException'.
	// Ak sa taka hrana v grafe uz nachadza, vyhodi sa vynimka 
	// 'EdgeDuplicateException'.
	//
	// Vyhadzuje vynimky:
	//		* VertexMissingException
	//		* EdgeDuplicateException
	//
	void addEdge(string vertexName1, string vertexName2, int length) {
		if (!this->containsEdge(vertexName1, vertexName2)) {
			Vertex& v1 = this->getVertex(vertexName1); // moze vyhodit vynimku 'VertexMissingException'
			Vertex& v2 = this->getVertex(vertexName2); // moze vyhodit vynimku 'VertexMissingException'
			v1.edges.push_back(EdgeTo(&v2, length));
			return;
		}
		throw EdgeDuplicateException(vertexName1, vertexName2);
	}

	// TODO 5
	// Funkcia, ktora vrati textovu reprezentaciu grafu.
	// Textova reprezentacia bude obsahovat vsetky vrcholy
	// grafu a ich zoznam vystupnych hran s uvedenim cieloveho
	// vrcholu hrany a jej dlzky.
	//
	// Vyhadzuje vynimky: ziadne
	//
	string toString() {
		stringstream sstream;
		// prejdeme celym zoznamom vrcholov
		for (const Vertex& v : this->vertices) {
			sstream << "Vertex: " << v.name << endl;
			// prejdeme vsetkymi vystupnymi hranami
			for (const EdgeTo& edge : v.edges) {
				sstream << "        ---> " << edge.endVertex->name << " (" << edge.length << ")" << endl;
			}
		}
		return sstream.str();
	}

	// TODO 6
	// Funkcia odstrani vrchol 'vertexName' z grafu.
	// Funkcia odstrani aj prislusne hrany.
	// Ak sa vrchol v grafe nenachadza, tak vyhodi 
	// vynimku typu 'VertexMissingException'.
	//
	// Vyhadzuje vynimky:
	//		* VertexMissingException
	//
	void removeVertex(string vertexName) {
		Vertex& to_remove = this->getVertex(vertexName); // moze vyhodit 'VertexMissingException'
		// vymazeme vsetky vyskyty vrcholu 'vertexName' vo vystupnych hranach inych vrcholov
		for (Vertex& v : this->vertices) {
			for (auto it = v.edges.begin(); it != v.edges.end();) {
				if ((*it).endVertex == &to_remove) {
					it = v.edges.erase(it);
					continue;
				}
				it++;
			}
		}
		this->vertices.remove(to_remove);
	}

	// TODO 7
	// Funkcia odstrani hranu z 'vertexName1' do 'vertexName2'.
	// Ak sa vrchol 'vertexName1' alebo 'vertexName2' v grafe 
	// nenachadza, tak vyhodi vynimku typu 'VertexMissingException'.
	// Ak sa hrana z 'vertexName1' do 'vertexName2' v grafe 
	// nenachadza, tak vyhodi vynimku typu 'EdgeMissingException'.
	//
	// Vyhadzuje vynimky:
	//		* VertexMissingException
	//		* EdgeMissingException
	//
	void removeEdge(string vertexName1, string vertexName2) {
		// moze vyhodit 'VertexMissingException' alebo 'EdgeMissingException' 
		EdgeTo& edge = this->getEdge(vertexName1, vertexName2);
		Vertex& source = this->getVertex(vertexName1);
		source.edges.remove(edge);
	}

	// TODO 8
	// Funkcia vrati vektor nazvov susednych vrcholov
	// vrcholu 'vertexName'. Susedny vrchol je taky, 
	// s ktorym je vrchol 'vertexName' spojeny vystupnou 
	// hranou. Ak sa vrchol 'vertexName' v grafe nenachadza,
	// vyhodi sa vynimka typu 'VertexMissingException'.
	//
	// Vyhadzuje vynimky:
	//		* VertexMissingException
	//
	vector<string> neighbors(string vertexName) {
		Vertex& v = this->getVertex(vertexName); // moze vyhodit 'VertexMissingException'
		vector<string> neighbor_names;
		for (const EdgeTo& edge : v.edges) {
			neighbor_names.push_back(edge.endVertex->name);
		}
		return neighbor_names;
	}

	// TODO 9
	// Funkcia, ktora vrati vektor nazvov vsetkych vrcholov v grafe.
	//
	// Vyhadzuje vynimky: ziadne
	//
	vector<string> getVertexNames() {
		vector<string> vertex_names;
		for (const Vertex& v : this->vertices) {
			vertex_names.push_back(v.name);
		}
		return vertex_names;
	}

	// TODO 10
	// Funkcia vrati vstupny stupen vrcholu 'vertexName'.
	// Vstupny stupen vrcholu hovori kolko hran do neho vstupuje. 
	// Ak sa vrchol 'vertexName' v grafe nenachadza,
	// vyhodi sa vynimka typu 'VertexMissingException'.
	//
	// Vyhadzuje vynimky:
	//		* VertexMissingException
	//
	int inDegree(string vertexName) {
		Vertex& v = this->getVertex(vertexName); // moze vyhodit 'VertexMissingException'
		int in_degree = 0;
		// musime prejst vsetky vystupne hrany ostatnych vrcholov
		for (const Vertex& vert : this->vertices) {
			for (const EdgeTo& e : vert.edges) {
				if (e.endVertex == &v) {
					in_degree++;
				}
			}
		}
		return in_degree;
	}

	// TODO 11
	// Funkcia vrati vystupny stupen vrcholu 'vertexName'.
	// Vystupny stupen vrcholu hovori kolko hran z neho vystupuje. 
	// Ak sa vrchol 'vertexName' v grafe nenachadza,
	// vyhodi sa vynimka typu 'VertexMissingException'.
	//
	// Vyhadzuje vynimky:
	//		* VertexMissingException
	//
	int outDegree(string vertexName) {
		Vertex& v = this->getVertex(vertexName); // moze vyhodit 'VertexMissingException'
		return v.edges.size();
	}

	// TODO 12
	// Funkcia vrati postupnost navstivenych vrcholov pocas
	// prechodu grafom do hlbky (pre-order) z vrcholu 'startVertexName'. 
	// Ak sa vrchol 'startVertexName' v grafe nenachadza, 
	// vyhodi sa vynimka typu 'VertexMissingException'.
	//
	// Vyhadzuje vynimky:
	//		* VertexMissingException
	//
	list<string> dfs(string startVertexName) {
		Vertex* start_v = &this->getVertex(startVertexName); // moze vyhodit 'VertexMissingException'
		stack<Vertex*> S; // prazdny zasobnik obsahujuci adresy vrcholov grafu
		Vertex* u = nullptr; // pomocny smernik na vrchol grafu
		list<string> sequence; // postupnost navstivenych vrcholov pocas DFS

		// pomocna mapa na zistenie, ci bol 
		// vrchol pocas prechodu navstiveny
		map<Vertex*, bool> visited;
		for (Vertex& v : this->vertices) {
			visited[&v] = false; // na zaciatku su vsetky vrcholy nenavstivene
		}

		S.push(start_v); // na vrch zasobnika vlozime startovaci vrchol

		 // hlavny algoritmus
		while (!S.empty()) {
			u = S.top();
			S.pop();
			if (!visited[u]) {
				visited[u] = true;
				sequence.push_back(u->name);
				for (const EdgeTo& e : u->edges) {
					if (!visited[e.endVertex]) {
						S.push(e.endVertex);
					}
				}
			}
		}
		return sequence;
	}

	// TODO 13
	// Funkcia najde a vrati cestu ('Path') z vrcholu 
	//	'startVertexName' do vrcholu 'endVertexName' 
	// pomocou prehladavania grafu do hlbky (Depth First Search). 
	// Ak sa vrchol 'startVertexName' alebo 'endVertexName' 
	// v grafe nenachadza, vyhodi sa vynimka typu 'VertexMissingException'. 
	// Ak graf neobsahuje cestu z 'startVertexName' do 'endVertexName',
	// vyhodi sa vynimka typu 'NoPathException'.
	//
	// Vyhadzuje vynimky:
	//		* VertexMissingException
	//		* NoPathException
	//
	Path dfs_Path(string startVertexName, string endVertexName) {
		Vertex* start_v = &this->getVertex(startVertexName); // moze vyhodit 'VertexMissingException'
		Vertex* end_v = &this->getVertex(endVertexName); // moze vyhodit 'VertexMissingException'

		stack<Vertex*> S; // prazdny zasobnik obsahujuci adresy vrcholov grafu
		Vertex* u = nullptr; // pomocny smernik na vrchol grafu

		// docasna pomocna struktura na ulozenie informacii pre ucely
		// prechodu grafom a rekonstrukciu cesty z 'startVertexName'
		// do 'endVertexName'.
		//
		// V tejto strukture ma kazdy vrchol evidovane 3 informacie:
		//	* navstivenost (bool)
		//	* predchadzajuci vrchol na ceste (Vertex *)
		//	* dlzka hrany z predchadzajuceho vrcholu na ceste (int)
		struct VertexInfo {
			bool visited;
			Vertex* previousVertex;
			int edgeLength;
		};

		map<Vertex*, VertexInfo> searchInfo; // kazdemu vrcholu namapujeme jeho VertexInfo
		for (Vertex& v : this->vertices) {
			searchInfo[&v] = { false, nullptr, -1 };
		}

		S.push(start_v); // na vrch zasobnika vlozime startovaci vrchol

		// hlavny algoritmus
		while (!S.empty()) {
			u = S.top();
			S.pop();
			if (u->name == endVertexName) {
				Path path(startVertexName); // cesta z 'startVertexName' do 'endVertexName'
				// cestu najdeme pomocou spatneho prechodu (backtrace) 
				// rodicmi az k startovaciemu vrcholu (ten nema rodica)
				while (u->name != startVertexName) {
					path.addEdgeToFront(u->name, searchInfo[u].edgeLength); // naplname cestu
					u = searchInfo[u].previousVertex;
				}
				return path; // vratim cestu
			}
			if (!searchInfo[u].visited) {
				searchInfo[u].visited = true;
				for (const EdgeTo& e : u->edges) {
					if (!searchInfo[e.endVertex].visited) {
						S.push(e.endVertex);
						searchInfo[e.endVertex].previousVertex = u; // aktualizujem rodica kazdeho cieloveho vrcholu
						searchInfo[e.endVertex].edgeLength = e.length; // aktualizujem dlzku hrany ku cielovemu vrcholu
					}
				}
			}
		}
		throw NoPathException(startVertexName, endVertexName); // cesta neexistuje
	}

	// TODO 14
	// Funkcia vrati postupnost navstivenych vrcholov pocas
	// prechodu grafom do sirky z vrcholu 'startVertexName'. 
	// Ak sa vrchol 'startVertexName' v grafe nenachadza, 
	// vyhodi sa vynimka typu 'VertexMissingException'.
	//
	// Vyhadzuje vynimky:
	//		* VertexMissingException
	//
	list<string> bfs(string startVertexName) {
		Vertex* start_v = &this->getVertex(startVertexName); // moze vyhodit 'VertexMissingException'
		queue<Vertex*> Q; // prazdna fronta obsahujuca adresy vrcholov grafu
		Vertex* u = nullptr; // pomocny smernik na vrchol grafu
		list<string> sequence; // postupnost navstivenych vrcholov pocas BFS

		// pomocna mapa na zistenie, ci bol 
		// vrchol pocas prechodu navstiveny
		map<Vertex*, bool> visited;
		for (Vertex& v : this->vertices) {
			visited[&v] = false; // na zaciatku su vsetky vrcholy nenavstivene
		}

		visited[start_v] = true;
		sequence.push_back(startVertexName);
		Q.push(start_v); // do fronty vlozime startovaci vrchol

		// hlavny algoritmus
		while (!Q.empty()) {
			u = Q.front();
			Q.pop();
			for (const EdgeTo& e : u->edges) {
				if (!visited[e.endVertex]) {
					visited[e.endVertex] = true;
					sequence.push_back(e.endVertex->name);
					Q.push(e.endVertex);
				}
			}
		}
		return sequence;
	}

	// TODO 15
	// Funkcia najde a vrati cestu ('Path') z vrcholu 
	//	'startVertexName' do vrcholu 'endVertexName' 
	// pomocou prehladavania grafu do sirky (Breadth First Search). 
	// Ak sa vrchol 'startVertexName' alebo 'endVertexName' 
	// v grafe nenachadza, vyhodi sa vynimka typu 'VertexMissingException'. 
	// Ak graf neobsahuje cestu z 'startVertexName' do 'endVertexName',
	// vyhodi sa vynimka typu 'NoPathException'.
	//
	// Vyhadzuje vynimky:
	//		* VertexMissingException
	//		* NoPathException
	//
	Path bfs_Path(string startVertexName, string endVertexName) {
		Vertex* start_v = &this->getVertex(startVertexName); // moze vyhodit 'VertexMissingException'
		Vertex* end_v = &this->getVertex(endVertexName); // moze vyhodit 'VertexMissingException'

		queue<Vertex*> Q; // prazdna fronta obsahujuca adresy vrcholov grafu
		Vertex* u = nullptr; // pomocny smernik na vrchol grafu

		// docasna pomocna struktura na ulozenie informacii pre ucely
		// prechodu grafom a rekonstrukciu cesty z 'startVertexName'
		// do 'endVertexName'.
		//
		// V tejto strukture ma kazdy vrchol evidovane 3 informacie:
		//	* navstivenost (bool)
		//	* predchadzajuci vrchol na ceste (Vertex *)
		//	* dlzka hrany z predchadzajuceho vrcholu na ceste (int)
		struct VertexInfo {
			bool visited;
			Vertex* previousVertex;
			int edgeLength;
		};

		map<Vertex*, VertexInfo> searchInfo; // kazdemu vrcholu namapujeme jeho VertexInfo
		for (Vertex& v : this->vertices) {
			searchInfo[&v] = { false,nullptr,-1 };
		}

		searchInfo[start_v].visited = true;
		Q.push(start_v); // do fronty vlozime startovaci vrchol

		// hlavny algoritmus
		while (!Q.empty()) {
			u = Q.front();
			Q.pop();
			if (u->name == endVertexName) {
				Path path(startVertexName); // cesta z 'startVertexName' do 'endVertexName'
				// cestu najdeme pomocou spatneho prechodu (backtrace) 
				// rodicmi az k startovaciemu vrcholu (ten nema rodica)
				while (u->name != startVertexName) {
					path.addEdgeToFront(u->name, searchInfo[u].edgeLength); // naplname cestu
					u = searchInfo[u].previousVertex;
				}
				return path; // vratim cestu
			}
			for (const EdgeTo& e : u->edges) {
				if (!searchInfo[e.endVertex].visited) {
					searchInfo[e.endVertex].visited = true;
					Q.push(e.endVertex);
					searchInfo[e.endVertex].previousVertex = u; // aktualizujem rodica kazdeho cieloveho vrcholu
					searchInfo[e.endVertex].edgeLength = e.length; // aktualizujem dlzku hrany ku cielovemu vrcholu
				}
			}
		}
		throw NoPathException(startVertexName, endVertexName); // cesta neexistuje
	}

	// TODO 16
	// Dijkstrov algoritmus
	// Funkcia najde najkratsiu cestu z 'startVertexName' do 
	// 'endVertexName'. Ak sa v grafe 'startVertexName' alebo
	// 'endVertexName' nenachadza, vyhodi sa vynimka 
	// 'VertexMissingException'. Ak neexistuje taka cesta,
	// vyhodi sa vynimka 'NoPathException'.
	//
	// Vyhadzuje vynimky:
	//		* VertexMissingException
	//		* NoPathException
	//
	Path dijkstra(string startVertexName, string endVertexName) {

		// Ziskame referenciu na startovaci a koncovy vrchol
		// ak neexistuju, vyhodi sa vynimka.
		Vertex* sV = &this->getVertex(startVertexName);
		Vertex* eV = &this->getVertex(endVertexName);

		// Pomocna docasna struktura, ktora pre kazdy vrchol v grafe 
		// eviduje nasledovne informacie:
		//	* distance - aktualna dlzka najkratsej cesty od startovacieho vrcholu
		//	* previousVertex - smernik na predchodcu
		//	* edgeLength - dlzka hrany od predchodcu
		//	* visited - navstivenost vrcholu
		struct VertexInfo {
			float distance; // typ float kvoli tomu aby sme vedeli reprezentovat 'nekonecno'
			Vertex* previousVertex;
			int edgeLength;
			bool visited;
		};

		// par, kde ma kazdy vrchol namapovanu najkratsiu vzdialenost k startovaciemu vrcholu
		typedef pair<float, Vertex*> dPair;

		priority_queue<dPair, vector<dPair>, greater<dPair>> Q; // min priority queue s vrcholmi
		// Dovod pouzitia priority queue: ako prvy sa z Q vzdy vyberie vrchol 
		// s najkratsou vzdialenostou k 'startVertexName', je to predpoklad
		// rychlejsieho najdenia najkratsej cesty

		// mapa, v ktorej budeme mat pre kazdy vrchol ulozene jeho VertexInfo
		map<Vertex*, VertexInfo> all_V;

		for (Vertex& v : this->vertices) {
			// na zaciatku ma kazdy vrchol nekonecnu vzdialenost
			// od startovacieho vrcholu a je nenavstiveny
			all_V[&v] = { numeric_limits<float>::infinity(),nullptr, 0, false };
		}
		// zaciatocnemu vrcholu nastavime vzdialenost 0
		all_V[sV].distance = 0;

		// vlozime startovaci vrchol do priority queue
		Q.push(make_pair(all_V[sV].distance, sV));

		Vertex* currentVertex = nullptr;
		float currentDist;
		while (!Q.empty()) {
			// Vyber nenavstiveneho vrcholu s najkratsou 
			// vzdialenostou k vrcholu 'startVertexname'.
			// Tento vrchol sa nachadza na pozicii Q.top().
			currentVertex = Q.top().second;
			currentDist = Q.top().first;
			// ak sa nasla najkratsia cesta do cieloveho vrcholu 'endVertexName'
			if (currentVertex->name == endVertexName) {
				Path path(startVertexName); // cesta z 'startVertexName' do 'endVertexName'
				// cestu najdeme pomocou spatneho prechodu (backtrace) 
				// rodicmi az k startovaciemu vrcholu (ten nema rodica)
				while (currentVertex->name != startVertexName) {
					path.addEdgeToFront(currentVertex->name, all_V[currentVertex].edgeLength); // naplname cestu
					currentVertex = all_V[currentVertex].previousVertex;
				}
				return path; // vratim cestu
			}
			Q.pop(); // z priority queue vyhodime vrchol s najkratsou vzdialenostou k startovaciemu vrcholu
			if (!all_V[currentVertex].visited) {
				// aktualizujeme najkratsie vzdialenosti pre vsetkych
				// nenavstivenych susedov vrcholu 'currentVertex'
				for (EdgeTo& e : currentVertex->edges) {
					if (!all_V[e.endVertex].visited) {
						if ((currentDist + e.length) < all_V[e.endVertex].distance) {
							all_V[e.endVertex].distance = currentDist + e.length;
							all_V[e.endVertex].previousVertex = currentVertex;
							all_V[e.endVertex].edgeLength = e.length;
						}
						// do priority queue pridame nenavstivenych susedov vrcholu
						Q.push(make_pair(all_V[e.endVertex].distance, e.endVertex));
					}
				}
				all_V[currentVertex].visited = true;
			}
		}
		throw NoPathException(startVertexName, endVertexName);
	}

	// EXTRA uloha
	// Konstruktor, ktory vytvori graf z dodaneho 
	// inicializacneho zoznamu. 
	//
	// Format jedneho prvku inicializacneho zoznamu:
	// {nazov zdrojoveho vrcholu, zoznam vystupnych hran }
	//
	// Priklad inicializacneho zoznamu pre graf z webstranky cvicenia:
	// 
	//	{ "A",	{ {"C", 9}, {"D", 10}, {"F", 14}, {"H", 1}, {"I", 3} } }, 
	//	{ "B",	{ {"A", 7} } },
	//  { "C",	{ {"D", 8} } },
	//	{ "D",	{ {"A", 2} } },
	//	{ "E",	{ } },
	//	{ "F",	{ } },
	//	{ "G",	{ {"A", 2}, {"F", 4} } },
	//	{ "H",	{ {"D", 5}, {"G", 3} } },
	//	{ "I",	{ {"C", 1} } }
	//
	// Poznamka: vrcholy uvedene v zozname vystupnych hran budu rovno pridane do grafu.
	//
	// Vyhadzuje vynimky: ziadne
	//
	GraphAsAdjacencyList(initializer_list<pair<string, list<pair<string, int>>>> init_list) {
		for (auto t : init_list) {
			try {
				this->addVertex(t.first);
			}
			catch (VertexDuplicateException& e) {
				// Sem sa dostaneme ak sa vrchol v grafe uz nachadza.
				// Vynimku musime chytat na tomto mieste, inak by 
				// riadenie programu bolo odovzdane az do main-u.
			}
			// prejdeme vsetky vystupne hrany
			for (auto p : t.second) {
				try {
					this->addVertex(p.first);
				}
				catch (VertexDuplicateException& e) {
					// Sem sa dostaneme ak sa vrchol v grafe uz nachadza.
					// Vynimku musime chytat na tomto mieste, inak by 
					// riadenie programu bolo odovzdane az do main-u.
				}
				try {
					this->addEdge(t.first, p.first, p.second);
				}
				catch (EdgeDuplicateException& e) {
					// Sem sa dostaneme ak sa hrana v grafe uz nachadza.
					// Vynimku musime chytat na tomto mieste, inak by 
					// riadenie programu bolo odovzdane az do main-u.
				}
			}
		}
	}
};

int main() {
	GraphAsAdjacencyList g;

	// EXTRA uloha: konstruktor s inicializacnym zoznamom
	GraphAsAdjacencyList g2({
		{ "A",{ { "C", 9 },{ "D", 10 },{ "F", 14 },{ "H", 1 },{ "I", 3 } } },
		{ "B",{ { "A", 7 } } },
		{ "C",{ { "D", 8 } } },
		{ "D",{ { "A", 2 } } },
		{ "E",{} },
		{ "F",{} },
		{ "G",{ { "A", 2 },{ "F", 4 } } },
		{ "H",{ { "D", 5 },{ "G", 3 } } },
		{ "I",{ { "C", 1 } } }
	});

	try {
		// TODO 1 - containsVertex
		cout << "TODO 1" << endl;
		cout << "A: " << (g.containsVertex("A") ? "exists." : "does not exist.") << endl;

		// TODO 2 - containsEdge
		cout << endl << "TODO 2" << endl;
		cout << "Edge A->B: " << (g.containsEdge("A", "B") ? "exists." : "does not exist.") << endl;

		// TODO 3 - addVertex
		cout << endl << "TODO 3" << endl << "Adding vertices to graph." << endl;
		list<string> vertex_data{ "A","B","C","D","E","F","G","H","I" };
		for (string& v : vertex_data) {
			g.addVertex(v);
		}

		// TODO 4 - addEdge
		cout << endl << "TODO 4" << endl << "Adding edges to graph." << endl;
		list<tuple<string, string, int>> edge_data{
			make_tuple("A","C",9),
			make_tuple("A","D",10),
			make_tuple("A","F",14),
			make_tuple("A","H",1),
			make_tuple("A","I",3),
			make_tuple("B","A",7),
			make_tuple("C","D",8),
			make_tuple("D","A",2),
			make_tuple("G","A",2),
			make_tuple("G","F",4),
			make_tuple("H","D",5),
			make_tuple("H","G",3),
			make_tuple("I","C",1)
		};
		for (auto& e : edge_data) {
			g.addEdge(get<0>(e), get<1>(e), get<2>(e));
		}

		// TODO 5 - toString
		cout << endl << "TODO 5" << endl;
		cout << g.toString();

		// TODO 6 - removeVertex
		cout << endl << "TODO 6" << endl;
		cout << "Removing vertices." << endl;
		/*cout << "Removing vertex B" << endl;
		g.removeVertex("B");*/
		//cout << "Removing vertex W" << endl;
		//g.removeVertex("W"); // odkomentujte, co sa stane?
		//cout << g.toString();

		// TODO 7 - removeEdge
		cout << endl << "TODO 7" << endl;
		cout << "Removing edges." << endl;
		/*cout << "Removing edge A ---> C" << endl;
		g.removeEdge("A", "C");
		cout << "Removing edge H ---> G" << endl;
		g.removeEdge("H", "G");*/
		//cout << "Removing edge G ---> H" << endl;
		//g.removeEdge("G", "H"); // odkomentujte, co sa stane?
		//cout << "Removing edge X ---> B" << endl;
		//g.removeEdge("X", "B"); // odkomentujte, co sa stane?
		//cout << "Removing edge E ---> A" << endl;
		//g.removeEdge("E", "A"); // odkomentujte, co sa stane?
		//cout << g.toString();

		// TODO 8 - neighbors
		cout << endl << "TODO 8" << endl;
		cout << "Neighbors of A: ";
		vector<string> A_neighbors = g.neighbors("A");
		for (string& n : A_neighbors) { cout << n << " "; }
		cout << endl << "Neighbors of D: ";
		vector<string> D_neighbors = g.neighbors("D");
		for (string& n : D_neighbors) { cout << n << " "; }
		//cout << endl << "Neighbors of P: ";
		//vector<string> P_neighbors = g.neighbors("P"); // odkomentujte, co sa stane?
		//for (string& n : P_neighbors) { cout << n << " "; }

		// TODO 9 - getVertexNames
		cout << endl << endl << "TODO 9" << endl;
		cout << "All vertices in the graph: ";
		vector<string> all_vertex_names = g.getVertexNames();
		for (string& v : all_vertex_names) { cout << v << " "; }

		// TODO 10 - inDegree
		cout << endl << endl << "TODO 10" << endl;
		cout << "In-degree:" << endl;
		for (const string& n : all_vertex_names) { cout << n << ": " << g.inDegree(n) << endl; }

		// TODO 11 - outDegree
		cout << endl << "TODO 11" << endl;
		cout << "Out-degree:" << endl;
		for (const string& n : all_vertex_names) { cout << n << ": " << g.outDegree(n) << endl; }

		// TODO 12 - dfs
		cout << endl << "TODO 12" << endl;
		list<string> visited_sequence;
		cout << "DFS(A): ";
		visited_sequence = g.dfs("A");
		for (string s : visited_sequence) { cout << s << " "; }
		cout << endl << "DFS(B): ";
		visited_sequence = g.dfs("B");
		for (string s : visited_sequence) { cout << s << " "; }
		cout << endl << "DFS(F): ";
		visited_sequence = g.dfs("F");
		for (string s : visited_sequence) { cout << s << " "; }
		cout << endl;

		// TODO 13 - dfs path
		cout << endl << "TODO 13" << endl;
		Path path;
		cout << "DFS(C,F): ";
		path = g.dfs_Path("C", "F");
		cout << path.toString() << endl;
		cout << "DFS(I,G): ";
		path = g.dfs_Path("I", "G");
		cout << path.toString() << endl;
		cout << "DFS(G,C): ";
		path = g.dfs_Path("G", "C");
		cout << path.toString() << endl;


		// TODO 14 - bfs
		cout << endl << "TODO 14" << endl;
		list<string> visited_sequence2;
		cout << "BFS(A): ";
		visited_sequence2 = g.bfs("A");
		for (string s : visited_sequence2) { cout << s << " "; }
		cout << endl << "BFS(H): ";
		visited_sequence2 = g.bfs("H");
		for (string s : visited_sequence2) { cout << s << " "; }
		cout << endl << "BFS(F): ";
		visited_sequence2 = g.bfs("F");
		for (string s : visited_sequence2) { cout << s << " "; }
		cout << endl;

		// TODO 15 - bfs Path
		cout << endl << "TODO 15" << endl;
		Path path2;
		cout << "BFS(C,F): ";
		path2 = g.bfs_Path("C", "F");
		cout << path2.toString() << endl;
		cout << "BFS(I,G): ";
		path2 = g.bfs_Path("I", "G");
		cout << path2.toString() << endl;
		cout << "BFS(G,C): ";
		path2 = g.bfs_Path("G", "C");
		cout << path2.toString() << endl;

		// TODO 16 - Dijkstra
		cout << endl << "TODO 16" << endl;
		Path shortestPath;
		cout << "Dijkstra (B,F): ";
		shortestPath = g.dijkstra("B", "F");
		cout << shortestPath.toString() << " (length=" << shortestPath.length() << ")" << endl;
		cout << "Dijkstra (G,D): ";
		shortestPath = g.dijkstra("G", "D");
		cout << shortestPath.toString() << " (length=" << shortestPath.length() << ")" << endl;
		cout << "Dijkstra (H,C): ";
		shortestPath = g.dijkstra("H", "C");
		cout << shortestPath.toString() << " (length=" << shortestPath.length() << ")" << endl;
		cout << "Dijkstra (E,I): ";
		shortestPath = g.dijkstra("E", "I");
		cout << shortestPath.toString() << " (length=" << shortestPath.length() << ")" << endl;

	}
	catch (VertexDuplicateException& e) {
		cout << e.getDescription() << endl;
	}
	catch (VertexMissingException& e) {
		cout << e.getDescription() << endl;
	}
	catch (EdgeDuplicateException& e) {
		cout << e.getDescription() << endl;
	}
	catch (EdgeMissingException& e) {
		cout << e.getDescription() << endl;
	}
	catch (NoPathException& e) {
		cout << e.getDescription() << endl;
	}
	return 0;
}