#pragma once
# include"Card.h"
class CardTen : public Card
{
private:
	static int cardprice;
	static int fees;
	static  bool card_bought;
	static bool created_before;
	static bool IsSaved;
	static bool IsLoaded;
public:

	CardTen(const CellPosition & pos);
	CardTen();

	~CardTen(void);
	virtual void ReadCardParameters(Grid * pGrid);
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	virtual void Save(ofstream &OutFile, int i, int Type);	// Saves the GameObject parameters to the file
	virtual void Load(ifstream &Infile, Grid *, int);// by decrementing the player's wallet by the walletAmount data member

};


