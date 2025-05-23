#include "Property.h"

Property::Property(size_t worth) : worth(worth) {}

size_t Property::get_worth() {
	return worth;
}

double Property::calculateIncomeTax() const {
	double percent = 0.13;
	return worth * percent;
}

ostream& operator<<(ostream& out, Property& pr) {
	pr.printProperty(out);
	return out;
}


Property::~Property() {}


