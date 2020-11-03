#include "Card.h"
#include <iostream>
#include <cstring>


//default constructor
Card::Card()
{
	this->setSuite(Hearts);
	this->setType('K');
	this->setIsDrawn(false);
}

//user defined constructor
Card::Card(int newColor, char value)
{
	switch (newColor)
	{
	case 0: this->setSuite(Hearts); break;
	case 1: this->setSuite(Spades); break;
	case 2: this->setSuite(Diamonds); break;
	case 3: this->setSuite(Clubs); break;
	}
	
	this->setType(value);
	this->power = cardPower(this->type);
	this->setIsDrawn(false);
}

//copy constructor
Card::Card(const Card& others)
{
	this->setSuite(others.suite);
	this->setType(others.type);
	this->setSerialNumber(others.serialNumber);
	this->setIsDrawn(others.isDrawn);
	this->power = cardPower(others.type);
}

//operator=
Card& Card::operator=(const Card& others)
{
	if (this != &others)
	{
		this->setSuite(others.suite);
		this->setType(others.type);
		this->setSerialNumber(others.serialNumber);
		this->setIsDrawn(others.isDrawn);
		this->power = cardPower(others.type);
	}
	return *this;
}

//assign power
size_t Card::cardPower(char newType)
{
	if (newType == 'A') return 11;
	if (newType == 'T' || newType == 'J' || newType == 'Q' || newType == 'K') return 10;
	else return newType - '0';
}

//setters and getters
void Card::setSuite(color newSuite)
{
	this->suite = newSuite;
}

color Card::getSuite() const
{
	return this->suite;
}

void Card::setType(char newType)
{
	this->type = newType;
}

char Card::getType() const
{
	return this->type;
}

int Card::getPower() const
{
	return this->power;
}

void Card::setSerialNumber(const char* newSerial)
{
	strcpy_s(this->serialNumber, strlen(newSerial) + 1, newSerial);
}

const char* Card::getSerialNumber() const
{
	return this->serialNumber;
}

void Card::setIsDrawn(bool newDrawn)
{
	this->isDrawn = newDrawn;
}

bool Card::getIsDrawn() const
{
	return this->isDrawn;
}
//output
void Card::print()
{
	std::cout << this->type << "(";
	switch (this->suite)
	{
	case Hearts: std::cout << "Hearts"; break;
	case Spades: std::cout << "Spades"; break;
	case Diamonds: std::cout << "Diamonds"; break;
	case Clubs: std::cout << "Clubs"; break;
	}
	std::cout << ")  SN:"<< this->serialNumber << std::endl;
}

std::ostream& operator<<(std::ostream& out, Card current)
{
	current.print();
	return out;
}