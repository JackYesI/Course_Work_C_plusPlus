#include "System.h"

bool System::isIn()
{
    return this->worker.getEnter();
}

void System::read()
{
	std::ifstream file("data_np.txt");
	file.seekg(0, std::ios::end);
	int count = file.tellg() / sizeof(Invoise);
	file.clear();
	file.seekg(0); 
	Invoise invoise;
	for (size_t i = 0; i < count; i++)
	{
		file.seekg(i * sizeof(Invoise));
		file.read(reinterpret_cast<char*>(&invoise), sizeof(Invoise));
		data_np.push_back(invoise);
	}
	file.close();
}

void System::write()
{
	std::ofstream file("data_np.txt", std::ios::trunc);
	for (auto i : data_np)
	{
		file.write(reinterpret_cast<char*>(&i), sizeof(Invoise));
	}
	file.close();
}

void System::writeClose(Invoise invoise)
{
	std::ofstream file("data_close.txt", std::ios::app);
	file.write(reinterpret_cast<char*>(&invoise), sizeof(Invoise));
	file.close();
}

bool System::isEnter()
{
	return this->worker.getEnter();
}

System::System(const Worker& worker)
{
	this->worker = worker;
	this->read();
}

System::System(const std::string& name, const std::string& password)
{
	this->worker.setEnter(name, password);
	this->read();
}

void System::ENTER(const Worker& worker)
{
	this->worker = worker;
}

void System::createInvoise()
{
	if (!isEnter())
	{
		std::cout << "You are't enter\n";
		return;
	}
	int choise = 0;
	std::cout << "coise invoise 1) internet;\t2) default;";
	std::cin >> choise;
	switch (choise)
	{
	case 1:
	{
		Self_service::createInvoise();
		this->read();
		break;
	}
	case 2:
	{
		char out_name[20], in_name[20], description[20];
		City out_city, in_city;
		Adress out_adress, in_adress;
		Pacage* box;
		std::cout << "What type of pacage need (1 - box / 2 - pag) :: ";
		int choise_;
		std::cin >> choise_;
		switch (choise_)
		{
		case 1: 
		{
			std::cout << "Choose box 0.5, 1, 2, 5, 10, 15, 20, 30 :: ";
			std::cin >> choise_;
			Box pag(static_cast<Pacage_Name>(choise_));
			box = &pag;
			break;
		}
		case 2:
		{
			std::cout << "Choose pag 2, 4 :: "; std::cin >> choise_;
			Pag pag(static_cast<Pacage_Name>(choise_));
			box = &pag;
			break;
		}
		default:
			None_Pag pag;
			box = &pag;
			break;
		}

		size_t num;
		std::cout << "Enter out name    :: "; std::cin.ignore(); std::cin.getline(out_name, 20);
		std::cout << "Enter in name     :: "; std::cin.ignore(); std::cin.getline(in_name, 20);
		std::cout << "Enter description :: "; std::cin.ignore(); std::cin.getline(description, 20);
		out_city.set();
		in_city.set();
		out_adress.setName_street();
		std::cout << "Enter number of post (out) :: ";
		std::cin >> num;
		out_adress.setNumber_np(num);
		std::cout << "Enter number of street (out) :: ";
		std::cin >> num;
		out_adress.setNumber_street(num);
		in_adress.setName_street();
		std::cout << "Enter number of post (in) :: ";
		std::cin >> num;
		in_adress.setNumber_np(num);
		std::cout << "Enter number of street (in) :: ";
		std::cin >> num;
		in_adress.setNumber_street(num);
		Invoise invoise(std::string(out_name), std::string(in_name), std::string(description), out_city, in_city, out_adress, in_adress, box);
		invoise.Print();
		Self_service::write(invoise);
		data_np.push_back(invoise);
		break;
	}
	default:
		break;
	}
}

void System::editInvoise()
{
	if (!isEnter())
	{
		std::cout << "You are't enter\n";
		return;
	}
	size_t id;
	std::cout << "Enter id of Invoise :: ";
	std::cin >> id;

	auto it = std::find_if(data_np.begin(), data_np.end(), [id](const Invoise& book)
		{
			return (book.getId() == id);
		});

	if (it != data_np.end())
	{
		std::cout << "What you want to edit:\n1) out name;\n2) in name;\n3) in city;\n4) in adress\n";
		int choice;
		std::cin >> choice;
		switch (choice)
		{
		case 1:
		{
			char name[20]{ '\0' };
			std::cout << "Enter new out name :: "; std::cin.ignore(); std::cin.getline(name, 20);
			(*it).setOut_name(std::string(name));
			break;
		}
		case 2:
		{
			char name[20]{ '\0' };
			std::cout << "Enter new in name :: "; std::cin.ignore(); std::cin.getline(name, 20);
			(*it).setIn_name(std::string(name));
			break;
		}
		case 3:
		{
			City in_city;
			in_city.set();
			(*it).setIn_city(in_city);
			break;
		}
		case 4:
		{
			Adress in_adress;
			size_t num;
			in_adress.setName_street();
			std::cout << "Enter new num Nova Post :: ";
			std::cin >> num;
			in_adress.setNumber_np(num);
			std::cout << "Enter new num of street :: ";
			std::cin >> num;
			in_adress.setNumber_street(num);
			break;
		}
		default:
			std::cout << "Exit\n";
			break;
		}
		this->write();
	}
	else
		std::cout << "do't find that invoise (on ID)\n";
}

void System::donePay()
{
	if (!isEnter())
	{
		std::cout << "You are't enter\n";
		return;
	}
	size_t id;
	std::cout << "Enter id of Invoise :: ";
	std::cin >> id;

	auto it = std::find_if(data_np.begin(), data_np.end(), [id](const Invoise& book)
		{
			return (book.getId() == id);
		});

	if (it != data_np.end()) {
		(*it).closeProce();
		this->write();
	}
	else
		std::cout << "do't find that invoise (on ID)\n";

	/*for (auto i : data_np)
	{
		if (i.getId() == id)
		{
			i.closeProce();
			break;
		}
	}*/
}

void System::closeInvoise()
{
	if (!isEnter())
	{
		std::cout << "You are't enter\n";
		return;
	}
	size_t id;
	std::cout << "Enter id of Invoise :: ";
	std::cin >> id;

	auto it = std::find_if(data_np.begin(), data_np.end(), [id](const Invoise& book)
		{
			return (book.getId() == id);
		});

	if (it != data_np.end())
	{
		if (!(*it).getPrice())
		{
			(*it).setSuccess();
			this->writeClose(*it);
			data_np.erase(it);
			this->write();
		}
		else
			std::cout << "Do't end this invoice because price is't equal to zero\n";
	}
	else
	{
		std::cout << "do't find that invoise (on ID)\n";
	}
}

void System::deleteInvoise()
{
	if (!isEnter())
	{
		std::cout << "You are't enter\n";
		return;
	}
	size_t id;
	std::cout << "Enter id of Invoise :: ";
	std::cin >> id;

	auto it = std::find_if(data_np.begin(), data_np.end(), [id](const Invoise& book)
		{
			return (book.getId() == id);
		});

	if (it != data_np.end())
	{
		data_np.erase(it);
		this->write();
	}
	else
		std::cout << "do't find that invoise (on ID)\n";
}

void System::printAll()
{
	if (!isEnter())
	{
		std::cout << "You are't enter\n";
		return;
	}
	for (auto i : data_np)
	{
		i.Print();
	}
}

void System::printId()
{
	if (!isEnter())
	{
		std::cout << "You are't enter\n";
		return;
	}
	for (auto i : data_np)
	{
		std::cout << " " << i.getId() << std::endl;
	}
}


