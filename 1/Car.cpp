#include "Car.h"

Car::Car(size_t worth, double horsepower) : Property(worth), horsepower(horsepower) {}

double Car::get_horsepower() const {
	return horsepower;
}

double Car::calculatePropertyTax() const {
	if (horsepower < TAX_RATES::LOW_HORSEPOWER) return worth * TAX_RATES::CAR_TAX;
	else {
		if (horsepower > TAX_RATES::HIGH_HORSEPOWER) return worth * TAX_RATES::CAR_LUXURY_TAX;
		else return worth * TAX_RATES::CAR_TRUCK_TAX;
	}
}

void Car::printProperty(ostream& out) {
	out << "Автомобиль: стоимость: " << worth << ", мощность двигателя: " << horsepower << '\n';
}

void Car::fromJson(nlohmann::json j) {
	try {
		horsepower = j["Car"]["horsepower"];
		worth = j["Car"]["worth"];
	}
	catch (exception) {
		throw invalid_argument("incorrect file");
	}
}

nlohmann::json Car::toJson() {
	nlohmann::json j;
	j["Car"]["tax"] = calculatePropertyTax();
	return j;
}

Car::~Car() {}