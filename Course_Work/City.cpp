#include "City.h"

std::string City::getCity() const
{
    return std::string(this->city);
}

std::string City::getRegion() const
{
    return std::string(this->Region);
}

void City::set()
{
    std::cout << "Enter how city named           :: "; std::cin.ignore(); std::cin.getline(this->city, SIZE);
    std::cout << "Enter how region of city named :: "; std::cin.ignore(); std::cin.getline(this->Region, SIZE);
}

void City::Print() const
{
    std::cout << "City   :: " << this->getCity() << std::endl;
    std::cout << "Region :: " << this->getRegion() << std::endl;
}
