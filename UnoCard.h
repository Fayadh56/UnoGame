#pragma once
#include <iostream>

// this class contains the unocards

// we need cards of ranks 1-5, and of suites: Red/Yellow/Blue/Green

enum Color { RED = 1, YELLOW = 2, BLUE = 3, GREEN = 4}; // COLORS
enum Rank { R1 = 1, R2 = 2, R3 = 3, R4 = 4, R5 = 5 };  // RANKS OF THE CARDS, CALLED RX WHERE X IS THE RANK

 class UnoCard
{
private:
	Color m_color;	
	Rank m_rank;
	// private storage of color, and rank
	// overloaded ostream or print cards
	friend std::ostream& operator<<(std::ostream& os, const UnoCard &uc);

public:
	UnoCard(Color color, Rank rank); // constructor
	~UnoCard(); // deconstructor
	inline Color getColor(void) const { return m_color; }
	inline Rank getRank(void) const { return m_rank; }
	char toCharColor(void); // returns a char that "describes" card's color
	char toCharRank(void); // returns a char that "describes" card's rank

};

// global operator functions comparing denominations of two cards
// The cards a and b are passed by reference
inline bool operator<(const UnoCard& a, const UnoCard& b) {	// < OPERATOR
	if (a.getColor() == b.getColor())
	{ 
		return (a.getRank() < b.getRank()); 
	}
	else {
		return (a.getColor() < b.getColor());
	}
}

inline bool operator>(const UnoCard& a, const UnoCard& b) { // > OPERATOR
	if (a.getColor() == b.getColor()) {
		return (a.getRank() > b.getRank());
	}
	else {
		return (a.getColor() > b.getColor());
	}
}

// checks equality of suits and denominations for two cards
inline bool operator==(UnoCard& a, UnoCard& b) { 

	return (a.getRank() == b.getRank() || a.getColor() == b.getColor()); 
}
