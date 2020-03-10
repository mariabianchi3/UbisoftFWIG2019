#pragma once
#include "app.h"
class GameBoard
{

public:
	int numRows = 0;
	int numCols = 0;
	int width = 750;
	int height = 750;
	int hSquareLength = 0;
	int vSquareLength = 0;

	GameBoard(int rows, int columns, int mwidth, int mheight);
	~GameBoard();

	void Render();


};

