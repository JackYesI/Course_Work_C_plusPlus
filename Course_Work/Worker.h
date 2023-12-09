#pragma once
#include <iostream>
#include <algorithm>
#include <list>
#include "Person.h"


class Worker
{
	Person person;
	bool enter = false;
	std::list<Person> data_person;
public:
	Worker() = default;
	Worker(const std::string& name, const std::string& passord);
	void setEnter(const std::string& name, const std::string& passord);
	bool getEnter();
	std::string getName();
	std::string getPass();
};

