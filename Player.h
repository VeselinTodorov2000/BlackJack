#pragma once
#include <iostream>
#include "Vector.h"
#include "Card.h"

class Player
{
private:
	//needed
	char name[64];
	int age;
	size_t wins;
	double winsCoef;
	size_t currentPoints;
	//added by me
	size_t gamesPlayed;
	Vector<Card> hand;
	void copy(const Player& others);

public:
	//constructors
	Player();
	Player(const char* name, int newAge);
	Player(const Player& others);
	Player& operator=(const Player& others);

	//setters and getters
	const char* getName() const;
	void setName(const char* newName);

	int getAge() const;
	void setAge(int newAge);

	size_t getWins() const;
	void setWins(size_t cntWins);

	double getWinsCoef() const;
	void setWinsCoef(double newCoef);

	size_t getCP() const;
	void setCP(size_t newCP);

	size_t getGames() const;
	void setGames(size_t newGames);

	//input and output
	friend std::istream& operator>>(std::istream& in, Player& others);
	friend std::ostream& operator<<(std::ostream& out, const Player& others);

	//print the player drawn cards
	void showHand();

	//draw a card
	void addCards(const Card& newCard);
	
	//empty the hand
	void newHand();
};

