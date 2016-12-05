// Uno Game - Made by Fayadh Ahamed

#include <iostream>
#include <time.h>
#include <memory>

// includes of headerfiles
#include "Bag.h"
#include "Stack.h"
#include "LinkedList.h"
#include "List.h"
#include "OrderedList.h"
#include "Queue.h"
#include "StandardFunctors.h"
#include "UnoCard.h"
#include "UnoGame.h"
#include "UnoPlayer.h"

using namespace std;
int main();




int main() {
	srand((unsigned int)time(NULL)); // needed for the bag
	int deckSize = 40; //DEFAULT DECK SIZE OF 40 FOR THIS GAME. 
	UnoGame myGame(deckSize, 3); // create the game
}

