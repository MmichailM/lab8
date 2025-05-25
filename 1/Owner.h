#pragma once
#include "Property.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Owner {
	string fullname;
	string inn;
	vector<Property*> properties;
public:
	Owner() : fullname(""), inn("") {}
	Owner(string fullname, string INN);
	string get_fullname();
	string get_inn();
	vector<Property*> get_properties();
	void addProperty(Property* property);
	void deleteProperty(size_t ind);
	double sumPropertyTaxes();
	friend ostream& operator<< (ostream& out, Owner& o);
};

