#pragma once
#include <iostream>
#include <cmath>
#include <Windows.h>
using namespace std;
class Point {
protected:
	int x;
	int y;
	string color;
public:
	int Get_x() { return this->x; }
	int Get_y() { return this->y; }
	string Get_color() { return this->color; }
	Point() {};
	Point(int x, int y, string color) { this->x = x; this->y = y; this->color = color; }
	void move_point(int x, int y) { this->x += x; this->y += y; };
	void change_xy(int x, int y) { this->x = x; this->y = y;  }
	void change_color(string color) { this->color = color; }
};
class Segment {
protected:
	Point point[2];
public:
	Segment() {  };
	Segment(Point point1, Point point2) { this->point[0] = point1; this->point[1] = point2; }
	Segment(const Segment& copy) { for (int i = 0; i < 2; i++) point[i] = copy.point[i]; };
	void change_segm(int x1, int y1,string color1, int x2, int y2,string color2);
	void move_segm(int x, int y); // x за движение по оси X , y за движение по оси Y
	Point Get_First() { return point[0]; };
	Point Get_Second() { return point[1]; }
	
};
void Segment::move_segm(int x, int y) {
	this->change_segm(point[0].Get_x() + x, point[0].Get_y() + y, point[0].Get_color(),
		point[1].Get_x() + x, point[1].Get_y() + y, point[1].Get_color());
}

class Square{
	Segment square[4];
public:
	Square() {};
	Square(Segment base);
	double area(); 
	Segment Get_segm(int i) { return square[i]; }
};

double Square:: area() {
	return (pow((square[0].Get_First().Get_x() - square[0].Get_Second().Get_x()),2 ) +
		    pow((square[0].Get_First().Get_y() - square[0].Get_Second().Get_y()),2 ));
}


class Clickable {
protected:
	string link;
	string topic;
public:
	Clickable(string link, string topic) {
		this->link = link;
		this->topic = topic;
	}
	string Get_link() { return link; }
	string Get_topic() { return topic; }
	void set_link(string link) { this->link = link; }
	void set_topic(string topic) { this->topic = topic; }


};

Square::Square(const Segment base) {
	square[0] = base;//присвоили значения для первого отрезка

	square[1].change_segm(square[0].Get_First().Get_x(),//x1 знаем 
						  square[0].Get_First().Get_y(),//y1 знаем 
						  square[0].Get_First().Get_color(),
						  square[0].Get_First().Get_x() + (square[0].Get_First().Get_y() - square[0].Get_Second().Get_y()),//+delta y
						  square[0].Get_First().Get_y() - (square[0].Get_First().Get_x() - square[0].Get_Second().Get_x()),//-delta x
						  square[0].Get_Second().Get_color());
	


	square[2].change_segm(square[0].Get_Second().Get_x(),//x2 знаем 
						  square[0].Get_Second().Get_y(),//y2 знаем 
						  square[0].Get_Second().Get_color(),
						  square[0].Get_Second().Get_x() + (square[0].Get_First().Get_y() - square[0].Get_Second().Get_y()),//+delta y
						  square[0].Get_Second().Get_y() - (square[0].Get_First().Get_x() - square[0].Get_Second().Get_x()),//-delta x)
						  square[0].Get_First().Get_color());

	square[3].change_segm(square[1].Get_Second().Get_x(), square[1].Get_Second().Get_y(),square[1].Get_Second().Get_color(),//переписали координаты со второго отрезка новые
						  square[2].Get_Second().Get_x(), square[2].Get_Second().Get_y(),square[2].Get_Second().Get_color());// переписаои координаты с третьего отрезка новые



};

class Button :public Square, public Clickable {
public :
	Button(Segment base, string link, string topic); 
	
};
Button::Button(Segment base, string link, string topic) : Square(base), Clickable(link, topic) {};

// можно добавить кнопку, а кроме этого как базовый класс стоит добавить объект или что-то около того


void Segment::change_segm(int x1, int y1, string color1, int x2, int y2,string color2) {
	point[0].change_xy(x1, y1);
	point[0].change_color(color1);
	point[1].change_xy(x2, y2);
	point[1].change_color(color2);
}

ostream& operator<<(ostream& out, Point& point) {
	return out << "(" << point.Get_x() << "," << point.Get_y() << ") цвет - " << point.Get_color();
}
 ostream& operator<<(ostream& out, Segment& segment) {
	 return out << "Первая точка отрезка :(" << segment.Get_First().Get_x() << "," 
				 << segment.Get_First().Get_y() << "), цвет - " << segment.Get_First().Get_color() << endl

				 <<"Вторая точка отрезка :(" << segment.Get_Second().Get_x() << ","
				<< segment.Get_Second().Get_y() << "), цвет - " << segment.Get_Second().Get_color();
} 
 ostream& operator <<(ostream& out, Button& button) {
	return out << "Первый отрезок: " << button.Get_segm(0).Get_First().Get_color() << " ("
		 << button.Get_segm(0).Get_First().Get_x() << "," << button.Get_segm(0).Get_First().Get_y() << ") ("
		 << button.Get_segm(0).Get_Second().Get_x() << "," << button.Get_segm(0).Get_Second().Get_y() << ") "
		 << button.Get_segm(0).Get_Second().Get_color() << endl
		 << "Второй отрезок: " << button.Get_segm(1).Get_First().Get_color() << " ("
		 << button.Get_segm(1).Get_First().Get_x() << "," << button.Get_segm(1).Get_First().Get_y() << ") ("
		 << button.Get_segm(1).Get_Second().Get_x() << "," << button.Get_segm(1).Get_Second().Get_y() << ") "
		 << button.Get_segm(1).Get_Second().Get_color() << endl
		 << "Третий отрезок: " << button.Get_segm(2).Get_First().Get_color() << " ("
		 << button.Get_segm(2).Get_First().Get_x() << "," << button.Get_segm(2).Get_First().Get_y() << ") ("
		 << button.Get_segm(2).Get_Second().Get_x() << "," << button.Get_segm(2).Get_Second().Get_y() << ") "
		 << button.Get_segm(2).Get_Second().Get_color() << endl
		 << "Четвёртый отрезок: " << button.Get_segm(3).Get_First().Get_color() << " ("
		 << button.Get_segm(3).Get_First().Get_x() << "," << button.Get_segm(3).Get_First().Get_y() << ") ("
		 << button.Get_segm(3).Get_Second().Get_x() << "," << button.Get_segm(3).Get_Second().Get_y() << ") "
		 << button.Get_segm(3).Get_Second().Get_color() << endl <<
		 "Тема: " << button.Get_topic() << " , ссылка: " << button.Get_link();
	 
}
