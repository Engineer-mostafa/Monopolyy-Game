#pragma once
# include"Action.h"

class to_design_mode :public Action
{
public:
	to_design_mode(ApplicationManager* pap);
	virtual ~to_design_mode(void);
	virtual void Execute();
	virtual void ReadActionParameters();
};

