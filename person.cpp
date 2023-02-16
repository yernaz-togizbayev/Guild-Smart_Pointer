#include<string>
#include<memory>
#include<vector>
#include<iostream>
#include<map>
#include "person.h"
#include "license.h"

using namespace std;

Person::Person(string name, size_t wealth): name{name}, wealth{wealth} {
	if (name.empty())
		throw runtime_error("Name cannot be empty");
}

void Person::work(string guild) {
	for(const auto& i : licenses) {
		if(i.first == guild && i.second->valid()) {
			i.second->use();
			work(licenses.at(guild)->get_salary());
      return;
		}
	}
	throw runtime_error("Not valid");
}

void Person::increase_wealth(size_t i) {
	wealth += i;
}

string Person::get_name() const {
	return name;
}

bool Person::pay_fee(size_t i) {
	if(wealth < i || i == 0)
		return false;
	wealth -= i;
	return true;
}

void Person::receive_license(unique_ptr<License> l) {
	string guildname = l->get_guildname();
	licenses[guildname] = std::move(l);
}

void Person::transfer_license(string l, shared_ptr<Person> p){
  if(this->licenses.count(l) == 0)
    throw runtime_error("license not found in licenses");
	
  p->licenses[l] = move(this->licenses[l]);
  licenses.erase(l);
}

bool Person::eligible(string l) const {
	for (const auto& i : licenses) {
		if(i.first == l && i.second->valid())
			return true;
	}
	return false;
}

ostream& Person::print(ostream& o) const {
	o << name << ", " << wealth << " Coins, {";
	for (const auto& i : licenses)
		i.second->print(o);
	o << "}]";
	return o;
}

Worker::Worker(string worker_name, size_t worker_wealth) : Person(worker_name, worker_wealth) {}

void Worker::work(size_t i) {
	Person::increase_wealth(i);
}

ostream& Worker::print(ostream& o) const {
	o << "[Worker "; Person::print(o);
	return o;
}

Superworker::Superworker(size_t fee, string superworker_name, size_t superworker_wealth): Person(superworker_name, superworker_wealth), fee{fee} {}

void Superworker::work(size_t i) {
	Superworker::increase_wealth(i + fee);
}

ostream& Superworker::print(ostream& o) const {
	o << "[Superworker "; Person::print(o);
	return o;
}

ostream& operator<< (ostream& o, const Person& p) {
	return p.print(o);
}