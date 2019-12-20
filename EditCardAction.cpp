#include "EditCardAction.h"

#include "Input.h"
#include "Output.h"
#include "CardOne.h"
#include "CardTwo.h"
#include "CardThree.h"
#include "CardFour.h"
#include "CardFive.h"
#include "CardSix.h"
#include "CardSeven.h"
#include"CardEight.h"
#include "CardNine.h"
#include"CardTen.h"
#include"CardEleven.h"
#include"CardTwelve.h"
#include"CardThirteen.h"
#include"CardFourteen.h"



EditCardAction::EditCardAction(ApplicationManager *pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

EditCardAction::~EditCardAction()
{
}

void EditCardAction::ReadActionParameters()
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	// 2- Read the "cardPosition" parameter (its cell position) and set its data member

	pOut->PrintMessage("Edit card: Click On The Card ...");
	cardPosition = pIn->GetCellClicked();
	pOut->ClearStatusBar();


}
void EditCardAction::Execute()
{

	ReadActionParameters();


	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pCard = pGrid->CurrentCard(cardPosition);
	int CN = pCard->GetCardNumber();
	switch (CN)
	{
	case 3:
		pOut->PrintMessage("Sorry! This Card Doesn't Take Any Parameters If You Want To Change It's Position Try Cut Or Copy | Click To Continue");
		pIn->GetCellClicked();
		pOut->ClearStatusBar();
		break;
	case 4:
		pOut->PrintMessage("Sorry! This Card Doesn't Take Any Parameters If You Want To Change It's Position Try Cut Or Copy | Click To Continue");
		pIn->GetCellClicked();
		pOut->ClearStatusBar();
		break;
	case 5:
		pOut->PrintMessage("Sorry! This Card Doesn't Take Any Parameters If You Want To Change It's Position Try Cut Or Copy | Click To Continue");
		pIn->GetCellClicked();
		pOut->ClearStatusBar();
		break;
	case 6:
		pOut->PrintMessage("Sorry! This Card Doesn't Take Any Parameters If You Want To Change It's Position Try Cut Or Copy | Click To Continue");
		pIn->GetCellClicked();
		pOut->ClearStatusBar();
		break;
	case 7:
		pOut->PrintMessage("Sorry! This Card Doesn't Take Any Parameters If You Want To Change It's Position Try Cut Or Copy | Click To Continue");
		pIn->GetCellClicked();
		pOut->ClearStatusBar();
		break;
	case 8:
		pOut->PrintMessage("Sorry! This Card Doesn't Take Any Parameters If You Want To Change It's Position Try Cut Or Copy | Click To Continue");
		pIn->GetCellClicked();
		pOut->ClearStatusBar();
		break;

	}
	if (pCard)
		pCard->ReadCardParameters(pGrid);
	else
		pOut->PrintMessage("This Cell Doesn't Have A Card");
}


