#pragma once
#include"Card.h"
class CardEleven : public Card
{
private:
	static int fees;
	static int cardprice;
	static bool card_bought;
	static bool created_before;
	static bool IsSaves;
	static bool IsSaved;
	static bool IsLoaded;
public:
	CardEleven(const CellPosition & pos);
	CardEleven();

	~CardEleven(void);
	virtual void ReadCardParameters(Grid * pGrid);
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	virtual void Save(ofstream &OutFile, int i, int Type);	// Saves the GameObject parameters to the file
	virtual void Load(ifstream &Infile, Grid *, int);// by decrementing the player's wallet by the walletAmount data member
};

