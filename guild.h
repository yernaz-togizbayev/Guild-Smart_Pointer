#ifndef GUILD_H
#define GUILD_H

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <memory>
#include "person.h"
#include "license.h"

using namespace std;


class Guild {
	string name;
	size_t fee;
	size_t salary;
	map<string, shared_ptr<Person>> members;
public:
	Guild(string, size_t, size_t, const vector<shared_ptr<Person>>& = {});
	bool add_member(shared_ptr<Person>);
	bool remove_member(string);
	void grant_license(string);
	bool offer_job(shared_ptr<Person>) const;
	ostream& print(ostream&) const;
};

ostream& operator<<(ostream&, const Guild&);


#endif
