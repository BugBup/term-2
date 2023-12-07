#include "header.h"

void Teacher:: add_stud(Student stud) {
	this->stud.push(stud);
}

void Teacher::pop_stud() {
	if (!stud.empty()) {
		Student temp = this->stud.top();
		cout << "����� ������� ��������� �������� " << temp.get_surname() << " � ������� " << temp.get_number() <<
			" ?" << endl;
		int	mark;
		cin >> mark;
		ofstream file;
		file.open("Mark.txt", ofstream::app);
		file << temp.get_surname() << '\t' << temp.get_number() << '\t' << mark;
		file.close();
		stud.pop();
	}
	else {
		cout << "������ �� �������� ��� �����" << endl;
		system("pause");
	}
	
}
void Teacher::amount_stud() {
	if (this->stud.empty())
		cout << "������ �� �������� � ������������� ��� �����" << endl;
	else
	cout << "������ �� �������� � ������������� " << this->stud.size() << " ����� ���������" << endl;
	system("pause");
}
void menu() {
	cout << "1 - �������� �������� � ������� �������" << endl <<
		"2 - ������� ���� ���� ������" << endl <<
		"3 - ������� ��������� ������" << endl <<
		"4 - ���������� ��������� �� ��������" << endl <<
		"5 - ���������� ��������� � �������" << endl <<
		"6 - �����" << endl;
}