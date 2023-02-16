#ifndef LICENSE_H
#define LICENSE_H
#include<string>
#include<memory>
#include<vector>
#include<iostream>
#include<map>
using namespace std;
class License {
	std::string name;
	size_t salary;
	size_t counter {0};
public:
	License(std::string, size_t);
	std::string get_guildname() const;
	size_t get_salary() const;
	bool valid() const;
	bool use();
	std::ostream& print(std::ostream&) const;
};

std::ostream& operator<<(std::ostream&, const License&);

#endif
