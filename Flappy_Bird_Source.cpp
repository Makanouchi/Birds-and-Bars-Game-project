#include<stdio.h>
#include<string.h>
#include "olcConsoleGameEngine.h"
using namespace std;


class Flappy_Bird_Class : public olcConsoleGameEngine
{
public:
	Flappy_Bird_Class() //constructor
	{
		m_sAppName = L"Himanshu's Flappy Bird Game";
	}

private:
	float fElapsedTime;
	float fPosition=0.0f, fVelocity=0.0f, fAcceleration=0.0f;
	float fGravity;
	int nBirdX;

public:
	virtual bool OnUserCreate()
	{
		fPosition = ScreenHeight()/2, fVelocity = 0, fAcceleration = 0;
		fGravity = 100.0f;
		nBirdX = (ScreenWidth() / 4); //starting x coordinate of bird is 1/4 th of screen
		return true;
	}

	virtual bool OnUserUpdate(float fElapsedTime)
	{
		//bird physics
		if (m_keys[VK_SPACE].bPressed)
		{
			fAcceleration = 10;
		}
		else
		{
			fAcceleration += fGravity * fElapsedTime;
		}
		fVelocity += fAcceleration * fElapsedTime;
		fPosition += fVelocity * fElapsedTime;

		//bird drawing
		if (fVelocity > 0)
		{
			DrawString(nBirdX, fPosition, L"\\\\\\", FG_GREEN);
			DrawString(nBirdX, fPosition + 1, L"\\\\\=Q", FG_BLUE);
		}
		else
		{
			DrawString(nBirdX, fPosition, L"/////=Q",FG_GREEN);
			DrawString(nBirdX, fPosition + 1, L"/////", FG_BLUE);
		}
		return true;
	}

};

int main()
{
	Flappy_Bird_Class Mygame;

	Mygame.ConstructConsole(80, 50, 8, 8);   //Play with this
	Mygame.Start();

	return 0;
}