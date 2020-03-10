#include "stdafx.h"
#include "GameBoard.h"

GameBoard::GameBoard(int rows, int columns, int mwidth, int mheight)
{
	numRows = rows;
	numCols = columns;
	width =  mwidth;
	height = mheight;
	hSquareLength = width / columns;
	vSquareLength = height / rows;	
}

GameBoard::~GameBoard()
{
}

void GameBoard::Render()
{
	App::DrawLine(135, 10, 135 + width, 10);
	App::DrawLine(135 + width, 10, 135 + width, 10 + height);
	App::DrawLine(135 + width, 760, 135, 10 + height);
	App::DrawLine(135, 10 + height, 135, 10);

	for (int i = 1; i < numCols; i++)
	{
		App::DrawLine(i * hSquareLength + 135, 10, i * hSquareLength + 135, 760); //col
	}
	
	for (int i = 1; i < numRows; i++)
	{
		App::DrawLine(135, i * vSquareLength + 10, 885, i * vSquareLength + 10); // row
	}
}
