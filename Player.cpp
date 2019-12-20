#include "Player.h"
#include"CardEight.h"
#include "GameObject.h"

Player::Player(Cell * pCell, int playerNum) : stepCount(0), wallet(100), playerNum(playerNum)
{
	this->pCell = pCell;
	this->turnCount = 0;
	card10_owner = false;   card11_owner = false;   card12_owner = false;   card13_owner = false;   card14_owner = false;

	// Make all the needed initialization or validations
}

// ====== Setters and Getters ======

void Player::SetCell(Cell * cell)
{
	pCell = cell;
}

Cell* Player::GetCell() const
{
	return pCell;
}

void Player::SetWallet(int wallet)
{
	this->wallet = wallet;
	// Make any needed validations
}

int Player::GetWallet() const
{
	return wallet;
}
void Player::set_turncount(int x)
{
	turnCount = x;
}
int Player::get_stepcount()
{
	return stepCount;
}
int Player::GetTurnCount() const
{
	return turnCount;
}

int Player::GetjustRolledDiceNum() const
{
	return justRolledDiceNum;
}

// ====== Drawing Functions ======

void Player::Draw(Output* pOut) const
{
	color playerColor = UI.PlayerColors[playerNum];
	pOut->DrawPlayer(pCell->GetCellPosition(), playerNum, playerColor);
	///TODO: use the appropriate output function to draw the player with "playerColor"

}

void Player::ClearDrawing(Output* pOut) const
{
	color cellColor = pCell->HasCard() ? UI.CellColor_HasCard : UI.CellColor_NoCard;
	pOut->DrawPlayer(pCell->GetCellPosition(), playerNum, cellColor);

	///TODO: use the appropriate output function to draw the player with "cellColor" (to clear it)

}

// ====== Game Functions ======

void Player::Move(Grid * pGrid, int diceNumber)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==


	// 1- Increment the turnCount because calling Move() means that the player has rolled the dice once
	turnCount++;

	//card eight condition
	if (pCell->GetGameObject())
		if (dynamic_cast<CardEight*>(pCell->GetGameObject()) && turnCount != 3)
		{
			CardEight* p8 = (CardEight*)pCell->GetGameObject();
			if (p8->IsPrevented(playerNum) == 1)
				diceNumber = 0;

		}


	//card eight condition
	if (pCell->GetGameObject())
		if (dynamic_cast<CardEight*>(pCell->GetGameObject()) && turnCount == 3)
		{
			CardEight* p8 = (CardEight*)pCell->GetGameObject();
			if (p8->IsPrevented(playerNum) == 1)
				diceNumber = 0;
			else
				p8->IsPrevented(playerNum);

		}
	
	if (turnCount == 3)
	{


		wallet += (10 * diceNumber);
		turnCount = 0;
		return;
	}

	justRolledDiceNum = diceNumber;
	CellPosition pos = pCell->GetCellPosition();
	ClearDrawing(pGrid->GetOutput());

	if ((pos.GetCellNum() + diceNumber) >= 99)
	{
		diceNumber = 99 - pos.GetCellNum();
		pGrid->SetEndGame(true);
		Output* pOut = pGrid->GetOutput();
		pOut->PrintMessage("Player Number " + to_string(playerNum) + " Has Won");
	}
	pos.AddCellNum(diceNumber);

	// 5- Use pGrid->UpdatePlayerCell() func to Update player's cell POINTER (pCell) with the cell in the passed position, "pos" (the updated one)
	//    the importance of this function is that it Updates the pCell pointer of the player and Draws it in the new position
	pGrid->UpdatePlayerCell(this, pos);
	// 6- Apply() the game object of the reached cell (if any)
	if (pCell->GetGameObject())
		(pCell->GetGameObject())->Apply(pGrid,this);
	// 7- Check if the player reached the end cell of the whole game, and if yes, Set end game with true: pGrid->SetEndGame(true)
	if (pos.GetCellNum()>99)
		pGrid->SetEndGame(true);
}





void Player::AppendPlayerInfo(string & playersInfo) const
{
	playersInfo += "P" + to_string(playerNum) + "(";
	playersInfo += to_string(wallet) + ", ";
	playersInfo += to_string(turnCount) + ")";
}

int Player::get_curr_player_num()
{
	return playerNum;
}
// ----------------------------getters and setters for card owners from (10->14)
void Player::set_card10_owner(bool owner)
{
	card10_owner = owner;
}
bool Player::get_card10_owner()
{
	return card10_owner;
}
void Player::set_card11_owner(bool owner)
{
	card11_owner = owner;
}
bool Player::get_card11_owner()
{
	return card11_owner;
}
void Player::set_card12_owner(bool owner)
{
	card12_owner = owner;
}
bool Player::get_card12_owner()
{
	return card12_owner;
}
void Player::set_card13_owner(bool owner)
{
	card13_owner = owner;
}
bool Player::get_card13_owner()
{
	return card13_owner;
}
void Player::set_card14_owner(bool owner)
{
	card14_owner = owner;
}
bool Player::get_card14_owner()
{
	return card14_owner;
}

