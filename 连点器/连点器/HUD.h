#pragma once
#include"Definition.h"
#include"Print.h"

char* RandGoodText()
{
	srand(time(NULL));
	switch (rand() % 16 + 1)
	{
	case 1:
		return (char*)"�����ٶ����!������!";
	case 2:
		return (char*)"���!����һ��ܹ�ɡ�";
	case 3:
		return (char*)"������Ŷ����Ȼ�����ٶ���ô��!";
	case 4:
		return (char*)"�����������ô��ѽ?";
	case 5:
		return (char*)"hi������쿪����?";
	case 6:
		return (char*)"��Ӧ�ң�һ��Ҫÿ�춼����Ŷ!";
	case 7:
		return (char*)"����������ã������������ô��ѽ?";
	case 8:
		return (char*)"��ѽ���ٶȺÿ찡���Ҷ��������ˡ�";
	case 9:
		return (char*)"���ѽ��������ϷӮ����?";
	case 10:
		return (char*)"hello!�����컹����?";
	case 11:
		return (char*)"һ��Ҫ����Ŷ!ôô��!";
	case 12:
		return (char*)"hi����Ϣһ�°ɣ�����˶����岻��Ŷ!";
	case 13:
		return (char*)"hi����μ����ٶ����ѽ���Ҷ��������ˡ�";
	case 14:
		return (char*)"���ѽ������о���ô��?";
	case 15:
		return (char*)"hi�����������ʲôѽ?";
	case 16:
		return (char*)"��...�Ҹо��Լ��ð���Ŷ!";
	}
	return (char*)"��ѽ!�����ˣ��޷�������ȡ�ʺ��ı���Error:�������������";
}

void prin()
{
	cls;
	playMusic;
	printf("�ҵ����� GC������ %s\n", banben);
	playMusic;
	colorprint("������ʹ�÷�ź���Ը�!\n", LIGHT_RED);
	playMusic;
	printf("PVPר��������\n");
	playMusic;
	printf("Ĭ�Ͽ�ݼ�");
	colorprint("Tab", LIGHT_YELLOW);
	printf("��");
	colorprint("���� 4", LIGHT_YELLOW);
	printf("��������Ҽ���������İ�������һЩ���û�У�\n");
	playMusic;
	printf("Ĭ�Ͽ�ݼ�");
	colorprint("Ctrl", LIGHT_YELLOW);
	printf("��");
	colorprint("���� 5", LIGHT_YELLOW);
	printf("������������������İ�������һЩ���û�У�\n");
	playMusic;
	printf("��");
	colorprint(" F12 ", LIGHT_YELLOW);
	printf("��������������\n");
	playMusic;
	colorprint("\n\t�Ҽ�CPS��", LIGHT_GREEN);
	SetColor(LIGHT_YELLOW);
	printf("%d", R_CPS);
	SetColor(CYAN);
	printf(" | ");
	SetColor(LIGHT_GREEN);
	colorprint("���CPS��", LIGHT_GREEN);
	SetColor(LIGHT_YELLOW);
	printf("%d\n\n", L_CPS);
	SetColor(7);
	playMusic;
	colorprint("��������", LIGHT_RED);
	colorprint(" MC1919 ", LIGHT_YELLOW);
	colorprint("���� ��ϵ��ʽ", LIGHT_RED);
	colorprint("QQ��", LIGHT_RED);
	colorprint("3451392772\n", LIGHT_YELLOW);
	playMusic;
	colorprint("δ����������ת��!\n", LIGHT_RED);
	playMusic;
	printf("��μ������� %.2lf �롣", LoadTime);
	srand(time(NULL));
	GoodText = RandGoodText();
	colorprint(GoodText, LIGHT_CYAN);
	ShowWindow(testwindow, (yc) ? false : true);
}