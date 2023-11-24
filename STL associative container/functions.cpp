#include "ClassName.h"

bool operator<(Student obj1, Student obj2) {
	return obj1.name < obj2.name;
}
bool operator>(Student obj1, Student obj2) {
	return obj1.name > obj2.name;
}
bool operator==(Student obj1, Student obj2) {
	return obj1.name == obj2.name;
}
ostream& operator<<(ostream& s, Student obj) {
	s << obj.name;
	return s;
}
ostream& operator<<(ostream& s, Pair obj) {
	s << obj.number << " " << obj.name;
	return s;
}
void menu1() {
	cout << "1 - �������� �������� \n2 - ������� �������� \n" <<
		"3 - ����� �������� �� ��� ������������������ ������\n" <<
		"4 - ������� ������ ���������\n5 - ������� ��������������� ������ ��������� ���������\n" <<
		"6 - ������������� �������� \n7 - �����\n";
}
void add_stud(map<int, Student>& obj, unordered_set<int>& ob, multiset<Pair>& o) {
	cout << "������� ������������������ ����� ��������" << endl;
	int number;
	string name;
	cin >> number;
	cout << "������� ��� ��������" << endl;
	cin.ignore(10, '\n');
	getline(cin, name);
	obj.insert(pair<int, Student>( number, Student(name)));
	ob.insert(number);
	o.insert(Pair(number,name));
}
void print_stud(map<int, Student> obj, unordered_set<int> keys) {
	if (obj.empty()) {
		cout << "������ ����" << endl;
		return;
	}
	map<int, Student>::iterator mapPtr;
	unordered_set<int>::iterator setPtr;
	setPtr = keys.begin();
	while (setPtr != keys.end()) {
		mapPtr = obj.find(*setPtr);
		cout <<mapPtr->first<<" " << mapPtr->second << '\n';
		setPtr++;
	}
}
void print_stud_sort(map<int, Student> obj, multiset<Pair> o) {
	if (obj.empty()) {
		cout << "������ ����" << endl;
		return;
	}
	map<int, Student>::iterator mapPtr;
	multiset<Pair>::iterator setPtr;
	setPtr = o.begin();
	while (setPtr != o.end()) {
		cout << *setPtr << '\n';
		setPtr++;
	}
}
void del_stud(map<int, Student>& obj, unordered_set<int>& ob, multiset<Pair>& o) {
	cout << "������� ����������������� ����� ��������, �������� ������ �������" << endl;
	int number;
	cin >> number;
	o.erase(Pair(number, obj.find(number)->second.name));
	ob.erase(number);
	obj.erase(number);
}
void find_stud(map<int, Student>obj) {
	cout << "������� ����������������� ����� ��������, �������� ������ �������" << endl;
	int number;
	cin >> number;
	if (obj.find(number) != obj.end()) {
		cout << obj.find(number)->second.name<<'\n';
	}
	else cout << "C������� � ����� ������� ��� � ������" << endl;
}
bool operator<(Pair obj1, Pair obj2) {
	return obj1.name < obj2.name;
}
void edit_stud(map<int, Student>& obj, multiset<Pair>& o) {
	cout << "������� ����������������� ����� ��������, �������� ������ ��������" << endl;
	int number;
	string name;
	cin >> number;
	cout << "������� ����� ��� ��������" << endl;
	cin.ignore(10, '\n');
	getline(cin, name);
	o.erase(Pair(number,obj.find(number)->second.name));
	o.insert(Pair(number, name));
	obj.erase(number);
	obj.insert(pair<int, Student>(number, Student(name)));
	
}
