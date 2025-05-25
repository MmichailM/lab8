#pragma once
#include "Property.h"
class Car : public Property {
protected:
	double horsepower;
public:
	Car() : horsepower(0.0), Property(0) {}
	Car(size_t worth, double horsepower);
	double get_horsepower() const;
	double calculatePropertyTax() const;
	void printProperty(ostream& out);
	void fromJson(nlohmann::json json);
	nlohmann::json toJson();
	~Car();
};

