#pragma once
#include <iostream>
const int SIZE_Adress = 20;


class Adress
{
	size_t number_np = 0;
	char name_street[SIZE_Adress]{ "NoStreet" };
	size_t number_street = 0;
public:
	Adress() = default;
	Adress(const size_t& number_np, const size_t& number_street, const std::string& name_street) :
		number_np{ number_np }, number_street{ number_street }
	{
		for (size_t i = 0; i < SIZE_Adress; i++)
		{
			if (i < name_street.length())
				this->name_street[i] = name_street[i];
			else
				this->name_street[i] = '\0';
		}
	}
	size_t getNumber_np() const;
	size_t getNumberOfStreet() const;
	std::string getName_street() const;
	void setNumber_np(const size_t& number_np);
	void setName_street();
	void setNumber_street(const size_t& number_street);
	void Print() const;
};

