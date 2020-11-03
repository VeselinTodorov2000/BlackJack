#pragma once
#include<iostream>
#include "color.cpp"
class Card
{
private:
	color suite;
	char type;
	size_t power;
	char serialNumber[15];
	bool isDrawn;

public:
	//constructors
	Card();
	Card(int newColor, char value);
	Card(const Card& others);
	Card& operator=(const Card& others);

	//setters and getters
	size_t cardPower(char newType);

	void setSuite(color newSuite);
	color getSuite() const;

	void setType(char newType);
	char getType() const;

	int getPower() const;

	void setSerialNumber(const char* newSerial);
	const char* getSerialNumber() const;

	void setIsDrawn(bool newDrawn);
	bool getIsDrawn() const;

	void print();
	friend std::ostream& operator<<(std::ostream& out, Card current);
};

