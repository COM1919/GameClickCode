#include"Setting.h"
#include"Load.h"

int run()
{
	mainLoad();
	int L_SLEEP = Default_Cps;
	int R_SLEEP = Default_Cps;
	while (1)
	{
		if (KEY_DOWN(L_KEY) || KEY_DOWN(MAIN_L_KEY))
		{
			mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
			Sleep(R_SLEEP);
		}

		if (KEY_DOWN(R_KEY) || KEY_DOWN(MAIN_R_KEY))
		{
			mouse_event(MOUSEEVENTF_RIGHTDOWN | MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
			Sleep(L_SLEEP);
		}

		if (KEY_DOWN(VK_F12))
		{
			set();
			R_SLEEP = 1000 / R_CPS;
			L_SLEEP = 1000 / L_CPS;
		}
		if (KEY_DOWN(sskey1))
		{
			if ((!fg) && onss)
			{
				L_SLEEP = 1000 / lss1;
				R_SLEEP = 1000 / rss1;
				SetPos(8, 7);
				playMusic;
				colorprint("右键CPS：", LIGHT_GREEN);
				SetColor(LIGHT_YELLOW);
				printf("%d", rss1);
				SetColor(CYAN);
				printf(" | ");
				SetColor(LIGHT_GREEN);
				colorprint("左键CPS：", LIGHT_GREEN);
				SetColor(LIGHT_YELLOW);
				printf("%d\n\n", lss1);
				SetColor(7);
			}
		}
		if (KEY_DOWN(sskey2))
		{
			if ((!fg) && onss)
			{
				L_SLEEP = 1000 / lss2;
				R_SLEEP = 1000 / rss2;
				SetPos(8, 7);
				playMusic;
				colorprint("右键CPS：", LIGHT_GREEN);
				SetColor(LIGHT_YELLOW);
				printf("%d", rss2);
				SetColor(CYAN);
				printf(" | ");
				SetColor(LIGHT_GREEN);
				colorprint("左键CPS：", LIGHT_GREEN);
				SetColor(LIGHT_YELLOW);
				printf("%d\n\n", lss2);
				SetColor(7);
			}
		}
		if (KEY_DOWN(sskey3))
		{
			if ((!fg) && onss)
			{
				L_SLEEP = 1000 / lss3;
				R_SLEEP = 1000 / rss3;
				SetPos(8, 7);
				playMusic;
				colorprint("右键CPS：", LIGHT_GREEN);
				SetColor(LIGHT_YELLOW);
				printf("%d", rss3);
				SetColor(CYAN);
				printf(" | ");
				SetColor(LIGHT_GREEN);
				colorprint("左键CPS：", LIGHT_GREEN);
				SetColor(LIGHT_YELLOW);
				printf("%d\n\n", lss3);
				SetColor(7);
			}
		}
	}
}

void LoadSet()
{
	RECT rec;
	GetWindowRect(testwindow, &rec);
	MoveWindow(testwindow, 10, 15, rec.right - rec.left, rec.bottom - rec.top, true);

	ShowCursor(false);

	SetWindowLongPtrA(testwindow,GWL_STYLE,GetWindowLongPtrA(GetConsoleWindow(), GWL_STYLE)& ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);

	HANDLE hstdin = GetStdHandle(STD_INPUT_HANDLE);
	SetConsoleMode(hstdin, ENABLE_QUICK_EDIT_MODE);
	SetConsoleMode(hstdin, ENABLE_INSERT_MODE);

	if (!(_access("D:\\连点器配置文件", 0) == 0) && _access("D:\\", 0) == 0)
	{
		system("md D:\\连点器配置文件");
		cls;
		colorprint("\n\n\n\n\t\t\t正在加载，请稍等...",LIGHT_CYAN);
	}
	else if (_access("C:\\连点器配置文件", 0) != 0)
	{
		system("md C:\\连点器配置文件");
		cls;
		colorprint("\n\n\n\n\t\t\t正在加载，请稍等...", LIGHT_CYAN);
	}
	run();
}

int main()
{
	system("mode con cols=75 lines=12");
	start = clock();
	colorprint("\n\n\n\n\t\t\t正在加载，请稍等...", LIGHT_CYAN);
	SetConsoleTitle(title);
	HANDLE hObject = ::CreateMutex(NULL, FALSE, _T("GameClick_MC1919"));
	if (GetLastError() == ERROR_ALREADY_EXISTS)
	{
		CloseHandle(hObject);
		MessageBox(NULL, TEXT("你已经打开了一个GC连点器!\n提示：如果你桌面没有连点器的窗口试试按 F9 或 F12 将隐藏的连点器显示。"), TEXT("提示"), MB_OK | MB_ICONQUESTION);
		exit(-1);
	}
	else
		LoadSet();
}