#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <sstream>
#include <conio.h>
#include <chrono>

using namespace std::literals::chrono_literals;

void WriteMouseToFile()
{
	std::ofstream macrofile_MW;
	macrofile_MW.open("Mouserecord.csv");

	POINT pointer;

	/*HWND hwnd = 0;
	LPCWSTR window_title = L"WindowName";
	hwnd = FindWindow(NULL, window_title);*/

	while (true)
	{
		if (GetCursorPos(&pointer))
		{
			std::cout << pointer.x << " " << pointer.y << "\n";
			macrofile_MW << pointer.x << "," << pointer.y << "\n";
		}

		/*if (GetCursorPos(&pointer))
		{
			ScreenToClient(hwnd, &pointer);
			std::cout << pointer.x << " " << pointer.y << "\n";
		}*/

		if (GetAsyncKeyState(VK_NUMPAD0))
		{
			break;
		}
		Sleep(15);
	}
	macrofile_MW.close();
}

void WriteKeyToFile()
{
	std::ofstream macrofile_KW;
	macrofile_KW.open("Keyrecord.csv");

	// KEY FLAGS
	bool f_LMB  { true };
	bool f_SPACE{ true };

	while (true) 
	{
		bool exitLoop{ true };

		auto start = std::chrono::high_resolution_clock::now();
		while (exitLoop)
		{
			//Left MOUSE BUTTON
			if ((GetAsyncKeyState(VK_LBUTTON) & 0x8000) != 0)
			{
				if (f_LMB == true)
				{
					auto stop = std::chrono::high_resolution_clock::now();
					std::chrono::duration<float> duration = stop - start;
					macrofile_KW << duration.count() << "\n";

					macrofile_KW << "LMB_D" << "\n";
					exitLoop = false;
					f_LMB = false;
				}

			}
			else if ((!GetAsyncKeyState(VK_LBUTTON)))
			{
				if (f_LMB == false)
				{
					auto stop = std::chrono::high_resolution_clock::now();
					std::chrono::duration<float> duration = stop - start;
					macrofile_KW << duration.count() << "\n";

					macrofile_KW << "LMB_U" << "\n";
					exitLoop = false;
					f_LMB = true;
				}
			}
			//SPACE KEY
		    if ((GetAsyncKeyState(VK_SPACE) & 0x8000) != 0)
			{
				if (f_SPACE == true)
				{
					auto stop = std::chrono::high_resolution_clock::now();
					std::chrono::duration<float> duration = stop - start;
					macrofile_KW << duration.count() << "\n";

					macrofile_KW << "SPACE_D" << "\n";
					exitLoop = false;
					f_SPACE = false;
				}

			}
			else if ((!GetAsyncKeyState(VK_SPACE)))
			{
				if (f_SPACE == false)
				{
					auto stop = std::chrono::high_resolution_clock::now();
					std::chrono::duration<float> duration = stop - start;
					macrofile_KW << duration.count() << "\n";

					macrofile_KW << "SPACE_U" << "\n";
					exitLoop = false;
					f_SPACE = true;
				}
			}

			if (GetAsyncKeyState(VK_NUMPAD0))
			{
				goto escape;
			}
			//std::chrono::microseconds(1);
			//Sleep(1);
		}
		//auto stop = std::chrono::high_resolution_clock::now();
		//std::chrono::microseconds(1);
		//Sleep(1);
	}
	escape:
	macrofile_KW.close();
}