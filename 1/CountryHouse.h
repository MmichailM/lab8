#pragma once
#include "Property.h"
class CountryHouse : public Property {
protected:
	size_t distanceFromCity;
public:
	CountryHouse() : distanceFromCity(0), Property(0) {}
	CountryHouse(size_t worth, size_t distanceFromCity);
	size_t get_distance() const;
	double calculatePropertyTax() const;
	void printProperty(ostream& out);
	void fromJson(nlohmann::json json);
	nlohmann::json toJson();
	~CountryHouse();
};

