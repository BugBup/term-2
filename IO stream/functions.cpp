#include "header.h"
Flowers Bouquet::get_flower(int i) {
	if (this->amount >= i)
		return *(flower + i);
	else {
		Flowers flowerk("Такого цветка не было", 0);
		return (flowerk);
	}
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
void Buyer::add_flower(Flowers flower) {
	this->order.add_flower(flower);
}
void Bouquet::sort_flower() {
	for(int i=0;i < this->amount-1; i++){
			for(int j=0;j< this->amount-1; j++){
				if (flower[j].get_name() > flower[j + 1].get_name())
					swap(flower[j], flower[j + 1]);
		}
	}
}
void Buyer::sort_flower() {
	order.sort_flower();
}
void Bouquet::set_flower(int i,Flowers flower) {
	if (this->amount < i + 1)
	{
		cout << "Цветка с таким номером не существует" << endl;
		return;
	}
	*(this->flower + i) =flower;
}
void Buyer::set_flower(int i, Flowers flower) {
	order.set_flower(i, flower);
}
void Bouquet::find_flower(string name) {
	for (int i = 0; i < this->amount; i++) {
		if ((this->flower + i)->get_name() == name)
			cout << (this->flower + i)->get_name() << ' ' << (this->flower + i)->get_cost() << endl;
	}
	system("pause");
}
void Bouquet::find_flower(float cost) {
	for (int i = 0; i < this->amount; i++) {
		if ((this->flower + i)->get_cost() == cost)
			cout << (this->flower + i)->get_name() << ' ' << (this->flower + i)->get_cost() << endl;
	}
	system("pause");
}
void Bouquet::del_flower(int i) {
	if (this->amount < i + 1 || i<0) {
		cout << "Цветка с таким номером нет" << endl;
		return;
	}
	for (int j = i; j < this->amount-1; j++) {
		*(this->flower + j) = *(this->flower + (j+1));
	}
	(this->flower + (amount - 1))->~Flowers();
	this->amount--;
}
void Buyer::del_flower(int i) {
	this->order.del_flower(i);
}
void termFunc() {
	cout << "Функция termFunc() вызвана функцией terminate().\n";
	// операторы освобождения ресурсов
	exit(-1);
}
void menu() {
	cout << "1 - Добавить цветы в букет" << endl
		<< "2 - Посмотреть все цветы букета" << endl
		<< "3 - Изменить цветок(ы) в букете" << endl
		<< "4 - Удалить цветок(ы) из букета" << endl
		<< "5 - Отсортировать цветы в букете" << endl
		<< "6 - Провести поиск цветка в букете" << endl
		<< "7 - Выйти " << endl
		<< "Сделайте свой выбор: " << endl;
}
void head() {
	line();
	cout << setw(3) << "№" << setw(15) << "Название" << setw(5) << "Цена" << endl;
	line();
}
void line() {
	for (int i = 0; i < 23; i++)
		cout << "*";
	cout << endl;
}