#include "Office.h"

void Office::writeWorkers()
{
	std::ofstream file("data_person.txt", std::ios::app);
	file.write(reinterpret_cast<char*>(workers.data()), sizeof(Person) * workers.size());
	file.close();
}

Office::Office(const Worker& worker, const size_t& number)
{
	this->office_number = number;
	addWorkers(worker);
	this->system.ENTER(worker);
}

void Office::addWorkers(const Worker & worker)
{
	this->workers.push_back(worker);
}

void Office::Work()
{
	std::cout << "up - create Invoise;\tdown - edit Invoise;\t left - close;\t right - Enter;\t a - pay;\td - delete;\t Esc - exit;" << std::endl;
	char s;
	do
	{
		s = _getch();
		if (s == 72)
		{
			this->system.createInvoise();
		}
		else if (s == 97)
		{
			this->system.deleteInvoise();
		}
		else if (s == 80)
		{
			this->system.editInvoise();
		}
		else if (s == 100)
		{
			this->system.donePay();
		}
		else if (s == 75)
		{
			this->system.closeInvoise();
		}
		else if (s == 77)
		{
			this->system.ENTER(workers[0]);
		}
		/// printAll()
		/// printId()
	} while (s != 27);
}

void Office::Cleaning(Worker& worker)
{
	std::cout << worker.getName() << " is cleaning\n";
}

void Office::enterInSystem(std::string& name)
{
	auto it = std::find_if(workers.begin(), workers.end(), [name](Worker& worker) {
		return worker.getName() == name;
		});

	if (it != workers.end())
		(*it).setEnter(name, (*it).getPass());
}

void Office::exitOutSystem(std::string& name)
{
	auto it = std::find_if(workers.begin(), workers.end(), [name](Worker& worker) {
		return worker.getName() == name;
		});

	if (it != workers.end())
		(*it).setEnter(name, "");
}

void Office::selfCreate()
{
	this->system_self.createInvoise();
}


