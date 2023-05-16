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
				MessageBox(NULL, (char*)Run, "����", MB_OK);
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

bool DelDispose()  //�û��Ƿ�ѡ��ɾ�� false û�� true ��
{
	cls;
	printf("\n\n\n\t��ȷ��Ҫɾ�������������������ļ���?\n");
	printf("\t����ζ�������õ��������ö���ָ�Ĭ��!\n");
	printf("\tY(ȷ��) / N(����)");

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
		printf("���� 1 ���ض�̬���⣺");
		colorprint((tl) ? "�ѿ���\n" : "�ѹر�\n", (tl) ? LIGHT_GREEN : LIGHT_RED);
		colorprint("|", LIGHT_CYAN);
		printf("���� 2 �����Զ����ش��ڣ�");
		colorprint((yc) ? "�ѿ���\n" : "�ѹر�\n", (yc) ? LIGHT_GREEN : LIGHT_RED);
		/*
		printf("���� 4 ���ؿ����Զ�������");
		colorprint((ao) ? "�ѿ���\n" : "�ѹر�\n", (ao) ? LIGHT_GREEN : LIGHT_RED);
		*/
		colorprint("|", LIGHT_CYAN);
		printf("���� 3 ɾ�����������������ļ�\n");
		if (yc)
		{
			SetPos(0, 8);
			printf("��������ʱ��ʾ���ڣ��˳�����ʱ���ش��ڡ��� ");
			colorprint("F12", LIGHT_YELLOW);
			printf(" �����á�");
		}
		SetPos(0, 3);
		colorprint("|", LIGHT_CYAN);
		printf("�س�����\n");

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
					colorprint("\n\n\n\n\t\t\tɾ���ɹ�!", LIGHT_RED);
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
	printf("����");
	colorprint(" 1 ", GREEN);
	printf("���õ���ģʽ(16CPS)\n");
	playMusic;
	colorprint("|", LIGHT_CYAN);
	printf("����");
	colorprint(" 2 ", GREEN);
	printf("��������ģʽ(30CPS)\n");
	playMusic;
	colorprint("|", LIGHT_CYAN);
	printf("����");
	colorprint(" 3 ", GREEN);
	printf("���ø���ģʽ(60CPS)\n");
	playMusic;
	colorprint("|", LIGHT_CYAN);
	printf("����");
	colorprint(" 4 ", GREEN);
	printf("���� ���� ģʽ!(��Ҫ��ĵ������ܺ�,������CPS!!!)\n");
	playMusic;
	colorprint("|", LIGHT_CYAN);
	printf("����");
	colorprint(" 0 ", GREEN);
	printf("�Զ���CPS��ÿ��������\n");
	playMusic;
	colorprint("|", LIGHT_CYAN);
	printf("�س�����\n\n");
	colorprint("��֪����?�ٶȲ����ǹ̶��ģ�CPS�ٶȿ����͵��������йء�", LIGHT_GREEN);

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
				printf("������CPS������ƣ�");
				playMusic;
				scanf_s("%d", &sp);
				if (sp > 1000 || sp < 5)
				{
					MessageBox(NULL, "�����õ�CPS��Ч!\n������ 5 �� 1000 ֮��!", "����", MB_OK | MB_ICONHAND);
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
		printf("�� 1 ���ʷ���ģʽ��");
		colorprint((fg) ? "�ѿ���\n" : "�ѹر�\n", (fg) ? LIGHT_GREEN : LIGHT_RED);
		colorprint("|", LIGHT_CYAN);
		printf("�س�����");
		SetPos(0, 6);
		colorprint("���ʷ�����ͨ������CPS���ﵽ���������������׼�⵽��\n", LIGHT_GREEN);
		colorprint("20���µ�CPS��100CPSû��ʲô�����þ����ˡ�", LIGHT_GREEN);

		while (1)
		{
			if (KEY_DOWN('1') | KEY_DOWN(97))
			{
				fg = !fg;
				SetPos(0,19);
				colorprint((fg) ? "�ѿ���\n" : "�ѹر�\n", (fg) ? LIGHT_GREEN : LIGHT_RED);
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
	printf("����");
	colorprint(" 1 ", GREEN);
	printf("������������Ŀ�ݼ�\n");
	playMusic;
	colorprint("|", LIGHT_CYAN);
	printf("����");
	colorprint(" 2 ", GREEN);
	printf("���������Ҽ��Ŀ�ݼ�\n");
	playMusic;
	colorprint("|", LIGHT_CYAN);
	printf("�س�����");

	while (1)
	{
		if (KEY_DOWN('1') | KEY_DOWN(97))
		{
			cls;
			playMusic;
			colorprint("|", LIGHT_CYAN);
			printf("�밴����������Ŀ�ݼ���");
			DelFile(file_lkey, cfile_lkey, "D:\\");
			L_KEY = GetKey();
			return WriteDispose(file_lkey, cfile_lkey, "D:\\", "w", L_KEY);
		}
		if (KEY_DOWN('2') | KEY_DOWN(98))
		{
			cls;
			playMusic;
			colorprint("|", LIGHT_CYAN);
			printf("�밴�������Ҽ��Ŀ�ݼ���");
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

void printspeed(bool ws = true, int* ri = 0, int* li = 0) //ws:�ж��Ƿ�����ͨCPS����,ri:Ҫ�޸ĵ�ֵ��li:һ���ģ�һ�������һ���Ҽ�
{
	cls;
	playMusic;
	colorprint("|", LIGHT_CYAN);
	printf("����");
	colorprint(" 1 ", GREEN);
	printf("��������������ٶ�\n");
	playMusic;
	colorprint("|", LIGHT_CYAN);
	printf("����");
	colorprint(" 2 ", GREEN);
	printf("���������Ҽ����ٶ�\n");
	playMusic;
	colorprint("|", LIGHT_CYAN);
	printf("�س�����");

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
		int xx = MessageBox(NULL, TEXT("��ǰ�ѿ�������ģʽ���Ҫ�����ٶȽ��Զ��رշ���ģʽ��\n���ǿ���ڷ���ģʽ��״̬���޸��������ٶȣ�\n��ô����ģʽ���ܲ���Ч,������֪��������ʲô!\n\n\t\tѡ���ǡ��رշ���ģʽ������CPS\n\t\tѡ�񡰷񡱺�����ʾ������\n\t\tѡ��ȡ�������ص�����"), TEXT("ע��!"), MB_YESNOCANCEL | MB_ICONQUESTION | MB_SYSTEMMODAL);
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
	printf("���� 1 �����ٶ�\n");
	playMusic;
	colorprint("|", LIGHT_CYAN);
	printf("���� 2 ���ÿ�ݼ�\n");
	playMusic;
	colorprint("|", LIGHT_CYAN);
	printf("�س�����");
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
			printf("�밴�¿����л� %d ���Ŀ�ݼ���", pos);
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
		colorprint("�����л��ٶ������㰴�����ݼ�ʱ���ٶ�����Ϊ���趨���ٶȡ�\n", LIGHT_GREEN);
		playMusic;
		colorprint("--------------------------------------\n", LIGHT_CYAN);
		playMusic;
		printf("���� 1 ����1��");
		colorprint(" | ", LIGHT_CYAN);
		printf("��CPS:%d", rss1);
		colorprint(" | ", LIGHT_CYAN);
		printf("��CPS:%d", lss1);
		colorprint(" | \n", LIGHT_CYAN);
		playMusic;
		printf("���� 2 ����2��");
		colorprint(" | ", LIGHT_CYAN);
		printf("��CPS:%d", rss2);
		colorprint(" | ", LIGHT_CYAN);
		printf("��CPS:%d", lss2);
		colorprint(" | \n", LIGHT_CYAN);
		playMusic;
		printf("���� 3 ����3��");
		colorprint(" | ", LIGHT_CYAN);
		printf("��CPS:%d", rss3);
		colorprint(" | ", LIGHT_CYAN);
		printf("��CPS:%d", lss3);
		colorprint(" | \n", LIGHT_CYAN);
		playMusic;
		colorprint("--------------------------------------\n", LIGHT_CYAN);
		playMusic;
		colorprint("|", LIGHT_CYAN);
		printf("�� 4 ���ؿ����л��ٶȣ�");
		colorprint((onss) ? "�ѿ���\n" : "�ѹر�\n", (onss) ? LIGHT_GREEN : LIGHT_RED);
		playMusic;
		colorprint("|", LIGHT_CYAN);
		printf("�س��˳�\n\n");
		playMusic;
		colorprint("F6 F7 F8 ", LIGHT_YELLOW);
		printf("�ֱ��л��� ");
		colorprint("1�� 2�� 3��\n\n", LIGHT_YELLOW);
		playMusic;
		colorprint("ע��!�������ʷ���ģʽ���޷�ʹ�ÿ����л�CPS!", LIGHT_RED);

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
				colorprint((onss) ? "�ѿ���\n" : "�ѹر�\n", (onss) ? LIGHT_GREEN : LIGHT_RED);
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
		printf("���� 0 �˳�\n");
		playMusic;
		colorprint("|", LIGHT_CYAN);
		printf("���� 1 ������������ݼ�\n");
		playMusic;
		colorprint("|", LIGHT_CYAN);
		printf("���� 2 �����������ٶ�\n");
		playMusic;
		colorprint("|", LIGHT_CYAN);
		printf("���� 3 �򿪷�������\n");
		playMusic;
		colorprint("|", LIGHT_CYAN);
		printf("���� 4 ���ÿ��������ٶ�\n");
		playMusic;
		colorprint("|", LIGHT_CYAN);
		printf("���� 5 ����������\n");
		/*playMusic;
		printf("���� 6 ����/���� ������\n");*/

		while (1)
		{
			if (KEY_DOWN('1') | KEY_DOWN(97))
			{
				if (setkey() != 0)
				{
					playMusic;
					cls;
					colorprint("\n\t����ʧ��!", LIGHT_RED);
					Sleep(400);
				}
				else
				{
					playMusic;
					cls;
					colorprint("\n\t���óɹ�!", LIGHT_GREEN);
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
					colorprint("\n\t���óɹ�!", LIGHT_GREEN);
					Sleep(400);
					break;
				}
			}
			if (KEY_DOWN('3') | KEY_DOWN(99))
			{
				f();
				playMusic;
				cls;
				colorprint("\n\t���óɹ�!", LIGHT_GREEN);
				Sleep(400);
				break;
			}
			if (KEY_DOWN('5') | KEY_DOWN(101))
			{
				if (else_set() != 0)
				{
					playMusic;
					cls;
					colorprint("\n\t����ʧ��!", LIGHT_RED);
					Sleep(400);
				}
				else
				{
					playMusic;
					cls;
					colorprint("\n\t���óɹ�!", LIGHT_GREEN);
					Sleep(400);
					break;
				}
			}
			if (KEY_DOWN('4') | KEY_DOWN(100))
			{
				SwitchingSpeed();
				playMusic;
				cls;
				colorprint("\n\t���óɹ�!", LIGHT_GREEN);
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