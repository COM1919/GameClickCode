#pragma once
#include"Definition.h"

void colorprint(const char ch[MAX], int color, int bcolor = 0)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color +bcolor * 0x10);
	printf("%s", ch);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

void SetColor(int color, int bcolor = 0)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color + bcolor * 0x10);
}

void SetPos(int x, int y)
{
	COORD pos = { x,y };
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(out, pos);
}

void SetPos(COORD pos)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(out, pos);
}

void ClearStream()
{
	keybd_event(72, NULL, 0, NULL);
	keybd_event(72, NULL, KEYEVENTF_KEYUP, NULL);
	keybd_event(13, NULL, 0, NULL);
	keybd_event(13, NULL, KEYEVENTF_KEYUP, NULL);
	while (1)
	{
		int c = getchar();
		if (c == 'H' || c == 'h')
		{
			getchar();
			cls;
			return;
		}
	}
}