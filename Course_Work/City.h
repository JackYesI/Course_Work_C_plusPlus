#pragma once
#include<iostream>
const int SIZE = 20;

class City
{
	char city[SIZE]{ "NoName" };
	char Region[SIZE]{ "NoRegion" };
public:
	std::string getCity() const;
	std::string getRegion() const;
	void set();
	void Print() const;
};

