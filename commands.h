#pragma once
#include<iostream>
#include <cstring>
#include "Vector.h"
#include "Card.h"
#include "Deck.h"
#include "Player.h"

//function that push_back the computer defined players
void standartPlayers(Vector<Player>& player)
{
	Player p1("Petar Dimitrov", 30);
	player.push_back(p1);
	p1.setName("Ivan Goranov");
	p1.setAge(25);
	player.push_back(p1);
}

//function used to create and add to the list of players
void createPlayer(Vector<Player>& player, const char* choise)
{
	int age;
	Player temp(choise, 18);
	std::cout << "You successfully created new player " << choise << std::endl;
	do
	{
		std::cout << "Age of your new player: ";
		std::cin >> age;
	} while (18 > age || age > 90);
	temp.setAge(age);
	player.push_back(temp);
}

//function that choose a player or create a new player
Player& choose(Vector<Player>& player)
{

	char choise[64];
	std::cin.sync();
	std::cin.getline(choise, 64);
	int size = player.capacity();
	for (int i = 0; i < size; i++)
	{
		if (strcmp(choise, player[i].getName()) == 0)
		{
			return player[i];
		}
	}
	createPlayer(player, choise);
	return player[player.capacity() - 1];
}

//give name to the deck 
char* inputSerie()
{
	std::cout << "How to name your deck? (press enter for default)" << std::endl;
	std::cout << "$ ";
	char* deckSerie = new char[10];
	std::cin.get();
	std::cin.getline(deckSerie, 10);

	return deckSerie;
}

//creating deck
Deck createDeck(int numberOfCards)
{
	if (numberOfCards == 52)
	{
		Deck current;
		std::cout << "You successfully created default deck" << std::endl;
		return current;
	}
	char* txt = inputSerie();
	if(numberOfCards != 52 && strcmp(txt,"") == 0)
	{
		Deck current(numberOfCards);
		std::cout << "You successfully created custom deck" << std::endl;
		return current;
	}
	if (numberOfCards != 52 && strcmp(txt,""))
	{
		Deck current(numberOfCards, txt);
		std::cout << "You successfully created deck " << txt << std::endl;
		return current;
	}
}

//returns probability
double probability(Player& currentPlayer, Deck& current)
{
	double nCards = current.getNumberOfCards();
	switch (21 - currentPlayer.getCP())
	{
	case 1 : case 11: return (current.rank_count('A') / nCards); break;
	case 2: return (current.rank_count('2') / nCards); break;
	case 3: return (current.rank_count('3') / nCards); break;
	case 4: return (current.rank_count('4') / nCards); break;
	case 5: return (current.rank_count('5') / nCards); break;
	case 6: return (current.rank_count('6') / nCards); break;
	case 7: return (current.rank_count('7') / nCards); break;
	case 8: return (current.rank_count('8') / nCards); break;
	case 9: return (current.rank_count('9') / nCards); break;
	case 10: return ((current.rank_count('T')+
					 current.rank_count('J')+
					 current.rank_count('Q')+
		             current.rank_count('K')) / nCards); break;
	default: return 0;
	}
}

//draw a new card and adds it to the player's hand
void hit(Player& currentPlayer, Deck& current)
{
	size_t points = currentPlayer.getCP();
	Card newCard = current.draw();
	currentPlayer.addCards(newCard);
	if (newCard.getType() == 'A')
	{
		if (points > 11)
		{
			points += 1;
		}
		else
		{
			points += 11;
		}
	}
	else
	{
		points += newCard.getPower();
	}
	currentPlayer.setCP(points);
}

//players decision
int playDecision(Player& currentPlayer, Deck& current, bool& haveLost)
{
	std::cout << "Hit/Stand/Probability" << std::endl;
	char txt[15];
	std::cin>> txt;
	if (strcmp(txt, "Hit") == 0)
	{
		hit(currentPlayer, current);
		currentPlayer.showHand();
		std::cout << "Points: " << currentPlayer.getCP() << std::endl;
		if (currentPlayer.getCP() > 21)
		{
			haveLost = true;
			return 0;
		}
	}
	if (strcmp(txt, "Stand") == 0)
	{
		return 0;
	}
	if (strcmp(txt, "Probability") == 0)
	{
		std::cout << probability(currentPlayer, current) << std::endl;
	}

	return 1;
}

//win dialog function
void winDialog(Player& currentPlayer)
{
	std::cout << "You win! " << std::endl;
	currentPlayer.setWins(currentPlayer.getWins() + 1);
	currentPlayer.setGames(currentPlayer.getGames() + 1);
	currentPlayer.setWinsCoef((double)currentPlayer.getWins() / currentPlayer.getGames());
	currentPlayer.newHand();
}

//lose dialog function
void loseDialog(Player& currentPlayer)
{
	std::cout << "You lose!" << std::endl;
	currentPlayer.setGames(currentPlayer.getGames() + 1);
	currentPlayer.setWinsCoef((double)currentPlayer.getWins() / currentPlayer.getGames());
	currentPlayer.newHand();
}