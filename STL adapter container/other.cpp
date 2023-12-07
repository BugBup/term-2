#include "header.h"

void Teacher:: add_stud(Student stud) {
	this->stud.push(stud);
}

void Teacher::pop_stud() {
	if (!stud.empty()) {
		Student temp = this->stud.top();
		cout << "Какую отметка поставить студенту " << temp.get_surname() << " с номером " << temp.get_number() <<
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
		cout << "Сейчас на проверке нет работ" << endl;
		system("pause");
	}
	
}
void Teacher::amount_stud() {
	if (this->stud.empty())
		cout << "Сейчас на проверке у преподавателя нет работ" << endl;
	else
	cout << "Сейчас на проверке у преподавателя " << this->stud.size() << " работ студентов" << endl;
	system("pause");
}
void menu() {
	cout << "1 - Добавить студента в очередь сдающих" << endl <<
		"2 - Студент сдал свою работу" << endl <<
		"3 - Учитель проверяет работу" << endl <<
		"4 - Количество студентов на проверке" << endl <<
		"5 - Количество студентов в очереди" << endl <<
		"6 - Выйти" << endl;
}