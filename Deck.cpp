#include "Deck.h"
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <cstring>

//function that creates serial num for every card
char* createSerial(const char* serie, int suite, char type)
{
	char* cardSerial = new char[15];
	size_t lnt = strlen(serie);
	for (int i = 0; i < lnt; i++)
	{
		cardSerial[i] = serie[i];
	}
	cardSerial[lnt] = suite + '0';
	cardSerial[lnt + 1] = type;
	cardSerial[lnt + 2] = 0;

	return cardSerial;
}

int Deck::getIndex(Card c)
{
	int ind = 0;
	switch (c.getType())
	{
	case 'A': ind += 0; break;
	case '2': ind += 1; break;
	case '3': ind += 2; break;
	case '4': ind += 3; break;
	case '5': ind += 4; break;
	case '6': ind += 5; break;
	case '7': ind += 6; break;
	case '8': ind += 7; break;
	case '9': ind += 8; break;
	case 'T': ind += 9; break;
	case 'J': ind += 10; break;
	case 'Q': ind += 11; break;
	case 'K': ind += 12; break;
	}
	ind *= 4;
	return (ind + c.getSuite());
}
//constructors
Deck::Deck()
{
	this->numberOfCards = 52;
	for (size_t i = 0; i < 52; i++)
	{
		this->timesInDeck[i] = 0;
	}
	this->fill();
	this->schuffle();
	char def[8] = "Default";
	for (size_t i = 0; i < 8; i++)
	{
		this->serie[i] = def[i];
	}
	for (int i = 0; i < numberOfCards; i++)
	{
		this->cards[i].setSerialNumber(createSerial("Default", cards[i].getSuite(), cards[i].getType()));
	}
}

Deck::Deck(int k)
{
	this->numberOfCards = 0;
	for (size_t i = 0; i < 52; i++)
	{
		this->timesInDeck[i] = 0;
	}
	for (int i = 0; i < k / 52; i++)
	{
		this->fill();
		this->numberOfCards += 52;
	}
	srand(time(NULL));
	do
	{
		size_t suite = rand() % 3;
		size_t value = rand() % 12;
		char symbol;
		if (this->timesInDeck[4 * value + suite] < ((k - 1) / 52) + 1)
		{
			switch (value+1) {
			case 1:  symbol = 'A'; break;
			case 2:  symbol = '2'; break;
			case 3:  symbol = '3'; break;
			case 4:  symbol = '4'; break;
			case 5:  symbol = '5'; break;
			case 6:  symbol = '6'; break;
			case 7:  symbol = '7'; break;
			case 8:  symbol = '8'; break;
			case 9:  symbol = '9'; break;
			case 10:  symbol = 'T'; break;
			case 11:  symbol = 'J'; break;
			case 12:  symbol = 'Q'; break;
			case 13:  symbol = 'K'; break;
			}
			Card newCard(suite, symbol);
			this->cards.push_back(newCard);
			numberOfCards++;
			this->timesInDeck[4 * value + suite]++;
		}
	} while (numberOfCards != k);
	this->schuffle();
	char def[7] = "Custom";
	for (size_t i = 0; i < 7; i++)
	{
		this->serie[i] = def[i];
	}
	for (int i = 0; i < numberOfCards; i++)
	{
		this->cards[i].setSerialNumber(createSerial(this->serie, cards[i].getSuite(), cards[i].getType()));
	}
}

Deck::Deck(int k, char* s)
{
	this->numberOfCards = 0;
	for (size_t i = 0; i < 52; i++)
	{
		this->timesInDeck[i] = 0;
	}
	for (int i = 0; i < k / 52; i++)
	{
		this->fill();
		this->numberOfCards += 52;
	}
	srand(time(NULL));
	do
	{
		size_t suite = rand() % 3;
		size_t value = rand() % 12;
		char symbol;
		if (this->timesInDeck[4 * value + suite] < ((k - 1) / 52) + 1)
		{
			switch (value + 1) {
			case 1:  symbol = 'A'; break;
			case 2:  symbol = '2'; break;
			case 3:  symbol = '3'; break;
			case 4:  symbol = '4'; break;
			case 5:  symbol = '5'; break;	
			case 6:  symbol = '6'; break;
			case 7:  symbol = '7'; break;
			case 8:  symbol = '8'; break;
			case 9:  symbol = '9'; break;
			case 10:  symbol = 'T'; break;
			case 11:  symbol = 'J'; break;
			case 12:  symbol = 'Q'; break;
			case 13:  symbol = 'K'; break;
			}
			Card newCard(suite, symbol);
			this->cards.push_back(newCard);
			numberOfCards++;
			this->timesInDeck[4 * value + suite]++;
		}
	} while (numberOfCards != k);
	this->schuffle();
	size_t size = strlen(s)+1;
	for (size_t i = 0; i < size; i++)
	{
		this->serie[i] = s[i];
	}
	for (int i = 0; i < numberOfCards; i++)
	{
		this->cards[i].setSerialNumber(createSerial(s, cards[i].getSuite(), cards[i].getType()));
	}
}

//setters and getters
const char* Deck::getSerie() const
{
	return this->serie;
}

void Deck::setSerie(const char* newSerie)
{
	strcpy_s(serie, strlen(newSerie) + 1, newSerie);
}

int Deck::getNumberOfCards() const
{
	return this->numberOfCards;
}

//print
void Deck::print()
{
	for (int i = 0; i < this->numberOfCards; i++)
	{
		this->cards[i].print();
	}
}

//fill
void Deck::fill()
{
	char symbol;
	for (int i = 0; i <= 12; ++i)
	{
		
		switch (i+1) {
		case 1:  symbol = 'A'; break;
		case 2:  symbol = '2'; break;
		case 3:  symbol = '3'; break;
		case 4:  symbol = '4'; break;
		case 5:  symbol = '5'; break;
		case 6:  symbol = '6'; break;
		case 7:  symbol = '7'; break;
		case 8:  symbol = '8'; break;
		case 9:  symbol = '9'; break;
		case 10:  symbol = 'T'; break;
		case 11:  symbol = 'J'; break;
		case 12:  symbol = 'Q'; break;
		case 13:  symbol = 'K'; break;
		}
		for (int n = 0; n <= 3; ++n)
		{
			Card newCard(n, symbol);
			cards.push_back(newCard);
			this->timesInDeck[4 * i + n]++;
		}
	}
}

//schuffle
void Deck::schuffle()
{
	srand(time(NULL));
	for (int i = 0; i < 200; i++)
	{
		int v1 = rand() % numberOfCards;
		int v2 = rand() % numberOfCards;
		swap(v1, v2);
	}
}

//swap
void Deck::swap(int fst, int snd)
{
	Card temp = this->cards[fst];
	this->cards[fst] = this->cards[snd];
	this->cards[snd] = temp;
}

//draw
Card Deck::draw()
{
	Card p (this->cards[0]);
	this->cards.pop_front();
	this->cards.push_back(p);
	this->timesInDeck[getIndex(p)]--;

	return p;
}


//used for probability
size_t Deck::suit_count(int test)
{
	size_t sum = 0;
	for (int i = test; i < 52; i += 4)
	{
		sum += (this->timesInDeck[i]);
	}
	return sum;
}

size_t Deck::rank_count(char test)
{
	int ind = 0, sum = 0;
	switch (test)
	{
	case 'A': ind = 0; break;
	case '2': ind = 1; break;
	case '3': ind = 2; break;
	case '4': ind = 3; break;
	case '5': ind = 4; break;
	case '6': ind = 5; break;
	case '7': ind = 6; break;
	case '8': ind = 7; break;
	case '9': ind = 8; break;
	case 'T': ind = 9; break;
	case 'J': ind = 10; break;
	case 'Q': ind = 11; break;
	case 'K': ind = 12; break;
	}
	for (size_t i = 0; i < 4; i++)
	{
		sum += this->timesInDeck[4 * ind + i];
	}
	return sum;
}
