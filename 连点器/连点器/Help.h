#pragma once
#include"Definition.h"
#include"FileOperation.h"
#include"Print.h"

void xy()
{
	int xzs = MessageBox(NULL, TEXT(UA), TEXT("�û�Э��"), MB_YESNO);
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
	printf("Ĭ�Ͽ�ݼ�");
	colorprint("Tab", LIGHT_YELLOW);
	printf("��");
	colorprint("������", LIGHT_YELLOW);
	printf("��������Ҽ���������İ�������һЩ���û�У�\n");
	playMusic;
	printf("Ĭ�Ͽ�ݼ�");
	colorprint("Ctrl", LIGHT_YELLOW);
	printf("��");
	colorprint("����ǰ��", LIGHT_YELLOW);
	printf("������������������İ�������һЩ���û�У�\n");
	playMusic;
	colorprint("�� F12 ", LIGHT_YELLOW);
	printf("��������������\n");
	pause;
	cls;
	playMusic;
	printf("��֪����cpsָ����ÿ��ĵ��������fps��࣬����fpsָ����ÿ���ˢ��Ƶ�ʡ�\n����������ͨ������cps�����ٶȻ�ÿ��ĵ����\n");
	pause;
	cls;
	playMusic;
	printf("����ģʽ�����̳̣���F12������ -> ��3�򿪷������� -> ��1�򿪷���ģʽ\n");
	pause;
	cls;
	playMusic;
	printf("����ʲô������ȥQQȺ�� \n�ٷ�Ⱥ��915344208 ������MC1919\n\n");
	colorprint("��ȷ�����Ǵӹٷ�·�����أ������ж�����Ը�!\n\n", LIGHT_RED);
	pause;
	cls;
}

void HelpSetKey()
{
	cls;
	Sleep(350);
	playMusic;
	printf("���������������ݼ���");
	Sleep(800);
	playMusic;
	colorprint("|", LIGHT_CYAN);
	printf("��������������Ŀ�ݼ���");
	WriteDispose(file_lkey, cfile_lkey, "D:\\", "w", GetKey());
	Sleep(350);
	playMusic;
	printf("Ȼ�������Ҽ���ݼ���");
	Sleep(800);
	cls;
	playMusic;
	colorprint("|", LIGHT_CYAN);
	printf("�����������Ҽ��Ŀ�ݼ���");
	WriteDispose(file_rkey, cfile_rkey, "D:\\", "w", GetKey());
	playMusic;
	cls;
	Sleep(100);
	colorprint("\n\t���óɹ�!", LIGHT_GREEN);
	Sleep(800);
	cls;
}

void HelpSetSS()
{
	cls;
	playMusic;
	printf("���Ƿ񱣳�Ҫ�����������л�CPS��ѡ��\n\n");
	playMusic;
	colorprint("|", LIGHT_CYAN);
	printf("�� 1 ���ؿ����л�CPS��");
	colorprint((onss) ? "�ѿ���\n\n" : "�ѹر�\n\n", (onss) ? LIGHT_GREEN : LIGHT_RED);
	playMusic;
	printf("��������CPS������������ʹ�û���PVPʱ�����л�CPS\n");
	playMusic;
	printf("Ŀǰ�� 3 ����λ��ÿ����λ�����������������Ҽ�CPS���л��õ�λ�Ŀ�ݼ���\n\n");
	playMusic;
	colorprint("|", LIGHT_CYAN);
	printf("�س�����\n");

	while (1)
	{
		if (KEY_DOWN('1') || KEY_DOWN(97))
		{
			playMusic;
			onss = !onss;
			SetPos(22, 2);
			colorprint((onss) ? "�ѿ���\n" : "�ѹر�\n", (onss) ? LIGHT_GREEN : LIGHT_RED);
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
			printf("�������ǵ�һ��ʹ���������������������Ҽ��Ŀ�ݼ���\n");
			playMusic;
			printf("���Ƿ�Ҫ���ÿ�ݼ�? Y(��) / N(��)");
			while (1)
			{
				if (KEY_DOWN('Y'))
				{
					playMusic;
					HelpSetKey();
					srand(time(NULL));
					WriteDispose(help, chelp, "D:\\", "w", rand() % 99999999 + 1000000);
					MessageBox(NULL, EM, "GC������", MB_OK);
					return;
				}
				if (KEY_DOWN('N'))
				{
					cls;
					playMusic;
					printf("\n\n\n\t��ȷ������Ҫ���ÿ�ݼ���?��������ÿ���ʹ��Ĭ�Ͽ�ݼ�\n");
					playMusic;
					printf("\tĬ�Ͽ�ݼ���Tab�����Ҽ���Alt�������\n");
					playMusic;
					printf("\t���߰������������Ҽ�������ǰ��������������\n");
					playMusic;
					printf("\tY(ȷ��) / N(����)");
					while (1)
					{
						if (KEY_DOWN('Y'))
						{
							playMusic;
							srand(time(NULL));
							WriteDispose(help, chelp, "D:\\", "w", rand() % 99999999 + 1000000);
							cls;
							MessageBox(NULL, EM, "GC������", MB_OK);
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