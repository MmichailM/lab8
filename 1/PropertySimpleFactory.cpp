#include "PropertySimpleFactory.h"

Property* PropertySimpleFactory::getProperty(string key) {
    Property* pr;
    if (key == "Apartment") (Apartment*) pr;
    else if (key == "Car") (Car*) pr;
    else if (key == "CountryHouse") (CountryHouse*) pr;
    return pr;
}
