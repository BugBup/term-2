#pragma once//написать свой класс исключения о том, что нельзя в букет разных цветов записать 2 одинаковых цветочка
#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

class Exception {
	string text;
public:
	Exception(string text) { this->text = text; }
	string what() {
		return this->text;
	}
};

class Plant {
protected:
	string name;
public:
	Plant() {};
	Plant(string name) :name(name) { cout << "Конструктор Plant" << endl; };
	~Plant() { if (name == "flow")  cout << "Деструтор Plant" << endl; }
	void set_name(string name) { this->name = name; }
	string get_name() { return this->name; }
};

class Flowers:public Plant {
float cost;
public:
	Flowers(string name, float cost) :Plant(name) { this->cost = cost; cout << "Конструтор Flowers" << endl; throw 1; }
	~Flowers() {if(name == "flow") cout << "Деструтор Flowers" << endl; }
	Flowers():Plant() { };
	void set_cost(int cost) { this->cost = cost; };
	int get_cost() { return this->cost; }
	//ofstream operator<<
};
class Bouquet {
	int amount;
	Flowers* flower;
public:
	Bouquet() { this->amount = 0; flower = nullptr; };
	Bouquet(const Bouquet& obj); 
	void add_flower(Flowers flower);
	void add_more() {
		flower = new Flowers[1001];
	}
	//~Bouquet();
	/*void set_flowers(int amount) {
		if (flower != NULL) {
			flower = new Flowers[amount];
		}
	}*/
	void set_amount(int amount){ this->amount = amount;}
	int get_amount() { return this->amount; }
	Flowers get_flower(int i) {
		if (this->amount >= i)
			return *(flower + i);
		else {
			Flowers flowerk("Такого цветка не было",0);
			return (flowerk);
		}
	}
};


class Buyer {
	class Order {
	protected:
		Flowers flower;
		Bouquet bouquet;
	public:
		Order() {};
		Order(Flowers flower) { this->flower = flower;  }
		Order(Bouquet buquet) { this->bouquet = buquet; }
		Flowers get_flower() { return this->flower; }
		void set_flower(Flowers flower) { this->flower = flower; }
		Bouquet get_bouquet() { return this->bouquet; }
		void set_bouquet(Bouquet bouquet) { this->bouquet = bouquet; }

		//void create_bouquet() {
			//this->bouquet.set_flowers(this->buquet.get_amount());}
	};

	Order order;
	string name;

public:
	Buyer() {};
	Buyer(string name, Order order) :name(name), order(order) {};
	void set_name(string name) { this->name = name; }
	string get_name() { return this->name; }
	Order get_order() { return this->order; }
	Bouquet get_bouquet() { return this->order.get_bouquet(); }
	Flowers get_flower(int i) {
		return order.get_bouquet().get_flower(i);
	}
	void set_order(Bouquet bouquet) {
		this->order.set_bouquet(bouquet);
	}
	void set_order(Flowers flower) {

		this->order.set_flower(flower);
	}
};


void menu();
void termFunc();
