#pragma once
#include "card.h"
class CardEight :
	public Card
{
	int prevent[4];
public:
	CardEight(const CellPosition & pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid * pGrid); // Reads the parameters of CardOne which is: walletAmount

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardOne on the passed Player
													  // by decrementing the player's wallet by the walletAmount data member

	int IsPrevented(int playernum);
	virtual ~CardEight(); // A Virtual Destructor
};

