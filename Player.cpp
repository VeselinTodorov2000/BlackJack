#include "Player.h"
#include <cstring>

void Player::copy(const Player& others)
{
	this->setName(others.name);
	this->setAge(others.age);
	this->setWins(others.wins);
	this->setWinsCoef(others.winsCoef);
	this->setCP(others.currentPoints);
	this->setGames(others.gamesPlayed);
}

//constructors
Player::Player()
{
	this->setName("NO NAME");
	this->setAge(18);
	this->setGames(0);
	this->setWinsCoef(0);
	this->setCP(0);
	this->setWins(0);
}

Player::Player(const char* name, int newAge)
{
	this->setName(name);
	if (18 < newAge && newAge < 90)
	{
		this->setAge(newAge);
	}
	else 
	{ 
		this->setAge(18); 
	}
	this->setGames(0);
	this->setWinsCoef(0);
	this->setCP(0);
	this->setWins(0);
}

Player::Player(const Player& others)
{
	this->copy(others);
}

//operator =
Player& Player::operator=(const Player& others)
{
	if (this != &others)
	{
		this->copy(others);
	}
	return *this;
}

//setters and getters
const char* Player::getName() const
{
	return this->name;
}

void Player::setName(const char* newName)
{
	strcpy_s(this->name, strlen(newName)+1, newName);
}

int Player::getAge() const
{
	return this->age;
}

void Player::setAge(int newAge)
{
	this->age = newAge;
}

size_t Player::getWins() const
{
	return this->wins;
}

void Player::setWins(size_t cntWins)
{
	this->wins = cntWins;
}

double Player::getWinsCoef() const
{
	return this->winsCoef;
}

void Player::setWinsCoef(double newCoef)
{
	this->winsCoef = newCoef;
}

size_t Player::getCP() const
{
	return this->currentPoints;
}

void Player::setCP(size_t newCP)
{
	this->currentPoints = newCP;
}

size_t Player::getGames() const
{
	return this->gamesPlayed;
}

void Player::setGames(size_t newGames)
{
	this->gamesPlayed = newGames;
}

//show hand
void Player::showHand()
{
	this->hand.print();
}

//drawCards
void Player::addCards(const Card& newCard)
{
	this->hand.push_back(newCard);
}
//clear hand
void Player::newHand()
{
	this->hand.clear();
	this->setCP(0);
}

//input
std::istream& operator>>(std::istream& in, Player& others)
{
	std::cout << "Name: ";
	in.get();
	in.getline(others.name, 64);

	std::cout << "Age: ";
	in >> others.age;

	return in;
}

//output
std::ostream& operator<<(std::ostream& out, const Player& others)
{
	out << others.name << " " << others.wins << " " << others.winsCoef << std::endl;
	return out;
}
