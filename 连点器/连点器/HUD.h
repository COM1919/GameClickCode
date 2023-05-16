#pragma once
#include"Definition.h"
#include"Print.h"

char* RandGoodText()
{
	srand(time(NULL));
	switch (rand() % 16 + 1)
	{
	case 1:
		return (char*)"加载速度真快!棒棒哒!";
	case 2:
		return (char*)"真棒!电脑一点很贵吧。";
	case 3:
		return (char*)"好厉害哦，居然加载速度这么快!";
	case 4:
		return (char*)"你今天身体怎么样呀?";
	case 5:
		return (char*)"hi，你今天开心吗?";
	case 6:
		return (char*)"答应我，一定要每天都开心哦!";
	case 7:
		return (char*)"今天天气真好，你今天心情怎么样呀?";
	case 8:
		return (char*)"哎呀，速度好快啊，我都跟不上了。";
	case 9:
		return (char*)"你好呀，今天游戏赢了吗?";
	case 10:
		return (char*)"hello!，今天还好吗?";
	case 11:
		return (char*)"一定要开心哦!么么哒!";
	case 12:
		return (char*)"hi，休息一下吧，玩久了对身体不好哦!";
	case 13:
		return (char*)"hi，这次加载速度真快呀，我都跟不上了。";
	case 14:
		return (char*)"你好呀，今天感觉怎么样?";
	case 15:
		return (char*)"hi，你今天在玩什么呀?";
	case 16:
		return (char*)"嗯...我感觉自己好棒棒哦!";
	}
	return (char*)"哎呀!出错了，无法正常获取问候文本，Error:随机发生器错误";
}

void prin()
{
	cls;
	playMusic;
	printf("我的世界 GC连点器 %s\n", banben);
	playMusic;
	colorprint("在网易使用封号后果自负!\n", LIGHT_RED);
	playMusic;
	printf("PVP专用连点器\n");
	playMusic;
	printf("默认快捷键");
	colorprint("Tab", LIGHT_YELLOW);
	printf("或");
	colorprint("鼠标键 4", LIGHT_YELLOW);
	printf("连点鼠标右键（鼠标侧面的按键，有一些鼠标没有）\n");
	playMusic;
	printf("默认快捷键");
	colorprint("Ctrl", LIGHT_YELLOW);
	printf("或");
	colorprint("鼠标键 5", LIGHT_YELLOW);
	printf("连点鼠标左键（鼠标侧面的按键，有一些鼠标没有）\n");
	playMusic;
	printf("按");
	colorprint(" F12 ", LIGHT_YELLOW);
	printf("打开连点器的设置\n");
	playMusic;
	colorprint("\n\t右键CPS：", LIGHT_GREEN);
	SetColor(LIGHT_YELLOW);
	printf("%d", R_CPS);
	SetColor(CYAN);
	printf(" | ");
	SetColor(LIGHT_GREEN);
	colorprint("左键CPS：", LIGHT_GREEN);
	SetColor(LIGHT_YELLOW);
	printf("%d\n\n", L_CPS);
	SetColor(7);
	playMusic;
	colorprint("连点器由", LIGHT_RED);
	colorprint(" MC1919 ", LIGHT_YELLOW);
	colorprint("制作 联系方式", LIGHT_RED);
	colorprint("QQ：", LIGHT_RED);
	colorprint("3451392772\n", LIGHT_YELLOW);
	playMusic;
	colorprint("未经允许请勿转载!\n", LIGHT_RED);
	playMusic;
	printf("这次加载用了 %.2lf 秒。", LoadTime);
	srand(time(NULL));
	GoodText = RandGoodText();
	colorprint(GoodText, LIGHT_CYAN);
	ShowWindow(testwindow, (yc) ? false : true);
}