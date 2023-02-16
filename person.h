#ifndef PERSON_H
#define PERSON_H
#include<string>
#include<memory>
#include<vector>
#include<iostream>
#include<map>
using namespace std;
class License;

class Person {
	std::string name;
	size_t wealth;
	std::map<std::string,std::unique_ptr<License>> licenses;
public:
	Person(std::string, size_t = 0);
	virtual ~Person() = default;
	void work(std::string);
	virtual void work(size_t) = 0;
	void increase_wealth(size_t);
	std::string get_name() const;
	bool pay_fee(size_t);
	void receive_license(std::unique_ptr<License>);
	void transfer_license(std::string, std::shared_ptr<Person>);
	bool eligible(std::string) const;
	virtual std::ostream& print(std::ostream& o) const;
	//ostream& print(ostream&) const;
};

class Worker : public Person {
public:
	Worker(string, size_t = 0);
	void work (size_t);
	ostream& print(ostream&) const;
};

class Superworker : public Person {
  size_t fee;
public:
	Superworker(size_t, string, size_t = 0);
	void work(size_t);
	ostream& print(ostream& o) const;
};


std::ostream& operator<<(std::ostream&, const Person&);

#endif
