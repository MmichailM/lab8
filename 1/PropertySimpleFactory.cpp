#include "PropertySimpleFactory.h"

Property* PropertySimpleFactory::getProperty(string key) {
    if (key == "Apartment") return new Apartment();
    else if (key == "Car") return new Car();
    else if (key == "CountryHouse") return new CountryHouse();
}
