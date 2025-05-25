#include "CountryHouse.h"

CountryHouse::CountryHouse(size_t worth, size_t distanceFromCity) : Property(worth), distanceFromCity(distanceFromCity) {}

size_t CountryHouse::get_distance() const {
	return distanceFromCity;
}

double CountryHouse::calculatePropertyTax() const {
	if (distanceFromCity <= TAX_RATES::LIMIT_DISTANCE_FROM_CITY) return worth * TAX_RATES::Apartment_TAX;
	else return worth * TAX_RATES::COUNTRY_HOUSE_TAX;
}

void CountryHouse::printProperty(ostream& out) {
	out << "«агородный дом: стоимость: " << worth << ", рассто€ние от города: " << distanceFromCity << '\n';
}

void CountryHouse::fromJson(nlohmann::json j) {
	distanceFromCity = j["CountryHouse"]["distanceFromCity"];
	worth = j["CountryHouse"]["worth"];
}

nlohmann::json CountryHouse::toJson() {
	ifstream fin("input.json");
	nlohmann::json j;
	j = nlohmann::json::parse(fin);
	int ind = j["properties"].size();
	j["properties"][ind]["CountryHouse"]["distanceFromCity"] = distanceFromCity;
	j["properties"][ind]["CountryHouse"]["worth"] = worth;
	fin.close();
	return j;
}

CountryHouse::~CountryHouse() {}
