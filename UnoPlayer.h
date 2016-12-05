#pragma once
#include <iostream>
#include "OrderedList.h"
#include "UnoCard.h"
#include <memory>
#include "Queue.h"
#include <string.h>
using namespace std;

// player classssss
// this nigg needs the hands

class MyFunctorDeRef {
public:
	static bool compare(const shared_ptr<UnoCard>& a, const shared_ptr<UnoCard>& b) {
		if (a->getRank() != b->getRank()) {
			if (a->getRank() < b->getRank()) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			if (a->getColor() < b->getColor()) {
				return true;
			}
			else {
				return false;
			}

		}
	}
};

class UnoPlayer
{
private:
	string m_playerName;
	OrderedList<shared_ptr<UnoCard>, MyFunctorDeRef> m_hand;

public:
	UnoPlayer(string playerName, Queue<shared_ptr<UnoCard>> &Deck); // CONSTRUCTOR
	~UnoPlayer(); // DECONSTRUCTOR
	void printHand(); // prints current hand of player
	void removeCard();
	void addCard(shared_ptr<UnoCard> card);
	bool oneCard();
	bool checkWin();
	string getName() { return m_playerName; }

	shared_ptr<UnoCard> peekHand(UnoCard &card);
};


