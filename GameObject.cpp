#include "GameObject.h"


GameObject::GameObject(const CellPosition & pos)
{
	position = pos; // Sets Position
}

CellPosition GameObject::GetPosition() const
{
	return position;
}

GameObject::~GameObject()
{
}
int GameObject::Num_Of_Laders = 0;

int GameObject::Num_Of_Snakes = 0;

int GameObject::Num_Of_Cardes = 0;

