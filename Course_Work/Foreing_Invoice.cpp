#include "Foreing_Invoice.h"

void Foreing_Invoice::setPrice()
{
	this->price = getBox()->getPacage_name() * 2 + 20 + getBox()->getWeight() * 5 + 100 * getIn_country();
}

Country Foreing_Invoice::getOut_country()
{
	return this->out_country;
}

Country Foreing_Invoice::getIn_country()
{
	return this->in_country;
}

void Foreing_Invoice::setOut_country(const Country& coun)
{
	this->out_country = coun;
}

void Foreing_Invoice::setIn_country(const Country& coun)
{
	this->in_country = coun;
}

void Foreing_Invoice::Print() const
{
	if (this->success != 1)
	{
		std::cout << "=================== Invoice ===================\n";
		std::cout << "Name out    :: " << this->out_name << std::endl;
		std::cout << "Description :: " << this->description << std::endl;
		std::cout << "Country out :: " << this->out_country << std::endl;
		std::cout << "City out    :: \n"; this->out_city.Print();
		std::cout << "Adress out  :: \n"; this->out_adress.Print();
		std::cout << "Name in     :: " << this->in_name << std::endl;
		std::cout << "Country in :: " << this->in_country << std::endl;
		std::cout << "City out    :: \n"; this->in_city.Print();
		std::cout << "Adress out  :: \n"; this->in_adress.Print();
		std::cout << "Price       :: " << this->price << std::endl;
		std::cout << "=================== Invoice ===================\n\n";
	}
	else
		std::cout << "Invoice close :(" << std::endl;
}


