#include <iostream>
#include <conio.h>

#include <iostream>
class Point {
protected:
	int x, y;
public:
	
	Point() {
		printf("Point()\n");
		x = 0;
		y = 0;
	}
	Point(int x, int y) {
		printf("Point(int x, int y)\n");
		this->x = x;
		this->y = y;
	}
	Point(const Point& p) {
		printf("Point(const Point &p)\n");
		x = p.x;
		y = p.y;
	}
	~Point() {
		printf("%d, %d\n", x, y);
		printf("~Point()\n");
	}
	void move(int dx,int dy) {
		x = x + dx;
		y = y + dy;
	}
};

//class Line {
//public:
//	int x1, y1, x2, y2;
//	Line(int x1, int y1, int x2, int y2) {
//		Point p1(x1, y1);
//		Point p2(x2, y2);
//		printf("Line(int x1, int y1, int x2, int y2)\n");
//	}
//	Line(const Line& l) {
//		printf("Line(const Line &p)\n");
//		x1 = l.x1;
//		y1 = l.y1;
//		x2 = l.x2;
//		y2 = l.y2;
//	}
//	~Line() {
//		/*printf("%d,%d,%d,%d\n", x1, y1, x2, y2);*/
//		printf("~Line\n");
//	}
//
//};

int main(){
	Point* p = new Point(5, 10);
	Point p2(1, 2);
	Point p3(p2);
	p->move(10, 10);
	delete p;

//{
//	Line l1(5, 10, 15, 20);
//	Line l2(l1);
//}
//_getch();
return 0;
};