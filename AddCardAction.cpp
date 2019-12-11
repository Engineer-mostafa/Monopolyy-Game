#include "AddCardAction.h"

#include "Input.h"
#include "Output.h"
#include "CardOne.h"
#include "CardNine.h"

AddCardAction::AddCardAction(ApplicationManager *pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

AddCardAction::~AddCardAction()
{

}

void AddCardAction::ReadActionParameters()
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	// 2- Read the "cardNumber" parameter and set its data member

	pOut->PrintMessage("New card: enter the card num ...");
	while (true) {
		cardNumber = pIn->GetInteger(pOut);

		// 4- Make the needed validations on the read parameters
		if (cardNumber<1 || cardNumber>14)
		{
			pOut->PrintMessage("Wrong CardNumber: Please Enter a Valid CardNumber Between 1:14 ");

			continue;
		}

		// 3- Read the "cardPosition" parameter (its cell position) and set its data member
		pOut->PrintMessage("New card: click on the cell...");
		cardPosition = pIn->GetCellClicked();
		// 5- Clear status bar
		pOut->ClearStatusBar();
		break;
	}
}

void AddCardAction::Execute()
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- The first line of any Action Execution is to read its parameter first
	ReadActionParameters();
	// 2- Switch case on cardNumber data member and create the appropriate card object type
	Card * pCard = NULL; // will point to the card object type
	switch (cardNumber)
	{
	case 1:
		pCard = new CardOne(cardPosition);
		break;
	case 9:
		pCard = new CardNine(cardPosition);
		break;
		// A- Add the remaining cases

	}
	// 3- if pCard is correctly set in the switch case (i.e. if pCard is pointing to an object -- NOT NULL)
	if (pCard)
	{
		// A- We get a pointer to the Grid from the ApplicationManager
		Grid* pGrid = pManager->GetGrid();
		// B- Make the "pCard" reads its card parameters: ReadCardParameters(), It is virtual and depends on the card type
		pCard->ReadCardParameters(pGrid);
		// C- Add the card object to the GameObject of its Cell:
		bool m = true;


		if (cardPosition.IsValidCell()) {
			m = pGrid->AddObjectToCell(pCard);
		}
		else
			m = false;

		// D- if the GameObject cannot be added in the Cell, Print the appropriate error message on statusbar
		if (!m) {
			pGrid->PrintErrorMessage("error: you can't add this card to this cell");
			pGrid->RemoveObjectFromCell(cardPosition);
			delete pCard;
			pCard = NULL;
		}

	}

	// Here, the card is created and added to the GameObject of its Cell, so we finished executing the AddCardAction

}