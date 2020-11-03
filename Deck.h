#pragma once
#include "Vector.h"
#include "Card.h"

class Deck
{
private:
	Vector<Card> cards;
	int numberOfCards;
	char serie[10];
	int timesInDeck[52];

public:
	//constructors
	int getIndex(Card c);
	Deck();
	Deck(int k);
	Deck(int k, char* s);

	//setter and getter
	const char* getSerie() const;
	void setSerie(const char* newSerie);
	
	int getNumberOfCards() const;
	//print deck
	void print();
	//create standart deck
	void fill();
	//swap random cards
	void schuffle();
	//change places of two cards
	void swap(int fst, int snd);
	//draw a card
	Card draw();
	
	//functions used for probability
	size_t suit_count(int test);
	size_t rank_count(char test);
};

