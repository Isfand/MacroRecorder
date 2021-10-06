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
//*Try make every input use this function. May help sync
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

void ReadPosFile()
{
	INPUT    Input = { 0 };
	ZeroMemory(&Input, sizeof(INPUT));

	int xPos{}, yPos{};

	std::string line;
	std::string x{}, y{};
	std::ifstream macrofile_RPF("Mouserecord.csv");

	while (getline(macrofile_RPF, line))
	{
		std::stringstream ss(line); //*Use int Stream if it exists

		getline(ss, x, ',');
		getline(ss, y, ',');

			xPos = stoi(x);
			yPos = stoi(y);

			//SetCursorPos(xPos, yPos);
			mouse_move(xPos, yPos);

		std::cout << "X:" << xPos << " " << "Y:" << yPos << '\n';

		if (GetAsyncKeyState(VK_NUMPAD0))
		{
			break;
		}
		Sleep(15);
	}
	macrofile_RPF.close();
}

void ReadKeyboardFile()
{
	INPUT    Input = { 0 };
	ZeroMemory(&Input, sizeof(INPUT));
	Input.type = INPUT_KEYBOARD;

	float fC{};
	int sC{}, tC{};

	std::string line;
	std::ifstream macrofile_KBF("KeyboardFile.csv");

	while (getline(macrofile_KBF, line))
	{
		std::stringstream ss(line); //*Use int Stream if it exists

		std::string firstC{}, secondC{}, thirdC;

		getline(ss, firstC, ',');
		getline(ss, secondC, ',');
		getline(ss, thirdC, ',');

		fC = stof(firstC);
		sC = strtol(secondC.c_str(), NULL, 16);
		tC = strtol(thirdC.c_str(), NULL, 16);

		Sleep(ceil(fC * 1000));

		Input.ki.wScan = sC;
		Input.ki.dwFlags = tC;
		SendInput(1, &Input, sizeof(INPUT));

		if (GetAsyncKeyState(VK_NUMPAD0))
		{
			break;
		}
	}
	macrofile_KBF.close();
}

void ReadMouseFile()
{
	INPUT    Input = { 0 };
	ZeroMemory(&Input, sizeof(INPUT));
	Input.type = INPUT_MOUSE;

	float fC{};
	int sC{};

	std::string line;
	std::ifstream macrofile_MF("MouseFile.csv");
	std::string firstC{}, secondC{};

	while (getline(macrofile_MF, line))
	{
		std::stringstream ss(line); //*Use int Stream if its exists

		getline(ss, firstC, ',');
		getline(ss, secondC, ',');

		fC = stof(firstC);
		sC = strtol(secondC.c_str(), NULL, 16);

		Sleep(ceil(fC * 1000));

		Input.mi.dwFlags = sC;
		SendInput(1, &Input, sizeof(INPUT));

		if (GetAsyncKeyState(VK_NUMPAD0))
		{
			break;
		}
	}
	macrofile_MF.close();
}
