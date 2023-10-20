#include "header.h"
int main() {
	set_terminate(termFunc);
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	Buyer buyer;
	Bouquet bouquet;
	string orders_name, name ;
	Flowers flower;
	int choice, amount ;
	cin.unsetf(ios::skipws);
	while (1) {
		cout << "������� ��� ������������" << endl;
		cin >> orders_name;
		if (!cin.good()) {

			cin.clear();
			cout << "��������� ����, ��� ������������ ������ �������� �� ������ �����" << endl;
			cin.ignore(10, '\n');
		}
		else {
			buyer.set_name(orders_name);
			cin.ignore(10, '\n');
			break;
		}

	}

	while (true) {
		system("cls");
		menu();
		//cout.setf(ios::right);
		cin >> choice;
		if (cin.fail()) {
			cout.setf(ios::right); 
			cout << "������� �������� ��������, �� �����" << endl;
			cout.unsetf(ios::right);
			cin.clear();
			continue;
		}
		cin.ignore(10, '\n');
		system("cls");
		switch (choice) {
			case 1: {
			cout << "������� ���������� ������,������� ������ �������� " << endl;
			cin >> amount;
			cin.clear();
			cin.ignore(10, '\n');
			if (cin.bad()) {
				cout << "�������� �������� �����" << endl;
				break;
			}
			for (int i = 0; i < amount; i++) {
				cout << "������� �������� ������" << endl;
				getline(cin, name);
				flower.set_name(name);
				flower.set_cost(100);
				buyer.add_flower(flower);
			}
			system("pause"); break; }
			case 2: {
			cout.setf(ios::left);
			head();
			for (int i = 0; i < buyer.get_bouquet().get_amount(); i++) {
				cout << setw(3) << i + 1 << setw(15) << buyer.get_bouquet().get_flower(i).get_name() << setw(5) <<
					buyer.get_bouquet().get_flower(i).get_cost() << endl;
				line();
			}
			cout.unsetf(ios::left);
			system("pause");
			break;
		}
			case 3: {
				cout << "�������� ������, ������� ������ ��������" << endl;
				cin >> choice;
				cin.ignore(10, '\n');
				cout << "������� ����� ��� ��� ����� ������" << endl;
				getline(cin, name);
				flower.set_name(name);
				flower.set_cost(100);
				buyer.set_flower(choice-1,flower);
				system("pause");
				break;
			}
			case 4: {
				cout << "�������� ������, ������� ������ �������" << endl;
				cin >> choice;
				cin.ignore(10, '\n');
				buyer.del_flower(choice-1);
				system("pause");
				break;
			}
			case 5: {
				buyer.sort_flower();
				cout << "������ ������ � ������ ������������" << endl;
				system("pause");
				break;
			}
			case 6: {
				cin.setf(ios::skipws);
				while (true) {
					cout << "��������, �� ������ ��������� ����� ����������� �����: " << endl
						<< "1 - �� �������� " << setw(10) << "" << "2 - �� ����"<<setw(10)<<"3 - �����" << endl;
					
					cin >> choice;
					if (cin.eof() || choice<0 || choice>3 || !cin.good()) {
						cin.clear();
						cout << "��� �������� ������������ ����" << endl;
						cin.ignore(10, '\n');
						system("pause");
						system("cls");
						continue;
					}
					cin.ignore(10, '\n');
					if (choice == 1) {
						cout << "������� �������� �������� ������ " << endl;
						getline(cin, name);
						buyer.get_bouquet().find_flower(name);
						break;
					}
					else if (choice) {
						cout << "������� ���� �������� ������ " << endl;
						cin >> amount;
						buyer.get_bouquet().find_flower(amount);
						break;
					}
					else break;
				}
				cin.unsetf(ios::skipws);
				system("pause");
				break;
			}
			case 7: {
				return 0;
			}
			default:cout << "������� ����� �� 1 �� 7" << endl; system("pause"); break;
		}
	}
}