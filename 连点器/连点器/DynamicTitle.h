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
		system("title ��");
		Sleep(sleeps);
		system("title �ҵ�");
		Sleep(sleeps);
		system("title �ҵ���");
		Sleep(sleeps);
		system("title �ҵ�����");
		Sleep(sleeps);
		system("title �ҵ�����G");
		Sleep(sleeps);
		system("title �ҵ�����GC");
		Sleep(sleeps);
		system("title �ҵ�����GC��");
		Sleep(sleeps);
		system("title �ҵ�����GC����");
		Sleep(sleeps);
		system("title �ҵ�����GC������");
		Sleep(sleeps);
		system("title �ҵ�����GC������  G");
		Sleep(sleeps);
		system("title �ҵ�����GC������  Ga");
		Sleep(sleeps);
		system("title �ҵ�����GC������  Gam");
		Sleep(sleeps);
		system("title �ҵ�����GC������  Game ");
		Sleep(sleeps);
		system("title �ҵ�����GC������  Game C");
		Sleep(sleeps);
		system("title �ҵ�����GC������  Game Cl");
		Sleep(sleeps);
		system("title �ҵ�����GC������  Game Cli");
		Sleep(sleeps);
		system("title �ҵ�����GC������  Game Clic");
		Sleep(sleeps);
		system("title �ҵ�����GC������  Game Click");
		Sleep(sleeps * 10);
		system("title �ҵ�����GC������  Game Clic");
		Sleep(sleeps);
		system("title �ҵ�����GC������  Game Cli");
		Sleep(sleeps);
		system("title �ҵ�����GC������  Game Cl");
		Sleep(sleeps);
		system("title �ҵ�����GC������  Game C");
		Sleep(sleeps);
		system("title �ҵ�����GC������  Game ");
		Sleep(sleeps);
		system("title �ҵ�����GC������  Game");
		Sleep(sleeps);
		system("title �ҵ�����GC������  Gam");
		Sleep(sleeps);
		system("title �ҵ�����GC������  Ga");
		Sleep(sleeps);
		system("title �ҵ�����GC������  G");
		Sleep(sleeps);
		system("title �ҵ�����GC������ ");
		Sleep(sleeps);
		system("title �ҵ�����GC������");
		Sleep(sleeps);
		system("title �ҵ�����GC����");
		Sleep(sleeps);
		system("title �ҵ�����GC��");
		Sleep(sleeps);
		system("title �ҵ�����GC");
		Sleep(sleeps);
		system("title �ҵ�����G");
		Sleep(sleeps);
		system("title �ҵ�����");
		Sleep(sleeps);
		system("title �ҵ���");
		Sleep(sleeps);
		system("title �ҵ�");
		Sleep(sleeps);
		system("title ��");
		Sleep(sleeps);
		system("title ");
		Sleep(sleeps * 10);
	}
	system("title �ҵ�����GC������  Game Click");
	return 0;
}

void ct()
{
	while (tl)
	{
		if (DWORD autoti = CreateThread(NULL, 0, autoTitle, 0, 0, NULL) == NULL)
		{
			int xs = MessageBox(NULL, TEXT("�����Դ����߳�ʱ���ִ���!"), TEXT("����"), MB_ABORTRETRYIGNORE | MB_ICONHAND);
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