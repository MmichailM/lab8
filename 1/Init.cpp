#include "Init.h"

void init(int n, vector<Owner>& vec) {
	string fullname, inn;
	for (int i = 0; i < n; i++) {
		cout << "Введите ФИО собственника: ";
		getline(cin, fullname);
		cout << "Введите ИНН собственника: ";
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
	}
	vec[0].addProperty(new Apartment(3000000, 105));
	vec[0].addProperty(new Car(1500000, 149));
	vec[0].addProperty(new CountryHouse(7000000, 120));
	vec[0].addProperty(new Car(500000, 130));

	vec[1].addProperty(new Apartment(9000000, 145));
	vec[1].addProperty(new Car(10000000, 230));
	vec[1].addProperty(new CountryHouse(14000000, 45));
	vec[1].addProperty(new Apartment(5000000, 100));
	vec[1].addProperty(new Car(2000000, 140));

	vec[2].addProperty(new Apartment(1500000, 37));
	vec[2].addProperty(new Car(1000000, 120));
	vec[2].addProperty(new CountryHouse(3000000, 150));
	vec[2].addProperty(new CountryHouse(4000000, 100));
}

void printArray(const vector<Owner>& vec) {
	int num = 1;
	cout << "==================================================\n";
	for (Owner i : vec) cout << num << ". " << i << '\n', num++;
	cout << "==================================================\n";
}
