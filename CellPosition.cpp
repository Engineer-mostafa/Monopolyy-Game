#include "CellPosition.h"
#include "UI_Info.h"

CellPosition::CellPosition () 
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1; 
	hCell = -1; 
}

CellPosition::CellPosition (int v, int h)
{ 
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1; 
	hCell = -1; 

	SetVCell(v);
	SetHCell(h);
}

CellPosition::CellPosition (int cellNum)
{
	(*this) = GetCellPositionFromNum(cellNum); // the function call with build a cell position (vCell and hCell)
												// from the passed (cellNum)
												// (*this) = ... --> this will copy the returned (vCell and hCell)
												//                   to the data members (vCell and hCell)
}

bool CellPosition::SetVCell(int v) 
{
	///TODO: Implement this function as described in the .h file (don't forget the validation)
if(v>-1 && v<9)
{
	vCell=v;
	return true;
}

	return false; // this line sould be changed with your implementation
}

bool CellPosition::SetHCell(int h) 
{
	///TODO: Implement this function as described in the .h file (don't forget the validation)
if(h>-1 && h<11)
{
	hCell=h;
	return true;
}

	return false; // this line sould be changed with your implementation
}

int CellPosition::VCell() const 
{
	if(IsValidCell())
	return vCell;

	return -1;
}

int CellPosition::HCell() const 
{
	if(IsValidCell())
	return hCell;

	return -1;
}

bool CellPosition::IsValidCell() const 
{
	///TODO: Implement this function as described in the .h file
if(vCell>-1 && hCell>-1) 
	return true;

	return false; // this line sould be changed with your implementation
}

int CellPosition::GetCellNum() const
{

	return GetCellNumFromPosition(*this); // (*this) is the calling object of GetCellNum
										  // which means the object of the current data members (vCell and hCell)
}

int CellPosition::GetCellNumFromPosition(const CellPosition & cellPosition)
{int cellnum;
	// Note:
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)
	// just define an integer that represents cell number and calculate it using the passed cellPosition then return it

	///TODO: Implement this function as described in the .h file
int a,k;
  
   
   a=8-cellPosition.VCell();
   k=a+1;
   cellnum= cellPosition.HCell() + (11*k-10);

   if(cellPosition.IsValidCell())
	   return cellnum;
	

	return 0; // this line should be changed with your implementation
}

CellPosition CellPosition::GetCellPositionFromNum(int cellNum)
{
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)

	CellPosition position;

	/// TODO: Implement this function as described in the .h file

	  int x,y,a,k;
  //insert the sell number
 a=cellNum/11;

 if(cellNum%11==0)
 a--;

 y=8-a;
 k=a+1;
 x= cellNum-(11*k-10);

 position.SetHCell(x);
 position.SetVCell(y);
 
	// Note: use the passed cellNum to set the vCell and hCell of the "position" variable declared inside the function
	//       I mean: position.SetVCell(...) and position.SetHCell(...) then return it




	return position;
}

void CellPosition::AddCellNum (int addedNum)
{int newcellnum;
	
	/// TODO: Implement this function as described in the .h file

	newcellnum=GetCellNum()+addedNum;

		  int a,k;
  //insert the sell number
 a=newcellnum/11;

 if(newcellnum%11==0)
 a--;

 vCell=8-a;
 k=a+1;
 hCell= newcellnum-(11*k-10);


	// Note: this function updates the data members (vCell and hCell) of the calling object

}