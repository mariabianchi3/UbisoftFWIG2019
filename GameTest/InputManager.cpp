#include "stdafx.h"
#include "InputManager.h"

InputManager::InputManager(int mrow, int mcol)
{
	m_sprite = App::CreateSprite(".\\TestData\\red_ball.bmp");
	m_sprite->SetPosition(50.0f, 100.0f);
	m_sprite->SetScale(0.5f);
	rows = mrow;
	cols = mcol;
}

InputManager::~InputManager()
{
	delete m_sprite;
}

void InputManager::Update(float deltaTime)
{
	if (!gameOver) {
		timeDelay -= deltaTime;

		if (selected == nullptr) {
			if (App::GetController().GetLeftThumbStickY() < -0.5f)
			{
				if (timeDelay <= 0)
				{
					index++;
					index = index % cars.size();//cycle through the list  of cars
					timeDelay = 200.0f;
				}
			}

			//cursor for showing currently selected car
			int x = 0;
			int y = 0;
			cars[index]->getCorner(&x, &y);
			m_sprite->SetPosition(x + 20, y - 20);

			if (App::GetController().CheckButton(XINPUT_GAMEPAD_A, true))
			{
				m_sprite->SetScale(0.25f);
				selected = cars[index];
			}
		}
		else
		{

			if (selected->isHorizontal)
			{
				if (App::GetController().GetLeftThumbStickX() > 0.5f)
				{
					if (timeDelay <= 0) {
						AABB testBox = selected->box;
						testBox.x1 += selected->getSquareSize();
						testBox.x2 += selected->getSquareSize();
						//check if selected car will collide with other cars or a wall
						if (!willCollide(testBox) &&
							checkBorders(selected->x + selected->size, selected->isHorizontal))
						{
							selected->x += 1;
							selected->UpdateAABB();
							int x = 0;
							int y = 0;
							selected->getCorner(&x, &y);
							m_sprite->SetPosition(x + 20, y - 20);
						}
						timeDelay = 200.0f;
					}
				}
				else if (App::GetController().GetLeftThumbStickX() < -0.5f)
				{
					if (timeDelay <= 0) {
						AABB testBox = selected->box;
						testBox.x1 -= selected->getSquareSize();
						testBox.x2 -= selected->getSquareSize();
						//check if selected car will collide with other cars or a wall
						if (!willCollide(testBox) &&
							checkBorders(selected->x, selected->isHorizontal))
						{
							selected->x -= 1;
							selected->UpdateAABB();
							int x = 0;
							int y = 0;
							selected->getCorner(&x, &y);
							m_sprite->SetPosition(x + 20, y - 20);
						}
						timeDelay = 200.0f;
					}
				}
			}
			else
			{
				if (App::GetController().GetLeftThumbStickY() > 0.5f)
				{
					if (timeDelay <= 0) {
						AABB testBox = selected->box;
						testBox.y1 += selected->getSquareSize();
						testBox.y2 += selected->getSquareSize();
						//check if selected car will collide with other cars or a wall
						if (!willCollide(testBox) &&
							checkBorders(selected->y, selected->isHorizontal))
						{
							selected->y += 1;
							selected->UpdateAABB();
							int x = 0;
							int y = 0;
							selected->getCorner(&x, &y);
							m_sprite->SetPosition(x + 20, y - 20);
						}
						timeDelay = 200.0f;
					}
				}
				else if (App::GetController().GetLeftThumbStickY() < -0.5f)
				{
					if (timeDelay <= 0) {
						AABB testBox = selected->box;
						testBox.y1 -= selected->getSquareSize();
						testBox.y2 -= selected->getSquareSize();
						//check if selected car will collide with other cars or a wall
						if (!willCollide(testBox) &&
							checkBorders(selected->y - selected->size, selected->isHorizontal))
						{
							selected->y -= 1;
							selected->UpdateAABB();
							int x = 0;
							int y = 0;
							selected->getCorner(&x, &y);
							m_sprite->SetPosition(x + 20, y - 20);
						}
						timeDelay = 200.0f;
					}
				}
			}
			//cancel selection
			if (App::GetController().CheckButton(XINPUT_GAMEPAD_B, true))
			{
				m_sprite->SetScale(0.5f);
				selected = nullptr;
			}
		}
	}
}

void InputManager::Render()
{
	m_sprite->Draw();
}
/*
check if box1 overlaps any car other than the currently selected one 
*/
bool InputManager::willCollide(AABB& box1)
{
	for (auto car : cars)
	{
		if (car != selected && areColliding(car->box, box1))
		{
			return true;
		}
	}
	return false;
}
/*
check if index is is outside of the borders for the game
*/
bool InputManager::checkBorders(int i, bool isHorizonal)
{
	if (isHorizonal)
	{
		return i > 0 && i < cols;
	}
	else
	{
		return i > 0 && i < rows;

	}
}

void InputManager::GameOver()
{
	gameOver = true;
}




