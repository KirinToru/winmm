#include <Windows.h>
#include <iostream>
#define MOVE_RIGHT -1
#define MOVE_LEFT 1
using namespace std; 

void shakeWindow(int moveDirection, HWND hWindow)
{
	RECT windowRect;
	GetWindowRect(hWindow, &windowRect);

	LONG moveAxisX = windowRect.left;

	if (moveDirection == MOVE_RIGHT)
		moveAxisX += 10;
	if (moveDirection == MOVE_LEFT)
		moveAxisX -= 10;

	SetWindowPos(hWindow, NULL, moveAxisX, windowRect.top, NULL, NULL, SWP_NOSIZE);
}

int main(int argc, char** argv)
{
    Sleep( 35 );
    ShowWindow(GetConsoleWindow(), SW_HIDE);

	PlaySoundA("sf.wav", NULL, SND_FILENAME + SND_LOOP + SND_ASYNC);

	int currentMoveDirection = MOVE_LEFT;

	while (true)
	{
		Sleep(35);
		shakeWindow(currentMoveDirection, GetForegroundWindow());

		switch (currentMoveDirection)
		{
		case MOVE_LEFT:
			currentMoveDirection = MOVE_RIGHT;
			break;
		case MOVE_RIGHT:
			currentMoveDirection = MOVE_LEFT;
		}
	}

	return 0;
}