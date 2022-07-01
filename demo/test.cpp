#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <ctime>
#include <conio.h>
#include <Windows.h>

#include "FindPathBFS.h"
using namespace std;

int dir[4][2] = {{0,1}, {0,-1}, {1,0}, {-1, 0}};

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
#define HEAD 0

int speed = 0;

void gotoxy(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void setColor(unsigned short ForeColor = 7, unsigned short BackGroundColor = 0)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, ForeColor + BackGroundColor * 0x10);
}

class GameSetting
{
	public:
			static const int window_height = 40;
			static const int window_width = 80;
	public:
			static void GameInit()
			{
				char buffer[32];
				sprintf_s(buffer, "mode con cols=%d lines=%d", window_height, window_width);
				system(buffer);

				HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
				CONSOLE_CURSOR_INFO CursorInfo;
				GetConsoleCursorInfo(handle, &CursorInfo);
				CursorInfo.bVisible = false;
				SetConsoleCursorInfo(handle, &CursorInfo);

				srand((unsigned int)(time(0)));
			}
};

class PrintInfo
{
	public:
			static void DrawChoiceInfo()
			{
				gotoxy(GameSetting::window_width / 2 - 10, GameSetting::window_height / 2 - 5);
				cout << "请选择游戏模式: " << endl;
				gotoxy(GameSetting::window_width / 2 - 10, GameSetting::window_height / 2 - 3);
				cout << "1.手动操作模式: " << endl;
				gotoxy(GameSetting::window_width / 2 - 10, GameSetting::window_height / 2 - 1);
				cout << "2.AI智能模式: " << endl;
				gotoxy(GameSetting::window_width / 2 - 10, GameSetting::window_height / 2 + 1);
				cout << "请输入您的选择->";
			}

			static void DrawMap()
			{
				system("cls");
				int i, j;
				for(i = 0; i < GameSetting::window_width; i++)
					cout << "#";
				cout << endl;
				for(i = 0; i < GameSetting::window_height-2; i++)
				{
					for(j = 0; j < GameSetting::window_width; j++)
					{
						if(i == 13 && j >= GameSetting::window_width - 29)
						{
							cout << "#";
							continue;
						}
						if(j == 0 || j == GameSetting::window_width - 29 || j == GameSetting::window_width-1)
						{
							cout << "#";
						}
						else
						{
							cout << " ";
						}
					}
					cout << endl;
				}
				for(i = 0; i < GameSetting::window_width; i++)
					cout << "#";
			}

			static void GameOver(int score)
			{
				setColor(12, 0);
			}
};



int main()
{
	

	return 0;
}
