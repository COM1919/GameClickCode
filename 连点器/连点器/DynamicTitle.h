#pragma once
#include"Definition.h"
#include"Print.h"

DWORD _stdcall autoTitle(LPVOID lpParam)
{
	int sleeps = 30;
	while (tl)
	{
		system("title ");
		Sleep(sleeps);
		system("title 我");
		Sleep(sleeps);
		system("title 我的");
		Sleep(sleeps);
		system("title 我的世");
		Sleep(sleeps);
		system("title 我的世界");
		Sleep(sleeps);
		system("title 我的世界G");
		Sleep(sleeps);
		system("title 我的世界GC");
		Sleep(sleeps);
		system("title 我的世界GC连");
		Sleep(sleeps);
		system("title 我的世界GC连点");
		Sleep(sleeps);
		system("title 我的世界GC连点器");
		Sleep(sleeps);
		system("title 我的世界GC连点器  G");
		Sleep(sleeps);
		system("title 我的世界GC连点器  Ga");
		Sleep(sleeps);
		system("title 我的世界GC连点器  Gam");
		Sleep(sleeps);
		system("title 我的世界GC连点器  Game ");
		Sleep(sleeps);
		system("title 我的世界GC连点器  Game C");
		Sleep(sleeps);
		system("title 我的世界GC连点器  Game Cl");
		Sleep(sleeps);
		system("title 我的世界GC连点器  Game Cli");
		Sleep(sleeps);
		system("title 我的世界GC连点器  Game Clic");
		Sleep(sleeps);
		system("title 我的世界GC连点器  Game Click");
		Sleep(sleeps * 10);
		system("title 我的世界GC连点器  Game Clic");
		Sleep(sleeps);
		system("title 我的世界GC连点器  Game Cli");
		Sleep(sleeps);
		system("title 我的世界GC连点器  Game Cl");
		Sleep(sleeps);
		system("title 我的世界GC连点器  Game C");
		Sleep(sleeps);
		system("title 我的世界GC连点器  Game ");
		Sleep(sleeps);
		system("title 我的世界GC连点器  Game");
		Sleep(sleeps);
		system("title 我的世界GC连点器  Gam");
		Sleep(sleeps);
		system("title 我的世界GC连点器  Ga");
		Sleep(sleeps);
		system("title 我的世界GC连点器  G");
		Sleep(sleeps);
		system("title 我的世界GC连点器 ");
		Sleep(sleeps);
		system("title 我的世界GC连点器");
		Sleep(sleeps);
		system("title 我的世界GC连点");
		Sleep(sleeps);
		system("title 我的世界GC连");
		Sleep(sleeps);
		system("title 我的世界GC");
		Sleep(sleeps);
		system("title 我的世界G");
		Sleep(sleeps);
		system("title 我的世界");
		Sleep(sleeps);
		system("title 我的世");
		Sleep(sleeps);
		system("title 我的");
		Sleep(sleeps);
		system("title 我");
		Sleep(sleeps);
		system("title ");
		Sleep(sleeps * 10);
	}
	system("title 我的世界GC连点器  Game Click");
	return 0;
}

void ct()
{
	while (tl)
	{
		if (DWORD autoti = CreateThread(NULL, 0, autoTitle, 0, 0, NULL) == NULL)
		{
			int xs = MessageBox(NULL, TEXT("程序尝试创建线程时出现错误!"), TEXT("错误"), MB_ABORTRETRYIGNORE | MB_ICONHAND);
			switch (xs)
			{
			case IDIGNORE:
				break;
			case IDRETRY:
				continue;
			case IDABORT:
				exit(1);
			}
		}
		else
			return;
	}
}