#include<string>
#include<memory>
#include<vector>
#include<iostream>
#include<map>
#include "license.h"
using namespace std;
License::License(std::string name, size_t salary): name{name}, salary{salary} {
	if(name.empty())
		throw std::runtime_error("Name cannot be empty");
	
	if(salary <= 0)
		throw std::runtime_error("Salary must be greather than 0");
}

std::string License::get_guildname() const {
	return name;
}

size_t License::get_salary() const {
	return salary;
}

bool License::valid() const{
	if (counter <= 3)
		return true;
	return false;
}

bool License::use() {
	if (!valid())
		return false;
	++counter;
	return true;
}

std::ostream& License::print(std::ostream& o) const {
	return o << '[' << "License for " << name << ", Salary: " << salary << ", Used: " << counter << ']';
}

std::ostream& operator<< (std::ostream& o, const License& l) {
	return l.print(o);
}
