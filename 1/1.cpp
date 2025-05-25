#include "Owner.h"
#include "Init.h"
#include <fstream>
#include <Windows.h>
#include <conio.h>
#include <iomanip>

void out(Owner* man);

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	setlocale(LC_ALL, "russian");
	int c;
	enum commands { Write, Json };
	cout << "Ввести данные о собственнике: \n"
		<< "\t1. Вручную\n"
		<< "\t2. Из Json-файла\n"
		<< "Ваш выбор: ";
	cin >> c;
	cin.ignore((numeric_limits<streamsize>::max)(), '\n');
	while (c < 1 || c > 2) {
		system("cls");
		cout << "Ввести данные о собственнике: \n"
			<< "\t1. Вручную\n"
			<< "\t2. Из Json-файла\n"
			<< "Ваш выбор: ";
		cin >> c;
		cin.ignore((numeric_limits<streamsize>::max)(), '\n');
	}
	c--;
	system("cls");
	Owner* man = new Owner;
	switch (c) {
		case Write: {
			string fullname;
			string inn;
			vector<Owner> vec;
			cout << "Введите полное имя собственника: ";
			getline(cin, fullname);
			while (fullname.empty()) {
				system("cls");
				cout << "Вы ничего не ввели, введите полное имя собственника: ";
				getline(cin, fullname);
			}
			cout << "Введите ИНН собственника (12 цифр): ";
			getline(cin, inn);
			while (inn.empty()) {
				system("cls");
				cout << "Вы ничего не ввели, введите ИНН собственника (12 цифр): ";
				getline(cin, inn);
			}
			while (true) {
				try {
					vec.push_back(Owner(fullname, inn));
					break;
				}
				catch (invalid_argument) {
					system("cls");
					cout << "ИНН должен состоять из 12 цифр, введите ИНН еще раз: ";
					getline(cin, inn);
				}
			}
			int n;
			Owner human = vec[0];
			system("cls");
			cout << "Введите сколько имущества будет у собственника " << human.get_fullname() << ": ";
			cin >> n;
			cin.ignore((numeric_limits<streamsize>::max)(), '\n');
			vector<Property*> prop;
			int count = 0;
			int c1;
			for (int i = 0; i < n; i++) {
				system("cls");
				count++;
				cout << "Какого типа будет имущество №" << count << ":\n"
					<< "1. Квартира\n"
					<< "2. Автомобиль\n"
					<< "3. Загородный дом\n";
				cin >> c1;
				cin.ignore((numeric_limits<streamsize>::max)(), '\n');
				while (c1 < 1 || c1 > 3) {
					system("cls");
					cout << "Какого типа будет имущество №" << count++ << ":\n"
						<< "1. Квартира\n"
						<< "2. Автомобиль\n"
						<< "3. Загородный дом\n";
					cin >> c1;
					cin.ignore((numeric_limits<streamsize>::max)(), '\n');
				}
				if (c1 == 1) {
					system("cls");
					size_t worth;
					double square;
					cout << count << ". Квартира\n"
						<< "\tВведите стоимость квартиры: ";
					cin >> worth;
					while (worth < 1) {
						system("cls");
						cout << "Стоимость квартиры не может быть <= 0, введите еще раз: ";
						if (worth >= 1) {
							system("cls");
							cout << count << ". Квартира\n"
								<< "\tВведите стоимость квартиры: " << worth << '\n';
						}
					}
					cout << "\tВведите площадь квартиры: ";
					cin >> square;
					while (square < 1) {
						system("cls");
						cout << "Площадь квартиры не может быть <= 0, введите еще раз: ";
						if (worth >= 1) {
							system("cls");
							cout << count << ". Квартира\n"
								<< "\tВведите стоимость квартиры: " << worth << '\n'
								<< "\tВведите площадь квартиры: " << square << '\n';
						}
					}
					prop.push_back(new Apartment(worth, square));
				}
				else if (c1 == 2) {
					system("cls");
					size_t worth;
					double horsepower;
					cout << count << ". Автомобиль\n"
						<< "\tВведите стоимость автомобиля: ";
					cin >> worth;
					while (worth < 1) {
						system("cls");
						cout << "Стоимость автомобиля не может быть <= 0, введите еще раз: ";
						if (worth >= 1) {
							system("cls");
							cout << count << ". Автомобиль\n"
								<< "\tВведите стоимость автомобиля: " << worth << '\n';
						}
					}
					cout << "\tВведите мощность двигателя автомобиля: ";
					cin >> horsepower;
					while (horsepower < 1) {
						system("cls");
						cout << "Мощность двигателя автомобиля не может быть <= 0, введите еще раз: ";
						if (worth >= 1) {
							system("cls");
							cout << count << ". Автомобиль\n"
								<< "\tВведите стоимость автомобиля: " << worth << '\n'
								<< "\tВведите мощность двигателя автомобиля: " << horsepower << '\n';
						}
					}
					prop.push_back(new Car(worth, horsepower));
				}
				else if (c1 == 3) {
					system("cls");
					size_t worth;
					int distanceFromCity;
					cout << count << ". Загородный дом\n"
						<< "\tВведите стоимость загородного дома: ";
					cin >> worth;
					while (worth < 1) {
						system("cls");
						cout << "Стоимость загородного дома не может быть <= 0, введите еще раз: ";
						if (worth >= 1) {
							system("cls");
							cout << count << ". Загородный дом\n"
								<< "\tВведите стоимость загородного дома: " << worth << '\n';
						}
					}
					cout << "\tВведите расстояние до города у загородного дома: ";
					cin >> distanceFromCity;
					while (distanceFromCity < 1) {
						system("cls");
						cout << "Расстояние до города не может быть <= 0, введите еще раз: ";
						if (worth >= 1) {
							system("cls");
							cout << count << ". Квартира\n"
								<< "\tВведите стоимость загородного дома: " << worth << '\n'
								<< "\tВведите расстояние до города у загородного дома: " << distanceFromCity << '\n';
						}
					}
					prop.push_back(new CountryHouse(worth, distanceFromCity));
				}
			}
			man = &human;
			out(man);
			break;
		}
		case (Json): {
			string input_file;
			cout << "Введите название файла ввода: ";
			getline(cin, input_file);
			ifstream fin;
			fin.open(input_file);
			while (!fin.good()) {
				system("cls");
				clog << "Такого файла несуществует, введите корректный файл ввода: ";
				getline(cin, input_file);
				fin.open(input_file);
			}
			Owner human;
			nlohmann::json j;

			try {
				j = nlohmann::json::parse(fin);
			}
			catch (nlohmann::json::parse_error) {
				clog << "Некорректный файл ввода\n";
				return -1;
			}

			try {
				human.fromJson(j);
			}
			catch (invalid_argument) {
				clog << "Некорректный файл ввода\n";
				return -1;
			}
			man = &human;
			out(man);
			break;
		}
	}
}

void out(Owner* man) {
	Owner human = *man;
	string output_file;
	cout << "Информация о собственнике:\n";
	cout << '\t' << human;
	cout << "Введите название файла вывода: ";
	getline(cin, output_file);
	ofstream fout;
	fout.open(output_file);
	nlohmann::json js = human.toJson();
	while (true) {
		try {
			fout << js.dump(4);
			break;
		}
		catch (exception) {
			system("cls");
			clog << "Некорректный файл вывода, введите еще раз: ";
			getline(cin, output_file);
			fout.open(output_file);
		}
	}
	fout.close();
	cout << "\n\nВ файл " << output_file << " выведена информация о налогах на имущество собственника " << human.get_fullname() << '\n';
}
