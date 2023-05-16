#pragma once
#include"Definition.h"
#include"FileOperation.h"
#include"Print.h"

void xy()
{
	int xzs = MessageBox(NULL, TEXT(UA), TEXT("用户协议"), MB_YESNO);
	while (1)
	{
		if (xzs == IDYES)
			return;
		else if (xzs == IDNO)
			exit(0);
	}
}


void helps()
{
	cls;
	playMusic;
	printf("默认快捷键");
	colorprint("Tab", LIGHT_YELLOW);
	printf("或");
	colorprint("鼠标侧后键", LIGHT_YELLOW);
	printf("连点鼠标右键（鼠标侧面的按键，有一些鼠标没有）\n");
	playMusic;
	printf("默认快捷键");
	colorprint("Ctrl", LIGHT_YELLOW);
	printf("或");
	colorprint("鼠标侧前键", LIGHT_YELLOW);
	printf("连点鼠标左键（鼠标侧面的按键，有一些鼠标没有）\n");
	playMusic;
	colorprint("按 F12 ", LIGHT_YELLOW);
	printf("打开连点器的设置\n");
	pause;
	cls;
	playMusic;
	printf("你知道吗：cps指的是每秒的点击数，和fps差不多，但是fps指的是每秒的刷新频率。\n所以连点器通常会用cps代表速度或每秒的点击数\n");
	pause;
	cls;
	playMusic;
	printf("防封模式开启教程：按F12打开设置 -> 按3打开防封设置 -> 按1打开防封模式\n");
	pause;
	cls;
	playMusic;
	printf("还有什么不懂的去QQ群问 \n官方群：915344208 制作：MC1919\n\n");
	colorprint("请确认你是从官方路径下载，否则中毒后果自负!\n\n", LIGHT_RED);
	pause;
	cls;
}

void HelpSetKey()
{
	cls;
	Sleep(350);
	playMusic;
	printf("接下来设置左键快捷键。");
	Sleep(800);
	playMusic;
	colorprint("|", LIGHT_CYAN);
	printf("请输入连点左键的快捷键：");
	WriteDispose(file_lkey, cfile_lkey, "D:\\", "w", GetKey());
	Sleep(350);
	playMusic;
	printf("然后设置右键快捷键。");
	Sleep(800);
	cls;
	playMusic;
	colorprint("|", LIGHT_CYAN);
	printf("请输入连点右键的快捷键：");
	WriteDispose(file_rkey, cfile_rkey, "D:\\", "w", GetKey());
	playMusic;
	cls;
	Sleep(100);
	colorprint("\n\t设置成功!", LIGHT_GREEN);
	Sleep(800);
	cls;
}

void HelpSetSS()
{
	cls;
	playMusic;
	printf("你是否保持要开启“快速切换CPS”选项\n\n");
	playMusic;
	colorprint("|", LIGHT_CYAN);
	printf("按 1 开关快速切换CPS：");
	colorprint((onss) ? "已开启\n\n" : "已关闭\n\n", (onss) ? LIGHT_GREEN : LIGHT_RED);
	playMusic;
	printf("快速设置CPS可以允许你在使用或者PVP时快速切换CPS\n");
	playMusic;
	printf("目前有 3 个档位，每个档位都可以自由设置左右键CPS和切换该档位的快捷键。\n\n");
	playMusic;
	colorprint("|", LIGHT_CYAN);
	printf("回车继续\n");

	while (1)
	{
		if (KEY_DOWN('1') || KEY_DOWN(97))
		{
			playMusic;
			onss = !onss;
			SetPos(22, 2);
			colorprint((onss) ? "已开启\n" : "已关闭\n", (onss) ? LIGHT_GREEN : LIGHT_RED);
		}
		if (KEY_DOWN(13))
		{
			DelFile(fonss, cfonss, "D:\\");
			WriteDispose(fonss, cfonss, "D:\\", "w", (onss) ? 1 : 0);
			return;
		}
	}
}

void Load()
{
	if (!(_access(help, 0) == 0) && !(_access(chelp, 0) == 0))
	{
		xy();
		helps();
		HelpSetSS();
		while (1)
		{
			cls;
			playMusic;
			printf("由于你是第一次使用连点器所以请设置左右键的快捷键。\n");
			playMusic;
			printf("你是否要设置快捷键? Y(是) / N(否)");
			while (1)
			{
				if (KEY_DOWN('Y'))
				{
					playMusic;
					HelpSetKey();
					srand(time(NULL));
					WriteDispose(help, chelp, "D:\\", "w", rand() % 99999999 + 1000000);
					MessageBox(NULL, EM, "GC连点器", MB_OK);
					return;
				}
				if (KEY_DOWN('N'))
				{
					cls;
					playMusic;
					printf("\n\n\n\t你确定不需要设置快捷键吗?如果不设置可以使用默认快捷键\n");
					playMusic;
					printf("\t默认快捷键：Tab连点右键，Alt连点左键\n");
					playMusic;
					printf("\t或者按鼠标侧后键连点右键，鼠标侧前键连点鼠标左键。\n");
					playMusic;
					printf("\tY(确定) / N(返回)");
					while (1)
					{
						if (KEY_DOWN('Y'))
						{
							playMusic;
							srand(time(NULL));
							WriteDispose(help, chelp, "D:\\", "w", rand() % 99999999 + 1000000);
							cls;
							MessageBox(NULL, EM, "GC连点器", MB_OK);
							return;
						}
						if (KEY_DOWN('N'))
						{
							playMusic;
							cls;
							break;
						}
					}
					break;
				}
			}
		}
	}
	LoadTime = difftime(clock(), start);
	LoadTime = LoadTime / 1000;
}