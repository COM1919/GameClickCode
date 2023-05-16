#pragma once
#include<iostream>
#include<windows.h>
#include<Mmsystem.h>
#include<math.h>
#include<io.h>
#include<tchar.h>
#include<wininet.h>
#include<tlhelp32.h>
#include<direct.h>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<time.h>
#pragma comment(lib,"winmm.lib")
#pragma comment(lib,"Urlmon.lib")
#pragma comment(lib,"Wininet.lib")

using namespace std;

#define Default_Cps 80
#define Default_Sleep 14
#define MAX 4096
#define KEY_DOWN(VK_NONAME) (GetAsyncKeyState(VK_NONAME) & 0x8000)
#define cls system("cls")
#define pause system("pause")
#define playMusic Sleep(125);sndPlaySound("GCmusic.wav", SND_ASYNC)
#define WM_NOTIFYICON WM_USER + 0x01

/*颜色列表*/
#define BLUE         1   //蓝色
#define GREEN        2   //绿色
#define CYAN         3   //青色
#define RED          4   //红色
#define PINK         5   //粉色
#define YELLOW       6   //黄色
#define WHITE        7   //白色
#define GREY         8   //灰色
#define LIGHT_BLUE   9   //浅蓝
#define LIGHT_GREEN  10  //浅绿
#define LIGHT_CYAN   11  //浅青
#define LIGHT_RED    12  //浅红
#define LIGHT_PINK   13  //浅粉
#define LIGHT_YELLOW 14  //浅黄
#define LIGHT_WHITE  15  //钱白色

int L_KEY                 = VK_MENU;
int R_KEY                 = VK_TAB;

int L_CPS                 = Default_Cps;
int R_CPS                 = Default_Cps;

int L_KEYS = 18; //默认快捷键
int R_KEYS                = 9;

const char* banben        = "2.48";
const char* title         = "我的世界GC连点器 Game Click";
const char* title2        = "Usermode Font Driver Host";

int ls                    = 12;
int cs                    = 75;

//记录加载时间，额。好像没用
time_t start;
double LoadTime;

const int MAIN_R_KEY      = 5;
const int MAIN_L_KEY      = 6;

int rss1                  = 16;    //快速切换速度
int rss2                  = 24;    
int rss3                  = 32;   
int lss1                  = 16;    
int lss2                  = 24;
int lss3                  = 32;
int sskey1                = VK_F6;
int sskey2                = VK_F7;
int sskey3                = VK_F8;


bool fg                   = false;    //国际版防封模式变量
bool at                   = true;     //动态标题
bool yc                   = false;    //自动隐藏窗口变量
bool tl                   = false;    //自动标题
bool mo                   = false;    //是否为老式音频
bool ao                   = false;    //开机自动启动
bool onss                 = true;

const char* cfile_lkey    = "C:\\连点器配置文件\\lkey.txt";
const char* cfile_rkey    = "C:\\连点器配置文件\\rkey.txt";
const char* chelp         = "C:\\连点器配置文件\\help.txt";
const char* ctilits       = "C:\\连点器配置文件\\tilit.txt";
const char* cnore         = "C:\\连点器配置文件\\nore.txt";
const char* clfss1        = "C:\\连点器配置文件\\lss1.txt";
const char* clfss2        = "C:\\连点器配置文件\\lss2.txt";
const char* clfss3        = "C:\\连点器配置文件\\lss3.txt";
const char* crfss1        = "C:\\连点器配置文件\\rss1.txt";
const char* crfss2        = "C:\\连点器配置文件\\rss2.txt";
const char* crfss3        = "C:\\连点器配置文件\\rss3.txt";
const char* cfsskey1      = "C:\\连点器配置文件\\sskey1.txt";
const char* cfsskey2      = "C:\\连点器配置文件\\sskey2.txt";
const char* cfsskey3      = "C:\\连点器配置文件\\sskey3.txt";
const char* csan          = "C:\\连点器配置文件\\san.txt";
const char* cfonss          = "C:\\连点器配置文件\\onss.txt";

const char* file_lkey     = "D:\\连点器配置文件\\lkey.txt";
const char* file_rkey     = "D:\\连点器配置文件\\rkey.txt";
const char* help          = "D:\\连点器配置文件\\help.txt";
const char* tilits        = "D:\\连点器配置文件\\tilit.txt";
const char* nore          = "D:\\连点器配置文件\\nore.txt";
const char* lfss1         = "D:\\连点器配置文件\\lss1.txt";
const char* lfss2         = "D:\\连点器配置文件\\lss2.txt";
const char* lfss3         = "D:\\连点器配置文件\\lss3.txt";
const char* rfss1         = "D:\\连点器配置文件\\rss1.txt";
const char* rfss2         = "D:\\连点器配置文件\\rss2.txt";
const char* rfss3         = "D:\\连点器配置文件\\rss3.txt";
const char* fsskey1       = "D:\\连点器配置文件\\sskey1.txt";
const char* fsskey2       = "D:\\连点器配置文件\\sskey2.txt";
const char* fsskey3       = "D:\\连点器配置文件\\sskey3.txt";
const char* san           = "D:\\连点器配置文件\\san.txt";
const char* fonss          = "D:\\连点器配置文件\\onss.txt";

const char* cDisposeFile  = "C:\\连点器配置文件";
const char* DisposeFile   = "D:\\连点器配置文件";

const char* unzip         = "unzip.exe";
const char* CopyPos       = "C:\\Windows\\unzip.exe";
const char* DownloadName  = "GC.zip";
const char* DownloadPos   = "D:\\GCDownloadFile";
const char* DownloadFile  = "D:\\GCDownloadFile\\GC.zip";
const char* cDownloadPos  = "C:\\GCDownloadFile";
const char* cDownloadFile = "C:\\GCDownloadFile\\GC.zip";
const char* DownloadURL   = "https://codeload.github.com/1919-mc/GameClick/zip/refs/heads/main";

char* GoodText = 0;   //撒娇文本

//用户协议
const char* UA = "1.请适当使用GC连点器，被封号概不负责!\n2.连点器采用的是本地算法，并不会上传和保存，请放心。\n3.没有经过制作者同意请勿仿照本程序或抄袭!\n4.请确保你是在官方QQ群下载的连点器，如果你在其他地方下载的“GC连点器”出现病毒或恶意插件，后果与制作者无关!\n5.本程序介解释与版权为 MC1919 所以，任何人不能在未经允许的情况修改本连点器!\n6.软件“按原样”分发。没有明示或暗示没有任何形式的担保。您可以自己承担风险。我们将不承担在使用或滥用这个软件时产生的数据丢失、损失，利润损失或任何其他形式的损失。\n7.您不能为了支持未经本作者同意的任何商业实体或活动使用次软件。包括但不限于直接或间接允许他人使用此软件，以及使用此软件销售任何商品或服务。\n8.此软件授权给您，免费供您私人使用。您仅可以使用以非商业目的使用该软件。\n\n\t\t\t\t\t联系方式QQ:3451392772\n\t\t\t\t\t官方QQ下载群：915344208";
const char* EM = "欢迎使用 Game Click 连点器。\n默认按 Tab 键连点右键，Alt 连点左键,按下连点松开停止(默认快捷键是防止程序出现BUG你没有设置快捷键)\n按 F12 打开连点器设置。\n一定要记住哦!不然你想用都不会用，又告诉了你一遍。\n\n\t\t\t\t\t由 MC1919 制作";

HWND testwindow = GetConsoleWindow();