#pragma once

//Header Guard for older systems
#ifndef MYHEADER_H
#define MYHEADER_H

//write
void WriteMouseToFile();
void WriteKeyToFile();


//read
bool isNumber(const std::string &str);
bool mouse_move(int x, int y);
void ReadFromMouseFile();
void ReadFromKeyFile();










#endif