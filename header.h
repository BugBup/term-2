	#pragma once
#include <iostream>
#include <cmath>
#include <Windows.h>
#include <fstream>
using namespace std;


enum State { begin, middle };


class Printed_edit {
protected:
	string title;
	string theme;
public:
	Printed_edit(string title, string theme) { this->theme = theme; this->title = title; };
	Printed_edit() {};
	string Get_title();
	string Get_theme();
};

class Book:public Printed_edit {
protected:
	string content;
public:
	Book(string title, string theme, string content) :Printed_edit(title, theme) { this->content = content; };
	Book() {};
	string Get_content() { return content; };
	string Get_title() { return title; }
	string Get_theme() { return theme; }
	void set_title(string title) { this->title = title; }
	void set_theme(string theme) { this->theme = theme; }
	void set_content(string content) { this->content = content; }
};

string Printed_edit::Get_title() {
	return (this->title);
}

string Printed_edit::Get_theme() {
	return theme;
}

/*class Newspaper :public Printed_edit {
	int date[3];
public:
	int Get_day() { return date[0]; };
	int Get_month() { return date[1]; };
	int Get_year() { return date[2]; };
};*/

class Employee {
	string FIO[3];//��� ��� ������� ������, ��� ��� � �������� ����� �������	 ���������� ��� ����������
	int age;
public:
	Employee() {}
	Employee(string name, string fam, string otch, int age) { this->FIO[0] = name; this->FIO[1] = fam; this->FIO[2] = otch; this->age = age; };
	string Get_name() {return FIO[0];};
	string Get_fam() { return FIO[1]; };
	string Get_otch() { return FIO[2]; };
	int Get_age() { return age; };
	void set_emp(string name, string fam, string otch, int age) { FIO[0] = name; FIO[1] = fam; FIO[2] = otch; this->age = age; };
};










template <class T>
struct Status {
	T* ptr;//��������� �� ������
	int counter;//������� ���������� ������ �� ������
};
//����� ������ ���������. ����� ��������� ������ ����� ������� ���������� ��������� ������ �� ������
template <class T>
class SmartPointer {
	Status<T>* smartPtr;// ��������� �� ������
public:
	SmartPointer(T* ptr);//����������� � ����� ���������� ���� T
	SmartPointer() {};
	SmartPointer(const SmartPointer& obj);//����������� �����������
		~SmartPointer();//����������
	SmartPointer& operator=(const SmartPointer& obj); //���������� ��������� ������������
		T* operator->() const;//�������� ��������� ������� � ������� ����� ���������
		int showCounter() {
		return smartPtr->counter ;
	}
};
template <class T>
SmartPointer<T>::SmartPointer(T* ptr) {
	if (!ptr)
		smartPtr = NULL;//��������� �� ������ ������
	else {
		smartPtr = new Status<T>();
		smartPtr->ptr = ptr;//�������������� ������ ����������
		smartPtr->counter = 1;//������� ��������������� �������� �������������� ��������
	}
}
template <class T>
SmartPointer<T>::SmartPointer(const SmartPointer& obj)
	:smartPtr(obj.smartPtr) {
	if (smartPtr) smartPtr->counter++;//���������� ���������� ������ �� ������
}
template <class T>
SmartPointer<T>::~SmartPointer() {
	if (smartPtr) {
		smartPtr->counter--;//���������� ���������� ������ �� ������
			if (smartPtr->counter == 0) {//���� ����� ������ �� ������ ����� ����, �� ������ ����������� ������
					delete smartPtr->ptr;//������������ ������,���������� ��� �������
					delete smartPtr;//������������ ������, ���������� ��� ���������
			}
	}
}
template <class T>
T* SmartPointer<T>::operator->() const {
	if (smartPtr) return smartPtr->ptr;
	else return NULL;
}
template <class T>
SmartPointer<T>& SmartPointer<T>::operator=(const SmartPointer& obj) {
	if (smartPtr) {
		smartPtr->counter--;//��������� ������� ��������������� �������� ��� �������� ���������
			if (smartPtr->counter == 0) {//���� �������� ������ ���, �� ���������� ����������� ���������� ������
					delete smartPtr->ptr;
				delete smartPtr;
			}
	}
	smartPtr = obj.smartPtr;//������������ ������ ������ ���������
	if (smartPtr) smartPtr->counter++;//��������� ��������������������� ��������
		return *this;
}








class Publisher :public Employee {
	
public:
	Publisher(string name, string fam, string otch, int age) :Employee(name, fam, otch, age) { }
	void publicate(SmartPointer<Book> book) {
		if (book.showCounter() != 2)
			cout << "������ ����������� �����" << endl;
		else {
			cout << "���������� �����" << endl;
			book.~SmartPointer();
		}
	}
	
};

class Author :public Employee {
protected:
	SmartPointer<Book> book;
	Book books;
	string cont;
public:
	string Get_cont() { return cont; }
	void set_cont(string content) { this->cont = content; }
	Author(string name, string fam, string otch, int age) :Employee(name, fam, otch, age) { };
	Author() {};
	void set_book(SmartPointer<Book> book) { this->book = book; }
	void set_books(SmartPointer<Book> books) { this->books.set_content(books->Get_content()); this->books.set_theme(books->Get_theme());
	this->books.set_title(books->Get_title()); }
	SmartPointer<Book> Get_book() { return this->book; };
	Book Get_books() { return this->books; }
};




template <class T>
class Transaction {
	T* currentState;//������� �������� ������� ������
	T* prevState;//���������� ��������� �������
public:

	Transaction() :prevState(NULL), currentState(new T) {}//����������� ��� ����������
	Transaction(const Transaction& obj) : currentState(new T(*(obj.currentState))), prevState(NULL) {}// ����������� �����������
		~Transaction() {
		delete currentState; delete prevState;
	}//����������
	Transaction& operator=(const Transaction& obj);//���������� ��������� ������������
		void showState(State state);//����������� ��������� (����������� � ��������) �������
		int beginTransactions(string content);//����� ������ ����������
		void commit();//����� ������������� (�������) ����������
	void deleteTransactions(); //����� ������ ����������
	T* operator->();//���������� ��������� ������� � ����������� ������� ����� ���������
};


template <class T>
Transaction<T>& Transaction<T>::operator=(const Transaction<T>&obj) {
	if (this != &obj) {//�������� �� ������ obj=obj
		delete currentState;//�������� �������� �������� �������
		currentState = new T(*(obj.currentState));//�������� � ����������� �������, ��������� ������������� ����������
	}
	return *this;
}

template <class T>
T* Transaction<T>::operator->() {
	return currentState;
}
template <class T>
void Transaction<T>::showState(State state) {//����� ����������� ��������� �������
		cout << "��������� ������� ";
	if (!state) cout << "�� ������ ���������� " << endl;
	else cout << "����� ���������� ���������� " << endl;
	if (prevState) cout << "prevState = " << prevState->Get_cont() << endl;//���������� ���������
	else cout << "prevState = NULL" << endl;
	cout << "currentState = " << currentState->Get_cont() << endl << "__________________________________" <<
		endl;//������� ���������
}

template <class T>
int Transaction<T>::beginTransactions(string content) {// ����� ������ ����������
		delete prevState;//�������� ����������� ��������
	prevState = currentState;//���������� ����������� ��������� ��� ��������
		currentState = new T(*prevState);//������� ��������� ���������!!!!!!!!!!!!!!
		if (!currentState) return 0;//������ (���������� �������� ����������)
		currentState->set_cont(content);//��������� ��������� �������

		return 1;//�������� ��������� ����������
}

template <class T>
void Transaction<T>::commit() {
	
	delete prevState;//�������� ����������� ��������
	prevState = NULL;//����������� ��������� ���
	currentState->Get_book()->set_content(currentState->Get_cont());
}

template <class T>
void Transaction<T>::deleteTransactions() {
	if (prevState != NULL) {
		delete currentState;//�������� �������� ��������
		currentState = prevState;//���������� ���������� �������
		prevState = NULL;//����������� ��������� ���
	}
}



