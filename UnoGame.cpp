#include "UnoGame.h"
#include <memory>
#include <iostream>


void UnoGame::makeFaceUpPile()
{
	
	
	m_faceUpPile.push(m_myDeck.peek()); // place the card from the deck, onto the faceup pile
	cout << "Face Card: " << *m_faceUpPile.peek() << endl; // print out the facecard
	m_myDeck.dequeue(); // dequeue the card we just placed on the faceup pile

	cout << "The Face up pile is made\n";
}

UnoGame::UnoGame(int deckSize,int noOfPlayers):m_deckSize(deckSize), m_noOfPlayers(noOfPlayers)
{

	// make the game
	createDeck(m_myDeck, deckSize); // make the bag of cards
	//cout << ">>Size of the Deck: " << m_myDeck.size() << "\n";
	
	// print test
	/*r (int i = 0; i < 40; i++) {
		cout << *m_myDeck.peek() << "\n"; // peek at the top of the deck
		m_myDeck.dequeue(); // remove the top card, and repeat
	}*/

	// make the 3 player objects
	/*UnoPlayer player1("Fayadh", m_myDeck);
	UnoPlayer player2("John", m_myDeck);
	UnoPlayer player3("Kate", m_myDeck);*/ // this works totall fine..
	
	UnoPlayer *player[2];	// define an array of 3 player objects
	player[0] = new UnoPlayer("Fayadh", m_myDeck);
	player[1] = new UnoPlayer("John", m_myDeck);
	player[2] = new UnoPlayer("Kate", m_myDeck);

	// print out thier hands to test..
	cout << "Hand\n";
	//player1.printHand();

	// check deck size
	//cout << "Deck Size is: " << m_myDeck.size() << endl;

	//make faceup
	makeFaceUpPile();
	play = true;
	int turn = 1;
	while (play) {
		cout << "Turn: " << turn << "\n";
		cout << "--------------------------------------------------------------------\n";
		playerTurn(*player[0]);
		playerTurn(*player[1]);
		playerTurn(*player[2]);
		cout << "\n--------------------------------------------------------------------\n";
		turn++;
	}
	
	delete[] player; //delte the player objects

	// Not sure why this happens...
	
}


UnoGame::~UnoGame()
{
	
}

void UnoGame::createDeck(Queue<shared_ptr<UnoCard>>& Deck, int m_deckSize)
{
	Bag<shared_ptr<UnoCard>> bagOfCards(m_deckSize); // creates a bag of cards
	Color color[] = { RED, YELLOW, BLUE, GREEN };
	Rank rank[] = { R1, R2, R3, R4, R5 };


	//	cout << bagOfCards.getOne;
	for (int k = 0; k < 2; k++) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 5; j++) {
				bagOfCards.add(make_shared<UnoCard>(color[i], rank[j]));
			}
		}
	}

	// now put the cards into the queue
	while (!bagOfCards.isEmpty()) {
		Deck.enqueue(bagOfCards.getOne());
	}

	cout << "Deck has been Made\n";
	cout << "\n";
}

bool UnoGame::checkNum(UnoPlayer &player)
{
	//cout << "\nFace up: " << *m_faceUpPile.peek() << "\n"; // gives me faceup pile card
	//cout << "Players card is: " << *player.peekHand() << endl;
	// now I have these 2 unocard objects.. now to compare them!?!
	// need to compare values..
	// sooo

	if ((*m_faceUpPile.peek()).getRank() == (*player.peekHand(*m_faceUpPile.peek())).getRank()) {
		//cout << "\nHey its a match!";
		// place players card on the stack..
		cout << player.getName() << " Found a match! They Played " << *player.peekHand(*m_faceUpPile.peek()) << "\n";
		m_faceUpPile.push(player.peekHand(*m_faceUpPile.peek()));
		player.removeCard();
		//cout << "Players hand is now: \n";
		//player.printHand();
		//cout << "\n";
		//cout << "The Face Card is now: " << *m_faceUpPile.peek() << endl;
		return true;
	}
	else {
		//cout << "\n>Not a match" << endl;
		return false;
	}

	
}

bool UnoGame::checkColor(UnoPlayer &player)
{
	//cout << "\nFace up: " << *m_faceUpPile.peek() << "\n"; // gives me faceup pile card
	//cout << "Players card is: " << *player.peekHand() << endl;
	// now I have these 2 unocard objects.. now to compare them!?!
	// need to compare values..
	// sooo

	if ((*m_faceUpPile.peek()).getColor() == (*player.peekHand(*m_faceUpPile.peek())).getColor()) {
		//cout << "\nHey its a match!";
		// place players card on the stack..
		cout << player.getName() << " Found a match! They Played " << *player.peekHand(*m_faceUpPile.peek()) << "\n";
		m_faceUpPile.push(player.peekHand(*m_faceUpPile.peek()));
		player.removeCard();
		//cout << "Players hand is now: \n";
		//player.printHand();
		//cout << "\n";
		//cout << "The Face Card is now: " << *m_faceUpPile.peek() << endl;
		return true;
	}
	else {
		//cout << "\n> Color Not a match" << endl;
		return false;
	}
}

void UnoGame::drawDeck(UnoPlayer &player)
{
	//if both checkNum and checkColor fails, then draw a card from the deck, and give it to the player, then 
	// end turn.

	// check deck card
	//cout << m_myDeck.size() << "\n"; // should be 18 at this point!! - WORKS

	//cout << "The Deck card is: " << *m_myDeck.peek() << "\n";
	if (!m_myDeck.isEmpty()) {
		cout << player.getName() << " Did not find a match! They drew a card \n";
		player.addCard(m_myDeck.peek()); // add the deck card to player hand
		m_myDeck.dequeue(); // remove the added card from the deck
	}
	else {
		// repopulate the empty deck
		emptyDeck(m_myDeck, m_faceUpPile);
		
	}
	
	/*cout << "Players current hand is: \n";
	player.printHand();
	cout << "The Deck card is: " << *m_myDeck.peek() << "\n";*/

	// works like a charm awesome.

	
}

bool UnoGame::emptyDeck(Queue<shared_ptr<UnoCard>> &deck, Stack<shared_ptr<UnoCard>> &faceUpPile)
{
	if (deck.isEmpty()) {
		cout << "\nRepopulating the Deck!!\n";
		shared_ptr<UnoCard> topCard = faceUpPile.pop(); // assign topcard on faceup pile to var
		//cout << "The Top Card is now: " << *topCard << "\n";
		// 'pop' the card
		cout << "Top Card is: " << *topCard << endl;
		
		cout << "Size of faceup pile is: " << faceUpPile.size() << endl;
		
			//if (m_faceUpPile.size() == 0) empty = 0;
		for (int i = 0; i < faceUpPile.size(); i++) {
			deck.enqueue(faceUpPile.pop());
			cout << "In here!!";
		}
		faceUpPile.push(topCard);
		return 1;
	}
	return 0;
}

void UnoGame::checkUno(UnoPlayer &player)
{	
	if (player.oneCard()) {
		cout << player.getName() << " shouts UNOOO!\n";
	}
}

bool UnoGame::checkWin(UnoPlayer &player)
{
	if (player.checkWin()) {
		return true;
	}
	else return false;
}

bool UnoGame::playerTurn(UnoPlayer &player)
{
	int caseOf = 1;

	switch (play) {
	case 1: //cout << "Case 1\n";
			if (checkNum(player)) {
				break;
			}
	case 2: //cout << "\nCase 2\n";
		if (checkColor(player)) {
				break;
			}
	case 3: //cout << "\nCase 3\n";
			drawDeck(player); // drawdeck
			break;
	}

	// Now checkUno, and checkWin.
	checkUno(player);

	if (checkWin(player)) {
		cout << "Player has won: " << player.getName() << "\n";
		play = false;
		return false;
	}
	else return true;

}


