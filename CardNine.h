#pragma once
#include "Card.h"

class CardNine : public Card
{
	int sCellNumber;    //Number that Instructs the player to go to a specific cell
public:

	CardNine(const CellPosition & pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid * pGrid); // Reads the parameters of CardOne which is: walletAmount

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardOne on the passed Player
			
	virtual void Save(ofstream &OutFile, int i, int Type);	// Saves the GameObject parameters to the file
	virtual void Load(ifstream &Infile);// by decrementing the player's wallet by the walletAmount data member
	~CardNine();
};

