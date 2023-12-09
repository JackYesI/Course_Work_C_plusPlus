#include "Invoise.h"

Pacage* Invoise::getBox()
{
	return this->box;
}

size_t Invoise::getPrice()
{
	return this->price;
}

bool Invoise::getSuccess()
{
	return this->success;
}

size_t Invoise::getId() const
{
	return this->id;
}

void Invoise::setOut_name(const std::string& name)
{
	for (size_t i = 0; i < 20; i++)
	{
		if (i < name.length())
			this->out_name[i] = name[i];
		else
			this->out_name[i] = '\0';
	}
}

void Invoise::setIn_name(const std::string& name)
{
	for (size_t i = 0; i < 20; i++)
	{
		if (i < name.length())
			this->in_name[i] = name[i];
		else
			this->in_name[i] = '\0';
	}
}

void Invoise::setDescription(const std::string& name)
{
	for (size_t i = 0; i < 20; i++)
	{
		if (i < name.length())
			this->description[i] = name[i];
		else
			this->description[i] = '\0';
	}
}

void Invoise::setOut_city(const City& name)
{
	this->out_city = name;
}

void Invoise::setIn_city(const City& name)
{
	this->in_city = name;
}

void Invoise::setOut_adress(const Adress& name)
{
	this->out_adress = name;
}

void Invoise::setIn_adress(const Adress& name)
{
	this->in_adress = name;
}

void Invoise::setBox(Pacage* pag)
{
	this->box = pag;
}

void Invoise::setPrice()
{
	this->price = getBox()->getPacage_name() * 2 + 20 + getBox()->getWeight() * 5;
}

void Invoise::closeProce()
{
	this->price = 0;
}

void Invoise::setSuccess()
{
	if (getPrice() == 0)
		this->success = true;
	else
		std::cout << "Do't end tthis invoice because price is't equal to zero\n";
}

void Invoise::Print() const
{
	if (this->success != 1)
	{
		std::cout << "=================== Invoice ===================\n";
		std::cout << "Name out    :: " << this->out_name << std::endl;
		std::cout << "Description :: " << this->description << std::endl;
		std::cout << "City out    :: \n"; this->out_city.Print();
		std::cout << "Adress out  :: \n"; this->out_adress.Print();
		std::cout << "Name in     :: " << this->in_name << std::endl;
		std::cout << "City out    :: \n"; this->in_city.Print();
		std::cout << "Adress out  :: \n"; this->in_adress.Print();
		std::cout << "Price       :: " << this->price << std::endl;
		std::cout << "=================== Invoice ===================\n\n";
	}
	else
		std::cout << "Invoice close :(" << std::endl;
}

void Invoise::setId()
{
	std::ifstream file("ID.txt");
	file >> this->id;
	file.close();
	std::ofstream file_("ID.txt", std::ios::trunc);
	file_ << ++this->id;
	file_.close();
}

Invoise::Invoise(const std::string& out_name, const std::string& in_name, const std::string& description, const City& out_city, const City& in_city, const Adress& out_adress, const Adress& in_adress,Pacage* box)
{
	setId();
	setOut_name(out_name);
	setIn_name(in_name);
	setDescription(description);
	setOut_city(out_city);
	setIn_city(in_city);
	setOut_adress(out_adress);
	setIn_adress(in_adress);
	setBox(box);
	setPrice();
}

std::string Invoise::getOut_name()
{
	return std::string(this->out_name);
}

std::string Invoise::getIn_name()
{
	return std::string(this->in_name);
}

std::string Invoise::getDescription()
{
	return std::string(this->description);
}

City Invoise::getOut_city()
{
	return this->out_city;
}

City Invoise::getIn_city()
{
	return this->in_city;
}

Adress Invoise::getOut_adress()
{
	return this->out_adress;
}

Adress Invoise::getIn_adress()
{
	return this->in_adress;
}
