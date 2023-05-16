#pragma once
#include"Definition.h"
#include"ErrorOperation.h"

int DelFile(LPCTSTR file, LPCTSTR cfile, LPCTSTR disc, bool yntip = false)
{
	if (yntip)
	{
		if (_access((_access(disc, 0) == 0) ? file : cfile, 0) == 0)
		{
			int error = DeleteFile((_access(disc, 0) == 0) ? file : cfile);
			if (error == false)
			{
				MessageBox(NULL, "ɾ���ļ�ʧ��!", "����", MB_ICONHAND);
				cls;
				printf("��ɾ���ļ� %s ʱ��������!", (_access(disc, 0) == 0) ? file : cfile);
				Sleep(1500);
				return error;
			}
		}
	}
	else
	{
		if (_access((_access(disc, 0) == 0) ? file : cfile, 0) == 0)
		{
			return DeleteFile((_access(disc, 0) == 0) ? file : cfile);
		}
		return -1;
	}
	return -1;
}
/*
* GC��������ѹ�ļ�˼·
CMD:unzip <Ҫ��ѹ���ļ�> -d <��ѹλ��> -x GameClick-main\.gitignore GameClick-main\README.md
*/
void UnZips(LPCTSTR zipPos)
{
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
	}
	char cmd[356] = "unzip -c ";
	strcat_s(cmd, strlen(zipPos) + strlen(cmd) + 1, zipPos);
	strcat_s(cmd, strlen(cmd) + strlen(" -d ") + 1, " -d ");
	strcat_s(cmd, strlen(cmd) + strlen(DownloadPos) + 1, DownloadPos);
	strcat_s(cmd, strlen(cmd) + strlen(" -x GameClick-main\\.gitignore GameClick-main\\README.md") + 1, " -x GameClick-main\\.gitignore GameClick-main\\README.md");
	system(cmd);
}

int ReadDispose(LPCTSTR file, LPCTSTR cfile, LPCTSTR disc, LPCTSTR mode, const int defreturn = 0)
{
	if (_access(file, 0) == 0)
	{
		while (1)
		{
			FILE* sf;
			errno_t err = fopen_s(&sf, (_access(disc, 0) == 0) ? file : cfile, mode);
			if (err != 0)
			{
				switch (iferr(err))
				{
				case IDIGNORE:
					break;
				case IDRETRY:
					continue;
				case IDABORT:
					fclose(sf);
					exit(err);
				case 0:
					break;
				}
			}
			int chs;
			fscanf_s(sf, "%d", &chs);
			fclose(sf);
			return chs;
		}
	}
	return defreturn;
}


int WriteDispose(LPCTSTR file, LPCTSTR cfile, LPCTSTR disc, LPCTSTR mode, const int wf, bool sd = false) //�Ƿ񷵻ش��������
{
	while (1)
	{
		FILE* sf;
		errno_t err = fopen_s(&sf, (_access(disc, 0) == 0) ? file : cfile, mode);
		if (err != 0)
		{
			switch (iferr(err))
			{
			case IDIGNORE:
				fclose(sf);
				return 0;
			case IDRETRY:
				continue;
			case IDABORT:
				fclose(sf);
				exit(err);
			case 0:
				break;
			}
		}
		fprintf_s(sf, "%d", wf);
		fclose(sf);
		return (sd) ? wf : err;
	}
}