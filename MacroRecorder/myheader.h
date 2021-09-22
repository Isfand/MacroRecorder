#pragma once

//Header Guard for older systems
#ifndef MYHEADER_H
#define MYHEADER_H

//write
void WritePosFile();
void WriteMouseFile();
void WriteKeyboardFile();


//read
bool isNumber(const std::string &str);
bool mouse_move(int x, int y);
void ReadPosFile();
void ReadKeyboardFile();
void ReadMouseFile();










#endif