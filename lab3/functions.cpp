#include "header.h"
void menu() {
	cout <<
		"1 - ������ ���� ������" << endl <<
		"2 - ������ ����� �� ������ ������" << endl <<
		"3 - ������� ����������� ����� ������� ��� � ������ ����� 1001 ���� " << endl <<
		"4 - �������� ���������� � ������������"<<endl<<
		"5 - �����" << endl;
}
Bouquet::Bouquet(const Bouquet& obj) {
	if (obj.amount > 0) {
		//delete[] this->flower;
		this->flower = new  Flowers[obj.amount];
		for (int i = 0; i < obj.amount; i++)
			*(this->flower + i) = *(obj.flower + i);
	}
	this->amount = obj.amount;
}
/*Bouquet::~Bouquet() {
	if (amount > 0) {
		delete[] flower;
		amount = 0;
	}
}*/
void Bouquet::add_flower(Flowers flower) {
	if (this->amount != 0) {
		Bouquet temp;
		temp.flower = new Flowers[this->amount];
		for (int i = 0; i < this->amount; i++) 
			*(temp.flower + i) = *(this->flower + i);

		delete[] this->flower;
		this->flower = new Flowers[this->amount + 1];

		for (int i = 0; i < this->amount; i++)
			*(this->flower + i) = *(temp.flower + i);
		delete[] temp.flower;
		*(this->flower + this->amount) = flower;
	}
	else {
		this->flower = new Flowers[1];
		*(this->flower + 0) = flower;
	}
	this->amount += 1;
	
}
void termFunc() {
	cout << "������� termFunc() ������� �������� terminate().\n";
	// ��������� ������������ ��������
	exit(-1);
}