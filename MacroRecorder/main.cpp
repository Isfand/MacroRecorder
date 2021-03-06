#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <sstream>
#include <conio.h>
#include <chrono>
#include <thread>
#include "myheader.h"

//Temporary Implementation
//To record press 1 and then 0 to exit. Do not press 2 while the recording is being played
//If something doesn't work correctly restart the program.

int main()
{
	while (true)
	{
		if (GetAsyncKeyState(VK_NUMPAD1))
		{
			std::thread thread1(WritePosFile);
			std::thread thread2(WriteMouseFile);
			std::thread thread3(WriteKeyboardFile);
			thread1.join();
			thread2.join();
			thread3.join();
		}
		if (GetAsyncKeyState(VK_NUMPAD2))
		{
			std::thread thread1(ReadPosFile);
			std::thread thread2(ReadMouseFile);
			std::thread thread3(ReadKeyboardFile);
			thread1.join();
			thread2.join();
			thread3.join();
		}
		Sleep(1);
	}
}
//MOUSEEVENTF_LEFTDOWN;

//HWND hwnd;
//for (int i = 1; i < 20; i++)
//	hwnd = FindWindow(NULL, TEXT("Mouseposition"));
//
//HDC hdc = GetDC(hwnd);
//
//POINT aPoint;
//
//
//
//for (int q = 0;; ++q)
//{
//	system("cls");
//	GetCursorPos(&aPoint);
//	ScreenToClient(hwnd, &aPoint);
//	std::cout << "Mouse position (x/y) was: " << aPoint.x << "/" << aPoint.y << std::endl;
//	Sleep(200);
//}