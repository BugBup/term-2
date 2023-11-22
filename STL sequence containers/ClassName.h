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
class Subject {//из них будет array
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
class Teacher:public Human { //список кстати
	
public:
	Teacher(string fam, string name, string otch) {
		this->FIO[0] = fam; this->FIO[1] = name; this->FIO[2] = otch;
	};
	friend ostream& operator<<(ostream& s, Teacher obj);
};
class Student:public Human {// из них будет vector 
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

//меню выбора(выбрать студента или добавить) 1 шаг
// в выбрать выведетс€ список, по которому можно или провести поиск, либо отсортировать, либо написать номер студента(поиск,сортировка тут) 
// у студента можно будет посмотреть его предметы(за ними будет написаны преподаватели) 
// также можно будет думаю редактировать студента, по типу курс, им€ фамили€, факультет и тд 
//самособой можно удалить студента(только когда его выбрал, наверно) 
// ƒЋя –јЅќ“џ
//создать сначала в классах все функции(гетеры и сетеры)
//создать в мэйне начальное меню, также сами контейнеры
// дл€ контейнеров создать сортировки и поиск, только дл€ которых надо
// создать полностью меню
// красиво оформить
// ѕ–ќ¬≈–я“№ ѕќ—Ћ≈  ј∆ƒќ√ќ ѕќƒѕ”Ќ “ј –јЅќ“ќ—ѕќ—ќЅЌќ—“№ ѕ–ќ√–јћћџ
// 
// 
//  
