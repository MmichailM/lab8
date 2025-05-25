#include "Owner.h"
#include "Init.h"
#include <fstream>
#include <Windows.h>
#include <conio.h>
#include <iomanip>

int main() {
	Owner man;
	nlohmann::json j;
	man.fromJson(j);
	cout << man;
}