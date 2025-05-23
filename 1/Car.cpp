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

Car::~Car() {}