#include "Apartment.h"

Apartment::Apartment(size_t worth, double square) : Property(worth), square(square) {}

double Apartment::get_square() const {
	return square;
}

double Apartment::calculatePropertyTax() const {
	if (square <= TAX_RATES::LIMIT_Apartment_SQUARE) return worth * TAX_RATES::Apartment_TAX;
	else return worth * TAX_RATES::Apartment_LUXURY_TAX;
}

void Apartment::printProperty(ostream& out) {
	out << " вартира: cтоимость: " << worth << ", площадь: " << square << '\n';
}

void Apartment::fromJson(nlohmann::json j) {
	try {
		square = j["Apartment"]["square"];
		worth = j["Apartment"]["worth"];
	}
	catch (exception) {
		throw invalid_argument("incorrect file");
	}
}

nlohmann::json Apartment::toJson() {
	nlohmann::json j;
	j["Apartment"]["tax"] = calculatePropertyTax();
	return j;
}

Apartment::~Apartment() {}
