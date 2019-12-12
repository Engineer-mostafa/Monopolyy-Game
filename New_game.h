#pragma once
# include"Action.h"
class New_game : public Action
{
public:
	New_game(ApplicationManager*);
	virtual ~New_game();
	virtual void Execute();
	virtual void ReadActionParameters();
};

