#pragma once
#include "Apartment.h"
#include "Car.h"
#include "CountryHouse.h"

class PropertySimpleFactory {
public:
	static Property* getProperty(string key);
};

