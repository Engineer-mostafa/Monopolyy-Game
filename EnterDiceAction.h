#pragma once
#include "action.h"
class EnterDiceAction :
	public Action
{

	int diceNumber;

public:
	EnterDiceAction(ApplicationManager *pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~EnterDiceAction();
};

