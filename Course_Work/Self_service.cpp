#include "Self_service.h"
#include "Exception_num.h"

void Self_service::write(Invoise invoise)
{
	std::ofstream file(FILE_SELF, std::ios::app);
	file.write(reinterpret_cast<char*>(&invoise), sizeof(Invoise));
	file.close();
}

void Self_service::createInvoise()
{
	char out_name[20], in_name[20], description[20];
	City out_city, in_city;
	Adress out_adress, in_adress;

	None_Pag pag;
	Pacage* box = &pag;

	std::string num = "";
	int num_;
	std::cout << "Enter out name    :: "; std::cin.ignore(); std::cin.getline(out_name, 20);
	std::cout << "Enter in name     :: "; std::cin.ignore(); std::cin.getline(in_name, 20);
	std::cout << "Enter description :: "; std::cin.ignore(); std::cin.getline(description, 20);
	out_city.set();
	in_city.set();
	out_adress.setName_street();
	std::cout << "Enter number of post (out) :: ";
	std::cin >> num;
	num_ = str_int(num);
	if (num_ == -1) throw Exception_num();
	out_adress.setNumber_np(num_);
	std::cout << "Enter number of street (out) :: ";
	std::cin >> num;
	num_ = str_int(num);
	if (num_ == -1) throw Exception_num();
	out_adress.setNumber_street(num_);
	in_adress.setName_street();
	std::cout << "Enter number of post (in) :: ";
	std::cin >> num;
	num_ = str_int(num);
	if (num_ == -1) throw Exception_num();
	in_adress.setNumber_np(num_);
	std::cout << "Enter number of street (in) :: ";
	std::cin >> num;
	num_ = str_int(num);
	if (num_ == -1) throw Exception_num();
	in_adress.setNumber_street(num_);
	Invoise invoise(std::string(out_name), std::string(in_name), std::string(description), out_city, in_city, out_adress, in_adress, box);
	invoise.Print();
	this->write(invoise);
}
