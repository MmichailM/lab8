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

double Owner::sumIncomeTaxes() {
	double taxes = 0.0;
	for (Property* i : properties) taxes += i->calculateIncomeTax();
	return taxes;
}

ostream& operator<<(ostream& out, Owner& o) {
	out << "Полное имя: " << o.fullname << ", ИНН: " << o.inn << '\n';
	vector<Property*> vec = o.get_properties();
	for (Property* i : vec) out << '\t' << *i;
	return out;
}

void Owner::fromJson(nlohmann::json j) {
	try {
		string fullname1 = j["fullname"];
		string inn1 = j["inn"];
		vector<Property*> properties1(j["properties"].size());
		string key;
		if (!j["properties"].is_array()) throw invalid_argument("incorrect file");
		for (int i = 0; i < properties1.size(); i++) {
			key = j["properties"][i].items().begin().key();
			properties1[i] = PropertySimpleFactory::getProperty(key);
			properties1[i]->fromJson(j["properties"][i]);
		}
		if (inn1.size() != 12) throw invalid_argument("inn must have 12 digits");
		for (char i : inn1) if (!isdigit(i)) throw invalid_argument("inn must have only digits");
		fullname = fullname1;
		inn = inn1;
		properties = properties1;
	}
	catch (exception) {
		throw invalid_argument("incorrect file");
	}
}

nlohmann::json Owner::toJson() {
	nlohmann::json j;
	j["fullname"] = fullname;
	j["inn"] = inn;
	j["sumtax"] = sumPropertyTaxes();
	for (int i = 0; i < properties.size(); i++) j["properties"][i] = properties[i]->toJson();
	return j;
}