#include "UnoCard.h"



UnoCard::UnoCard(Color color, Rank rank) : m_color(color), m_rank(rank)
{
	// constructor
}


UnoCard::~UnoCard()
{
	// destructor
}

char UnoCard::toCharColor() {
	// THIS RETURNS THE COLOR OF THE UNO CARD ITS CALLED ON. 
	if (m_color == RED) return 'R';
	else if (m_color == YELLOW) return 'Y';
	else if (m_color == BLUE) return 'B';
	else return 'G';
}

char UnoCard::toCharRank() {
	// THIS RETURNS THE RANK OF THE UNO CARD ITS CALLED ON.
	if (m_rank == R1) return '1';
	else if (m_rank == R2) return '2';
	else if (m_rank == R3) return '3';
	else if (m_rank == R4) return '4';
	else return '5';
}

std::ostream& operator <<(std::ostream& os, const UnoCard &uc) {
	int color = uc.getColor();
	int rank = uc.getRank();

	switch(color) {
	case 1:
		os << "A Red ";
		break;
	case 2:
		os << "A Yellow ";
		break;
	case 3:
		os << "A Blue ";
		break;
	case 4:
		os << "A Green ";
		break;

	default:
		os << "An Error Has Occured in the UnoCard Print Function";
	}

	os << rank;

	return os;

}