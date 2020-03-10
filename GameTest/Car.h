#pragma once
#include "app.h"
#include "AABB.h"
class Car
{
private:
	float colorR = 1.0f;
	float colorG = 1.0f;
	float colorB = 1.0f;
public:
	int size = 2; //number of squares car takes up

	//top left corner of car
	int x = 0;
	int y = 0;

	bool isHorizontal = true; //does the car lay horizontal or vertical

	AABB box;

	Car(int size, int mx, int my, bool isHoriz, float r, float g, float b);
	~Car();
	static void setSquareSize(int size);
	int getSquareSize();
	void Render();
	void getCorner(int* _x, int* _y);
	void UpdateAABB();
	
};

