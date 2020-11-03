#include <iostream>
#include "Card.h"
#include "Vector.h"	
#include "Deck.h"
#include "Player.h"
#include "commands.h"

int main()
{
	//initialise computer defined players
	Vector<Player> players;
	standartPlayers(players);
	bool haveLost = false;
	char option;
	int numberOfCards;
	std::cout << "Welcome to my BlackJack simulator!" << std::endl;
	do
	{
		//create or choose player
		std::cout << players;
		std::cout << "Choose a player or add a new player" << std::endl;
		std::cout << "$ ";
		Player& currentPlayer = choose(players);
		
		//create deck
		std::cout << "Choose size of the deck" << std::endl << "$ ";
		std::cin >> numberOfCards;
		Deck ingame (createDeck(numberOfCards)); 
		
		//player draw
		while (playDecision(currentPlayer, ingame, haveLost) != 0);
		
		//case if not lost by the time of the draw
		if (!haveLost)
		{
			Player dealer("Dealer", 35);
			//dealer draw
			while (true)
			{
				hit(dealer, ingame);
				//case dealer not lost but competing the player
				if (17 <= dealer.getCP() && dealer.getCP() <= 21)
				{
					std::cout << "Dealer's hand:" << std::endl;
					dealer.showHand();
					std::cout << "Dealer's points " << dealer.getCP() << std::endl;
					//case dealer wins
					if (dealer.getCP() > currentPlayer.getCP())
					{
						loseDialog(currentPlayer);
						break;
					}
					//case player wins
					else
					{
						winDialog(currentPlayer);
						break;
					}
				}
				//case dealer lost
				if (dealer.getCP() > 21)
				{
					std::cout << "Dealer's hand:" << std::endl;
					dealer.showHand();
					std::cout << "Dealer's points " << dealer.getCP() << std::endl;
					winDialog(currentPlayer);
					break;
				}
			}
		}
		//case if player have lost without dealer's draw
		else
		{
			loseDialog(currentPlayer);
		}

		//option to start a new game
		std::cout << "Do you want to start new game? (Y/N)" << std::endl << "$ ";
		std::cin >> option;
		std::cin.get();
	} while (option != 'N');
	std::cout << "Thanks for playing!" << std::endl;
}  
