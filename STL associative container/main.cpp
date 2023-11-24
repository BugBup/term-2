#include "ClassName.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
//	system("1251");
	bool check = true;
	int choice;
	map<int, Student> exam;//идентификационный номер - ключ студент - значение
	//set<map<int, Student>> journey;
	multiset<Pair> sort;
	unordered_set<int> unsort;
	
	while (check) {
		system("cls");
		menu1();
		cin >> choice;
		system("cls");
		switch (choice)
		{
		case 1: add_stud(exam,unsort,sort); break;
		case 2: del_stud(exam,unsort,sort); break;
		case 3: find_stud(exam); system("pause"); break;
		case 4: print_stud(exam, unsort); system("pause"); break;
		case 5: print_stud_sort(exam, sort); system("pause"); break;
		case 6: edit_stud(exam, sort); break;
		case 7: return 0; break;
		default:cout << "Введите значение от 1 до 6\n";
			break;
		}
	}
}