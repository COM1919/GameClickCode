#pragma once
#include"Print.h"
#include"Setting.h"

int iferr(int errs, int errtybe = 0)  //0没有权限 1无法获取路径 2其他错误
{
	LPCTSTR text = 0;
	switch (errtybe)
	{
	case 0:
		text = "当前程序没有权限读取配置文件或该文件被占用!\n请尝试关闭杀毒软件或以管理员身份运行本程序!";
		break;
	case 1:
		text = "当前程序无法获取当前路径!\n请不用将连点器放在系统文件目录下，建议放桌面。";
		break;
	case 2:
		text = "当前程序因为其他错误而终止!";
		break;
	}
	if (errs == 13)
	{
		while (1)
		{
			cls;
			int xss;
			printf("错误代码：%d", errs);
			xss = MessageBox(NULL, "当前程序没有权限读取配置文件或该文件被占用!\n请尝试关闭杀毒软件或以管理员身份运行本程序!", "错误", MB_ABORTRETRYIGNORE | MB_ICONHAND);
			return xss;
		}
	}
	else
	{
		while (1)
		{
			cls;
			int xss;
			printf("错误代码：%d\n", errs);
			printf("请联系作者解决或去官方群。联系:\n");
			printf("QQ群：915344208\n");
			printf("作者QQ：3451392772\n");
			xss = MessageBox(NULL, text, "错误", MB_ABORTRETRYIGNORE | MB_ICONHAND);
			return xss;
		}
	}
	return 0;
}