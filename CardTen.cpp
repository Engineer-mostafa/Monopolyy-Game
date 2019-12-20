#include "CardTen.h"


CardTen::CardTen(const CellPosition & pos) : Card(pos)
{
	cardNumber = 10;


}

bool CardTen::card_bought = false;
bool CardTen::created_before = false;
int CardTen::cardprice = 0;
int CardTen::fees = 0;

CardTen::CardTen() 
{
	Num_Of_Cardes++;

}

void CardTen::Save(ofstream &OutFile, int i, int Type) {
	if (i == 0 && Type == 2)
		OutFile << Num_Of_Cardes << endl;

	if (Type == 2) {
		OutFile << GetCardNumber() << " " << position.GetCellNum() << " ";
		if (IsSaved) { OutFile << endl; }
		else
		{
			OutFile << cardprice << " " << fees << endl;
			IsSaved = true;
		}

	}
	return;

}
void CardTen::Load(ifstream &Infile, Grid *g, int r) {
	cardNumber = r;
	int cellnumber;
	CellPosition *c = new CellPosition;
	Infile >> cellnumber;
	position = c->GetCellPositionFromNum(cellnumber);
	if (IsLoaded) {}
	else
	{
		Infile >> cardprice;
		Infile >> fees;
		IsLoaded = true;
	}

	g->AddObjectToCell(this);
	Draw(g->GetOutput());
}
bool CardTen::IsSaved = false;
bool CardTen::IsLoaded = false;

CardTen::~CardTen(void)
{
	Num_Of_Cardes--;
	IsSaved = false;
	IsLoaded = false;


}

void CardTen::ReadCardParameters(Grid * pGrid)
{
	if (created_before == false)
	{
		Output* pOut = pGrid->GetOutput();
		Input* pIn = pGrid->GetInput();
		pOut->PrintMessage("Plesae Entre Card 10 Fees :");
		fees = pIn->GetInteger(pOut);
		pOut->PrintMessage("Plesae Entre Card 10 Price :");
		cardprice = pIn->GetInteger(pOut);
		pOut->ClearStatusBar();
		Card::Draw(pOut);
		created_before = true;
	}

}


void CardTen::Apply(Grid* pGrid, Player*pPlayer)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	if (card_bought == true)
	{
		if (pPlayer->get_card10_owner() == false)
		{
			pOut->PrintMessage("Sorry! You Will Pay Card 10 Fees To Pass | Click To Continue...");
			pIn->GetCellClicked();
			pOut->ClearStatusBar();

			pPlayer->SetWallet((pPlayer->GetWallet()) - fees);

		}

	}
	else
	{
		Card::Apply(pGrid, pPlayer);
		pOut->ClearStatusBar();
		pOut->PrintMessage("Now You On Card 10 And No One Bought This Card Do You Want To Buy This Card ? Click 1 - 0 | YES = 1 || NO == 0");
		int i = pIn->GetInteger(pOut);
		if (i == 1) {
			pPlayer->SetWallet((pPlayer->GetWallet()) - cardprice);
			pOut->PrintMessage("Congratulations | You Have Just Bought card 10 | Click To Continue... ");
			pIn->GetCellClicked();
			pOut->ClearStatusBar();
			pPlayer->set_card10_owner(true);
			card_bought = true;
		}
	}



}

