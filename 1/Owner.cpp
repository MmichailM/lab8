#include "Owner.h"
#include "Init.h"

Owner::Owner(string fullname, string INN) : fullname(fullname) {
	if (INN.size() != 12) throw invalid_argument("inn must have 12 digits");
	for (char i : INN) if (!isdigit(i)) throw invalid_argument("inn must have only digits");
	inn = INN;
}

string Owner::get_fullname() {
	return fullname;
}

string Owner::get_inn() {
	return inn;
}

vector<Property*> Owner::get_properties() {
	return properties;
}

void Owner::addProperty(Property* property) {
	properties.push_back(property);
}

void Owner::deleteProperty(size_t ind) {
	if (ind >= properties.size()) throw out_of_range("index out of range");
	else properties.erase(properties.begin() + ind);
}

double Owner::sumPropertyTaxes() {
	double taxes = 0.0;
	for (Property* i : properties) taxes += i->calculatePropertyTax();
	return taxes;
}

ostream& operator<<(ostream& out, Owner& o) {
	out << "Собственник: " << o.fullname << ", ИНН: " << o.inn << '\n';
	vector<Property*> vec = o.get_properties();
	for (Property* i : vec) out << '\t' << *i;
	return out;
}
