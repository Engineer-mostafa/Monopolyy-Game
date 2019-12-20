#include "CardEleven.h"


CardEleven::CardEleven(const CellPosition & pos) : Card(pos)
{
	cardNumber = 11;
}


bool CardEleven::card_bought = false;
bool CardEleven::created_before = false;
int CardEleven::cardprice = 0;
int CardEleven::fees = 0;

void CardEleven::Save(ofstream &OutFile, int i, int Type) {
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
void CardEleven::Load(ifstream &Infile, Grid *g, int r) {
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

bool CardEleven::IsSaved = false;
bool CardEleven::IsLoaded = false;

CardEleven::~CardEleven(void)
{
	Num_Of_Cardes--;
	IsSaved = false;
	IsLoaded = false;

}

void CardEleven::ReadCardParameters(Grid * pGrid)
{
	if (created_before == false)
	{
		Output* pOut = pGrid->GetOutput();
		Input* pIn = pGrid->GetInput();
		pOut->PrintMessage("Plesae Entre Card 11 Fees :");
		fees = pIn->GetInteger(pOut);
		pOut->PrintMessage("Plesae Entre Card 11 Price :");
		cardprice = pIn->GetInteger(pOut);
		pOut->ClearStatusBar();
		Card::Draw(pOut);
		created_before = true;
	}
}
CardEleven::CardEleven() {
	Num_Of_Cardes++;

}

void CardEleven::Apply(Grid* pGrid, Player* pPlayer)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	if (card_bought == true)
	{
		pOut->PrintMessage("Sorry! You Will Pay Card 11 Fees To Pass | Click To Continue...");
		pIn->GetCellClicked();
		pOut->ClearStatusBar();

		pPlayer->SetWallet((pPlayer->GetWallet()) - fees);

	}


	else
	{
		Card::Apply(pGrid, pPlayer);
		pOut->ClearStatusBar();
		pOut->PrintMessage("Now You On Card 11 And No One Bought This Card Do You Want To Buy This Card ? Click 1 - 0 | YES = 1 || NO == 0");
		int i = pIn->GetInteger(pOut);
		if (i == 1) 
		{
			pPlayer->SetWallet((pPlayer->GetWallet()) - cardprice);
			pOut->PrintMessage("Congratulations | You Have Just Bought card 11 | Click To Continue... ");
			pIn->GetCellClicked();
			pOut->ClearStatusBar();

			pPlayer->set_card11_owner(true);
			card_bought = true;
		}
	}
}
