#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
#include <search.h>
#include <stdlib.h>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include<map>
#include<set>
#include <unordered_set>
#include <list>
using namespace std;
class Pair {
	int number;
	string name;
public:
	Pair(int number, string name) {
		this->number = number;
		this->name = name;
	}
	friend ostream& operator<<(ostream& s, Pair obj);
	friend bool operator<(Pair obj1, Pair obj2);
};
class Student {
	string name;
public:
	Student() {};
	Student(string name) :name(name) {};
	friend void add_stud(map<int,Student> &obj, unordered_set<int>& ob, multiset<Pair> &o);
	friend void print_stud(map<int, Student> obj, unordered_set<int> keys);
	friend void print_stud_sort(map<int, Student> obj, multiset<Pair> o);
	friend void del_stud(map<int, Student>& obj, unordered_set<int>& ob, multiset<Pair>& o);
	friend void find_stud(map<int, Student>obj);
	friend void edit_stud(map<int, Student>& obj, multiset<Pair>& o);
	friend bool operator<(Student obj1, Student obj2);
	friend bool operator>(Student obj1, Student obj2);
	friend bool operator==(Student obj1, Student obj2);
	friend ostream& operator<<(ostream& s, Student obj);
};

void menu1();