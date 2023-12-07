#include "header.h"
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	bool work = true;
	Teacher teacher("Салапура") ;
	queue<Student> q;
	while (work) {
		int choice;
		system("cls");
		menu();
		cout << "Введите значение" << endl;
		cin >> choice;
		switch (choice) {
		case 1: {
				string surname; int number;
				cout << "Введите имя студента" << endl;
				cin >> surname;
				cout << "Введите уникальный номер студента" << endl;
				cin >> number;
				q.push(Student(number, surname));
			break; }
		case 2: if (!q.empty()) {
			teacher.add_stud(q.front());
			q.pop();
		}
			  else cout << "В очереди никого нет, для того чтобы сдать работу" << endl;
			break;
		case 3: teacher.pop_stud(); break;
		case 4: teacher.amount_stud(); break;
		case 5:
			if (q.empty())
				cout << "Очередь пуста" << endl;
			else
			cout << "В очереди на сдачу сейчас " << q.size() << " человек" << endl; 
			system("pause"); break;
		case 6: work = false; break;
		default:break;
		}
	}

	return 0;
}