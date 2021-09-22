#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <sstream>
#include <conio.h>
#include <chrono>

using namespace std::literals::chrono_literals;

void WritePosFile()
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

void WriteMouseFile()
{	
	bool kf_LMB{ true };
	bool kf_RMB{ true };
	bool kf_MMB{ true };

	std::ofstream macrofile_MF;
	macrofile_MF.open("MouseFile.csv");

	while (true)
	{
		bool enterLoop{ true };

		auto start = std::chrono::high_resolution_clock::now();
		while (enterLoop)
		{
			//Left MOUSE BUTTON
			if ((GetAsyncKeyState(VK_LBUTTON) & 0x8000) != 0)
			{
				if (kf_LMB == true)
				{
					auto stop = std::chrono::high_resolution_clock::now();
					std::chrono::duration<float> duration = stop - start;

					macrofile_MF << duration.count() << ',' << "0x0002" <<"\n";

					enterLoop = false;
					kf_LMB = false;
				}

			}
			else if ((!GetAsyncKeyState(VK_LBUTTON)))
			{
				if (kf_LMB == false)
				{
					auto stop = std::chrono::high_resolution_clock::now();
					std::chrono::duration<float> duration = stop - start;
					
					macrofile_MF << duration.count() << ',' <<  "0x0004" << "\n";

					enterLoop = false;
					kf_LMB = true;
				}
			}

			if ((GetAsyncKeyState(VK_RBUTTON) & 0x8000) != 0)
			{
				if (kf_RMB == true)
				{
					auto stop = std::chrono::high_resolution_clock::now();
					std::chrono::duration<float> duration = stop - start;

					macrofile_MF << duration.count() << ',' << "0x0008" << "\n";

					enterLoop = false;
					kf_RMB = false;
				}

			}
			else if ((!GetAsyncKeyState(VK_RBUTTON)))
			{
				if (kf_RMB == false)
				{
					auto stop = std::chrono::high_resolution_clock::now();
					std::chrono::duration<float> duration = stop - start;

					macrofile_MF << duration.count() << ',' << "0x0010" << "\n";

					enterLoop = false;
					kf_RMB = true;
				}
			}

			if ((GetAsyncKeyState(VK_MBUTTON) & 0x8000) != 0)
			{
				if (kf_MMB == true)
				{
					auto stop = std::chrono::high_resolution_clock::now();
					std::chrono::duration<float> duration = stop - start;

					macrofile_MF << duration.count() << ',' << "0x0020" << "\n";

					enterLoop = false;
					kf_MMB = false;
				}

			}
			else if ((!GetAsyncKeyState(VK_MBUTTON)))
			{
				if (kf_MMB == false)
				{
					auto stop = std::chrono::high_resolution_clock::now();
					std::chrono::duration<float> duration = stop - start;

					macrofile_MF << duration.count() << ',' << "0x0040" << "\n";

					enterLoop = false;
					kf_MMB = true;
				}
			}

			if (GetAsyncKeyState(VK_NUMPAD0))
			{
				goto escape2;
			}
		}
	}		
			escape2:
			macrofile_MF.close();
}

void WriteKeyboardFile()
{

	std::ofstream macrofile_KBF;
	macrofile_KBF.open("KeyboardFile.csv");

	// KEY FLAGS
	bool kf_SPACE{ true };

	bool kf_A{ true };  bool kf_N{ true };
	bool kf_B{ true }; 	bool kf_O{ true };
	bool kf_C{ true }; 	bool kf_P{ true };
	bool kf_D{ true }; 	bool kf_Q{ true };
	bool kf_E{ true }; 	bool kf_R{ true };
	bool kf_F{ true }; 	bool kf_S{ true };
	bool kf_G{ true }; 	bool kf_T{ true };
	bool kf_H{ true }; 	bool kf_U{ true };
	bool kf_I{ true }; 	bool kf_V{ true };
	bool kf_J{ true }; 	bool kf_W{ true };
	bool kf_K{ true }; 	bool kf_X{ true };
	bool kf_L{ true }; 	bool kf_Y{ true };
	bool kf_M{ true };	bool kf_Z{ true };

	//Maybe wait for the user to enter something
	//When writing instead
	//Find A way too loop all of this in 1 If statement, while keeping keyFlags

	while (true)
	{
		bool exitLoop{ true };

		auto start = std::chrono::high_resolution_clock::now();
		while (exitLoop)
		{
			//SPACE KEY
			if ((GetAsyncKeyState(VK_SPACE) & 0x8000) != 0)
			{
				if (kf_SPACE == true)
				{
					auto stop = std::chrono::high_resolution_clock::now();
					std::chrono::duration<float> duration = stop - start;
					macrofile_KBF << duration.count() << ',' << "0x20" << ',' << "0x0002" << "\n";

					exitLoop = false;
					kf_SPACE = false;
				}

			}
			else if ((!GetAsyncKeyState(VK_SPACE)))
			{
				if (kf_SPACE == false)
				{
					auto stop = std::chrono::high_resolution_clock::now();
					std::chrono::duration<float> duration = stop - start;
					macrofile_KBF << duration.count() << ',' << "0x20" << ',' << "0x0004" << "\n";

					exitLoop = false;
					kf_SPACE = true;
				}
			}

			//A KEY
			if ((GetAsyncKeyState(0x41) & 0x8000) != 0)
			{
				if (kf_A == true)
				{
					auto stop = std::chrono::high_resolution_clock::now();
					std::chrono::duration<float> duration = stop - start;
					macrofile_KBF << duration.count() << ',' << "0x61" << ',' << "0x0004" << "\n";

					exitLoop = false;
					kf_A = false;
				}

			}
			else if ((!GetAsyncKeyState(0x41)))
			{
				if (kf_A == false)
				{
					auto stop = std::chrono::high_resolution_clock::now();
					std::chrono::duration<float> duration = stop - start;
					macrofile_KBF << duration.count() << ',' << "0x61" << ',' << "0x0002" << "\n";

					exitLoop = false;
					kf_A = true;
				}
			}

			//B KEY
			if ((GetAsyncKeyState(0x42) & 0x8000) != 0)
			{
				if (kf_B == true)
				{
					auto stop = std::chrono::high_resolution_clock::now();
					std::chrono::duration<float> duration = stop - start;
					macrofile_KBF << duration.count() << ',' << "0x62" << ',' << "0x0004" << "\n";

					exitLoop = false;
					kf_B = false;
				}

			}
			else if ((!GetAsyncKeyState(0x42)))
			{
				if (kf_B == false)
				{
					auto stop = std::chrono::high_resolution_clock::now();
					std::chrono::duration<float> duration = stop - start;
					macrofile_KBF << duration.count() << ',' << "0x62" << ',' << "0x0002" << "\n";

					exitLoop = false;
					kf_B = true;
				}
			}

			//C KEY
			if ((GetAsyncKeyState(0x43) & 0x8000) != 0)
			{
				if (kf_C == true)
				{
					auto stop = std::chrono::high_resolution_clock::now();
					std::chrono::duration<float> duration = stop - start;
					macrofile_KBF << duration.count() << ',' << "0x63" << ',' << "0x0004" << "\n";

					exitLoop = false;
					kf_C = false;
				}

			}
			else if ((!GetAsyncKeyState(0x43)))
			{
				if (kf_C == false)
				{
					auto stop = std::chrono::high_resolution_clock::now();
					std::chrono::duration<float> duration = stop - start;
					macrofile_KBF << duration.count() << ',' << "0x63" << ',' << "0x0002" << "\n";

					exitLoop = false;
					kf_C = true;
				}
			}

			//D KEY
			if ((GetAsyncKeyState(0x44) & 0x8000) != 0)
			{
				if (kf_D == true)
				{
					auto stop = std::chrono::high_resolution_clock::now();
					std::chrono::duration<float> duration = stop - start;
					macrofile_KBF << duration.count() << ',' << "0x64" << ',' << "0x0004" << "\n";

					exitLoop = false;
					kf_D = false;
				}

			}
			else if ((!GetAsyncKeyState(0x44)))
			{
				if (kf_D == false)
				{
					auto stop = std::chrono::high_resolution_clock::now();
					std::chrono::duration<float> duration = stop - start;
					macrofile_KBF << duration.count() << ',' << "0x64" << ',' << "0x0002" << "\n";

					exitLoop = false;
					kf_D = true;
				}
			}

			//E KEY
			if ((GetAsyncKeyState(0x45) & 0x8000) != 0)
			{
				if (kf_E == true)
				{
					auto stop = std::chrono::high_resolution_clock::now();
					std::chrono::duration<float> duration = stop - start;
					macrofile_KBF << duration.count() << ',' << "0x65" << ',' << "0x0004" << "\n";

					exitLoop = false;
					kf_E = false;
				}

			}
			else if ((!GetAsyncKeyState(0x45)))
			{
				if (kf_E == false)
				{
					auto stop = std::chrono::high_resolution_clock::now();
					std::chrono::duration<float> duration = stop - start;
					macrofile_KBF << duration.count() << ',' << "0x65" << ',' << "0x0002" << "\n";

					exitLoop = false;
					kf_E = true;
				}
			}

			//F KEY
			if ((GetAsyncKeyState(0x46) & 0x8000) != 0)
			{
				if (kf_F == true)
				{
					auto stop = std::chrono::high_resolution_clock::now();
					std::chrono::duration<float> duration = stop - start;
					macrofile_KBF << duration.count() << ',' << "0x66" << ',' << "0x0004" << "\n";

					exitLoop = false;
					kf_F = false;
				}

			}
			else if ((!GetAsyncKeyState(0x46)))
			{
				if (kf_F == false)
				{
					auto stop = std::chrono::high_resolution_clock::now();
					std::chrono::duration<float> duration = stop - start;
					macrofile_KBF << duration.count() << ',' << "0x66" << ',' << "0x0002" << "\n";

					exitLoop = false;
					kf_F = true;
				}
			}

			//G KEY
			if ((GetAsyncKeyState(0x47) & 0x8000) != 0)
			{
				if (kf_G == true)
				{
					auto stop = std::chrono::high_resolution_clock::now();
					std::chrono::duration<float> duration = stop - start;
					macrofile_KBF << duration.count() << ',' << "0x67" << ',' << "0x0004" << "\n";

					exitLoop = false;
					kf_G = false;
				}

			}
			else if ((!GetAsyncKeyState(0x47)))
			{
				if (kf_G == false)
				{
					auto stop = std::chrono::high_resolution_clock::now();
					std::chrono::duration<float> duration = stop - start;
					macrofile_KBF << duration.count() << ',' << "0x67" << ',' << "0x0002" << "\n";

					exitLoop = false;
					kf_G = true;
				}
			}

			//H KEY
			if ((GetAsyncKeyState(0x48) & 0x8000) != 0)
			{
				if (kf_H == true)
				{
					auto stop = std::chrono::high_resolution_clock::now();
					std::chrono::duration<float> duration = stop - start;
					macrofile_KBF << duration.count() << ',' << "0x68" << ',' << "0x0004" << "\n";

					exitLoop = false;
					kf_H = false;
				}

			}
			else if ((!GetAsyncKeyState(0x48)))
			{
				if (kf_H == false)
				{
					auto stop = std::chrono::high_resolution_clock::now();
					std::chrono::duration<float> duration = stop - start;
					macrofile_KBF << duration.count() << ',' << "0x68" << ',' << "0x0002" << "\n";

					exitLoop = false;
					kf_H = true;
				}
			}

			//I KEY
			if ((GetAsyncKeyState(0x49) & 0x8000) != 0)
			{
				if (kf_I == true)
				{
					auto stop = std::chrono::high_resolution_clock::now();
					std::chrono::duration<float> duration = stop - start;
					macrofile_KBF << duration.count() << ',' << "0x69" << ',' << "0x0004" << "\n";

					exitLoop = false;
					kf_I = false;
				}

			}
			else if ((!GetAsyncKeyState(0x49)))
			{
				if (kf_I == false)
				{
					auto stop = std::chrono::high_resolution_clock::now();
					std::chrono::duration<float> duration = stop - start;
					macrofile_KBF << duration.count() << ',' << "0x69" << ',' << "0x0002" << "\n";

					exitLoop = false;
					kf_I = true;
				}
			}

			//J KEY
			if ((GetAsyncKeyState(0x4A) & 0x8000) != 0)
			{
				if (kf_J == true)
				{
					auto stop = std::chrono::high_resolution_clock::now();
					std::chrono::duration<float> duration = stop - start;
					macrofile_KBF << duration.count() << ',' << "0x6A" << ',' << "0x0004" << "\n";

					exitLoop = false;
					kf_J = false;
				}

			}
			else if ((!GetAsyncKeyState(0x4A)))
			{
				if (kf_J == false)
				{
					auto stop = std::chrono::high_resolution_clock::now();
					std::chrono::duration<float> duration = stop - start;
					macrofile_KBF << duration.count() << ',' << "0x6A" << ',' << "0x0002" << "\n";

					exitLoop = false;
					kf_J = true;
				}
			}

			//K KEY
			if ((GetAsyncKeyState(0x4B) & 0x8000) != 0)
			{
				if (kf_K == true)
				{
					auto stop = std::chrono::high_resolution_clock::now();
					std::chrono::duration<float> duration = stop - start;
					macrofile_KBF << duration.count() << ',' << "0x6B" << ',' << "0x0004" << "\n";

					exitLoop = false;
					kf_K = false;
				}

			}
			else if ((!GetAsyncKeyState(0x4B)))
			{
				if (kf_K == false)
				{
					auto stop = std::chrono::high_resolution_clock::now();
					std::chrono::duration<float> duration = stop - start;
					macrofile_KBF << duration.count() << ',' << "0x6B" << ',' << "0x0002" << "\n";

					exitLoop = false;
					kf_K = true;
				}
			}

			//L KEY
			if ((GetAsyncKeyState(0x4C) & 0x8000) != 0)
			{
				if (kf_L == true)
				{
					auto stop = std::chrono::high_resolution_clock::now();
					std::chrono::duration<float> duration = stop - start;
					macrofile_KBF << duration.count() << ',' << "0x6C" << ',' << "0x0004" << "\n";

					exitLoop = false;
					kf_L = false;
				}

			}
			else if ((!GetAsyncKeyState(0x4C)))
			{
				if (kf_L == false)
				{
					auto stop = std::chrono::high_resolution_clock::now();
					std::chrono::duration<float> duration = stop - start;
					macrofile_KBF << duration.count() << ',' << "0x6C" << ',' << "0x0002" << "\n";

					exitLoop = false;
					kf_L = true;
				}
			}

			//M KEY
			if ((GetAsyncKeyState(0x4D) & 0x8000) != 0)
			{
				if (kf_M == true)
				{
					auto stop = std::chrono::high_resolution_clock::now();
					std::chrono::duration<float> duration = stop - start;
					macrofile_KBF << duration.count() << ',' << "0x6D" << ',' << "0x0004" << "\n";

					exitLoop = false;
					kf_M = false;
				}

			}
			else if ((!GetAsyncKeyState(0x4D)))
			{
				if (kf_M == false)
				{
					auto stop = std::chrono::high_resolution_clock::now();
					std::chrono::duration<float> duration = stop - start;
					macrofile_KBF << duration.count() << ',' << "0x6D" << ',' << "0x0002" << "\n";

					exitLoop = false;
					kf_M = true;
				}
			}

			//N KEY
			if ((GetAsyncKeyState(0x4E) & 0x8000) != 0)
			{
				if (kf_N == true)
				{
					auto stop = std::chrono::high_resolution_clock::now();
					std::chrono::duration<float> duration = stop - start;
					macrofile_KBF << duration.count() << ',' << "0x6E" << ',' << "0x0004" << "\n";

					exitLoop = false;
					kf_N = false;
				}

			}
			else if ((!GetAsyncKeyState(0x4E)))
			{
				if (kf_N == false)
				{
					auto stop = std::chrono::high_resolution_clock::now();
					std::chrono::duration<float> duration = stop - start;
					macrofile_KBF << duration.count() << ',' << "0x6E" << ',' << "0x0002" << "\n";

					exitLoop = false;
					kf_N = true;
				}
			}

			//O KEY
			if ((GetAsyncKeyState(0x4F) & 0x8000) != 0)
			{
				if (kf_O == true)
				{
					auto stop = std::chrono::high_resolution_clock::now();
					std::chrono::duration<float> duration = stop - start;
					macrofile_KBF << duration.count() << ',' << "0x6F" << ',' << "0x0004" << "\n";

					exitLoop = false;
					kf_O = false;
				}

			}
			else if ((!GetAsyncKeyState(0x4F)))
			{
				if (kf_O == false)
				{
					auto stop = std::chrono::high_resolution_clock::now();
					std::chrono::duration<float> duration = stop - start;
					macrofile_KBF << duration.count() << ',' << "0x6F" << ',' << "0x0002" << "\n";

					exitLoop = false;
					kf_O = true;
				}
			}

			//P KEY
			if ((GetAsyncKeyState(0x50) & 0x8000) != 0)
			{
				if (kf_P == true)
				{
					auto stop = std::chrono::high_resolution_clock::now();
					std::chrono::duration<float> duration = stop - start;
					macrofile_KBF << duration.count() << ',' << "0x70" << ',' << "0x0004" << "\n";

					exitLoop = false;
					kf_P = false;
				}

			}
			else if ((!GetAsyncKeyState(0x50)))
			{
				if (kf_P == false)
				{
					auto stop = std::chrono::high_resolution_clock::now();
					std::chrono::duration<float> duration = stop - start;
					macrofile_KBF << duration.count() << ',' << "0x70" << ',' << "0x0002" << "\n";

					exitLoop = false;
					kf_P = true;
				}
			}

			//Q KEY
			if ((GetAsyncKeyState(0x51) & 0x8000) != 0)
			{
				if (kf_Q == true)
				{
					auto stop = std::chrono::high_resolution_clock::now();
					std::chrono::duration<float> duration = stop - start;
					macrofile_KBF << duration.count() << ',' << "0x71" << ',' << "0x0004" << "\n";

					exitLoop = false;
					kf_Q = false;
				}

			}
			else if ((!GetAsyncKeyState(0x51)))
			{
				if (kf_Q == false)
				{
					auto stop = std::chrono::high_resolution_clock::now();
					std::chrono::duration<float> duration = stop - start;
					macrofile_KBF << duration.count() << ',' << "0x71" << ',' << "0x0002" << "\n";

					exitLoop = false;
					kf_Q = true;
				}
			}

			//R KEY
			if ((GetAsyncKeyState(0x52) & 0x8000) != 0)
			{
				if (kf_R == true)
				{
					auto stop = std::chrono::high_resolution_clock::now();
					std::chrono::duration<float> duration = stop - start;
					macrofile_KBF << duration.count() << ',' << "0x72" << ',' << "0x0004" << "\n";

					exitLoop = false;
					kf_R = false;
				}

			}
			else if ((!GetAsyncKeyState(0x52)))
			{
				if (kf_R == false)
				{
					auto stop = std::chrono::high_resolution_clock::now();
					std::chrono::duration<float> duration = stop - start;
					macrofile_KBF << duration.count() << ',' << "0x72" << ',' << "0x0002" << "\n";

					exitLoop = false;
					kf_R = true;
				}
			}

			//S KEY
			if ((GetAsyncKeyState(0x53) & 0x8000) != 0)
			{
				if (kf_S == true)
				{
					auto stop = std::chrono::high_resolution_clock::now();
					std::chrono::duration<float> duration = stop - start;
					macrofile_KBF << duration.count() << ',' << "0x73" << ',' << "0x0004" << "\n";

					exitLoop = false;
					kf_S = false;
				}

			}
			else if ((!GetAsyncKeyState(0x53)))
			{
				if (kf_S == false)
				{
					auto stop = std::chrono::high_resolution_clock::now();
					std::chrono::duration<float> duration = stop - start;
					macrofile_KBF << duration.count() << ',' << "0x73" << ',' << "0x0002" << "\n";

					exitLoop = false;
					kf_S = true;
				}
			}

			//T KEY
			if ((GetAsyncKeyState(0x54) & 0x8000) != 0)
			{
				if (kf_T == true)
				{
					auto stop = std::chrono::high_resolution_clock::now();
					std::chrono::duration<float> duration = stop - start;
					macrofile_KBF << duration.count() << ',' << "0x74" << ',' << "0x0004" << "\n";

					exitLoop = false;
					kf_T = false;
				}

			}
			else if ((!GetAsyncKeyState(0x54)))
			{
				if (kf_T == false)
				{
					auto stop = std::chrono::high_resolution_clock::now();
					std::chrono::duration<float> duration = stop - start;
					macrofile_KBF << duration.count() << ',' << "0x74" << ',' << "0x0002" << "\n";

					exitLoop = false;
					kf_T = true;
				}
			}

			//U KEY
			if ((GetAsyncKeyState(0x55) & 0x8000) != 0)
			{
				if (kf_U == true)
				{
					auto stop = std::chrono::high_resolution_clock::now();
					std::chrono::duration<float> duration = stop - start;
					macrofile_KBF << duration.count() << ',' << "0x75" << ',' << "0x0004" << "\n";

					exitLoop = false;
					kf_U = false;
				}

			}
			else if ((!GetAsyncKeyState(0x55)))
			{
				if (kf_U == false)
				{
					auto stop = std::chrono::high_resolution_clock::now();
					std::chrono::duration<float> duration = stop - start;
					macrofile_KBF << duration.count() << ',' << "0x75" << ',' << "0x0002" << "\n";

					exitLoop = false;
					kf_U = true;
				}
			}

			//V KEY
			if ((GetAsyncKeyState(0x56) & 0x8000) != 0)
			{
				if (kf_V == true)
				{
					auto stop = std::chrono::high_resolution_clock::now();
					std::chrono::duration<float> duration = stop - start;
					macrofile_KBF << duration.count() << ',' << "0x76" << ',' << "0x0004" << "\n";

					exitLoop = false;
					kf_V = false;
				}

			}
			else if ((!GetAsyncKeyState(0x56)))
			{
				if (kf_V == false)
				{
					auto stop = std::chrono::high_resolution_clock::now();
					std::chrono::duration<float> duration = stop - start;
					macrofile_KBF << duration.count() << ',' << "0x76" << ',' << "0x0002" << "\n";

					exitLoop = false;
					kf_V = true;
				}
			}

			//W KEY
			if ((GetAsyncKeyState(0x57) & 0x8000) != 0)
			{
				if (kf_W == true)
				{
					auto stop = std::chrono::high_resolution_clock::now();
					std::chrono::duration<float> duration = stop - start;
					macrofile_KBF << duration.count() << ',' << "0x77" << ',' << "0x0004" << "\n";

					exitLoop = false;
					kf_W = false;
				}

			}
			else if ((!GetAsyncKeyState(0x57)))
			{
				if (kf_W == false)
				{
					auto stop = std::chrono::high_resolution_clock::now();
					std::chrono::duration<float> duration = stop - start;
					macrofile_KBF << duration.count() << ',' << "0x77" << ',' << "0x0002" << "\n";

					exitLoop = false;
					kf_W = true;
				}
			}

			//X KEY
			if ((GetAsyncKeyState(0x58) & 0x8000) != 0)
			{
				if (kf_X == true)
				{
					auto stop = std::chrono::high_resolution_clock::now();
					std::chrono::duration<float> duration = stop - start;
					macrofile_KBF << duration.count() << ',' << "0x78" << ',' << "0x0004" << "\n";

					exitLoop = false;
					kf_X = false;
				}

			}
			else if ((!GetAsyncKeyState(0x58)))
			{
				if (kf_X == false)
				{
					auto stop = std::chrono::high_resolution_clock::now();
					std::chrono::duration<float> duration = stop - start;
					macrofile_KBF << duration.count() << ',' << "0x78" << ',' << "0x0002" << "\n";

					exitLoop = false;
					kf_X = true;
				}
			}

			//Y KEY
			if ((GetAsyncKeyState(0x59) & 0x8000) != 0)
			{
				if (kf_Y == true)
				{
					auto stop = std::chrono::high_resolution_clock::now();
					std::chrono::duration<float> duration = stop - start;
					macrofile_KBF << duration.count() << ',' << "0x79" << ',' << "0x0004" << "\n";

					exitLoop = false;
					kf_Y = false;
				}

			}
			else if ((!GetAsyncKeyState(0x59)))
			{
				if (kf_Y == false)
				{
					auto stop = std::chrono::high_resolution_clock::now();
					std::chrono::duration<float> duration = stop - start;
					macrofile_KBF << duration.count() << ',' << "0x79" << ',' << "0x0002" << "\n";

					exitLoop = false;
					kf_Y = true;
				}
			}

			//Z KEY
			if ((GetAsyncKeyState(0x5A) & 0x8000) != 0)
			{
				if (kf_Z == true)
				{
					auto stop = std::chrono::high_resolution_clock::now();
					std::chrono::duration<float> duration = stop - start;
					macrofile_KBF << duration.count() << ',' << "0x7A" << ',' << "0x0004" << "\n";

					exitLoop = false;
					kf_Z = false;
				}

			}
			else if ((!GetAsyncKeyState(0x5A)))
			{
				if (kf_Z == false)
				{
					auto stop = std::chrono::high_resolution_clock::now();
					std::chrono::duration<float> duration = stop - start;
					macrofile_KBF << duration.count() << ',' << "0x7A" << ',' << "0x0002" << "\n";

					exitLoop = false;
					kf_Z = true;
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
	macrofile_KBF.close();
}