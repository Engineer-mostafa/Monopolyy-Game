#pragma once
# include"Action.h"
class Input_Dice_Action : public Action
{
private: int num;  CellPosition pos;
public:
	Input_Dice_Action(ApplicationManager*);
	virtual ~Input_Dice_Action();
	virtual void Execute();
	virtual void ReadActionParameters();

};

