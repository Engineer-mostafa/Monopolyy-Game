#include "PasteCardAction.h"

#include "Input.h"
#include "Output.h"
#include "CardOne.h"


PasteCardAction::PasteCardAction(ApplicationManager *pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

PasteCardAction::~PasteCardAction()
{
}

void PasteCardAction::ReadActionParameters()
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	// 2- Read the "cardPosition" parameter (its cell position) and set its data member

	pOut->PrintMessage("Paste card: Click On The Cell ...");
	cardPosition = pIn->GetCellClicked();
	// 3- Make the needed validations on the read parameters


	// 4- Clear status bar
	pOut->ClearStatusBar();
}

void PasteCardAction::Execute()
{

	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==
	pOut->PrintMessage("Are You Sure You Need To Past Card ? Click 1 - 0 | YES = 1 || NO == 0");
	int i = pIn->GetInteger(pOut);
	if (i == 1) {
		// 1- The first line of any Action Execution is to read its parameter first
		ReadActionParameters();
		// 2- Switch case on cardNumber data member and create the appropriate card object type
		Card * pCard = new Card(cardPosition); // will point to the card object type
											   // A- We get a pointer to the Grid from the ApplicationManager
		Grid* pGrid = pManager->GetGrid();
		if (pGrid->GetClipboard())
			*pCard = *(pGrid->GetClipboard());

		// A- Add the remaining cases



		// 3- if pCard is correctly set in the switch case (i.e. if pCard is pointing to an object -- NOT NULL)
		if (pGrid->GetClipboard())
		{
			// A- We get a pointer to the Grid from the ApplicationManager
			Grid* pGrid = pManager->GetGrid();
			// B- Make the "pCard" reads its card parameters: ReadCardParameters(), It is virtual and depends on the card type
			pCard->SetPosition(cardPosition);
			// C- Add the card object to the GameObject of its Cell:
			bool m = pGrid->AddObjectToCell(pCard);
			Output* pOut = pGrid->GetOutput();
			// D- if the GameObject cannot be added in the Cell, Print the appropriate error message on statusbar
			if (!m) pOut->PrintMessage("error: you can't add this card to this cell");

		}

		// Here, the card is created and added to the GameObject of its Cell, so we finished executing the AddCardAction
	}
	else
	{
		pOut->PrintMessage("You Just Cancelled The Past Card | Click To Continue...");
		pIn->GetCellClicked();
		pOut->ClearStatusBar();
		return;
	}

}

