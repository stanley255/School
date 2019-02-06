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
		list<Vertex>::iterator it = find_if(this->vertices.begin(), this->vertices.end(), [&](Vertex& v) {
			return v.name == vertexName;
		});
		if (it != this->vertices.end()) {
			return *it;
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
		Vertex& start_v = this->getVertex(vertexName1); // moze hodit vynimku 'VertexMissing'
		Vertex& end_v   = this->getVertex(vertexName2); // moze hodit vynimku 'VertexMissing'
		for (EdgeTo& e : start_v.edges) {
			if (e.endVertex == &end_v)
				return e;
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
			Vertex& v = this->getVertex(vertexName);
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
			EdgeTo& e = this->getEdge(vertexName1, vertexName2);
			return true;
		}
		catch(VertexMissingException& vertexExcept){
			return false;
		}
		catch (EdgeMissingException& edgeExcept) {
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
		if (this->containsVertex(vertexName)) {
			throw VertexDuplicateException(vertexName);
		}
		else {
			this->vertices.push_back(Vertex(vertexName));
		}
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
		Vertex& start_v = this->getVertex(vertexName1);
		Vertex& end_v   = this->getVertex(vertexName2);
		if (this->containsEdge(start_v.name, end_v.name)) {
			throw EdgeDuplicateException(start_v.name, end_v.name);
		}
		start_v.edges.push_back(EdgeTo(&end_v, length));
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
		string str{};
		for (const Vertex& v : this->vertices) {
			str += v.name + ": ";
			for (EdgeTo e : v.edges) {
				str += "->" + e.endVertex->name + "(" + to_string(e.length) + ")";
			}
			str += "\n";
		}
		return str;
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
		Vertex& v = this->getVertex(vertexName);
		for (Vertex& v : this->vertices) {
			for (auto it = v.edges.begin(); it != v.edges.end(); ) {
				if ((*it).endVertex->name == vertexName) {
					it = v.edges.erase(it);
					continue;
				}
				it++;
			}
		}
		this->vertices.remove(v);
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
		Vertex& v1 = this->getVertex(vertexName1);
		Vertex& v2 = this->getVertex(vertexName2);
		EdgeTo& e  = this->getEdge(vertexName1, vertexName2);
		v1.edges.remove(e);
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
		return{};
	}

	// TODO 9
	// Funkcia, ktora vrati vektor nazvov vsetkych vrcholov v grafe.
	//
	// Vyhadzuje vynimky: ziadne
	//
	vector<string> getVertexNames() {
		return{};
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
		return -1;
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
		return -1;
	}

	// TODO 12
	// Funkcia vrati postupnost navstivenych vrcholov pocas
	// prechodu grafom do hlbky z vrcholu 'startVertexName'. 
	// Ak sa vrchol 'startVertexName' v grafe nenachadza, 
	// vyhodi sa vynimka typu 'VertexMissingException'.
	//
	// Vyhadzuje vynimky:
	//		* VertexMissingException
	//
	list<string> dfs(string startVertexName) {
		return{};
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
		return Path();
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
		return{};
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
		return Path();
	}


	// TODO 16
	// Funkcia najde najkratsiu cestu z 'startVertexName' do 'endVertexName'.
	// Ak 'startVertexName' alebo 'endVertexName' neexistuju, vyhodi sa vynimka
	// typu 'VertexMissingException'. Ak neexistuje medzi nimi cesta, vyhodi sa
	// 'NoPathException'.
	Path dijkstra(string startVertexName, string endVertexName) {
		return Path();
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

	}
};

int main() {
	GraphAsAdjacencyList g;
	vector<string> graph_vertices{"A","B","C","D","E","F","G","H","I"};
	vector<tuple<string, string, int>> graph_edges{
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
	try {
		for (string& v : graph_vertices) {
			g.addVertex(v);
		}
		for (auto t : graph_edges) {
			g.addEdge(get<0>(t),get<1>(t),get<2>(t));
		}
		//g.removeEdge("B", "A");
		//g.removeEdge("X", "A");
		g.removeVertex("A");
		std::cout << g.toString() << std::endl;
		//g.removeVertex("X");
	}
	catch(VertexDuplicateException& e){
		std::cout << e.getDescription() << std::endl;
	}
	catch (EdgeDuplicateException& e) {
		std::cout << e.getDescription() << std::endl;
	}
	catch (EdgeMissingException& e) {
		std::cout << e.getDescription() << std::endl;
	}
	catch (VertexMissingException& e) {
		std::cout << e.getDescription() << std::endl;
	}

	return 0;
}