#pragma once
#include "Property.h"
#include <string>
#include <vector>
#include <iostream>
#include "PropertySimpleFactory.h"

using namespace std;

class Owner : public Ijsonio {
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
	void fromJson(nlohmann::json j);
	nlohmann::json toJson();
};

