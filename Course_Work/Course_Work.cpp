#include <iostream>
#include <fstream>
#include <vector>
#include "Adress.h"
#include "Invoise.h"
#include "Self_service.h"
#include "Worker.h"
#include "System.h"
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

	Worker petro("Shydlovskyi Petro", "Aa151515*");
	std::cout << petro.getEnter();
	
	System sys(petro);
	sys.createInvoise();
	sys.donePay();
	sys.closeInvoise();
	sys.printAll();
	sys.printId();
	/*Self_service sys;
	sys.createInvoise();*/


	/*sys.donePay();*/
}


