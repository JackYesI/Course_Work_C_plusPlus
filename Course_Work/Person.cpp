#include "Person.h"



Person::Person(const std::string& name, const std::string& password)
{
    setName(name);
    setPassword(password);
}

std::string Person::getName()
{
    return std::string(this->name);
}

std::string Person::getPassword()
{
    return std::string(this->password);
}

void Person::setName(const std::string& name)
{
    for (size_t i = 0; i < 20; i++)
    {
        if (i < name.length())
            this->name[i] = name[i];
        else
            this->name[i] = '\0';
    }
}

void Person::setPassword(const std::string& password)
{
    for (size_t i = 0; i < 20; i++)
    {
        if (i < password.length())
            this->password[i] = password[i];
        else
            this->password[i] = '\0';
    }
}
