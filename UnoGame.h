#pragma once

// UnoGame Class.

#include "Bag.h"
#include "Stack.h"
#include "LinkedList.h"
#include "List.h"
#include "OrderedList.h"
#include "Queue.h"
#include "StandardFunctors.h"
#include "UnoCard.h"
#include "UnoPlayer.h"

class UnoGame
{
private:
	int m_deckSize;
	int m_noOfPlayers;
	Queue<shared_ptr<UnoCard>> m_myDeck;
	void makeFaceUpPile();
	Stack<shared_ptr<UnoCard>> m_faceUpPile;
	bool play = true;
	
public:
	UnoGame(int deckSize, int noOfPlayers);
	~UnoGame();
	void createDeck(Queue<shared_ptr<UnoCard>> &Deck, int m_deckSize);
	bool checkNum(UnoPlayer &player);
	bool checkColor(UnoPlayer &player);
	void drawDeck(UnoPlayer &player);
	bool emptyDeck(Queue<shared_ptr<UnoCard>> &deck, Stack<shared_ptr<UnoCard>> &faceUpPile);
	void checkUno(UnoPlayer &player);
	bool checkWin(UnoPlayer &player);
	bool playerTurn(UnoPlayer &player);
	

};

