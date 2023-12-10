#include <iostream>
#include <fstream>
#include <vector>
#include "Adress.h"
#include "Invoise.h"
#include "Self_service.h"
#include "Worker.h"
#include "System.h"
#include "Office.h"
#include "Exception_num.h"
using namespace std;


int main()
{
	//City out_city, in_city;
	//Adress out_adress, in_adress;


	//None_Pag none;
	//Pacage* pag = &none;

	//Invoise invoise("denus", "solomia", "Clothes", out_city, in_city, out_adress, in_adress, pag);

	///*invoise.Print();*/

	//Foreing_Invoice in(UA, YG, "denus", "solomia", "Clothes", out_city, in_city, out_adress, in_adress, pag);

	//std::vector<Invoise*> vec{ &invoise, &in };

	//for (size_t i = 0; i < vec.size(); i++)
	//{
	//	vec[i]->Print();
	//}


	/*std::ofstream file("data_person.txt");
	std::vector<Person> vec;
	Person Petro("Shydlovskyi Petro", "Aa151515*");
	Person Andriy("Zarichnyi Andrew", "Aa515151*");
	vec.push_back(Petro);
	vec.push_back(Andriy);
	file.write(reinterpret_cast<char*>(vec.data()), sizeof(Person) * vec.size());
	file.close();*/

	Worker petro("Shydlovskyi Petro", "Aa51515*");
	Worker Andriy("Zarichnyi Andrew", "Aa515151*");
	/*std::cout << petro.getEnter();
	
	System sys(petro);
	sys.createInvoise();
	sys.donePay();
	sys.closeInvoise();
	sys.printAll();
	sys.printId();*/
	/*Self_service sys;
	sys.createInvoise();*/

	std::string name = "Shydlovskyi Petro";
	/*sys.donePay();*/
	Office np_33(petro, 33);

	// Petro fault password
	np_33.Work();
	np_33.addWorkers(Andriy);
	// enter andriy with index 1 (you enter in sustem)
	np_33.Work();
	np_33.Cleaning(petro);

	// self-system work
	np_33.selfCreate();

	

	/*char s;

	do
	{
		s = _getch();
		int s_ = s;
		std::cout << s_ << std::endl;
	} while (true);*/

	/*std::cout << str_int("112f36") << std::endl;*/

}


