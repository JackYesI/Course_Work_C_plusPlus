#pragma once
#include "Invoise.h"

enum Country
{
	UA = 1,
	Pl = 5,
	SL = 7,
	YG = 7,
	RU = 10
};

class Foreing_Invoice : public Invoise
{
	Country out_country = UA;
	Country in_country = Pl;
public:
	Foreing_Invoice() = default;
	Foreing_Invoice(const Country& out_country, const Country& in_country,const std::string& out_name, const std::string& in_name, const std::string& description, const City& out_city, const City& in_city, const Adress& out_adress, const Adress& in_adress, Pacage* box):
		out_country{out_country}, in_country{in_country}, Invoise(out_name, in_name, description, out_city, in_city, out_adress, in_adress, box)
	{
		Foreing_Invoice::setPrice();
	}
	void setPrice() override;
	Country getOut_country();
	Country getIn_country();
	void setOut_country(const Country& coun);
	void setIn_country(const Country& coun);
	void Print() const override;
};

