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

	ReadActionParameters();
	// Create a Ladder object with the parameters read from the user
	Snake * pSnake = new Snake(startPos, endPos);
	Grid * pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager

										// Add the card object to the GameObject of its Cell:
	Input* pIn = pGrid->GetInput();

	bool added = pGrid->AddObjectToCell(pSnake);
	if (startPos.HCell() != endPos.HCell())
	{
		pGrid->AddObjectToCell(pSnake);
		pGrid->PrintErrorMessage("Error: End Cell And Start Cell Are Not In The Same Column | Click To Continue...");
		pIn->GetCellClicked();
		pGrid->RemoveObjectFromCell(startPos);
	}
	if (startPos.GetCellNum() < endPos.GetCellNum()) {
		pGrid->AddObjectToCell(pSnake);
		pGrid->PrintErrorMessage("Error: Start Cell Cannot Be Smaller Than End Cell | Click To Continue...");
		pIn->GetCellClicked();
		pGrid->RemoveObjectFromCell(startPos);
	}

	// if the GameObject cannot be added
	if (!added)
	{
		// Print an appropriate message
		pGrid->PrintErrorMessage("Error: Cell already has an object Or You Clicked Invalid Cell! Click to continue ...");
		pGrid->RemoveObjectFromCell(startPos);
	}
	// Here, the ladder is created and added to the GameObject of its Cell, so we finished executing the AddLadderAction


}
