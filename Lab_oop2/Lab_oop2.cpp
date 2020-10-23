#include <iostream>
#include <conio.h>
#include <iostream>
using namespace std;

class Point {           //класс точка
protected:
	int x, y;
public:
	
	Point() {
		printf("Пустая точка\n");                  //конструктор путой точки
		x = 0;
		y = 0;
	}
	Point(int x, int y) {
		printf("Точка с координатами\n");          //конструктор точки с координатами
		this->x = x;
		this->y = y;
	}
	Point(const Point& p) {
		printf("Точка-копия\n");                   //копирующий конструктор
		x = p.x;
		y = p.y;
	}
	~Point() {
		printf("Удаление точки с координатами %d, %d\n", x, y);                  //диструктор
	}
	void move(int dx,int dy) {                     //метод move
		x = x + dx;
		y = y + dy;
	}
	void reset();
};

void Point::reset() {
	x = 0;
	y = 0;
}

class Line: public Point {
protected:
	Point *p1;
	Point *p2;
	int x2, y2;
public:
	Line() {
		p1 = new Point;
		p2 = new Point;
		printf("Пустая линия\n");
	}
	Line(int x, int y, int x2, int y2) {
		Point p1(x, y);
		Point p2(x2, y2);
		printf("Линия\n");
	}
	Line(const Line& l) {
		printf("Линия-копия\n");
		x = l.x;
		y = l.y;
		x2 = l.x2;
		y2 = l.y2;
	}
	~Line() {
		delete p1;
		delete p2;
		printf("Удаление линии с координатами %d,%d,%d,%d\n", x, y, x2, y2);

	}

};

int main(){
	setlocale(LC_ALL, "Russian");
//{
//	Point p0;
//	Point* p = new Point(5, 10);
//	Point p2(1, 2);
//	Point p3(p2);
//	p->reset();
//	p->move(10, 10);
//	delete p;
//}

{
	Line l0;
	Line l1(5, 10, 15, 20);
	Line l2(l1);
}
//_getch();
return 0;
};