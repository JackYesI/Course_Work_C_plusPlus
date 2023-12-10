#include "Exception_num.h"

int str_int(const std::string str)
{
	int num = 0;
	size_t length = std::string(str).length();
	for (size_t i = 0; i < length; i++)
	{
		if (0 <= (int)str[i] - 48 and (int)str[i] - 48 <= 9)
			num += ((int)str[i] - 48) * (pow(10, length - 1) / pow(10, i));
		else
			return -1;
	}
	return num;
}

Exception_num::Exception_num(const std::string massage) :
	massage{ massage } {}

void Exception_num::What()
{
	std::cout << this->massage << std::endl;
}
