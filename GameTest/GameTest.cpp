//------------------------------------------------------------------------
// GameTest.cpp
//------------------------------------------------------------------------
#include "stdafx.h"
//------------------------------------------------------------------------
#include <windows.h> 
#include <math.h>  
//------------------------------------------------------------------------
#include "app.h"
#include "AABB.h"

#include "GameBoard.h"
#include "Car.h"
#include "InputManager.h"
#include <vector>

Car * playercar;
GameBoard * gb = nullptr;
InputManager* im = nullptr;
AABB* exitLine = nullptr;
enum GameState
{
	RUNNING,
	WIN,
	LOST
} ;

GameState globalState = RUNNING;

void Init()
{
	Car::setSquareSize(750 / 6);
	gb = new GameBoard(6, 6, 750, 750);
	im = new InputManager(6, 6);

	/*
	//Easy Mode
	playercar = new Car(2, 0, 4, true, 1, 0, 0);
	Car * car1 = new Car(3, 3, 6, true, 0, 1, 0);
	Car * car2 = new Car(3, 4, 4, false, 0, 0, 1);
	Car * car3 = new Car(2, 2, 3, false, 0, 1, 1);
	Car * car4 = new Car(2, 3, 1, true, 1, 1, 0);

	im->cars.push_back(car1);
	im->cars.push_back(car2);
	im->cars.push_back(car3);
	im->cars.push_back(car4);
	im->cars.push_back(playercar);
	//*/
	///*
	//Hard Mode
	playercar = new Car(2, 1, 4, true, 1, 0, 0);
	Car * car1 = new Car(2, 0, 5, false, 1, 0.6f, 0);	//orange
	Car * car2 = new Car(2, 2, 6, false, 0, 1, 0);	//green
	Car * car3 = new Car(3, 3, 6, true, 1, 1, 0);	//yellow
	Car * car4 = new Car(3, 3, 5, false, 0.8, 0, 0.6);	//purple
	Car * car5 = new Car(2, 4, 5, true, 0, 0, 1);	//Cyan
	Car * car6 = new Car(2, 1, 3, false, 1, 0, 1);	//Magenta
	Car * car7 = new Car(2, 4, 3, true, 0, 0.2, 0.6);	//Dark blue
	Car * car8 = new Car(2, 0, 2, false, 0.2, 0.6, 0.2); //Dark green
	Car * car9 = new Car(2, 2, 2, true, 0.8, 0.6, 0);	//brown
	Car * car10 = new Car(2, 5, 2, false, 0.8, 0.6, 1);	//light purple
	Car * car11 = new Car(3, 1, 1, true, 0, 0, 1);	//blue
	
	im->cars.push_back(playercar);
	im->cars.push_back(car1);
	im->cars.push_back(car2);
	im->cars.push_back(car3);
	im->cars.push_back(car4);
	im->cars.push_back(car5);
	im->cars.push_back(car6);
	im->cars.push_back(car7);
	im->cars.push_back(car8);
	im->cars.push_back(car9);
	im->cars.push_back(car10);
	im->cars.push_back(car11);	
	//*/




	//the collision box for winning the game
	exitLine = new AABB();
	exitLine->x1 = 135 + gb->width - gb->hSquareLength;
	exitLine->x2 = 135 + gb->width;
	exitLine->y1 = 10 + (gb->vSquareLength * 3);
	exitLine->y2 = 10 + (gb->vSquareLength * 4);
}

void StartEndGame()
{
	im->GameOver();
}

void Update(float deltaTime)
{
	im->Update(deltaTime);
	if (areColliding(playercar->box, *exitLine)) 
	{
		StartEndGame();
		globalState = WIN;
	}
}

void Render()
{
	gb->Render();
	playercar->Render();
	for (auto car : im->cars)
	{
		car->Render();
	}
	im->Render();

	//draw the exit door;
	App::DrawLine(exitLine->x2,
		exitLine->y1,
		exitLine->x2,
		exitLine->y2, 1.0, 0, 0); 

	if (globalState == WIN)
	{
		App::Print(500, 400, "!!! YOU WIN !!!");
	}
}

void Shutdown()
{	
	delete gb;
	for (auto car : im->cars)
	{
		delete car;
	}
	delete im;
	delete playercar;
	delete exitLine;
}
