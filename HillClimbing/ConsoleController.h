#pragma once
#include <windows.h> 
#include <iostream>
#include <string>
#include <vector>  
#include <stdlib.h>  
#include <time.h>  

using namespace std;

void Console_gotoXY(int x, int y);

void Console_Resize(int x, int y);

void Console_Clear();

void Console_ColoredTEXTChar(char m_word, int m_color);

void Console_ColoredTEXT(string m_word, int m_color);

void Console_RainbowWrite(string m_word);

void DrawConsole(FractalGrid m_grid);
