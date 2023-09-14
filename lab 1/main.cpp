#include "header.h"
int main() {
	SetConsoleOutputCP(1251);
	Point point1(5, 5,"Красный"), point2(1, 3, "Синий");
	Segment base(point1, point2);
	Button knopka(base,"нерабочая ссылка", " множественное наследование от Вани");

	cout << "Координаты точек и их цвет: " << endl
		<< "Первая точка: "<< point1 << endl
		<< "Вторая точка: "<< point2 << endl;
	system("pause");
	point1.move_point(3, 2);
	point2.change_xy(3, 4);
	
	cout << "Передвинул первую точку на 3 по х и на 2 по у, а у второй поменял координаты на 3,4 " << endl;
	cout << "Координаты точек и их цвет: " << endl
		<< "Первая точка: "<<point1 << endl
		<< "Вторая точка: "<<point2 << endl;
	system("pause");
	cout << "Отрезок создан из первоначальных точек и вот его значения:" << endl <<
		base << endl;
	system("pause");

	base.move_segm(5, 2);
	cout << "Отрезок был сдвинут 5 по х и на 2 по у" << endl << base << endl;
	system("pause");

	cout << "Была создана кнопка, которая имеет характеристики квадрата, ссылку на объект и тему" << endl;
	cout << knopka << endl;
	cout << "Её площадь равна " << knopka.area()<<endl;

	return 0;
}