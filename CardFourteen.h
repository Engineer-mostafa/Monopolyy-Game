#pragma once
# include"Card.h"
class CardFourteen : public Card
{
private:
	static int cardprice;
	static int fees;
	static  bool card_bought;
	static bool created_before;
	static bool IsSaved;
	static bool IsLoaded;
public:
	CardFourteen(const CellPosition & pos);
	CardFourteen();


	~CardFourteen(void);
	virtual void ReadCardParameters(Grid * pGrid);
	virtual void Save(ofstream &OutFile, int i, int Type);	// Saves the GameObject parameters to the file
	virtual void Load(ifstream &Infile, Grid *, int);// by decrementing the player's wallet by the walletAmount data member
	virtual void Apply(Grid* pGrid, Player* pPlayer);
};

