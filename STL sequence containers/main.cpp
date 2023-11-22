#include "ClassName.h"


bool comp(Student o1, Student o2) { return o1 < o2; }

int main() {
	bool check = true, check2 = true;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int number=0;
	vector<Student> students;
	array<Subject, 3> subjects {Subject("ООПиП"),Subject("СММиФ"), Subject("ММЭ")};
	list<Teacher> teachers{Teacher("Салапура","Марина ", "Николаевна "), Teacher("Романчук", "Татьяна", "Анатольевна"),
		Teacher("Шкода", "Валентина", "Ивановна")};
	list<Teacher>::iterator listPtr = teachers.begin();
	
	while (true) {
		check2 = true;
		int choice;
		system("cls");
		menu1();
		cin >> choice;
		switch (choice) {
		case 1: {
			string name, fam, otch;
			int group;
			cin.ignore(10,'\n');
			cout << "Введите фамилию студента" << endl;
			getline(cin, fam);
			cout << "Введите имя студента" << endl;
			getline(cin, name);
			cout << "Введите отчество студента" << endl;
			getline(cin, otch);
			cout << "Введите группу студента" << endl;
			cin >> group;
			students.push_back(Student(fam,name,otch,group));
			fstream f; f.open("MyFile.txt", ios::app); f << students.back(); f.close();
			break; }
		case 2: {
			while (check2) {
				if (students.empty()) {
					cout << "Сейчас нет студентов в базе" << endl;
					system("pause");
					break;
				}
				system("cls");
				menu2();
				cin >> choice;
				switch (choice) {
				case 1: read_stud(students); system("pause"); break;
				case 2: sort(students.begin(), students.end(), comp); cout << "Список отсортирован" << "\n"; break;
				case 3: {
					string name, fam, otch;
					int group;
					cout << "Введите фамилию студента" << endl;
					getline(cin, fam);
					cout << "Введите имя студента" << endl;
					getline(cin, name);
					cout << "Введите отчество студента" << endl;
					getline(cin, otch);
					cout << "Введите группу студента" << endl;
					cin >> group;
					find(students.begin(), students.end(), Student(fam, name, otch, group)); break; }
				case 4: {
					read_stud(students);
					cout << "Напишите номер студента, или 0 чтобы выйти" << endl;
					cin >> number;
					while (check) {
						system("cls");
						menu3();
						cin >> choice;
						switch (choice) {
						case 1: cout << subjects.front() << "\n" << subjects.at(1) << "\n" << subjects.back() << "\n"; system("pause");
							break;
						case 2:while (listPtr != teachers.end()) {
							cout << *listPtr << endl;
							listPtr++;
						} listPtr = teachers.begin(); system("pause");
						break;
						case 3:check = false; break;
						}
					} check = true;
					break; }
				case 5:check2 = false; break;
				default:cout << "Введите число в диапазоне(1-5)" << endl; break;
				}
				
			}break;
		}
		case 3: return 0;
		default: cout << "Введите число в диапазоне(1-3)" << endl; break;
		}
	}
	return 0;
}