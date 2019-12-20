#pragma once
# include"Action.h"
class NewGAction : public Action
{
public:
	NewGAction(ApplicationManager*);
	virtual ~NewGAction();
	virtual void Execute();
	virtual void ReadActionParameters();
};

