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
	this->system.read();
}

void Office::addWorkers(const Worker & worker)
{
	this->workers.push_back(worker);
}

void Office::Work()
{
	std::cout << "up - create Invoise;\tdown - edit Invoise;\t left - close;\t right - Enter;\t d - pay;\ta - delete;\tp - printAll\to - printId Esc - exit;" << std::endl;
	char s;
	do
	{
		s = _getch();
		if (s == 72)
		{
			try
			{
				this->system.createInvoise();
			}
			catch (Exception_num& ex)
			{
				ex.What();
			}
		}
		else if (s == 97)
		{
			try
			{
				this->system.deleteInvoise();
			}
			catch (Exception_num& ex)
			{
				ex.What();
			}
		}
		else if (s == 80)
		{
			try
			{
				this->system.editInvoise();
			}
			catch (Exception_num& ex)
			{
				ex.What();
			}
		}
		else if (s == 100)
		{
			try
			{
				this->system.donePay();
			}
			catch (Exception_num& ex)
			{
				ex.What();
			}
		}
		else if (s == 75)
		{
			try
			{
				this->system.closeInvoise();
			}
			catch (Exception_num& ex)
			{
				ex.What();
			}
		}
		else if (s == 77)
		{
			try
			{
				std::string index_;
				int index;
				std::cout << "Enter index workera :: ";
				std::cin >> index_;
				index = str_int(index_);
				if (index == -1) throw Exception_num("index No number");
				if (!(0 <= index and index < workers.size())) throw Exception_num("Index no in interwal");
				this->system.ENTER(workers[index]);
			}
			catch (Exception_num& ex)
			{
				ex.What();
			}
		}
		else if (s == 112)
		{
			this->system.printAll();
		}
		else if (s == 111)
		{
			this->system.printId();
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

	if (it != workers.end()) {
		(*it).setEnter(name, (*it).getPass());
		std::cout << "you in\n";
	}
		
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
	try
	{
		this->system_self.createInvoise();
	}
	catch (Exception_num& ex)
	{
		ex.What();
	}
}


