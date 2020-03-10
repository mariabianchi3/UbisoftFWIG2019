#include "stdafx.h"
#include "Car.h"

static int SquareSize;

Car::Car(int msize, int mx, int my, bool isHoriz, float r, float g, float b)
{
	size = msize;
	x = mx;
	y = my;
	isHorizontal = isHoriz;
	colorR = r;
	colorG = g;
	colorB = b;
	UpdateAABB();
}

Car::~Car()
{
}

void Car::setSquareSize(int size)
{
	SquareSize = size;
}

void Car::Render()
{
	if (isHorizontal) 
	{
		App::DrawLine(135 + x * SquareSize + 10, 
			10 + y * SquareSize - 10, 
			135 + (x + size) * SquareSize - 10,
			10 + y * SquareSize - 10, 
			colorR, colorG, colorB);
		App::DrawLine(135 + x * SquareSize + 10,
			10 + (y - 1) * SquareSize + 10,
			135 + (x + size) * SquareSize - 10,
			10 + (y - 1) * SquareSize + 10, 
			colorR, colorG, colorB);
		App::DrawLine(135 + x * SquareSize + 10,
			10 + y * SquareSize - 10,
			135 + x * SquareSize + 10,
			10 + (y - 1) * SquareSize + 10, 
			colorR, colorG, colorB);
		App::DrawLine(135 + (x + size) * SquareSize - 10,
			10 + y * SquareSize - 10,
			135 + (x + size) * SquareSize - 10,
			10 + (y - 1) * SquareSize + 10, 
			colorR, colorG, colorB);
	}
	else
	{
		App::DrawLine(135 + x * SquareSize + 10,
			10 + y * SquareSize - 10,
			135 + x * SquareSize + 10,
			10 + (y - size) * SquareSize + 10, 
			colorR, colorG, colorB);
		App::DrawLine(135 + (x + 1) * SquareSize - 10,
			10 + y  * SquareSize - 10,
			135 + (x + 1) * SquareSize - 10,
			10 + (y - size) * SquareSize + 10, 
			colorR, colorG, colorB);
		App::DrawLine(135 + x * SquareSize + 10,
			10 + y * SquareSize - 10,
			135 + (x + 1) * SquareSize - 10,
			10 + y * SquareSize - 10, 
			colorR, colorG, colorB);
		App::DrawLine(135 + x  * SquareSize + 10,
			10 + (y - size) * SquareSize + 10,
			135 + (x + 1) * SquareSize - 10,
			10 + (y - size) * SquareSize + 10, 
			colorR, colorG, colorB);
	}
}
//get coordinates for top left corner of car
void Car::getCorner(int* _x, int* _y)
{
	*_x = 135 + x * SquareSize;
	*_y = 10 + y * SquareSize;
}

void Car::UpdateAABB()
{
	int mx = 0;
	int my = 0;
	
	getCorner(&mx, &my);
	box.x1 = mx + 10;
	box.y1 =  isHorizontal ? my - SquareSize : my - (SquareSize * size);

	box.x2 = isHorizontal ? mx + (SquareSize * size) : mx + SquareSize;
	box.y2 = my - 10;

	box.x2 -= 10;
	box.y1 += 10;
	/*Note: The collision box is shrunk to allow cars to move side by side */
}

int Car::getSquareSize()
{
	return SquareSize;
}
