#pragma once
#include"Print.h"
#include"Setting.h"

int iferr(int errs, int errtybe = 0)  //0û��Ȩ�� 1�޷���ȡ·�� 2��������
{
	LPCTSTR text = 0;
	switch (errtybe)
	{
	case 0:
		text = "��ǰ����û��Ȩ�޶�ȡ�����ļ�����ļ���ռ��!\n�볢�Թر�ɱ��������Թ���Ա������б�����!";
		break;
	case 1:
		text = "��ǰ�����޷���ȡ��ǰ·��!\n�벻�ý�����������ϵͳ�ļ�Ŀ¼�£���������档";
		break;
	case 2:
		text = "��ǰ������Ϊ�����������ֹ!";
		break;
	}
	if (errs == 13)
	{
		while (1)
		{
			cls;
			int xss;
			printf("������룺%d", errs);
			xss = MessageBox(NULL, "��ǰ����û��Ȩ�޶�ȡ�����ļ�����ļ���ռ��!\n�볢�Թر�ɱ��������Թ���Ա������б�����!", "����", MB_ABORTRETRYIGNORE | MB_ICONHAND);
			return xss;
		}
	}
	else
	{
		while (1)
		{
			cls;
			int xss;
			printf("������룺%d\n", errs);
			printf("����ϵ���߽����ȥ�ٷ�Ⱥ����ϵ:\n");
			printf("QQȺ��915344208\n");
			printf("����QQ��3451392772\n");
			xss = MessageBox(NULL, text, "����", MB_ABORTRETRYIGNORE | MB_ICONHAND);
			return xss;
		}
	}
	return 0;
}