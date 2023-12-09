#pragma once
#include <iostream>
#include <algorithm>
#include <conio.h>
#include <vector>
#include "Worker.h"
#include "System.h"

class Office
{
	size_t office_number;
	std::vector<Worker> workers;
	System system;
	Self_service system_self;
	void writeWorkers();
public:
	Office(const Worker& worker, const size_t& number);
	void addWorkers(const Worker& worker);
	void Work();
	void Cleaning(Worker& worker);
	void enterInSystem(std::string& name);
	void exitOutSystem(std::string& name);
	void selfCreate();
};

