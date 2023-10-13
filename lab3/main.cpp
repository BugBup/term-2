#include "header.h"
/*����������� ����� ������� (������� 5 �������, ����� �����
��������: ���������, ����������, ������������) �� ���������� �������
���������� �������. ���������� ��������� ������ ���������
������� �����. ������������� ������� ���� ����� ��������������
��������. ����������� ��������������� �������������� ��������.
������������� ������� ���� �������������� �������� � ���������� new.
������� �������������� �������� � ������������ � ������������������
����� ������������� � ������������. ������ ����������� �������
����������. ������� ����������� (����������������) ����� ����������,
������������� ���������� ����� ���� � ���������� ���. */


int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	int choise=0;
	string choiseStr,str;
	//getline(cin,choiseStr);
	Buyer buyer;
	Flowers flower;
	set_terminate(termFunc);
	int average, count,cost=0;
	while (true) {
		system("cls");
		menu();
		try {//������� � ��������� �������??? ���???
			if(!(cin >> choise))
				throw runtime_error("��������� �������� ���� ������");
		}
		catch (runtime_error errr) {

			cout<<errr.what()<< endl;
			system("pause");
			cin.clear();
			cin.ignore(1024,'\n');
			continue;
		}
		switch (choise) {
		case 1:
			cout << "������� ��� ����������" << endl;
			getline(cin, str);
			getline(cin, str);
			buyer.set_name(str);
			cout << "������� �������� ������" << endl;
			getline(cin, str);
			flower.set_name(str);
			flower.set_cost(100);
			buyer.set_order(flower);
			cout << "��� ������ ����� �������� " << buyer.get_name() << " ������ ������ " << buyer.get_order().get_flower().get_name()
				<< " �� ���������� " << buyer.get_order().get_flower().get_cost() << endl;
			system("pause");
			break;


		case 2:{
			cout << "������� ��� ����������" << endl;
			getline(cin, str);
			getline(cin, choiseStr);
			buyer.set_name(choiseStr);
			cout << "������� ���-�� ������ � ������" << endl;
			while (1) {
				try {
					Bouquet bouquet;
					if (!(cin >> count))
						throw runtime_error("��������� �������� ���� ������");
					for (int i = 0; i < count; i++) {
						cout << "������� �������� ������ ��� ������� " << i+1 << endl;
						cin.clear();
						cin.ignore();
						try{
							
							getline(cin, str);
							string prov = str;
							for (int j = 0; j < i; j++) {
								if (prov == bouquet.get_flower(j).get_name() )
									throw Exception("�������� ���������� ��� ������");
							}
						}
						catch (Exception exep) {
							cout << exep.what() << endl;
							cout << "� ����� ��������� 2" << endl;
							str += "2";
							
						}
						
						flower.set_name(str);
						flower.set_cost(100);
						bouquet.add_flower(flower);
						
					}
					buyer.set_order(bouquet);
					if(count!=0)
					cout << "� ������ ���������� ��������� �����: " << endl;
					for (int i = 0; i < count; i++) {
						cout << buyer.get_flower(i).get_name() << " " 
							<< buyer.get_flower(i).get_cost() << endl;
					}
					try {
						if (count == 0)
							throw 1;
						average = 100 * count / count;

					}
					catch (...) {
						cout << "���� �� �� ��������� ������� �� 0" << endl;
					}
				}
				catch (runtime_error er) {
					cout << er.what() << endl;
					system("pause");
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}

				break;
			}

			system("pause");
			break;//������� ���-�� ������, ����� ����������� ���, �� ������
		}

		case 3: {
			int counter = 0;
			Bouquet* bouq;
			bouq = new Bouquet[100000000];
			try {
				while (1) {
					bouq[counter].add_more();
					counter++;
				}
			}
			catch (bad_alloc exept) {
				cout << "�������� ����������" << exept.what() << endl;
				cout << "������� ������� �� ��� ����� ������ " << counter << " �������" << endl;
			}

			system("pause");
			break; }
		
		case 4: {
			try {
				Flowers flowe("flow", 10);
			}
			catch (int) {
				cout << "���������� ���������� ��� �����������" << endl;
				
			}
			
			system("pause"); 
			break; }// ��� ����� ����� ������������ �� ������� ��������, ����� �� ��������
			// (�����������+������������)
		case 5:cout << "���������� ���������" << endl; return 0 ;//��� ����� ��� ���������� ���������
		default:
			cout << "������� �������� �� � ��������� �� 1 �� 5" << endl;
			system("pause");
			break;
		}
		//������ ����� ����� ����� �������� �������� ����� �� ��������� ����� ������ � ������(���� ����� �� ����� ������, ����� �� ������)
		// ������� ������� ����� ���������� ��� ������ ����� ������� ���������� ����� ���� ������������� ���������� ����� 4
		// �������� ������� �� 0 ��� ������ ���������� ��� ���-�� �����
		
	}

	return 0;
}