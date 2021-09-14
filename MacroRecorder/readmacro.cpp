#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <sstream>
#include <conio.h>
#include <chrono>
#include <math.h>

using namespace std::literals::chrono_literals;

// Checks if the String is convertable to integer
bool isNumber(const std::string &str)
{
	for (char const &c : str) 
	{	
		if (c == '.') //Bad Implementation, works for now.
		{
			return true;
		}

		else if (std::isdigit(c) == 0)
		{
			return false;
		}
	}
	return true;
}

//function for lower level mouse movement
void mouse_move(int x, int y)
{
	INPUT    Input = { 0 };
	double fScreenWidth = GetSystemMetrics(SM_CXSCREEN) - 1;
	double fScreenHeight = GetSystemMetrics(SM_CYSCREEN) - 1;
	double fx = x * (65535.0f / fScreenWidth);
	double fy = y * (65535.0f / fScreenHeight);

	Input.type = INPUT_MOUSE;
	Input.mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE;
	Input.mi.dx = fx;
	Input.mi.dy = fy;
	SendInput(1, &Input, sizeof(INPUT));

	//OLD
	/*
	INPUT input;
	input.type = INPUT_MOUSE;
	input.mi.mouseData = 0;
	input.mi.time = 0;
	input.mi.dx = x * (65536 / GetSystemMetrics(SM_CXSCREEN));//x being coord in pixels
	input.mi.dy = y * (65536 / GetSystemMetrics(SM_CYSCREEN));//y being coord in pixels
	input.mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_VIRTUALDESK | MOUSEEVENTF_ABSOLUTE;
	SendInput(1, &input, sizeof(input));
	return true;
	*/
}

void ReadFromMouseFile()
{
	INPUT    Input = { 0 };
	ZeroMemory(&Input, sizeof(INPUT));

	int xPos{}, yPos{};

	std::string line;
	std::ifstream macrofile_MR("Mouserecord.csv");

	while (getline(macrofile_MR, line))
	{
		std::stringstream ss(line);
		std::string x{}, y{};

		getline(ss, x, ',');
		getline(ss, y, ',');

		if (isNumber(x))
		{
			xPos = stoi(x);
			yPos = stoi(y);

			//SetCursorPos(xPos, yPos);
			mouse_move(xPos, yPos);
		}

		std::cout << "X:" << xPos << " " << "Y:" << yPos << '\n';

		if (GetAsyncKeyState(VK_NUMPAD0))
		{
			break;
		}
		Sleep(15);
	}
	macrofile_MR.close();
}

void ReadFromKeyFile()
{
	INPUT    Input = { 0 };
	ZeroMemory(&Input, sizeof(INPUT));

	std::string line;
	std::ifstream macrofile_KR("Keyrecord.csv");

	while (getline(macrofile_KR, line))
	{
		std::stringstream ss(line);
		std::string key{};

		getline(ss, key);

		if (isNumber(key))
		{
			//needs fixing
			Sleep(ceil(std::stof(key) * 1000));
		}

		//Left MOUSE BUTTON
		else if (key == "LMB_D")
		{
		Input.type = INPUT_MOUSE;
		Input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
		SendInput(1, &Input, sizeof(INPUT));

		//mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
		}
		else if (key == "LMB_U")
		{
		Input.type = INPUT_MOUSE;
		Input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
		SendInput(1, &Input, sizeof(INPUT));

		//mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
		}
		//SPACE KEY
		else if (key == "SPACE_D")
		{
			Input.type = INPUT_KEYBOARD;
			Input.ki.dwFlags = KEYEVENTF_UNICODE;
			Input.ki.wScan = VK_SPACE;
			SendInput(1, &Input, sizeof(INPUT));
		}
		else if (key == "SPACE_U")
		{
			Input.type = INPUT_KEYBOARD;
			Input.ki.dwFlags = KEYEVENTF_KEYUP;
			Input.ki.wScan = VK_SPACE;
			SendInput(1, &Input, sizeof(INPUT));
		}

		//FILL IN KEYS

		if (GetAsyncKeyState(VK_NUMPAD0))
		{
			break;
		}
		//Sleep(1);
	}
	macrofile_KR.close();
}