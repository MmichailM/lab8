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
	Owner man;
	ifstream fin("input.json");
	nlohmann::json j;
	j = nlohmann::json::parse(fin);
	man.fromJson(j);
	cout << man;
}