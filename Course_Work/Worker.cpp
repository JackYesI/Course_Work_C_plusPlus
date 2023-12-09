#include "Worker.h"

Worker::Worker(const std::string& name, const std::string& passord)
{
	std::ifstream file("data_person.txt");
	file.seekg(0, std::ios::end);
	int count = file.tellg() / sizeof(Person);
	file.clear();
	file.seekg(0);
	Person pers;
	for (size_t i = 0; i < count; i++)
	{
		file.seekg(i * sizeof(Person));
		file.read(reinterpret_cast<char*>(&pers), sizeof(Person));
		data_person.push_back(pers);
	}
	file.close();

	auto it = std::find_if(data_person.begin(), data_person.end(), [passord, name](Person& book)
		{
			return (book.getName() == name and book.getPassword() == passord);
		});

	if (it != data_person.end())
	{
		this->person.setName((*it).getName());
		this->person.setPassword((*it).getPassword());
		this->enter = true;
	}
	else
		std::cout << "worker with such data not exist !!!\nTRY AGAIN :)\n";
}

void Worker::setEnter(const std::string& name, const std::string& passord)
{
	auto it = std::find_if(data_person.begin(), data_person.end(), [passord, name](Person& book)
		{
			return (book.getName() == name and book.getPassword() == passord);
		});

	if (it != data_person.end())
	{
		this->person.setName((*it).getName());
		this->person.setPassword((*it).getPassword());
		this->enter = true;
	}
	else
		std::cout << "worker with such data not exist !!!\nTRY AGAIN :)\n";
}

bool Worker::getEnter()
{
	return this->enter;
}

std::string Worker::getName()
{
	return std::string(this->person.getName());
}

std::string Worker::getPass()
{
	return std::string(this->person.getPassword());
}
