#include "UnoPlayer.h"



UnoPlayer::UnoPlayer(string playerName, Queue<shared_ptr<UnoCard>> &Deck):m_playerName(playerName)
{
	for (int i = 0; i < 7; i++) {
		m_hand.insert(Deck.peek());
		Deck.dequeue();
	}
}


UnoPlayer::~UnoPlayer()
{
}

void UnoPlayer::printHand()
{
	for (int i = 1; i <= m_hand.getLength(); i++) {
		cout << "Card " << i << " is: " << *m_hand.retrieve(i) << "\n";
	}
}

void UnoPlayer::removeCard()
{
	m_hand.remove(1);
}

void UnoPlayer::addCard(shared_ptr<UnoCard> card)
{
	m_hand.insert(card);
}

bool UnoPlayer::oneCard()
{
	if (m_hand.getLength() == 1) {
		return true;
	}
	else return false;
}

bool UnoPlayer::checkWin()
{
	if (m_hand.isEmpty()) {
		return true; // return true if won
	}
	return false; // return true if not won
}

shared_ptr<UnoCard> UnoPlayer::peekHand(UnoCard &card)
{
	//cout << *m_hand.retrieve(1) << endl; 
	for (int i = 1; i <= m_hand.getLength(); i++) {
		if ((*m_hand.retrieve(i)).getRank() == card.getRank()) {
			return m_hand.retrieve(i);
		}
		if ((*m_hand.retrieve(i)).getColor() == card.getColor()) return m_hand.retrieve(i);
	}
	//return m_hand.retrieve(1);
	return m_hand.retrieve(1);
	
}


