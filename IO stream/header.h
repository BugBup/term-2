#pragma once//�������� ���� ����� ���������� � ���, ��� ������ � ����� ������ ������ �������� 2 ���������� ��������
#include <iostream>
#include <Windows.h>
#include <string>
#include <search.h>
#include <stdlib.h>
#include <iomanip>


using namespace std;

class Plant {
protected:
	string name;
public:
	Plant() {};
	Plant(string name) :name(name) { cout << "����������� Plant" << endl; };
	~Plant() { if (name == "flow")  cout << "��������� Plant" << endl; }
	void set_name(string name) { this->name = name; }
	string get_name() { return this->name; }
};

class Flowers :public Plant {
	float cost;
public:
	Flowers(string name, float cost) :Plant(name) { this->cost = cost; cout << "���������� Flowers" << endl; throw 1; }
	~Flowers() { if (name == "flow") cout << "��������� Flowers" << endl; }
	Flowers() :Plant() { };
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
	void set_amount(int amount) { this->amount = amount; }
	int get_amount() { return this->amount; }
	Flowers get_flower(int i);
	void sort_flower();
	void set_flower(int i,Flowers flower);
	void find_flower(string name);
	void find_flower(float cost);
	void del_flower(int i);
};


class Buyer {
	class Order {
	protected:
		//Flowers flower;
		Bouquet bouquet;
	public:
		Order() {};
		//Order(Flowers flower) { this->flower = flower; }
		Order(Bouquet buquet) { this->bouquet = buquet; }
		//Flowers get_flower() { return this->flower; }
		//void set_flower(Flowers flower) { this->flower = flower; }
		Bouquet get_bouquet() { return this->bouquet; }
		void add_flower(Flowers flower) {
			bouquet.add_flower(flower);
		}
		void del_flower(int i) {
			bouquet.del_flower(i);
		}
		void set_flower(int i, Flowers flower) {
			bouquet.set_flower(i, flower);
		}
		void sort_flower() {
			bouquet.sort_flower();
		}
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
	void add_flower(Flowers flower);
	void del_flower(int i);
	void set_flower(int i, Flowers flower);
	void sort_flower();
	void set_order(Bouquet bouquet) {
		this->order.set_bouquet(bouquet);
	}
	//void set_order(Flowers flower) {
		//this->order.set_flower(flower);
	//}
};

void menu();
void termFunc();
void head();
void line();