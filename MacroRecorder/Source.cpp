void ReadKeyFiles()
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

		//Bad implementaion too much redundency. Too much time lost.
		//Keys A-Z start and end: 0x41 - 0x5A. Could use a for loop to save processing time
		//Save the Strings as their literal windows API HEX codes, which you can then pass directly into a loop from file stream. Or use Enums.
		//Windows uses ASCII codes which equal to hex. Start with 97 not 65
		//May need to create a seperate file for mouse and keyboard because of input.mi & input.ki being different
		//0x0002 0x0004 up down. Reverse for mouse.

		//Left MOUSE BUTTON
		if (key == "LMB_D")
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

		//FILL IN KEYS

		if (GetAsyncKeyState(VK_NUMPAD0))
		{
			break;
		}
		//Sleep(1);
	}
	macrofile_KR.close();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
		//A KEY
else if (key == "A_D")
		{
		Input.type = INPUT_KEYBOARD;
		Input.ki.dwFlags = KEYEVENTF_UNICODE;
		Input.ki.wScan = 97;
		SendInput(1, &Input, sizeof(INPUT));
		}
else if (key == "A_U")
		{
		Input.type = INPUT_KEYBOARD;
		Input.ki.dwFlags = KEYEVENTF_KEYUP;
		Input.ki.wScan = 97;
		SendInput(1, &Input, sizeof(INPUT));
		}
		//B KEY
else if (key == "B_D")
		{
		Input.type = INPUT_KEYBOARD;
		Input.ki.dwFlags = KEYEVENTF_UNICODE;
		Input.ki.wScan = 0x42;
		SendInput(1, &Input, sizeof(INPUT));
		}
else if (key == "B_U")
		{
		Input.type = INPUT_KEYBOARD;
		Input.ki.dwFlags = KEYEVENTF_KEYUP;
		Input.ki.wScan = 0x42;
		SendInput(1, &Input, sizeof(INPUT));
		}
		//C KEY
else if (key == "C_D")
		{
		Input.type = INPUT_KEYBOARD;
		Input.ki.dwFlags = KEYEVENTF_UNICODE;
		Input.ki.wScan = 0x43;
		SendInput(1, &Input, sizeof(INPUT));
		}
else if (key == "C_U")
		{
		Input.type = INPUT_KEYBOARD;
		Input.ki.dwFlags = KEYEVENTF_KEYUP;
		Input.ki.wScan = 0x43;
		SendInput(1, &Input, sizeof(INPUT));
		}
		//D KEY
else if (key == "D_D")
		{
		Input.type = INPUT_KEYBOARD;
		Input.ki.dwFlags = KEYEVENTF_UNICODE;
		Input.ki.wScan = 0x44;
		SendInput(1, &Input, sizeof(INPUT));
		}
else if (key == "D_U")
		{
		Input.type = INPUT_KEYBOARD;
		Input.ki.dwFlags = KEYEVENTF_KEYUP;
		Input.ki.wScan = 0x44;
		SendInput(1, &Input, sizeof(INPUT));
		}
		//E KEY
else if (key == "E_D")
		{
		Input.type = INPUT_KEYBOARD;
		Input.ki.dwFlags = KEYEVENTF_UNICODE;
		Input.ki.wScan = 0x45;
		SendInput(1, &Input, sizeof(INPUT));
		}
else if (key == "E_U")
		{
		Input.type = INPUT_KEYBOARD;
		Input.ki.dwFlags = KEYEVENTF_KEYUP;
		Input.ki.wScan = 0x45;
		SendInput(1, &Input, sizeof(INPUT));
		}
		//F KEY
else if (key == "F_D")
		{
		Input.type = INPUT_KEYBOARD;
		Input.ki.dwFlags = KEYEVENTF_UNICODE;
		Input.ki.wScan = 0x46;
		SendInput(1, &Input, sizeof(INPUT));
		}
else if (key == "F_U")
		{
		Input.type = INPUT_KEYBOARD;
		Input.ki.dwFlags = KEYEVENTF_KEYUP;
		Input.ki.wScan = 0x46;
		SendInput(1, &Input, sizeof(INPUT));
		}
		//G KEY
else if (key == "G_D")
		{
		Input.type = INPUT_KEYBOARD;
		Input.ki.dwFlags = KEYEVENTF_UNICODE;
		Input.ki.wScan = 0x47;
		SendInput(1, &Input, sizeof(INPUT));
		}
else if (key == "G_U")
		{
		Input.type = INPUT_KEYBOARD;
		Input.ki.dwFlags = KEYEVENTF_KEYUP;
		Input.ki.wScan = 0x47;
		SendInput(1, &Input, sizeof(INPUT));
		}
		//H KEY
else if (key == "H_D")
		{
		Input.type = INPUT_KEYBOARD;
		Input.ki.dwFlags = KEYEVENTF_UNICODE;
		Input.ki.wScan = 0x48;
		SendInput(1, &Input, sizeof(INPUT));
		}
else if (key == "H_U")
		{
		Input.type = INPUT_KEYBOARD;
		Input.ki.dwFlags = KEYEVENTF_KEYUP;
		Input.ki.wScan = 0x48;
		SendInput(1, &Input, sizeof(INPUT));
		}
		//I KEY
else if (key == "I_D")
		{
		Input.type = INPUT_KEYBOARD;
		Input.ki.dwFlags = KEYEVENTF_UNICODE;
		Input.ki.wScan = 0x49;
		SendInput(1, &Input, sizeof(INPUT));
		}
else if (key == "I_U")
		{
		Input.type = INPUT_KEYBOARD;
		Input.ki.dwFlags = KEYEVENTF_KEYUP;
		Input.ki.wScan = 0x49;
		SendInput(1, &Input, sizeof(INPUT));
		}
		//J KEY
else if (key == "J_D")
		{
		Input.type = INPUT_KEYBOARD;
		Input.ki.dwFlags = KEYEVENTF_UNICODE;
		Input.ki.wScan = 0x4A;
		SendInput(1, &Input, sizeof(INPUT));
		}
else if (key == "J_U")
		{
		Input.type = INPUT_KEYBOARD;
		Input.ki.dwFlags = KEYEVENTF_KEYUP;
		Input.ki.wScan = 0x4A;
		SendInput(1, &Input, sizeof(INPUT));
		}
		//K KEY
else if (key == "K_D")
		{
		Input.type = INPUT_KEYBOARD;
		Input.ki.dwFlags = KEYEVENTF_UNICODE;
		Input.ki.wScan = 0x4B;
		SendInput(1, &Input, sizeof(INPUT));
		}
else if (key == "K_U")
		{
		Input.type = INPUT_KEYBOARD;
		Input.ki.dwFlags = KEYEVENTF_KEYUP;
		Input.ki.wScan = 0x4B;
		SendInput(1, &Input, sizeof(INPUT));
		}
		//L KEY
else if (key == "L_D")
		{
		Input.type = INPUT_KEYBOARD;
		Input.ki.dwFlags = KEYEVENTF_UNICODE;
		Input.ki.wScan = 0x4C;
		SendInput(1, &Input, sizeof(INPUT));
		}
else if (key == "L_U")
		{
		Input.type = INPUT_KEYBOARD;
		Input.ki.dwFlags = KEYEVENTF_KEYUP;
		Input.ki.wScan = 0x4C;
		SendInput(1, &Input, sizeof(INPUT));
		}
		//M KEY
else if (key == "M_D")
		{
		Input.type = INPUT_KEYBOARD;
		Input.ki.dwFlags = KEYEVENTF_UNICODE;
		Input.ki.wScan = 0x4D;
		SendInput(1, &Input, sizeof(INPUT));
		}
else if (key == "M_U")
		{
		Input.type = INPUT_KEYBOARD;
		Input.ki.dwFlags = KEYEVENTF_KEYUP;
		Input.ki.wScan = 0x4D;
		SendInput(1, &Input, sizeof(INPUT));
		}
		//N KEY
else if (key == "N_D")
		{
		Input.type = INPUT_KEYBOARD;
		Input.ki.dwFlags = KEYEVENTF_UNICODE;
		Input.ki.wScan = 0x4E;
		SendInput(1, &Input, sizeof(INPUT));
		}
else if (key == "N_U")
		{
		Input.type = INPUT_KEYBOARD;
		Input.ki.dwFlags = KEYEVENTF_KEYUP;
		Input.ki.wScan = 0x4E;
		SendInput(1, &Input, sizeof(INPUT));
		}
		//O KEY
else if (key == "O_D")
		{
		Input.type = INPUT_KEYBOARD;
		Input.ki.dwFlags = KEYEVENTF_UNICODE;
		Input.ki.wScan = 0x4F;
		SendInput(1, &Input, sizeof(INPUT));
		}
else if (key == "O_U")
		{
		Input.type = INPUT_KEYBOARD;
		Input.ki.dwFlags = KEYEVENTF_KEYUP;
		Input.ki.wScan = 0x4F;
		SendInput(1, &Input, sizeof(INPUT));
		}
		//P KEY
else if (key == "P_D")
		{
		Input.type = INPUT_KEYBOARD;
		Input.ki.dwFlags = KEYEVENTF_UNICODE;
		Input.ki.wScan = 0x50;
		SendInput(1, &Input, sizeof(INPUT));
		}
else if (key == "P_U")
		{
		Input.type = INPUT_KEYBOARD;
		Input.ki.dwFlags = KEYEVENTF_KEYUP;
		Input.ki.wScan = 0x50;
		SendInput(1, &Input, sizeof(INPUT));
		}
		//Q KEY
else if (key == "Q_D")
		{
		Input.type = INPUT_KEYBOARD;
		Input.ki.dwFlags = KEYEVENTF_UNICODE;
		Input.ki.wScan = 0x51;
		SendInput(1, &Input, sizeof(INPUT));
		}
else if (key == "Q_U")
		{
		Input.type = INPUT_KEYBOARD;
		Input.ki.dwFlags = KEYEVENTF_KEYUP;
		Input.ki.wScan = 0x51;
		SendInput(1, &Input, sizeof(INPUT));
		}
		//R KEY
else if (key == "R_D")
		{
		Input.type = INPUT_KEYBOARD;
		Input.ki.dwFlags = KEYEVENTF_UNICODE;
		Input.ki.wScan = 0x52;
		SendInput(1, &Input, sizeof(INPUT));
		}
else if (key == "R_U")
		{
		Input.type = INPUT_KEYBOARD;
		Input.ki.dwFlags = KEYEVENTF_KEYUP;
		Input.ki.wScan = 0x52;
		SendInput(1, &Input, sizeof(INPUT));
		}
		//S KEY
else if (key == "S_D")
		{
		Input.type = INPUT_KEYBOARD;
		Input.ki.dwFlags = KEYEVENTF_UNICODE;
		Input.ki.wScan = 0x53;
		SendInput(1, &Input, sizeof(INPUT));
		}
else if (key == "S_U")
		{
		Input.type = INPUT_KEYBOARD;
		Input.ki.dwFlags = KEYEVENTF_KEYUP;
		Input.ki.wScan = 0x53;
		SendInput(1, &Input, sizeof(INPUT));
		}
		//T KEY
else if (key == "T_D")
		{
		Input.type = INPUT_KEYBOARD;
		Input.ki.dwFlags = KEYEVENTF_UNICODE;
		Input.ki.wScan = 0x54;
		SendInput(1, &Input, sizeof(INPUT));
		}
else if (key == "T_U")
		{
		Input.type = INPUT_KEYBOARD;
		Input.ki.dwFlags = KEYEVENTF_KEYUP;
		Input.ki.wScan = 0x54;
		SendInput(1, &Input, sizeof(INPUT));
		}
		//U KEY
else if (key == "U_D")
		{
		Input.type = INPUT_KEYBOARD;
		Input.ki.dwFlags = KEYEVENTF_UNICODE;
		Input.ki.wScan = 0x55;
		SendInput(1, &Input, sizeof(INPUT));
		}
else if (key == "U_U")
		{
		Input.type = INPUT_KEYBOARD;
		Input.ki.dwFlags = KEYEVENTF_KEYUP;
		Input.ki.wScan = 0x55;
		SendInput(1, &Input, sizeof(INPUT));
		}
		//V KEY
else if (key == "V_D")
		{
		Input.type = INPUT_KEYBOARD;
		Input.ki.dwFlags = KEYEVENTF_UNICODE;
		Input.ki.wScan = 0x56;
		SendInput(1, &Input, sizeof(INPUT));
		}
else if (key == "V_U")
		{
		Input.type = INPUT_KEYBOARD;
		Input.ki.dwFlags = KEYEVENTF_KEYUP;
		Input.ki.wScan = 0x56;
		SendInput(1, &Input, sizeof(INPUT));
		}
		//W KEY
else if (key == "W_D")
		{
		Input.type = INPUT_KEYBOARD;
		Input.ki.dwFlags = KEYEVENTF_UNICODE;
		Input.ki.wScan = 0x57;
		SendInput(1, &Input, sizeof(INPUT));
		}
else if (key == "W_U")
		{
		Input.type = INPUT_KEYBOARD;
		Input.ki.dwFlags = KEYEVENTF_KEYUP;
		Input.ki.wScan = 0x57;
		SendInput(1, &Input, sizeof(INPUT));
		}
		//X KEY
else if (key == "X_D")
		{
		Input.type = INPUT_KEYBOARD;
		Input.ki.dwFlags = KEYEVENTF_UNICODE;
		Input.ki.wScan = 0x58;
		SendInput(1, &Input, sizeof(INPUT));
		}
else if (key == "X_U")
		{
		Input.type = INPUT_KEYBOARD;
		Input.ki.dwFlags = KEYEVENTF_KEYUP;
		Input.ki.wScan = 0x58;
		SendInput(1, &Input, sizeof(INPUT));
		}
		//Y KEY
else if (key == "Y_D")
		{
		Input.type = INPUT_KEYBOARD;
		Input.ki.dwFlags = KEYEVENTF_UNICODE;
		Input.ki.wScan = 0x59;
		SendInput(1, &Input, sizeof(INPUT));
		}
else if (key == "Y_U")
		{
		Input.type = INPUT_KEYBOARD;
		Input.ki.dwFlags = KEYEVENTF_KEYUP;
		Input.ki.wScan = 0x59;
		SendInput(1, &Input, sizeof(INPUT));
		}
		//Z KEY
else if (key == "Z_D")
		{
		Input.type = INPUT_KEYBOARD;
		Input.ki.dwFlags = KEYEVENTF_UNICODE;
		Input.ki.wScan = 0x5A;
		SendInput(1, &Input, sizeof(INPUT));
		}
else if (key == "Z_U")
		{
		Input.type = INPUT_KEYBOARD;
		Input.ki.dwFlags = KEYEVENTF_KEYUP;
		Input.ki.wScan = 0x5A;
		SendInput(1, &Input, sizeof(INPUT));
		}


		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void WriteKeyToFile()
{
	std::ofstream macrofile_KW;
	macrofile_KW.open("Keyrecord.csv");

	// KEY FLAGS
	bool kf_LMB{ true };
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

	while (true)
	{
		bool exitLoop{ true };

		auto start = std::chrono::high_resolution_clock::now();
		while (exitLoop)
		{
			//Left MOUSE BUTTON
			if ((GetAsyncKeyState(VK_LBUTTON) & 0x8000) != 0)
			{
				if (kf_LMB == true)
				{
					auto stop = std::chrono::high_resolution_clock::now();
					std::chrono::duration<float> duration = stop - start;
					macrofile_KW << duration.count() << "\n";

					macrofile_KW << "LMB_D" << "\n";
					exitLoop = false;
					kf_LMB = false;
				}

			}
			else if ((!GetAsyncKeyState(VK_LBUTTON)))
			{
				if (kf_LMB == false)
				{
					auto stop = std::chrono::high_resolution_clock::now();
					std::chrono::duration<float> duration = stop - start;
					macrofile_KW << duration.count() << "\n";

					macrofile_KW << "LMB_U" << "\n";
					exitLoop = false;
					kf_LMB = true;
				}
			}

			//SPACE KEY
			if ((GetAsyncKeyState(VK_SPACE) & 0x8000) != 0)
			{
				if (kf_SPACE == true)
				{
					auto stop = std::chrono::high_resolution_clock::now();
					std::chrono::duration<float> duration = stop - start;
					macrofile_KW << duration.count() << "\n";

					macrofile_KW << "SPACE_D" << "\n";
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
					macrofile_KW << duration.count() << "\n";

					macrofile_KW << "SPACE_U" << "\n";
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
					macrofile_KW << duration.count() << "\n";

					macrofile_KW << "A_D" << "\n";
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
					macrofile_KW << duration.count() << "\n";

					macrofile_KW << "A_U" << "\n";
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
					macrofile_KW << duration.count() << "\n";

					macrofile_KW << "B_D" << "\n";
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
					macrofile_KW << duration.count() << "\n";

					macrofile_KW << "B_U" << "\n";
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
					macrofile_KW << duration.count() << "\n";

					macrofile_KW << "C_D" << "\n";
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
					macrofile_KW << duration.count() << "\n";

					macrofile_KW << "C_U" << "\n";
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
					macrofile_KW << duration.count() << "\n";

					macrofile_KW << "D_D" << "\n";
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
					macrofile_KW << duration.count() << "\n";

					macrofile_KW << "D_U" << "\n";
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
					macrofile_KW << duration.count() << "\n";

					macrofile_KW << "E_D" << "\n";
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
					macrofile_KW << duration.count() << "\n";

					macrofile_KW << "E_U" << "\n";
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
					macrofile_KW << duration.count() << "\n";

					macrofile_KW << "F_D" << "\n";
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
					macrofile_KW << duration.count() << "\n";

					macrofile_KW << "F_U" << "\n";
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
					macrofile_KW << duration.count() << "\n";

					macrofile_KW << "G_D" << "\n";
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
					macrofile_KW << duration.count() << "\n";

					macrofile_KW << "G_U" << "\n";
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
					macrofile_KW << duration.count() << "\n";

					macrofile_KW << "H_D" << "\n";
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
					macrofile_KW << duration.count() << "\n";

					macrofile_KW << "H_U" << "\n";
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
					macrofile_KW << duration.count() << "\n";

					macrofile_KW << "I_D" << "\n";
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
					macrofile_KW << duration.count() << "\n";

					macrofile_KW << "I_U" << "\n";
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
					macrofile_KW << duration.count() << "\n";

					macrofile_KW << "J_D" << "\n";
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
					macrofile_KW << duration.count() << "\n";

					macrofile_KW << "J_U" << "\n";
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
					macrofile_KW << duration.count() << "\n";

					macrofile_KW << "K_D" << "\n";
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
					macrofile_KW << duration.count() << "\n";

					macrofile_KW << "K_U" << "\n";
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
					macrofile_KW << duration.count() << "\n";

					macrofile_KW << "L_D" << "\n";
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
					macrofile_KW << duration.count() << "\n";

					macrofile_KW << "L_U" << "\n";
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
					macrofile_KW << duration.count() << "\n";

					macrofile_KW << "M_D" << "\n";
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
					macrofile_KW << duration.count() << "\n";

					macrofile_KW << "M_U" << "\n";
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
					macrofile_KW << duration.count() << "\n";

					macrofile_KW << "N_D" << "\n";
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
					macrofile_KW << duration.count() << "\n";

					macrofile_KW << "N_U" << "\n";
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
					macrofile_KW << duration.count() << "\n";

					macrofile_KW << "O_D" << "\n";
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
					macrofile_KW << duration.count() << "\n";

					macrofile_KW << "O_U" << "\n";
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
					macrofile_KW << duration.count() << "\n";

					macrofile_KW << "P_D" << "\n";
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
					macrofile_KW << duration.count() << "\n";

					macrofile_KW << "P_U" << "\n";
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
					macrofile_KW << duration.count() << "\n";

					macrofile_KW << "Q_D" << "\n";
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
					macrofile_KW << duration.count() << "\n";

					macrofile_KW << "Q_U" << "\n";
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
					macrofile_KW << duration.count() << "\n";

					macrofile_KW << "R_D" << "\n";
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
					macrofile_KW << duration.count() << "\n";

					macrofile_KW << "R_U" << "\n";
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
					macrofile_KW << duration.count() << "\n";

					macrofile_KW << "S_D" << "\n";
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
					macrofile_KW << duration.count() << "\n";

					macrofile_KW << "S_U" << "\n";
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
					macrofile_KW << duration.count() << "\n";

					macrofile_KW << "T_D" << "\n";
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
					macrofile_KW << duration.count() << "\n";

					macrofile_KW << "T_U" << "\n";
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
					macrofile_KW << duration.count() << "\n";

					macrofile_KW << "U_D" << "\n";
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
					macrofile_KW << duration.count() << "\n";

					macrofile_KW << "U_U" << "\n";
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
					macrofile_KW << duration.count() << "\n";

					macrofile_KW << "V_D" << "\n";
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
					macrofile_KW << duration.count() << "\n";

					macrofile_KW << "V_U" << "\n";
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
					macrofile_KW << duration.count() << "\n";

					macrofile_KW << "W_D" << "\n";
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
					macrofile_KW << duration.count() << "\n";

					macrofile_KW << "W_U" << "\n";
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
					macrofile_KW << duration.count() << "\n";

					macrofile_KW << "X_D" << "\n";
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
					macrofile_KW << duration.count() << "\n";

					macrofile_KW << "X_U" << "\n";
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
					macrofile_KW << duration.count() << "\n";

					macrofile_KW << "Y_D" << "\n";
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
					macrofile_KW << duration.count() << "\n";

					macrofile_KW << "Y_U" << "\n";
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
					macrofile_KW << duration.count() << "\n";

					macrofile_KW << "Z_D" << "\n";
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
					macrofile_KW << duration.count() << "\n";

					macrofile_KW << "Z_U" << "\n";
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
	macrofile_KW.close();
}