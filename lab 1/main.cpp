#include "header.h"
int main() {
	SetConsoleOutputCP(1251);
	Point point1(5, 5,"�������"), point2(1, 3, "�����");
	Segment base(point1, point2);
	Button knopka(base,"��������� ������", " ������������� ������������ �� ����");

	cout << "���������� ����� � �� ����: " << endl
		<< "������ �����: "<< point1 << endl
		<< "������ �����: "<< point2 << endl;
	system("pause");
	point1.move_point(3, 2);
	point2.change_xy(3, 4);
	
	cout << "���������� ������ ����� �� 3 �� � � �� 2 �� �, � � ������ ������� ���������� �� 3,4 " << endl;
	cout << "���������� ����� � �� ����: " << endl
		<< "������ �����: "<<point1 << endl
		<< "������ �����: "<<point2 << endl;
	system("pause");
	cout << "������� ������ �� �������������� ����� � ��� ��� ��������:" << endl <<
		base << endl;
	system("pause");

	base.move_segm(5, 2);
	cout << "������� ��� ������� 5 �� � � �� 2 �� �" << endl << base << endl;
	system("pause");

	cout << "���� ������� ������, ������� ����� �������������� ��������, ������ �� ������ � ����" << endl;
	cout << knopka << endl;
	cout << "Ÿ ������� ����� " << knopka.area()<<endl;

	return 0;
}