#include<string>
#include<memory>
#include<vector>
#include<iostream>
#include<stdexcept>
#include<set>
#include<algorithm>
#include<map>
#include "guild.h"
#include "license.h"
#include "person.h"

using namespace std;

Guild::Guild(string name, size_t fee, size_t sal, const vector<shared_ptr<Person>>& members): name{name}, fee{fee}, salary{sal} {
	if(name.empty())
		throw runtime_error("Name cannot be empty");
	
	if (fee <= 0)
		throw runtime_error("Fee must be greather than 0");
	
	if (salary <= 0)
		throw runtime_error("Salary must be greather than 0");
	
	for (auto& i : members) {
		size_t count{0};
		for (auto& j : members) {
			if (i == j)
				++count;
		}
		if (count > 1)
			throw runtime_error("This person is alredy in members");
		this->members.insert(make_pair(i->get_name(), i));
	}
}

bool Guild::add_member(shared_ptr<Person> p) {
	if(members.count(p->get_name()) == 0) {
		this->members[p->get_name()] = move(p);
		return true;
	}
	else return false;
}

bool Guild::remove_member(string n) {
	if(members.erase(n))
		return true;
	else return false;
}

void Guild::grant_license(string n) {
	if(members.count(n) == 0 || !(members[n]->pay_fee(fee)))
		throw runtime_error("Member is not in guild (fee is not enough");
	members[n]->receive_license(make_unique<License>(this->name, this->salary));
}

bool Guild::offer_job(shared_ptr<Person> p) const {
	if(members.count(p->get_name()) == 0) {
		if (p->eligible(this->name)) {
			p->work(name);
			return true;
		}
		else return false;
	}
	p->work(2*salary);
	return true;
}

ostream& Guild::print(ostream& o) const {
	o << '[' << name << ", License fee: " << fee << ", Job salary: " << salary << ", {";
	bool first{true};
	for (const auto& i : members) {
		if(first)
			first = false;
		else
			o << ", ";
		o << i.first;
	}
	o << "}]";
	return o;

}

ostream& operator<< (ostream& o, const Guild& g) {
	return g.print(o);
}
