#include "AddLadderAction.h"

#include "Input.h"
#include "Output.h"
#include "Ladder.h"

AddLadderAction::AddLadderAction(ApplicationManager *pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

AddLadderAction::~AddLadderAction()
{
}

void AddLadderAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the startPos parameter
	pOut->PrintMessage("New Ladder: Click on its Start Cell ...");
	startPos = pIn->GetCellClicked();

	// Read the endPos parameter
	pOut->PrintMessage("New Ladder: Click on its End Cell ...");
	endPos = pIn->GetCellClicked();



	///TODO: Make the needed validations on the read parameters



	// Clear messages
	pOut->ClearStatusBar();
}


// Execute the action
void AddLadderAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("Are You Sure You Need To Add Ladder ? Click 1 - 0 | YES = 1 || NO == 0");
	int i = pIn->GetInteger(pOut);
	if (i == 1) {
		// The first line of any Action Execution is to read its parameter first 
		// and hence initializes its data members
		ReadActionParameters();
		bool added = true;
		// Create a Ladder object with the parameters read from the user
		Ladder * pLadder = new Ladder(startPos, endPos);
		Grid * pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager

											// Add the card object to the GameObject of its Cell:
		if (startPos.GetCellNum() < endPos.GetCellNum() && startPos.HCell() == endPos.HCell() && startPos.IsValidCell() && endPos.IsValidCell()) {
			added = pGrid->AddObjectToCell(pLadder);
		}
		else
		{
			added = false;
		}

		// if the GameObject cannot be added
		if (!added)
		{

			// Print an appropriate message
			pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
			delete pLadder;
			pLadder = NULL;
		}
		// Here, the ladder is created and added to the GameObject of its Cell, so we finished executing the AddLadderAction
	}
	else
	{
		pOut->PrintMessage("You Just Cancelled The Add Ladder | Click To Continue...");
		pIn->GetCellClicked();
		pOut->ClearStatusBar();
		return;
	}

}
