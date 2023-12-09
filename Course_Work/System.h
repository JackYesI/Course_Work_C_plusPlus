#pragma once
#include <iostream>
#include <algorithm>
#include <list>
#include"Self_service.h"
#include "Worker.h"

class System : public Self_service
{
	Worker worker;
	std::list<Invoise> data_np;
	bool isIn();
	void read();
	void write();
	void writeClose(Invoise invoise);
	bool isEnter();
public:
	System() = default;
	System(const Worker& worker);
	System(const std::string& name, const std::string& password);
	void ENTER(const Worker& worker);
	void createInvoise() override;
	void editInvoise();
	void donePay();
	void closeInvoise();
	void deleteInvoise();
	void printAll();
	void printId();
};

