#pragma once
#include"Definition.h"
#include"FileOperation.h"

int URLDownloadFiles(LPCTSTR URL, LPCTSTR FileName)
{
	CoInitialize(NULL);
	DeleteUrlCacheEntry(URL);//��ջ��棬����������ϵ��ļ��޸ĺ��޷��������µ��ļ�
	int error = URLDownloadToFile(NULL, URL, FileName, 0, NULL);
	CoUninitialize();
	return error;
}

void Updata()
{
	cls;
	if (!(_access(DownloadPos, 0) == 0 || _access(cDownloadPos, 0) == 0))
	{
		char cmd[256] = "md ";
		strcat_s(cmd, strlen((_access("C:\\�����������ļ�", 0) != 0) ? cDownloadPos : DownloadPos) + strlen(cmd) + 1, (_access("C:\\�����������ļ�", 0) != 0) ? cDownloadPos : DownloadPos);
		system(cmd);
	}
	while (1)
	{
		if (URLDownloadFiles(DownloadURL, DownloadFile) != S_OK)
		{
			static int err = 0;
			cls;
			printf("������룺%d", err);
			err = MessageBox(0, "�������ļ�ʱ���ִ���!", "����", MB_ICONHAND | MB_ABORTRETRYIGNORE);
			switch (err)
			{
			case IDIGNORE:
				return;
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
			break;
		}
	}
	while (1)
	{
		if (CopyFile(unzip, CopyPos, false) == 0)
		{
			static int err = 0;
			cls;
			printf("������룺%d\n", err);
			printf("�ڸ����ļ� %s ʱ���ִ���!", unzip);
			err = MessageBox(0, "�ڸ����ļ�ʱ���ִ���!", "����", MB_ICONHAND | MB_ABORTRETRYIGNORE);
			switch (err)
			{
			case IDIGNORE:
				return;
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
			break;
		}
	}//_getcwd(NULL, NULL)
	UnZips(DownloadFile);
	CopyFile(DownloadPos, _getcwd(NULL, NULL), false);
	char* tr = "�������!�����ص�";
	strcat_s(tr, strlen(tr) + strlen(_getcwd(NULL, NULL)), _getcwd(NULL, NULL));
	strcat_s(tr, strlen(tr) + strlen("\n���������˳��������д򿪸��º��������!"), "\n���������˳��������д򿪸��º��������!");
	MessageBox(0, tr, "��ʾ", MB_ICONASTERISK | MB_OK);
	playMusic;
	Sleep(600);
	exit(0);
}