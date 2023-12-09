#pragma once
#include <iostream>
#include <fstream>
#include "Invoise.h"

const std::string FILE_SELF = "data_np.txt";

class Self_service
{
protected:
	void write(Invoise invoise);
public:
	virtual void createInvoise();
};

