#include "Adress.h"

size_t Adress::getNumber_np() const
{
    return this->number_np;
}

size_t Adress::getNumberOfStreet() const
{
    return this->number_street;
}

std::string Adress::getName_street() const
{
    return std::string(this->name_street);
}

void Adress::setNumber_np(const size_t& number_np)
{
    this->number_np = number_np;
}

void Adress::setName_street()
{
    std::cout << "Enter new name of street :: "; std::cin.ignore(); std::cin.getline(this->name_street, SIZE_Adress);
}

void Adress::setNumber_street(const size_t& number_street)
{
    this->number_street = number_street;
}

void Adress::Print() const
{
    std::cout << "Name of street      :: " << this->getName_street() << std::endl;
    std::cout << "Number of street    :: " << this->getNumberOfStreet() << std::endl;
    std::cout << "Name of nova post   :: " << this->getNumber_np() << std::endl;
}


