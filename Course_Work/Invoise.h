#pragma once
#include "City.h"
#include "Adress.h"
#include "Pacage.h"
#include <iostream>


class Invoise 
{
protected:
	char out_name[SIZE]{ '\0' };
	char in_name[SIZE]{ '\0' };
	char description[SIZE]{ '\0' };
	City out_city;
	City in_city;
	Adress out_adress;
	Adress in_adress;
	Pacage* box;
	bool success = false;
	size_t price = 0;
public:
	Invoise() = default;
	Invoise(const std::string& out_name, const std::string& in_name, const std::string& description, const City& out_city, const City& in_city, const Adress& out_adress, const Adress& in_adress, Pacage* box);
	std::string getOut_name();
	std::string getIn_name();
	std::string getDescription();
	City getOut_city();
	City getIn_city();
	Adress getOut_adress();
	Adress getIn_adress();
	Pacage* getBox();
	size_t getPrice();
	bool getSuccess();
	void setOut_name(const std::string& name);
	void setIn_name(const std::string& name);
	void setDescription(const std::string& name);
	void setOut_city(const City& name);
	void setIn_city(const City& name);
	void setOut_adress(const Adress& name);
	void setIn_adress(const Adress& name);
	void setBox( Pacage* pag);
	virtual void setPrice();
	void closeProce();
	void setSuccess();
	virtual void Print() const;
};

