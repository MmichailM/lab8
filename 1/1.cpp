#include "Owner.h"
#include "Init.h"
#include <fstream>
#include <Windows.h>
#include <conio.h>
#include <iomanip>

int main() {
	ifstream fin("input.json");
	Apartment ap;
	nlohmann::json j;
	j = nlohmann::json::parse(fin);
	/*j = j["properties"][0];
	cout << j["Apartment"]["square"];*/
	ap.fromJson(j["properties"][0]);
	Car c(3000000, 200);
	nlohmann::json js = c.toJson();
	ofstream fout("output.json");
	fout << js.dump(4);
	fout.close();
}