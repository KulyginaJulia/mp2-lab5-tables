#include "table.h"

//NodeTable
NodeTable::NodeTable() {
	name = "";
	element = new Polinom;
}

NodeTable::NodeTable(const NodeTable& r) {
	name = r.GetKey();
	element = new Polinom(*r.GetElement());
}

NodeTable::NodeTable(string name_, Polinom* elem) {
	name = name_;
	element = elem;
}

NodeTable& NodeTable::operator=(const NodeTable& r) {
	if (this == &r) {
		return *this;
	}
	name = r.GetKey();
	element = r.GetElement();
	return *this;
}

bool NodeTable::operator==(const NodeTable& r)
{
	return GetKey() == r.GetKey();
}

std::string NodeTable::GetKey() const {
	return name;
}
Polinom* NodeTable::GetElement() const {
	return element;
}