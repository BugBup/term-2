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
	string FIO[3];//там или сделать массив, или так и оставить одной строкой	 ЗАДУМАТЬСЯ НАД ПРОВЕРКАМИ
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
	T* ptr;//указатель на объект
	int counter;//счетчик количества ссылок на объект
};
//Класс умного указателя. Умный указатель должен вести подсчет количества созданный ссылок на объект
template <class T>
class SmartPointer {
	Status<T>* smartPtr;// указатель на объект
public:
	SmartPointer(T* ptr);//конструктор с одним параметром типа T
	SmartPointer() {};
	SmartPointer(const SmartPointer& obj);//конструктор копирования
		~SmartPointer();//деструктор
	SmartPointer& operator=(const SmartPointer& obj); //перегрузка оператора присваивания
		T* operator->() const;//оператор получения доступа к объекту через указатель
		int showCounter() {
		return smartPtr->counter ;
	}
};
template <class T>
SmartPointer<T>::SmartPointer(T* ptr) {
	if (!ptr)
		smartPtr = NULL;//указатель на объект пустой
	else {
		smartPtr = new Status<T>();
		smartPtr->ptr = ptr;//инициализирует объект указателем
		smartPtr->counter = 1;//счетчик «прикрепленных» объектов инициализируем единицей
	}
}
template <class T>
SmartPointer<T>::SmartPointer(const SmartPointer& obj)
	:smartPtr(obj.smartPtr) {
	if (smartPtr) smartPtr->counter++;//увеличение количества ссылок на объект
}
template <class T>
SmartPointer<T>::~SmartPointer() {
	if (smartPtr) {
		smartPtr->counter--;//уменьшение количества ссылок на объект
			if (smartPtr->counter == 0) {//если число ссылок на объект равно нулю, то должен уничтожится объект
					delete smartPtr->ptr;//освобождение памяти,выделенной для объекта
					delete smartPtr;//освобождение памяти, выделенной для указателя
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
		smartPtr->counter--;//уменьшаем счетчик «прикрепленных» объектов для текущего указателя
			if (smartPtr->counter == 0) {//если объектов больше нет, то необходимо освобождить выделенную память
					delete smartPtr->ptr;
				delete smartPtr;
			}
	}
	smartPtr = obj.smartPtr;//присваивание нового адреса указателю
	if (smartPtr) smartPtr->counter++;//увеличить счетчик«прикрепленных» объектов
		return *this;
}








class Publisher :public Employee {
	
public:
	Publisher(string name, string fam, string otch, int age) :Employee(name, fam, otch, age) { }
	void publicate(SmartPointer<Book> book) {
		if (book.showCounter() != 2)
			cout << "Нельзя публиковать книгу" << endl;
		else {
			cout << "Публикация книги" << endl;
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
	T* currentState;//текущее значение объекта класса
	T* prevState;//предыдущее состояние объекта
public:

	Transaction() :prevState(NULL), currentState(new T) {}//конструктор без параметров
	Transaction(const Transaction& obj) : currentState(new T(*(obj.currentState))), prevState(NULL) {}// конструктор копирования
		~Transaction() {
		delete currentState; delete prevState;
	}//деструктор
	Transaction& operator=(const Transaction& obj);//перегрузка оператора присваивания
		void showState(State state);//отображение состояний (предыдущего и текущего) объекта
		int beginTransactions(string content);//метод начала транзакции
		void commit();//метод подтверждения (коммита) транзакции
	void deleteTransactions(); //метод отката транзакции
	T* operator->();//перегрузка оператора доступа к содержимому объекта через указатель
};


template <class T>
Transaction<T>& Transaction<T>::operator=(const Transaction<T>&obj) {
	if (this != &obj) {//проверка на случай obj=obj
		delete currentState;//удаление текущего значения объекта
		currentState = new T(*(obj.currentState));//создание и копирование объекта, используя присваеваемую транзакцию
	}
	return *this;
}

template <class T>
T* Transaction<T>::operator->() {
	return currentState;
}
template <class T>
void Transaction<T>::showState(State state) {//метод отображение состояния объекта
		cout << "Состояние объекта ";
	if (!state) cout << "до начала транзакции " << endl;
	else cout << "после выполнения транзакции " << endl;
	if (prevState) cout << "prevState = " << prevState->Get_cont() << endl;//предыдущее состояние
	else cout << "prevState = NULL" << endl;
	cout << "currentState = " << currentState->Get_cont() << endl << "__________________________________" <<
		endl;//текущее состояние
}

template <class T>
int Transaction<T>::beginTransactions(string content) {// метод начала транзакции
		delete prevState;//удаление предыдущего значения
	prevState = currentState;//сохранение предыдущего состояния как текущего
		currentState = new T(*prevState);//текущее состояние создается!!!!!!!!!!!!!!
		if (!currentState) return 0;//ошибка (необходимо отменить транзакцию)
		currentState->set_cont(content);//изменение состояния объекта

		return 1;//успешное окончание транзакции
}

template <class T>
void Transaction<T>::commit() {
	
	delete prevState;//удаление предыдущего значения
	prevState = NULL;//предыдущего состояния нет
	currentState->Get_book()->set_content(currentState->Get_cont());
}

template <class T>
void Transaction<T>::deleteTransactions() {
	if (prevState != NULL) {
		delete currentState;//удаление текущего значения
		currentState = prevState;//предыдущее становится текущим
		prevState = NULL;//предыдущего состояния нет
	}
}



