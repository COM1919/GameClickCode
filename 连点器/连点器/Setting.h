#pragma once
#include"Definition.h"
#include"Print.h"
#include"FileOperation.h"
#include"DynamicTitle.h"
#include"HUD.h"

int GetKey()
{
	playMusic;
	Sleep(50);
	int key = 0;
	while (1)
	{
		if (KEY_DOWN(key))
		{
			if (!(key == 1 || key == 2))
			{
				return key;
			}
		}
		key++;
		if (key > 280)
			key = 0;
	}
}

void ShowCursor(bool visible)
{
	CONSOLE_CURSOR_INFO Cursor;
	Cursor.bVisible = visible;
	Cursor.dwSize = sizeof(Cursor);
	HANDLE Hand = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(Hand, &Cursor);
}


/*
int AutoOpen(bool ar)  //Add or Remove
{
	while (1)
	{
		HKEY hKey = 0;
		BYTE Run[10000] = {};
		GetModuleFileName(NULL, (char*)Run, 10000);
		if (Run == NULL)
		{
			switch (iferr((int)Run, 1))
			{
			case IDIGNORE:
				return -1;
			case IDRETRY:
				continue;
			case IDABORT:
				exit(-1);
			case 0:
				break;
			}
		}
		else
		{
			long err = RegOpenKeyEx(HKEY_LOCAL_MACHINE, "Software\\Microsoft\\lwindows\\icurrentversion\\Run", 0, KEY_WRITE, &hKey);
			if (err != ERROR_SUCCESS)
			{
				MessageBox(NULL, (char*)Run, "错误", MB_OK);
				switch (iferr(err, 2))
				{
				case IDIGNORE:
					return -1;
				case IDRETRY:
					continue;
				case IDABORT:
					exit(err);
				case 0:
					break;
				}
			}
			else
			{
				long ret1 = (RegSetValueEx(hKey, "remotecontrol", NULL, REG_SZ, Run, 10000));
				if (ret1 != ERROR_SUCCESS)
				{
					switch (iferr(err, 2))
					{
					case IDIGNORE:
						return -1;
					case IDRETRY:
						continue;
					case IDABORT:
						exit(err);
					case 0:
						break;
					}
				}
			}
			RegCloseKey(hKey);
		}
	}
	return -1;
}
*/

bool DelDispose()  //用户是否选择删除 false 没有 true 有
{
	cls;
	printf("\n\n\n\t你确定要删除连点器的所有配置文件吗?\n");
	printf("\t这意味着你设置的所有设置都会恢复默认!\n");
	printf("\tY(确定) / N(返回)");

	while (1)
	{
		if (KEY_DOWN('Y'))
		{
			DelFile(file_lkey, cfile_lkey, "D:\\", true);
			DelFile(file_rkey, cfile_rkey, "D:\\", true);
			DelFile(help, chelp, "D:\\", true);
			DelFile(tilits, ctilits, "D:\\", true);
			DelFile(nore, cnore, "D:\\", true);
			DelFile(rfss1, crfss1, "D:\\", true);
			DelFile(lfss1, clfss1, "D:\\", true);
			DelFile(lfss2, clfss2, "D:\\", true);
			DelFile(rfss2, crfss2, "D:\\", true);
			DelFile(rfss3, crfss3, "D:\\", true);
			DelFile(lfss3, clfss3, "D:\\", true);
			DelFile(san, csan, "D:\\", true);
			DelFile(fsskey1, cfsskey1, "D:\\", true);
			DelFile(fsskey2, cfsskey2, "D:\\", true);
			DelFile(fsskey3, cfsskey3, "D:\\", true);
			playMusic;
			return true;
		}
		if (KEY_DOWN('N'))
		{
			playMusic;
			return false;
		}
	}
}

int else_set()
{
	playMusic;
	while (1)
	{
		cls;
		colorprint("|", LIGHT_CYAN);
		printf("按下 1 开关动态标题：");
		colorprint((tl) ? "已开启\n" : "已关闭\n", (tl) ? LIGHT_GREEN : LIGHT_RED);
		colorprint("|", LIGHT_CYAN);
		printf("按下 2 开关自动隐藏窗口：");
		colorprint((yc) ? "已开启\n" : "已关闭\n", (yc) ? LIGHT_GREEN : LIGHT_RED);
		/*
		printf("按下 4 开关开机自动启动：");
		colorprint((ao) ? "已开启\n" : "已关闭\n", (ao) ? LIGHT_GREEN : LIGHT_RED);
		*/
		colorprint("|", LIGHT_CYAN);
		printf("按下 3 删除连点器所有配置文件\n");
		if (yc)
		{
			SetPos(0, 8);
			printf("当打开设置时显示窗口，退出设置时隐藏窗口。按 ");
			colorprint("F12", LIGHT_YELLOW);
			printf(" 打开设置。");
		}
		SetPos(0, 3);
		colorprint("|", LIGHT_CYAN);
		printf("回车返回\n");

		while (1)
		{
			if (KEY_DOWN('1') | KEY_DOWN(97))
			{
				tl = !tl;
				playMusic;
				ct();
				break;
			}
			if (KEY_DOWN('2') | KEY_DOWN(98))
			{
				yc = !yc;
				playMusic;
				break;
			}
			/*
			if (KEY_DOWN('4') | KEY_DOWN(100))
			{
				if(AutoOpen(!ao) != 0)
				{
					ao = !ao;
				}
				break;
			}
			*/
			if (KEY_DOWN('3') | KEY_DOWN(99))
			{
				if (DelDispose())
				{
					cls;
					playMusic;
					colorprint("\n\n\n\n\t\t\t删除成功!", LIGHT_RED);
				}
				break;
			}
			if (KEY_DOWN(13))
			{
				DelFile(nore, cnore, "D:\\");
				DelFile(tilits, ctilits, "D:\\");
				WriteDispose(nore, cnore, "D:\\", "w", (yc) ? 1 : 0);
				WriteDispose(tilits, ctilits, "D:\\", "w", (tl) ? 1 : 0);
				playMusic;
				return 0;
			}
		}
	}
}

int setspeed()
{
	cls;
	playMusic;
	colorprint("|", LIGHT_CYAN);
	printf("按下");
	colorprint(" 1 ", GREEN);
	printf("设置低速模式(16CPS)\n");
	playMusic;
	colorprint("|", LIGHT_CYAN);
	printf("按下");
	colorprint(" 2 ", GREEN);
	printf("设置中速模式(30CPS)\n");
	playMusic;
	colorprint("|", LIGHT_CYAN);
	printf("按下");
	colorprint(" 3 ", GREEN);
	printf("设置高速模式(60CPS)\n");
	playMusic;
	colorprint("|", LIGHT_CYAN);
	printf("按下");
	colorprint(" 4 ", GREEN);
	printf("设置 急速 模式!(需要你的电脑性能好,无限制CPS!!!)\n");
	playMusic;
	colorprint("|", LIGHT_CYAN);
	printf("按下");
	colorprint(" 0 ", GREEN);
	printf("自定义CPS（每秒点击数）\n");
	playMusic;
	colorprint("|", LIGHT_CYAN);
	printf("回车返回\n\n");
	colorprint("你知道吗?速度并不是固定的，CPS速度快慢和电脑性能有关。", LIGHT_GREEN);

	while (1)
	{
		if (KEY_DOWN('1') | KEY_DOWN(97))
		{
			playMusic;
			return 16;
		}
		if (KEY_DOWN('2') | KEY_DOWN(98))
		{
			playMusic;
			return 30;
		}
		if (KEY_DOWN('3') | KEY_DOWN(99))
		{
			playMusic;
			return 60;
		}
		if (KEY_DOWN('4') | KEY_DOWN(100))
		{
			playMusic;
			return 1000;
		}
		if (KEY_DOWN('0') | KEY_DOWN(96))
		{
			int sp = Default_Cps;
			while (1)
			{
				cls;
				ClearStream();
				colorprint("|", LIGHT_CYAN);
				printf("请输入CPS最高限制：");
				playMusic;
				scanf_s("%d", &sp);
				if (sp > 1000 || sp < 5)
				{
					MessageBox(NULL, "你设置的CPS无效!\n必须在 5 到 1000 之间!", "错误", MB_OK | MB_ICONHAND);
					continue;
				}
				else
				{
					break;
				}
			}
			return sp;
		}
		if (KEY_DOWN(13))
		{
			playMusic;
			return Default_Cps;
		}
	}
}

void f()
{
	playMusic;
	while (1)
	{
		cls;
		playMusic;
		colorprint("|", LIGHT_CYAN);
		printf("按 1 国际防封模式：");
		colorprint((fg) ? "已开启\n" : "已关闭\n", (fg) ? LIGHT_GREEN : LIGHT_RED);
		colorprint("|", LIGHT_CYAN);
		printf("回车返回");
		SetPos(0, 6);
		colorprint("国际防封是通过降低CPS来达到不被服务器反作弊检测到。\n", LIGHT_GREEN);
		colorprint("20以下的CPS和100CPS没有什么区别，用就行了。", LIGHT_GREEN);

		while (1)
		{
			if (KEY_DOWN('1') | KEY_DOWN(97))
			{
				fg = !fg;
				SetPos(0,19);
				colorprint((fg) ? "已开启\n" : "已关闭\n", (fg) ? LIGHT_GREEN : LIGHT_RED);
				playMusic;
				break;
			}
			if (KEY_DOWN(13))
			{
				L_CPS = (fg) ? 17 : Default_Cps;
				R_CPS = (fg) ? 17 : Default_Cps;
				playMusic;
				return;
			}
		}
	}
}

int setkey()
{
	cls;
	playMusic;
	colorprint("|", LIGHT_CYAN);
	printf("按下");
	colorprint(" 1 ", GREEN);
	printf("设置连点左键的快捷键\n");
	playMusic;
	colorprint("|", LIGHT_CYAN);
	printf("按下");
	colorprint(" 2 ", GREEN);
	printf("设置连点右键的快捷键\n");
	playMusic;
	colorprint("|", LIGHT_CYAN);
	printf("回车返回");

	while (1)
	{
		if (KEY_DOWN('1') | KEY_DOWN(97))
		{
			cls;
			playMusic;
			colorprint("|", LIGHT_CYAN);
			printf("请按下连点左键的快捷键：");
			DelFile(file_lkey, cfile_lkey, "D:\\");
			L_KEY = GetKey();
			return WriteDispose(file_lkey, cfile_lkey, "D:\\", "w", L_KEY);
		}
		if (KEY_DOWN('2') | KEY_DOWN(98))
		{
			cls;
			playMusic;
			colorprint("|", LIGHT_CYAN);
			printf("请按下连点右键的快捷键：");
			DelFile(file_rkey, cfile_rkey, "D:\\");
			R_KEY = GetKey();
			return WriteDispose(file_rkey, cfile_rkey, "D:\\", "w", R_KEY);
		}
		if (KEY_DOWN(13))
		{
			return 0;
		}
	}
}

void printspeed(bool ws = true, int* ri = 0, int* li = 0) //ws:判断是否是普通CPS设置,ri:要修改的值，li:一样的，一个左键。一个右键
{
	cls;
	playMusic;
	colorprint("|", LIGHT_CYAN);
	printf("按下");
	colorprint(" 1 ", GREEN);
	printf("设置连点左键的速度\n");
	playMusic;
	colorprint("|", LIGHT_CYAN);
	printf("按下");
	colorprint(" 2 ", GREEN);
	printf("设置连点右键的速度\n");
	playMusic;
	colorprint("|", LIGHT_CYAN);
	printf("回车返回");

	while (1)
	{
		if (KEY_DOWN('1') | KEY_DOWN(97))
		{
			playMusic;
			int sp = setspeed();
			if (sp != 0)
			{
				if (ws)
				{
					L_CPS = sp;
					return;
				}
				else
				{
					*li = sp;
					return;
				}
			}
		}
		if (KEY_DOWN('2') | KEY_DOWN(98))
		{
			playMusic;
			int sp = setspeed();
			if (sp != 0)
			{
				if (ws)
				{
					R_CPS = sp;
					return;
				}
				else
				{
					*ri = sp;
					return;
				}
			}
		}
		if (KEY_DOWN(13))
		{
			return;
		}
	}
}

bool ifprsp()
{
	if (fg)
	{
		int xx = MessageBox(NULL, TEXT("当前已开启防封模式如果要设置速度将自动关闭防封模式。\n如果强行在防封模式打开状态下修改连点器速度，\n那么防封模式可能不生效,除非你知道你在做什么!\n\n\t\t选择“是”关闭防封模式并设置CPS\n\t\t选择“否”忽略提示并继续\n\t\t选择“取消”返回到设置"), TEXT("注意!"), MB_YESNOCANCEL | MB_ICONQUESTION | MB_SYSTEMMODAL);
		switch (xx)
		{
		case IDYES:
			fg = false;
			printspeed();
			break;
		case IDCANCEL:
			return false;
		case IDNO:
			printspeed();
			break;
		default:
			return false;
		}

	}
	else
		printspeed();
	return true;
}

void SwitchingSpeedSet(int* key, int* ri = 0, int* li = 0, int pos = 0)
{
	cls;
	playMusic;
	colorprint("|", LIGHT_CYAN);
	printf("按下 1 设置速度\n");
	playMusic;
	colorprint("|", LIGHT_CYAN);
	printf("按下 2 设置快捷键\n");
	playMusic;
	colorprint("|", LIGHT_CYAN);
	printf("回车返回");
	while (1)
	{
		if (KEY_DOWN('1') | KEY_DOWN(97))
		{
			printspeed(false, ri, li);
			return;
		}
		if (KEY_DOWN('2') | KEY_DOWN(98))
		{
			cls;
			printf("请按下快速切换 %d 档的快捷键：", pos);
			*key = GetKey();
			return;
		}
		if (KEY_DOWN(13))
		{
			return;
		}
	}
}

void SwitchingSpeed()
{
	while (1)
	{
		cls;
		playMusic;
		colorprint("快速切换速度是在你按下你快捷键时将速度设置为你设定的速度。\n", LIGHT_GREEN);
		playMusic;
		colorprint("--------------------------------------\n", LIGHT_CYAN);
		playMusic;
		printf("按下 1 设置1档");
		colorprint(" | ", LIGHT_CYAN);
		printf("右CPS:%d", rss1);
		colorprint(" | ", LIGHT_CYAN);
		printf("左CPS:%d", lss1);
		colorprint(" | \n", LIGHT_CYAN);
		playMusic;
		printf("按下 2 设置2档");
		colorprint(" | ", LIGHT_CYAN);
		printf("右CPS:%d", rss2);
		colorprint(" | ", LIGHT_CYAN);
		printf("左CPS:%d", lss2);
		colorprint(" | \n", LIGHT_CYAN);
		playMusic;
		printf("按下 3 设置3档");
		colorprint(" | ", LIGHT_CYAN);
		printf("右CPS:%d", rss3);
		colorprint(" | ", LIGHT_CYAN);
		printf("左CPS:%d", lss3);
		colorprint(" | \n", LIGHT_CYAN);
		playMusic;
		colorprint("--------------------------------------\n", LIGHT_CYAN);
		playMusic;
		colorprint("|", LIGHT_CYAN);
		printf("按 4 开关快速切换速度：");
		colorprint((onss) ? "已开启\n" : "已关闭\n", (onss) ? LIGHT_GREEN : LIGHT_RED);
		playMusic;
		colorprint("|", LIGHT_CYAN);
		printf("回车退出\n\n");
		playMusic;
		colorprint("F6 F7 F8 ", LIGHT_YELLOW);
		printf("分别切换到 ");
		colorprint("1挡 2挡 3挡\n\n", LIGHT_YELLOW);
		playMusic;
		colorprint("注意!开启国际防封模式后无法使用快速切换CPS!", LIGHT_RED);

		while (1)
		{
			if (KEY_DOWN('1') | KEY_DOWN(97))
			{
				SwitchingSpeedSet(&sskey1, &rss1, &lss1, 1);
				playMusic;
				break;
			}
			if (KEY_DOWN('2') | KEY_DOWN(98))
			{
				SwitchingSpeedSet(&sskey2, &rss2, &lss2, 2);
				playMusic;
				break;
			}
			if (KEY_DOWN('3') | KEY_DOWN(99))
			{
				SwitchingSpeedSet(&sskey3, &rss3, &lss3, 3);
				playMusic;
				break;
			}
			if (KEY_DOWN('4') | KEY_DOWN(100))
			{
				playMusic;
				onss = !onss;
				SetPos(23, 6);
				colorprint((onss) ? "已开启\n" : "已关闭\n", (onss) ? LIGHT_GREEN : LIGHT_RED);
			}
			if (KEY_DOWN(13))
			{
				DelFile(rfss1, crfss1, "D:\\");
				DelFile(rfss2, crfss2, "D:\\");
				DelFile(rfss3, crfss3, "D:\\");
				DelFile(lfss1, clfss1, "D:\\");
				DelFile(lfss2, clfss2, "D:\\");
				DelFile(lfss3, clfss3, "D:\\");
				DelFile(fsskey3, cfsskey3, "D:\\");
				DelFile(fsskey2, cfsskey2, "D:\\");
				DelFile(fsskey1, cfsskey1, "D:\\");
				DelFile(fonss, cfonss, "D:\\");
				WriteDispose(lfss1, clfss1, "D:\\", "w", lss1);
				WriteDispose(lfss2, clfss2, "D:\\", "w", lss2);
				WriteDispose(lfss3, clfss3, "D:\\", "w", lss3);
				WriteDispose(rfss1, crfss1, "D:\\", "w", rss1);
				WriteDispose(rfss2, crfss2, "D:\\", "w", rss2);
				WriteDispose(rfss3, crfss3, "D:\\", "w", rss3);
				WriteDispose(fsskey1, cfsskey1, "D:\\", "w", sskey1);
				WriteDispose(fsskey2, cfsskey2, "D:\\", "w", sskey2);
				WriteDispose(fsskey3, cfsskey3, "D:\\", "w", sskey3);
				WriteDispose(fonss, cfonss, "D:\\", "w", (onss) ? 1 : 0);
				playMusic;
				return;
			}
		}
	}
}

void set()
{
	if (yc)
		ShowWindow(testwindow, true);
	while (1)
	{
		cls;
		playMusic;
		colorprint("|", LIGHT_CYAN);
		printf("按下 0 退出\n");
		playMusic;
		colorprint("|", LIGHT_CYAN);
		printf("按下 1 设置连点器快捷键\n");
		playMusic;
		colorprint("|", LIGHT_CYAN);
		printf("按下 2 设置连点器速度\n");
		playMusic;
		colorprint("|", LIGHT_CYAN);
		printf("按下 3 打开防封设置\n");
		playMusic;
		colorprint("|", LIGHT_CYAN);
		printf("按下 4 设置快速设置速度\n");
		playMusic;
		colorprint("|", LIGHT_CYAN);
		printf("按下 5 打开其他设置\n");
		/*playMusic;
		printf("按下 6 下载/更新 连点器\n");*/

		while (1)
		{
			if (KEY_DOWN('1') | KEY_DOWN(97))
			{
				if (setkey() != 0)
				{
					playMusic;
					cls;
					colorprint("\n\t设置失败!", LIGHT_RED);
					Sleep(400);
				}
				else
				{
					playMusic;
					cls;
					colorprint("\n\t设置成功!", LIGHT_GREEN);
					Sleep(400);
					break;
				}
			}
			if (KEY_DOWN('2') | KEY_DOWN(98))
			{
				if (!ifprsp())
					break;
				else
				{
					playMusic;
					cls;
					colorprint("\n\t设置成功!", LIGHT_GREEN);
					Sleep(400);
					break;
				}
			}
			if (KEY_DOWN('3') | KEY_DOWN(99))
			{
				f();
				playMusic;
				cls;
				colorprint("\n\t设置成功!", LIGHT_GREEN);
				Sleep(400);
				break;
			}
			if (KEY_DOWN('5') | KEY_DOWN(101))
			{
				if (else_set() != 0)
				{
					playMusic;
					cls;
					colorprint("\n\t设置失败!", LIGHT_RED);
					Sleep(400);
				}
				else
				{
					playMusic;
					cls;
					colorprint("\n\t设置成功!", LIGHT_GREEN);
					Sleep(400);
					break;
				}
			}
			if (KEY_DOWN('4') | KEY_DOWN(100))
			{
				SwitchingSpeed();
				playMusic;
				cls;
				colorprint("\n\t设置成功!", LIGHT_GREEN);
				Sleep(400);
				break;
			}
			/*if (KEY_DOWN('6') | KEY_DOWN(102))
			{
				cls;
				Updata();
				break;
			}*/
			if (KEY_DOWN('0') | KEY_DOWN(96))
			{
				cls;
				prin();
				return;
			}
		}
	}
}