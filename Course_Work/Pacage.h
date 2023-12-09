#pragma once
#include <iostream>


enum Pacage_Name
{
	None = 0,
	box_2 = 2,
	box_5 = 5,
	box_10 = 10,
	box_15 = 15,
	box_20 = 20,
	box_30 = 30,
	pag_2 = 20,
	pag_4 = 40,
	box_0_5 = 50,
	box_1 = 1
};

class Pacage abstract
{
protected:
	Pacage_Name pacage_name = None;
	size_t length = 1;
	size_t weight = 1;
	size_t hight = 1;
	size_t wight = 1;
	virtual void setSize() = 0;
public:
	Pacage() = default;
	Pacage_Name getPacage_name() const
	{
		return this->pacage_name;
	}
	size_t getLenght() const
	{
		return this->length;
	}
	size_t getHight() const
	{
		return this->hight;
	}
	size_t getWeight() const
	{
		return this->weight;
	}
	size_t getWight() const
	{
		return this->wight;
	}
};

class Box : public Pacage
{
	void setSize() override
	{
		switch (this->pacage_name)
		{
		case box_2:
		{
			this->hight = 20;
			this->length = 20;
			this->wight = 20;
			this->weight = 2;
			break;
		}
		case box_5:
		{
			this->hight = 20;
			this->length = 25;
			this->wight = 30;
			this->weight = 5;
			break;
		}
		case box_10:
		{
			this->hight = 35;
			this->length = 40;
			this->wight = 29;
			this->weight = 10;
			break;
		}
		case box_15:
		{
			this->hight = 20;
			this->length = 40;
			this->wight = 35;
			this->weight = 15;
			break;
		}
		case box_20:
		{
			this->hight = 47;
			this->length = 40;
			this->wight = 43;
			this->weight = 20;
			break;
		}
		case box_30:
		{
			this->hight = 42;
			this->length = 40;
			this->wight = 70;
			this->weight = 30;
			break;
		}
		case box_0_5:
		{
			this->hight = 17;
			this->length = 12;
			this->wight = 10;
			this->weight = 1;
			break;
		}
		case box_1:
		{
			this->hight = 24;
			this->length = 17;
			this->wight = 10;
			this->weight = 1;
			break;
		}
		default:
			break;
		}
	}
public:
	Box(const Pacage_Name& name) 
	{
		this->pacage_name = name;
		this->setSize();
	}
};

class Pag : public Pacage
{
	void setSize() override
	{
		switch (this->pacage_name)
		{
		case pag_2:
		{
			this->hight = 20;
			this->length = 20;
			this->wight = 20;
			this->weight = 2;
			break;
		}
		case pag_4:
		{
			this->hight = 20;
			this->length = 20;
			this->wight = 30;
			this->weight = 4;
			break;
		}
		default:
			break;
		}
	}
public:
	Pag(const Pacage_Name& name)
	{
		this->pacage_name = name;
		this->setSize();
	}
};

class None_Pag : public Pacage
{
	void setSize() override
	{
		std::cout << "Enter lenght :: "; std::cin >> this->length;
		std::cout << "Enter hight  :: "; std::cin >> this->hight;
		std::cout << "Enter wight  :: "; std::cin >> this->wight;
		std::cout << "Enter weight :: "; std::cin >> this->weight;
	}
public:
	None_Pag()
	{
		this->setSize();
	}
};

