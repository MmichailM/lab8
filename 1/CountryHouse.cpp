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

CountryHouse::~CountryHouse() {}
