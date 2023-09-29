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
	string FIO[3];//òàì èëè ñäåëàòü ìàññèâ, èëè òàê è îñòàâèòü îäíîé ñòðîêîé	 ÇÀÄÓÌÀÒÜÑß ÍÀÄ ÏÐÎÂÅÐÊÀÌÈ
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
	T* ptr;//óêàçàòåëü íà îáúåêò
	int counter;//ñ÷åò÷èê êîëè÷åñòâà ññûëîê íà îáúåêò
};
//Êëàññ óìíîãî óêàçàòåëÿ. Óìíûé óêàçàòåëü äîëæåí âåñòè ïîäñ÷åò êîëè÷åñòâà ñîçäàííûé ññûëîê íà îáúåêò
template <class T>
class SmartPointer {
	Status<T>* smartPtr;// óêàçàòåëü íà îáúåêò
public:
	SmartPointer(T* ptr);//êîíñòðóêòîð ñ îäíèì ïàðàìåòðîì òèïà T
	SmartPointer() {};
	SmartPointer(const SmartPointer& obj);//êîíñòðóêòîð êîïèðîâàíèÿ
		~SmartPointer();//äåñòðóêòîð
	SmartPointer& operator=(const SmartPointer& obj); //ïåðåãðóçêà îïåðàòîðà ïðèñâàèâàíèÿ
		T* operator->() const;//îïåðàòîð ïîëó÷åíèÿ äîñòóïà ê îáúåêòó ÷åðåç óêàçàòåëü
		int showCounter() {
		return smartPtr->counter ;
	}
};
template <class T>
SmartPointer<T>::SmartPointer(T* ptr) {
	if (!ptr)
		smartPtr = NULL;//óêàçàòåëü íà îáúåêò ïóñòîé
	else {
		smartPtr = new Status<T>();
		smartPtr->ptr = ptr;//èíèöèàëèçèðóåò îáúåêò óêàçàòåëåì
		smartPtr->counter = 1;//ñ÷åò÷èê «ïðèêðåïëåííûõ» îáúåêòîâ èíèöèàëèçèðóåì åäèíèöåé
	}
}
template <class T>
SmartPointer<T>::SmartPointer(const SmartPointer& obj)
	:smartPtr(obj.smartPtr) {
	if (smartPtr) smartPtr->counter++;//óâåëè÷åíèå êîëè÷åñòâà ññûëîê íà îáúåêò
}
template <class T>
SmartPointer<T>::~SmartPointer() {
	if (smartPtr) {
		smartPtr->counter--;//óìåíüøåíèå êîëè÷åñòâà ññûëîê íà îáúåêò
			if (smartPtr->counter == 0) {//åñëè ÷èñëî ññûëîê íà îáúåêò ðàâíî íóëþ, òî äîëæåí óíè÷òîæèòñÿ îáúåêò
					delete smartPtr->ptr;//îñâîáîæäåíèå ïàìÿòè,âûäåëåííîé äëÿ îáúåêòà
					delete smartPtr;//îñâîáîæäåíèå ïàìÿòè, âûäåëåííîé äëÿ óêàçàòåëÿ
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
		smartPtr->counter--;//óìåíüøàåì ñ÷åò÷èê «ïðèêðåïëåííûõ» îáúåêòîâ äëÿ òåêóùåãî óêàçàòåëÿ
			if (smartPtr->counter == 0) {//åñëè îáúåêòîâ áîëüøå íåò, òî íåîáõîäèìî îñâîáîæäèòü âûäåëåííóþ ïàìÿòü
					delete smartPtr->ptr;
				delete smartPtr;
			}
	}
	smartPtr = obj.smartPtr;//ïðèñâàèâàíèå íîâîãî àäðåñà óêàçàòåëþ
	if (smartPtr) smartPtr->counter++;//óâåëè÷èòü ñ÷åò÷èê«ïðèêðåïëåííûõ» îáúåêòîâ
		return *this;
}








class Publisher :public Employee {
	
public:
	Publisher(string name, string fam, string otch, int age) :Employee(name, fam, otch, age) { }
	void publicate(SmartPointer<Book> book) {
		if (book.showCounter() != 2)
			cout << "Íåëüçÿ ïóáëèêîâàòü êíèãó" << endl;
		else {
			cout << "Ïóáëèêàöèÿ êíèãè" << endl;
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
	T* currentState;//òåêóùåå çíà÷åíèå îáúåêòà êëàññà
	T* prevState;//ïðåäûäóùåå ñîñòîÿíèå îáúåêòà
public:

	Transaction() :prevState(NULL), currentState(new T) {}//êîíñòðóêòîð áåç ïàðàìåòðîâ
	Transaction(const Transaction& obj) : currentState(new T(*(obj.currentState))), prevState(NULL) {}// êîíñòðóêòîð êîïèðîâàíèÿ
		~Transaction() {
		delete currentState; delete prevState;
	}//äåñòðóêòîð
	Transaction& operator=(const Transaction& obj);//ïåðåãðóçêà îïåðàòîðà ïðèñâàèâàíèÿ
		void showState(State state);//îòîáðàæåíèå ñîñòîÿíèé (ïðåäûäóùåãî è òåêóùåãî) îáúåêòà
		int beginTransactions(string content);//ìåòîä íà÷àëà òðàíçàêöèè
		void commit();//ìåòîä ïîäòâåðæäåíèÿ (êîììèòà) òðàíçàêöèè
	void deleteTransactions(); //ìåòîä îòêàòà òðàíçàêöèè
	T* operator->();//ïåðåãðóçêà îïåðàòîðà äîñòóïà ê ñîäåðæèìîìó îáúåêòà ÷åðåç óêàçàòåëü
};


template <class T>
Transaction<T>& Transaction<T>::operator=(const Transaction<T>&obj) {
	if (this != &obj) {//ïðîâåðêà íà ñëó÷àé obj=obj
		delete currentState;//óäàëåíèå òåêóùåãî çíà÷åíèÿ îáúåêòà
		currentState = new T(*(obj.currentState));//ñîçäàíèå è êîïèðîâàíèå îáúåêòà, èñïîëüçóÿ ïðèñâàåâàåìóþ òðàíçàêöèþ
	}
	return *this;
}

template <class T>
T* Transaction<T>::operator->() {
	return currentState;
}
template <class T>
void Transaction<T>::showState(State state) {//ìåòîä îòîáðàæåíèå ñîñòîÿíèÿ îáúåêòà
		cout << "Ñîñòîÿíèå îáúåêòà ";
	if (!state) cout << "äî íà÷àëà òðàíçàêöèè " << endl;
	else cout << "ïîñëå âûïîëíåíèÿ òðàíçàêöèè " << endl;
	if (prevState) cout << "prevState = " << prevState->Get_cont() << endl;//ïðåäûäóùåå ñîñòîÿíèå
	else cout << "prevState = NULL" << endl;
	cout << "currentState = " << currentState->Get_cont() << endl << "__________________________________" <<
		endl;//òåêóùåå ñîñòîÿíèå
}

template <class T>
int Transaction<T>::beginTransactions(string content) {// ìåòîä íà÷àëà òðàíçàêöèè
		delete prevState;//óäàëåíèå ïðåäûäóùåãî çíà÷åíèÿ
	prevState = currentState;//ñîõðàíåíèå ïðåäûäóùåãî ñîñòîÿíèÿ êàê òåêóùåãî
		currentState = new T(*prevState);//òåêóùåå ñîñòîÿíèå ñîçäàåòñÿ!!!!!!!!!!!!!!
		if (!currentState) return 0;//îøèáêà (íåîáõîäèìî îòìåíèòü òðàíçàêöèþ)
		currentState->set_cont(content);//èçìåíåíèå ñîñòîÿíèÿ îáúåêòà

		return 1;//óñïåøíîå îêîí÷àíèå òðàíçàêöèè
}

template <class T>
void Transaction<T>::commit() {
	
	delete prevState;//óäàëåíèå ïðåäûäóùåãî çíà÷åíèÿ
	prevState = NULL;//ïðåäûäóùåãî ñîñòîÿíèÿ íåò
	currentState->Get_book()->set_content(currentState->Get_cont());
}

template <class T>
void Transaction<T>::deleteTransactions() {
	if (prevState != NULL) {
		delete currentState;//óäàëåíèå òåêóùåãî çíà÷åíèÿ
		currentState = prevState;//ïðåäûäóùåå ñòàíîâèòñÿ òåêóùèì
		prevState = NULL;//ïðåäûäóùåãî ñîñòîÿíèÿ íåò
	}
}



