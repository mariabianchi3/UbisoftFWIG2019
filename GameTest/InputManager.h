#pragma once
#include "app.h"
#include <vector>
#include "Car.h"
#include "AABB.h"
class InputManager
{
private:
	int rows = 0;
	int cols = 0;

	float timeDelay = 200.0f; //time delay for controller stick input

	Car* selected = nullptr; //currently selected car
	int index = 0; //Index for which car from list is selected

	bool gameOver = false;
	CSimpleSprite* m_sprite;
public:
	std::vector<Car*> cars; //list of cars to cycle through

	InputManager(int mrow, int mcol);
	~InputManager();
	void Update(float deltaTime);
	void Render();
	bool willCollide(AABB &box1);
	bool checkBorders(int i, bool isHorizonal);
	void GameOver();
};

