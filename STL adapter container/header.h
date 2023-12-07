#pragma once
#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <fstream>
#include <Windows.h>
using namespace std;
void menu();
class Student {
	int number;
	string surname;
public:
	Student() {};
	Student(int number, string surname) :number(number), surname(surname) {};
	void set_number(int number) { this->number = number; };
	void set_surname(string surname) { this->surname = surname; };
	int get_number() { return number; };
	string get_surname() { return surname; };
};
class Teacher {
	string surname;
	stack<Student> stud;
public:
	Teacher() {};
	Teacher(string surname) :surname(surname) {};
	void add_stud(Student stud);
	void pop_stud();
	void amount_stud();
	void set_surname(string surname) { this->surname = surname; };
	string get_surname() { return surname; };
};
