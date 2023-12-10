#pragma once
#include <iostream>
#include<string>

int str_int(const std::string str);

class Exception_num
{
	std::string massage = "you are input no number :(";
public:
	Exception_num() = default;
	Exception_num(const std::string massage);
	void What();
};

