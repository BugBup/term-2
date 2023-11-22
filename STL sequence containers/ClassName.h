#include <iostream>
#include <Windows.h>
#include <string>
#include <search.h>
#include <stdlib.h>
#include <iomanip>
#include <fstream>
#include <vector>
#include<array>
#include<list>
#include <algorithm>

using namespace std;
class Subject {//�� ��� ����� array
protected:
	string name;
public:
	Subject(string name) { this->name = name; } 
	void set_name(string name) { this->name = name; };
	string get_name() { return this->name; };
	friend ostream& operator<<(ostream& s, Subject obj);
};

class Human {
protected:
	string FIO[3];
public:
	string get_fam() { return this->FIO[0]; };
	void set_fam(string fam) {
		this->FIO[0] = fam;
	}

};
class Teacher:public Human { //������ ������
	
public:
	Teacher(string fam, string name, string otch) {
		this->FIO[0] = fam; this->FIO[1] = name; this->FIO[2] = otch;
	};
	friend ostream& operator<<(ostream& s, Teacher obj);
};
class Student:public Human {// �� ��� ����� vector 
	int group;
public:
	Student(string fam, string name, string otch, int group) { this->FIO[1] = name; this->FIO[0] = fam; this->FIO[2] = otch; this->group = group; };
	void set_group(int group) { this->group = group; };
	int get_group() { return this->group; };
	void print() { cout << FIO[0] << " " << FIO[1] << " " << FIO[2] << " " << " " << group << endl; };
	friend bool	operator <(const Student& o1, const Student& o2);
	friend bool operator>(const Student& o1, const Student& o2);
	friend bool operator==(const Student& o1, const Student& o2);
	friend bool comp( Student o1, Student o2) ;
	friend istream& operator<<(istream& s, Student obj);
};
void menu1();
void menu2();
void menu3();
void read_stud(vector<Student> students);

//���� ������(������� �������� ��� ��������) 1 ���
// � ������� ��������� ������, �� �������� ����� ��� �������� �����, ���� �������������, ���� �������� ����� ��������(�����,���������� ���) 
// � �������� ����� ����� ���������� ��� ��������(�� ���� ����� �������� �������������) 
// ����� ����� ����� ����� ������������� ��������, �� ���� ����, ��� �������, ��������� � �� 
//��������� ����� ������� ��������(������ ����� ��� ������, �������) 
// ��� ������
//������� ������� � ������� ��� �������(������ � ������)
//������� � ����� ��������� ����, ����� ���� ����������
// ��� ����������� ������� ���������� � �����, ������ ��� ������� ����
// ������� ��������� ����
// ������� ��������
// ��������� ����� ������� ��������� ����������������� ���������
// 
// 
//  
