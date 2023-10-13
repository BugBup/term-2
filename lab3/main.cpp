#include "header.h"
/*Разработать набор классов (минимум 5 классов, связи между
классами: агрегация, композиция, наследование) по предметной области
«Цветочный магазин». Функционал программы должен позволить
собрать заказ. Сгенерировать минимум пять типов исключительных
ситуаций. Реализовать перенаправление исключительных ситуаций.
Сгенерировать минимум одну исключительную ситуацию с оператором new.
Создать исключительную ситуацию в конструкторе и продемонстрировать
вызов конструкторов и деструкторов. Задать собственную функцию
завершения. Создать собственный (пользовательский) класс исключения,
сгенерировать исключение этого типа и обработать его. */


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
		try {//сделать в отдельную функцию??? или???
			if(!(cin >> choise))
				throw runtime_error("Произошёл неверный ввод данных");
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
			cout << "Введите имя покупателя" << endl;
			getline(cin, str);
			getline(cin, str);
			buyer.set_name(str);
			cout << "Введите название цветка" << endl;
			getline(cin, str);
			flower.set_name(str);
			flower.set_cost(100);
			buyer.set_order(flower);
			cout << "Был сделан заказ клиентом " << buyer.get_name() << " куплен цветок " << buyer.get_order().get_flower().get_name()
				<< " со стоимостью " << buyer.get_order().get_flower().get_cost() << endl;
			system("pause");
			break;


		case 2:{
			cout << "Введите имя покупателя" << endl;
			getline(cin, str);
			getline(cin, choiseStr);
			buyer.set_name(choiseStr);
			cout << "Введите кол-во цветов в букете" << endl;
			while (1) {
				try {
					Bouquet bouquet;
					if (!(cin >> count))
						throw runtime_error("Произошёл неверный ввод данных");
					for (int i = 0; i < count; i++) {
						cout << "Введите название цветка под номером " << i+1 << endl;
						cin.clear();
						cin.ignore();
						try{
							
							getline(cin, str);
							string prov = str;
							for (int j = 0; j < i; j++) {
								if (prov == bouquet.get_flower(j).get_name() )
									throw Exception("Прозошла совпадение имён цветов");
							}
						}
						catch (Exception exep) {
							cout << exep.what() << endl;
							cout << "К имени добавится 2" << endl;
							str += "2";
							
						}
						
						flower.set_name(str);
						flower.set_cost(100);
						bouquet.add_flower(flower);
						
					}
					buyer.set_order(bouquet);
					if(count!=0)
					cout << "В букете содержатся следующие цветы: " << endl;
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
						cout << "Чуть ли не произошло деление на 0" << endl;
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
			break;//пишется кол-во цветов, после добавляются они, по одному
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
				cout << "Возникло исключение" << exept.what() << endl;
				cout << "Удалось создать за это время только " << counter << " букетов" << endl;
			}

			system("pause");
			break; }
		
		case 4: {
			try {
				Flowers flowe("flow", 10);
			}
			catch (int) {
				cout << "Обработчик исключения для конструтора" << endl;
				
			}
			
			system("pause"); 
			break; }// тут будет ломка конструктора по образцу примерно, нужно всё показать
			// (деструкторы+конструкторы)
		case 5:cout << "Завершение программы" << endl; return 0 ;//тут будет своё завершение программы
		default:
			cout << "Введено значение не в диапозоне от 1 до 5" << endl;
			system("pause");
			break;
		}
		//помимо всего нужно будет добавить например чтобы не совпадали имена цветов в букете(если будет не очень сложно, вроде не сложно)
		// наверно создать класс исключения для самого моего первого исключения чтобы было перснональное исключение итого 4
		// добавить деление на 0 для пятого исключения или что-то такое
		
	}

	return 0;
}