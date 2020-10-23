#include <iostream>
#include <conio.h>
#include <iostream>
using namespace std;

class Point {           //класс точка
protected:
	int x, y;
public:
	
	Point() {
		printf("Пустая точка\n");                  //конструктор точки без параметров
		x = 0;
		y = 0;
	}
	Point(int x, int y) {
		printf("Точка с координатами\n");          //конструктор точки с параметрами
		this->x = x;
		this->y = y;
	}
	Point(const Point &p) {
		printf("Точка-копия\n");                   //копирующий конструктор
		x = p.x;
		y = p.y;
	}
	~Point() {
		printf("Удаление точки с координатами %d, %d\n", x, y);                  //диструктор точки
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

class ColorPoint : public Point {           //класс цветная точка
protected:
	int color;
public:

	ColorPoint() {
		printf("Пустая цветная точка\n");                  //конструктор точки без параметров
		x = 0;
		y = 0;
		color = 0;
	}
	ColorPoint(int x, int y, int color):Point(x,y) {
		printf("Цветная точка с координатами\n");          //конструктор точки с параметрами
		this->x = x;
		this->y = y;
		this->color = color;
	}
	ColorPoint(const ColorPoint& c) {
		printf("Цветная точка-копия\n");                   //копирующий конструктор
		x = c.x;
		y = c.y;
		color = c.color;

	}
	~ColorPoint() {
		printf("Удаление цветной точки с координатами %d, %d, %d\n", x, y, color);                  //диструктор цветной точки
	}
};

class Line/*: public Point */{                                //класс линия
protected:
	Point *p1;
	Point *p2;
	int x, y, x2, y2;
public:
	Line() {
		p1 = new Point;                                       //конструктор линии без параметров
		p2 = new Point;
		printf("Пустая линия\n");
	}
	Line(int x, int y, int x2, int y2) {                       //конструктор линии с параметрами
		p1 = new Point(x, y);
		p2 = new Point(x2, y2);
		/*Point p1(x, y);
		Point p2(x2, y2);*/
		printf("Линия\n");
	}
	Line(const Line &l) {                                     //конструктор линии-копии
		printf("Линия-копия\n");
		p1 = new Point(*(l.p1));
		p2 = new Point(*(l.p2));
	}
	~Line() {                                                  //диструктор линии
		delete p1;
		delete p2;
		printf("Удаление линии с координатами %d,%d,%d,%d\n", x, y, x2, y2);

	}

};

int main(){
	setlocale(LC_ALL, "Russian");
{
	{
		Point p1;
		Point p2(1, 2);                               //статическое создание точек
		Point p3(p2);
	}
	_getch();
	printf("\n\n");
	{
		Point* p0 = new Point();
		Point* p01 = new Point(5, 10);
		Point* p02 = new Point(*p01);                  //динамическое создание точек
		p0->reset();
		p0->move(10, 10);
		delete p0;
		delete p01;
		delete p02;
	}
}
_getch();
printf("\n\n");
{
	{
		ColorPoint cp1;
		ColorPoint cp2(1, 2, 30);                               //статическое создание цветных точек
		ColorPoint cp3(cp2);
	}
	_getch();
	printf("\n\n");
	{
		Point *cp = new ColorPoint(1,2,5);                      //помещение объекта в переменную другого типа
		delete cp;

		ColorPoint* cp0 = new ColorPoint();
		ColorPoint* cp01 = new ColorPoint(5, 10, 45);
		ColorPoint* cp02 = new ColorPoint(*cp01);                  //динамическое создание цветных точек

		delete cp0;
		delete cp01;
		delete cp02;
	}
}
_getch();
printf("\n\n");
{
	{
		Line l1;                                                  //статическое создание линий
		Line l2(1, 2, 3, 4);
		Line l3(l2);
	}
	_getch();
	printf("\n\n");
	{
		Line* l0 = new Line();                                     //динамическое создание линий
		delete l0;
		Line* l01 = new Line(5, 10, 15, 20);
		Line* l02 = new Line(*l01);
		delete l01;
		delete l02;
	}
}
_getch();
return 0;
};