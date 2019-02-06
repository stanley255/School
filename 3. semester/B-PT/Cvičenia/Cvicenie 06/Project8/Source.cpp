#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>

// TODO 1:
// Naprogramujte triedu 'Point' reprezentujucu bod v rovine.
// Atributy triedy:
//  * x a y suradnice (typ int)
// Metody triedy:
//  * default konstruktor s implicitnymi hodnotami parametrov
//  * destruktor (nebude nic vykonavat, len vypise "Destruktor 'Point' zavolany.")
//  * metody na nastavenie (z angl. setters) a ziskanie suradnic (z angl. getters)
class Point {
private:
	double x, y;
public:
	//Point(double x = 0.0, double y = 0.0) {
	//	this->x = x;
	//	this->y = y;
	//}
	Point(double _x = 0, double _y = 0) :
		x(_x), y(_y) 
	{}
	~Point() {
		std::cout << "Destruktor 'Point' zavolany." << std::endl;
	}
	void set_x(double x) {
		this->x = x;
	}
	void set_y(double y) {
		this->y = y;
	}
	double get_x() {
		return this->x;
	}
	double get_y() {
		return this->y;
	}
	void print() {
		std::cout << "X: " << this->x << std::endl;
		std::cout << "Y: " << this->y << std::endl;
	}
};
// TODO 2:
// Naprogramujte triedu 'Line' reprezentujucu usecku v rovine definovanu pomocou 
// zaciatocneho a koncoveho bodu (typ 'Point')
// Atributy triedy:
//  * zaciatocny bod usecky 'startPoint'
//  * koncovy bod usecky 'endPoint'
// Metody triedy:
//  * default konstruktor s implicitnymi hodnotami vsetkych 4 suradnic
//  * parametricky konstruktor na zostrojenie usecky zo zaciatocneho a koncoveho bodu
//  * destruktor (nebude nic vykonavat, len vypise "Destruktor 'Line' zavolany.")
//  * metody na nastavenie a ziskanie zaciatocneho/koncoveho bodu
//  * metodu na vratenie dlzky usecky

class Line {
private:
	Point startPoint;
	Point endPoint;
public:
	Line(double startPointX = 0.0, double startPointY = 0.0, double endPointX = 0.0, double endPointY = 0.0) {
		this->startPoint = Point(startPointX, startPointY);
		this->endPoint = Point(endPointX, endPointY);
	}
	Line(Point startPoint, Point endPoint) {
		this->startPoint = startPoint;
		this->endPoint = endPoint;
	}
	~Line() {
		std::cout << "Destruktor 'Line' zavolany."<<std::endl;
	}
	//  * metody na nastavenie a ziskanie zaciatocneho/koncoveho bodu
	void set_startPoint(double x, double y) {
		this->startPoint.set_x(x);
		this->startPoint.set_y(y);
	}
	void set_endPoint(double x, double y) {
		this->endPoint.set_x(x);
		this->endPoint.set_y(y);
	}
	Point* get_startPoint() {
		return &(this->startPoint);
	}
	Point* get_endPoint() {
		return &(this->startPoint);
	}
	//  * metodu na vratenie dlzky usecky
	/*double getLength() {
		return sqrt(pow(this->startPoint.get_x - this->endPoint.get_x,2)+(this->startPoint.get_y - this->endPoint.get_y,2));
	}*/

	/*void print() {
		std::cout << "StartPoint(x): " << this->startPoint.get_x;
		std::cout << "StartPoint(y): " << this->startPoint.get_y;
		std::cout << "EndPoint(x):   " << this->endPoint.get_x;
		std::cout << "EndPoint(y):   " << this->endPoint.get_y;
	}*/
};

int main()
{
	// TODO 3: otestujte pouzitie tried 'Point' a 'Line'
	Point* point1 = new Point{};
	point1->print();
	delete point1;

	Point point2;
	point2.set_x(1.5);
	point2.set_y(14.9);
	point2.print();

	std::cout << std::endl;

	Line l1{};
	Point* sp = l1.get_startPoint;
	std::cout << sp->get_x;
	//l1.print();
	return 0;
}