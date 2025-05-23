#pragma once
#include "Property.h"
class Apartment : public Property {
protected:
	double square;
public:
	Apartment(size_t worth, double square);
	double get_square() const;
	double calculatePropertyTax() const;
	void printProperty(ostream& out);
	void fromJson(nlohmann::json json);
	void toJson();
	~Apartment();
};

