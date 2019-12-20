#include "ApplicationManager.h"

#include "Grid.h"
#include "AddLadderAction.h"
#include "AddSnakeAction.h"
#include "AddCardAction.h"
#include "CopyCardAction.h"
#include "EditCardAction.h"
#include "CutCardAction.h"
#include "PasteCardAction.h"
#include "RollDiceAction.h"
#include"DeleteGameObject.h"
#include "SaveGridAction.h"
#include "OpenGrid.h"
#include "Input_Dice_Action.h"
# include"to_design_mode.h"
#include "NewGAction.h"

///TODO: Add #include for all action types

ApplicationManager::ApplicationManager()
{
	// Create Input, output and Grid
	pOut = new Output();
	pIn = pOut->CreateInput();
	pGrid = new Grid(pIn, pOut);
}

////////////////////////////////////////////////////////////////////////////////////

ApplicationManager::~ApplicationManager()
{
	delete pGrid;
}

//==================================================================================//
//								Interface Management Functions						//
//==================================================================================//

Grid * ApplicationManager::GetGrid() const
{
	return pGrid;
}
Output* ApplicationManager::get_Pout() const
{
	return pOut;
}
Input* ApplicationManager::get_Pin() const
{
	return pIn;
}

void ApplicationManager::UpdateInterface() const
{
	pGrid->UpdateInterface();
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//

ActionType ApplicationManager::GetUserAction() const
{
	// Ask the input to get the action from the user.
	return pIn->GetUserAction();
}

////////////////////////////////////////////////////////////////////////////////////

// Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType  & ActType)
{
	Action* pAct = NULL;

	// According to Action Type, create the corresponding action object

	switch (ActType)
	{
	case ADD_LADDER:
		pAct = new AddLadderAction(this);
		break;

	case ADD_SNAKE:
		pAct = new AddSnakeAction(this);
		break;

	case ADD_CARD:
		// create an object of AddCardAction here
		pAct = new AddCardAction(this);
		break;

	case Exit:
		ActType = EXIT;
		break;


	case EXIT:
		break;


	case Copy_Card:
		// create an object of AddCardAction here
		pAct = new CopyCardAction(this);
		break;
	case Edit_Card:
		// create an object of AddCardAction here
		pAct = new EditCardAction(this);
		break;
	case Cut_Card:
		// create an object of AddCardAction here
		pAct = new CutCardAction(this);
		break;

	case Paste_Card:
		// create an object of AddCardAction here
		pAct = new PasteCardAction(this);
		break;

	case TO_PLAY_MODE:
		pOut->CreatePlayModeToolBar(); // temporary till you made its action class (CHANGE THIS LATTER)
		break;

	case ROLL_DICE:
		// create an object of RollDiceAction here
		pAct = new RollDiceAction(this);
		break;

	case TO_DESIGN_MODE:
		pOut->CreateDesignModeToolBar(); // temporary till you made its action class (CHANGE THIS LATTER)
		pAct = new to_design_mode(this);
		break;
	case Input_Dice_value:
		pAct = new Input_Dice_Action(this);
		break;
	case New_Game:
		pAct = new NewGAction(this);
		break;
	case Open_Grid:
		pAct = new OpenGrid(this);
		break;
	case Save_Grid:
		pAct = new SaveGridAction(this);
		break;
		///TODO: Add a case for EACH Action type in the Design mode or Play mode
	case Delete_Game_Object:
		pAct = new DeleteGameObject(this);
		break;


	case STATUS:	// a click on the status bar ==> no action
		return;
	}

	// Execute the created action
	if (pAct != NULL)
	{
		pAct->Execute(); // Execute
		delete pAct;	 // Action is not needed any more after executing ==> delete it
		pAct = NULL;
	}
}
