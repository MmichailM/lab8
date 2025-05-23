#include "Owner.h"
#include "Init.h"
#include <fstream>
#include <Windows.h>
#include <conio.h>
#include <iomanip>

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	setlocale(LC_ALL, "russian");
	int n = 3;
	bool flag = true;
	vector<Owner> vec;
	init(n, vec);
	int c;
	enum commands { Exit, Add_Owner, Remove_Owner, Change_Owner, Calculate_Taxes };
	while (flag) {
		system("cls");
		printArray(vec);
		cout << "\nЧто Вы хотите сделать:\n"
			<< "\t1. Добавить нового собственника\n"
			<< "\t2. Удалить собственника\n"
			<< "\t3. Изменить данные у одного из собственников\n"
			<< "\t4. Посчитать налоги\n"
			<< "\t0. Выйти\n";
		cout << "Ваш выбор: ";
		cin >> c;
		cin.ignore((numeric_limits<streamsize>::max)(), '\n');
		while (c < 0 || c > 4) {
			system("cls");
			printArray(vec);
			cout << "\nЧто Вы хотите сделать:\n"
				<< "\t1. Добавить нового собственника\n"
				<< "\t2. Удалить собственника\n"
				<< "\t3. Изменить данные у одного из собственников\n"
				<< "\t4. Посчитать налоги\n"
				<< "\t0. Выйти\n";
			cout << "Ваш выбор: ";
			cin >> c;
			cin.ignore((numeric_limits<streamsize>::max)(), '\n');
		}
		switch (c) {
			case Add_Owner: {
				system("cls");
				string fullname;
				string inn;
				cout << "Добавление нового собственника:\n";
				cout << "\tВведите ФИО: ";
				getline(cin, fullname);
				cout << "\tВведите ИНН: ";
				getline(cin, inn);
				while (true) {
					try {
						vec.push_back(Owner(fullname, inn));
						system("cls");
						break;
					}
					catch (invalid_argument) {
						system("cls");
						cout << "ИНН должен состоять из 12 цифр, введите ИНН еще раз: ";
						getline(cin, inn);
					}
				}
				break;
			}
			case Remove_Owner: {
				system("cls");
				if (vec.size() == 0) {
					cout << "Список собственников пустой\n";
					cout << "Для продолжения нажмите любую клавишу...";
					_getch();
					break;
				}
				int ind = -1;
				printArray(vec);
				while (ind < 0 || ind >= vec.size()) {
					cout << "Введите индекс собственника, которого хотите удалить: ";
					cin >> ind;
					--ind;
					cin.ignore((numeric_limits<streamsize>::max)(), '\n');
				}
				system("cls");
				cout << "Удален собственник " << vec[ind].get_fullname() << '\n';
				vec.erase(vec.begin() + ind);
				cout << "Для продолжения нажмите любую клавишу...";
				_getch();
				break;
			}
			case Change_Owner: {
				system("cls");
				if (vec.size() == 0) {
					cout << "Список собственников пустой\n";
					cout << "Для продолжения нажмите любую клавишу...";
					_getch();
					break;
				}
				int ind = -1;
				printArray(vec);
				while (ind < 0 || ind >= vec.size()) {
					cout << "Введите индекс собственника, которого хотите изменить: ";
					cin >> ind;
					--ind;
					cin.ignore((numeric_limits<streamsize>::max)(), '\n');
				}
				system("cls");
				cout << "Редактирование собственника " << vec[ind].get_fullname() << '\n';
				cout << "\t1. Добавить имущество\n"
					<< "\t2. Отнять имущество\n"
					<< "\t3. \033[31mОтнять все \033[0m\n";
				cout << "Ваш выбор: ";
				cin >> c;
				cin.ignore((numeric_limits<streamsize>::max)(), '\n');
				if (c == 1) {
					system("cls");
					cout << "Редактирование собственника " << vec[ind].get_fullname() << '\n';
					cout << "\t1. Квартира\n"
						<< "\t2. Автомобиль\n"
						<< "\t3. Загородный дом\n";
					cout << "Ваш выбор: ";
					cin >> c;
					cin.ignore((numeric_limits<streamsize>::max)(), '\n');
					if (c == 1) {
						system("cls");
						size_t cost;
						double square;
						cout << "Редактирование собственника " << vec[ind].get_fullname() << '\n';
						cout << "\tВведите стоимость квартиры: ";
						cin >> cost;
						cin.ignore((numeric_limits<streamsize>::max)(), '\n');
						cout << "\tВведите площадь квартиры: ";
						cin >> square;
						cin.ignore((numeric_limits<streamsize>::max)(), '\n');
						vec[ind].addProperty(new Apartment(cost, square));
						cout << "Для продолжения нажмите любую клавишу...";
						_getch();
					}
					else if (c == 2) {
						system("cls");
						size_t cost;
						double hp;
						cout << "Редактирование собственника " << vec[ind].get_fullname() << '\n';
						cout << "\tВведите стоимость автомобиля: ";
						cin >> cost;
						cin.ignore((numeric_limits<streamsize>::max)(), '\n');
						cout << "\tВведите мощность двигателя автомобиля: ";
						cin >> hp;
						cin.ignore((numeric_limits<streamsize>::max)(), '\n');
						vec[ind].addProperty(new Car(cost, hp));
						cout << "Для продолжения нажмите любую клавишу...";
						_getch();
					}
					else if (c == 3) {
						system("cls");
						size_t cost;
						size_t dc;
						cout << "Редактирование собственника " << vec[ind].get_fullname() << '\n';
						cout << "\tВведите стоимость загородного дома: ";
						cin >> cost;
						cin.ignore((numeric_limits<streamsize>::max)(), '\n');
						cout << "\tВведите расстояние до города: ";
						cin >> dc;
						cin.ignore((numeric_limits<streamsize>::max)(), '\n');
						vec[ind].addProperty(new CountryHouse(cost, dc));
						cout << "Для продолжения нажмите любую клавишу...";
						_getch();
					}
				}
				else if (c == 2) {
					system("cls");
					if (vec[ind].get_properties().size() == 0) {
						cout << "Список собственности пустой\n";
						cout << "Для продолжения нажмите любую клавишу...";
						_getch();
						break;
					}
					cout << "Удаление собственности у собственника " << vec[ind].get_fullname() << '\n';
					int ind_;
					int num = 0;
					for (Property* i : vec[ind].get_properties()) {
						cout << '\t' << num << ". " << *i;
						num++;
					}
					cout << "Введите индекс имущества, которое хотите отнять: ";
					cin >> ind_;
					cin.ignore((numeric_limits<streamsize>::max)(), '\n');
					while (ind_ < 0 || ind_ >= vec[ind].get_properties().size()) {
						system("cls");
						cout << "Удаление собственности у собственника " << vec[ind].get_fullname() << '\n';
						cout << "\tВведите индекс имущества, которое хотите отнять:\n";
						int num = 0;
						for (Property* i : vec[ind].get_properties()) {
							cout << '\t' << num << ". " << *i;
							num++;
						}
						cin >> ind_;
						cin.ignore((numeric_limits<streamsize>::max)(), '\n');
					}
					vec[ind].deleteProperty(ind_);
					cout << "Для продолжения нажмите любую клавишу...";
					_getch();
				}
				else if (c == 3) {
					system("cls");
					int size = vec[ind].get_properties().size();
					for (int i = 0; i < size; i++) vec[ind].deleteProperty(0);
					cout << "Имущество успешно отнято\n";
					cout << "Для продолжения нажмите любую клавишу...";
					_getch();
				}
				break;
			}
			case Calculate_Taxes: {
				system("cls");
				int ind;
				double inc = 0, prop;
				printArray(vec);
				cout << "Выберете индекс собственника: ";
				cin >> ind;
				cin.ignore((numeric_limits<streamsize>::max)(), '\n');
				while (ind < 1 || ind > vec.size()) {
					system("cls");
					printArray(vec);
					cout << "Выберете индекс собственника: ";
					cin >> ind;
					cin.ignore((numeric_limits<streamsize>::max)(), '\n');
				}
				ind--;
				system("cls");
				cout << "Подсчет налогов для собственника " << vec[ind].get_fullname() << ":\n";
				prop = vec[ind].sumPropertyTaxes();
				for (int i = 0; i < vec[ind].get_properties().size(); i++) inc += vec[ind].get_properties()[i]->calculateIncomeTax();
				cout << "\tПодоходный налог: " << fixed << inc << endl;
				cout << "\tНалог на имущество: " << prop << '\n';
				cout << "Для продолжения нажмите любую клавишу...";
				_getch();
				break;
			}
			case Exit: {
				flag = false;
				break;
			}
		}
	}
}