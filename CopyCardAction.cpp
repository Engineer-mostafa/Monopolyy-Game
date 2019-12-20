#include "CopyCardAction.h"

#include "Input.h"
#include "Output.h"
#include "CardOne.h"


CopyCardAction::CopyCardAction(ApplicationManager *pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

CopyCardAction::~CopyCardAction()
{
}

void CopyCardAction::ReadActionParameters()
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	// 2- Read the "cardPosition" parameter (its cell position) and set its data member

	pOut->PrintMessage("Copy card: Click On The Card ...");
	cardPosition = pIn->GetCellClicked();
	// 3- Make the needed validations on the read parameters


	// 4- Clear status bar
	pOut->ClearStatusBar();
}

void CopyCardAction::Execute()
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("Are You Sure You Need To Copy Card ? Click 1 - 0 | YES = 1 || NO == 0");
	int i = pIn->GetInteger(pOut);
	if (i == 1) {

		// == Here are some guideline steps (numbered below) to implement this function ==

		// 1- The first line of any Action Execution is to read its parameter first
		ReadActionParameters();
		// 2- Switch case on cardNumber data member and create the appropriate card object type
		Card * pCard = NULL;
		Grid* pGrid = pManager->GetGrid();
		Output* pOut = pGrid->GetOutput();

		///////////////////// validations
		if (cardPosition.IsValidCell())
		{


			pCard = new Card(cardPosition); // will point to the card object type
			if ((pGrid->IsOverlapping(pCard)))
				pGrid->SetClipboard(pCard);
			else
				pOut->PrintMessage("Error: There is No Card In This Cell | Click To Continue");
			pGrid->GetInput()->GetCellClicked();
			pGrid->GetOutput()->ClearStatusBar();
		}

		else
			pOut->PrintMessage("Error: There is No Card In This Cell | Click To Continue");
		pGrid->GetInput()->GetCellClicked();
		pGrid->GetOutput()->ClearStatusBar();


	}
	else
	{
		pOut->PrintMessage("You Just Cancelled The Copy Card | Click To Continue...");
		pIn->GetCellClicked();
		pOut->ClearStatusBar();
		return;
	}


}
