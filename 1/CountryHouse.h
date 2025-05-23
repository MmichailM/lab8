#pragma once
#include "Property.h"
class CountryHouse : public Property {
protected:
	size_t distanceFromCity;
public:
	CountryHouse(size_t worth, size_t distanceFromCity);
	size_t get_distance() const;
	double calculatePropertyTax() const;
	void printProperty(ostream& out);
	void fromJson(nlohmann::json json);
	void toJson();
	~CountryHouse();
};

