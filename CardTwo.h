#pragma once
#include "Card.h"

class CardTwo : public Card
{
	int vofincreament;    //This Number is value that will increase the wallet of passing player
public:

	CardTwo(const CellPosition & pos); // A Constructor takes card position
	CardTwo();
	virtual void ReadCardParameters(Grid * pGrid); // Reads the parameters of CardOne which is: walletAmount

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardOne on the passed Player
	virtual void Save(ofstream &OutFile, int i, int Type);	// Saves the GameObject parameters to the file
	virtual void Load(ifstream &Infile, Grid *, int);
	~CardTwo();
};
