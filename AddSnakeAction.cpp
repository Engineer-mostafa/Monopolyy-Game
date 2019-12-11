#include "AddSnakeAction.h"

#include "Input.h"
#include "Output.h"
#include "Snake.h"

AddSnakeAction::AddSnakeAction(ApplicationManager *pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

AddSnakeAction::~AddSnakeAction()
{
}

void AddSnakeAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the startPos parameter
	pOut->PrintMessage("New Snake: Click on its Start Cell ...");
	startPos = pIn->GetCellClicked();

	// Read the endPos parameter
	pOut->PrintMessage("New Snake: Click on its End Cell ...");
	endPos = pIn->GetCellClicked();



	///TODO: Make the needed validations on the read parameters



	// Clear messages
	pOut->ClearStatusBar();
}


// Execute the action
void AddSnakeAction::Execute()
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();
	bool added = true;
	// Create a Ladder object with the parameters read from the user
	Snake * pSnake = new Snake(startPos, endPos);
	Grid * pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager

										// Add the card object to the GameObject of its Cell:
	if (endPos.GetCellNum() < startPos.GetCellNum() && endPos.HCell() == startPos.HCell()) {
		added = pGrid->AddObjectToCell(pSnake);
	}
	else
		added = false;

	// if the GameObject cannot be added
	if (!added)
	{
		pGrid->RemoveObjectFromCell(startPos);
		// Print an appropriate message
		pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
		delete pSnake;
		pSnake = NULL;
	}
	// Here, the ladder is created and added to the GameObject of its Cell, so we finished executing the AddLadderAction

}
