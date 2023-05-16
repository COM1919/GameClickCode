#pragma once
#include"Definition.h"
#include"FileOperation.h"

int URLDownloadFiles(LPCTSTR URL, LPCTSTR FileName)
{
	CoInitialize(NULL);
	DeleteUrlCacheEntry(URL);//清空缓存，否则服务器上的文件修改后，无法下载最新的文件
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
		strcat_s(cmd, strlen((_access("C:\\连点器配置文件", 0) != 0) ? cDownloadPos : DownloadPos) + strlen(cmd) + 1, (_access("C:\\连点器配置文件", 0) != 0) ? cDownloadPos : DownloadPos);
		system(cmd);
	}
	while (1)
	{
		if (URLDownloadFiles(DownloadURL, DownloadFile) != S_OK)
		{
			static int err = 0;
			cls;
			printf("错误代码：%d", err);
			err = MessageBox(0, "在下载文件时出现错误!", "错误", MB_ICONHAND | MB_ABORTRETRYIGNORE);
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
			printf("错误代码：%d\n", err);
			printf("在复制文件 %s 时出现错误!", unzip);
			err = MessageBox(0, "在复制文件时出现错误!", "错误", MB_ICONHAND | MB_ABORTRETRYIGNORE);
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
	char* tr = "下载完毕!已下载到";
	strcat_s(tr, strlen(tr) + strlen(_getcwd(NULL, NULL)), _getcwd(NULL, NULL));
	strcat_s(tr, strlen(tr) + strlen("\n连点器将退出，请自行打开更新后的连点器!"), "\n连点器将退出，请自行打开更新后的连点器!");
	MessageBox(0, tr, "提示", MB_ICONASTERISK | MB_OK);
	playMusic;
	Sleep(600);
	exit(0);
}