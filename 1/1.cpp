#include "Owner.h"
#include "Init.h"
#include <fstream>
#include <Windows.h>
#include <conio.h>
#include <iomanip>

int main() {
	Apartment ap;
	nlohmann::json j;
	ap.fromJson(j);
	cout << ap;
}