#include "ClassName.h"
void menu1() {
	cout << "1 - �������� ��������" << endl <<
		"2 - ������� �������� �� ������" << endl <<
		"3 - �����" << endl;
}
void menu2() {
	cout << "1 - ����������� ���� ������ ���������" << endl <<
		"2 - ������������� ������ ��������� �� �������" << endl <<
		"3 - ����� �������� �� �������" << endl <<
		"4 - ������� ��������" << endl<<
		"5 - �����" << endl;
}
void menu3() {
	cout << "1 - ����������� ��� �������� ��������" << endl
		<< "2 - ����������� ���� �������������� ��������" << endl
		<< "3 - �����" << endl;
}
void read_stud(vector<Student> students){
	//for_each(students.begin(), students.end(), print() ) {	}
	for (int i = 0; i < students.size(); i++) {
		cout << i + 1<< " "; students[i].print();
	}
}
bool operator<(const Student& o1, const Student& o2) {
	return o1.FIO[0]<o2.FIO[0];
 }
bool operator>(const Student& o1, const Student& o2) {
	return o2.FIO[0]>o1.FIO[0];
}
bool operator==(const Student& o1, const Student& o2) {
	if (o1.FIO[0].compare(o2.FIO[0]) == 0) {
		return true;
	}
	else return false;;
}
ostream& operator<<(ostream& s, Subject obj) {
	s << obj.name;
	return s;
}
ostream& operator<<(ostream& s, Teacher obj) {
	s << obj.FIO[0]<<" "<<obj.FIO[1]<<" "<<obj.FIO[2];
	return s;
}
istream& operator<<(istream& s, Student obj) {
	s >> obj.FIO[0];
	return s;
}
