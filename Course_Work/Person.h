#pragma once
#include <iostream>
#include <fstream>

class Person
{
	char name[20]{ '\0' };
	char password[20]{ '\0' };
public:
	Person() = default;
	Person(const std::string& name, const std::string& password);
	std::string getName();
	std::string getPassword();
	void setName(const std::string& name);
	void setPassword(const std::string& password);
};

