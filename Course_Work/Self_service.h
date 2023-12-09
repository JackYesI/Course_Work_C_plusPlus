#pragma once
#include <iostream>
#include <fstream>
#include "Invoise.h"
#include "Foreing_Invoice.h"

const std::string FILE_SELF = "data.txt";

class Self_service
{
	void write(Invoise* invoise);
public:
	virtual void createInvoise();
};

