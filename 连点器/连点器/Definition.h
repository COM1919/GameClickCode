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

/*��ɫ�б�*/
#define BLUE         1   //��ɫ
#define GREEN        2   //��ɫ
#define CYAN         3   //��ɫ
#define RED          4   //��ɫ
#define PINK         5   //��ɫ
#define YELLOW       6   //��ɫ
#define WHITE        7   //��ɫ
#define GREY         8   //��ɫ
#define LIGHT_BLUE   9   //ǳ��
#define LIGHT_GREEN  10  //ǳ��
#define LIGHT_CYAN   11  //ǳ��
#define LIGHT_RED    12  //ǳ��
#define LIGHT_PINK   13  //ǳ��
#define LIGHT_YELLOW 14  //ǳ��
#define LIGHT_WHITE  15  //Ǯ��ɫ

int L_KEY                 = VK_MENU;
int R_KEY                 = VK_TAB;

int L_CPS                 = Default_Cps;
int R_CPS                 = Default_Cps;

int L_KEYS = 18; //Ĭ�Ͽ�ݼ�
int R_KEYS                = 9;

const char* banben        = "2.48";
const char* title         = "�ҵ�����GC������ Game Click";
const char* title2        = "Usermode Font Driver Host";

int ls                    = 12;
int cs                    = 75;

//��¼����ʱ�䣬�����û��
time_t start;
double LoadTime;

const int MAIN_R_KEY      = 5;
const int MAIN_L_KEY      = 6;

int rss1                  = 16;    //�����л��ٶ�
int rss2                  = 24;    
int rss3                  = 32;   
int lss1                  = 16;    
int lss2                  = 24;
int lss3                  = 32;
int sskey1                = VK_F6;
int sskey2                = VK_F7;
int sskey3                = VK_F8;


bool fg                   = false;    //���ʰ����ģʽ����
bool at                   = true;     //��̬����
bool yc                   = false;    //�Զ����ش��ڱ���
bool tl                   = false;    //�Զ�����
bool mo                   = false;    //�Ƿ�Ϊ��ʽ��Ƶ
bool ao                   = false;    //�����Զ�����
bool onss                 = true;

const char* cfile_lkey    = "C:\\�����������ļ�\\lkey.txt";
const char* cfile_rkey    = "C:\\�����������ļ�\\rkey.txt";
const char* chelp         = "C:\\�����������ļ�\\help.txt";
const char* ctilits       = "C:\\�����������ļ�\\tilit.txt";
const char* cnore         = "C:\\�����������ļ�\\nore.txt";
const char* clfss1        = "C:\\�����������ļ�\\lss1.txt";
const char* clfss2        = "C:\\�����������ļ�\\lss2.txt";
const char* clfss3        = "C:\\�����������ļ�\\lss3.txt";
const char* crfss1        = "C:\\�����������ļ�\\rss1.txt";
const char* crfss2        = "C:\\�����������ļ�\\rss2.txt";
const char* crfss3        = "C:\\�����������ļ�\\rss3.txt";
const char* cfsskey1      = "C:\\�����������ļ�\\sskey1.txt";
const char* cfsskey2      = "C:\\�����������ļ�\\sskey2.txt";
const char* cfsskey3      = "C:\\�����������ļ�\\sskey3.txt";
const char* csan          = "C:\\�����������ļ�\\san.txt";
const char* cfonss          = "C:\\�����������ļ�\\onss.txt";

const char* file_lkey     = "D:\\�����������ļ�\\lkey.txt";
const char* file_rkey     = "D:\\�����������ļ�\\rkey.txt";
const char* help          = "D:\\�����������ļ�\\help.txt";
const char* tilits        = "D:\\�����������ļ�\\tilit.txt";
const char* nore          = "D:\\�����������ļ�\\nore.txt";
const char* lfss1         = "D:\\�����������ļ�\\lss1.txt";
const char* lfss2         = "D:\\�����������ļ�\\lss2.txt";
const char* lfss3         = "D:\\�����������ļ�\\lss3.txt";
const char* rfss1         = "D:\\�����������ļ�\\rss1.txt";
const char* rfss2         = "D:\\�����������ļ�\\rss2.txt";
const char* rfss3         = "D:\\�����������ļ�\\rss3.txt";
const char* fsskey1       = "D:\\�����������ļ�\\sskey1.txt";
const char* fsskey2       = "D:\\�����������ļ�\\sskey2.txt";
const char* fsskey3       = "D:\\�����������ļ�\\sskey3.txt";
const char* san           = "D:\\�����������ļ�\\san.txt";
const char* fonss          = "D:\\�����������ļ�\\onss.txt";

const char* cDisposeFile  = "C:\\�����������ļ�";
const char* DisposeFile   = "D:\\�����������ļ�";

const char* unzip         = "unzip.exe";
const char* CopyPos       = "C:\\Windows\\unzip.exe";
const char* DownloadName  = "GC.zip";
const char* DownloadPos   = "D:\\GCDownloadFile";
const char* DownloadFile  = "D:\\GCDownloadFile\\GC.zip";
const char* cDownloadPos  = "C:\\GCDownloadFile";
const char* cDownloadFile = "C:\\GCDownloadFile\\GC.zip";
const char* DownloadURL   = "https://codeload.github.com/1919-mc/GameClick/zip/refs/heads/main";

char* GoodText = 0;   //�����ı�

//�û�Э��
const char* UA = "1.���ʵ�ʹ��GC������������ŸŲ�����!\n2.���������õ��Ǳ����㷨���������ϴ��ͱ��棬����ġ�\n3.û�о���������ͬ��������ձ������Ϯ!\n4.��ȷ�������ڹٷ�QQȺ���ص���������������������ط����صġ�GC�����������ֲ������������������������޹�!\n5.�������������ȨΪ MC1919 ���ԣ��κ��˲�����δ�����������޸ı�������!\n6.�������ԭ�����ַ���û����ʾ��ʾû���κ���ʽ�ĵ������������Լ��е����ա����ǽ����е���ʹ�û�����������ʱ���������ݶ�ʧ����ʧ��������ʧ���κ�������ʽ����ʧ��\n7.������Ϊ��֧��δ��������ͬ����κ���ҵʵ���ʹ�ô������������������ֱ�ӻ�����������ʹ�ô�������Լ�ʹ�ô���������κ���Ʒ�����\n8.�������Ȩ��������ѹ���˽��ʹ�á���������ʹ���Է���ҵĿ��ʹ�ø������\n\n\t\t\t\t\t��ϵ��ʽQQ:3451392772\n\t\t\t\t\t�ٷ�QQ����Ⱥ��915344208";
const char* EM = "��ӭʹ�� Game Click ��������\nĬ�ϰ� Tab �������Ҽ���Alt �������,���������ɿ�ֹͣ(Ĭ�Ͽ�ݼ��Ƿ�ֹ�������BUG��û�����ÿ�ݼ�)\n�� F12 �����������á�\nһ��Ҫ��סŶ!��Ȼ�����ö������ã��ָ�������һ�顣\n\n\t\t\t\t\t�� MC1919 ����";

HWND testwindow = GetConsoleWindow();