#pragma once
#include"Definition.h"
#include"FileOperation.h"
#include"HUD.h"
#include"Help.h"

void Read()
{
	R_KEY = ReadDispose(file_rkey, cfile_rkey, "D:\\", "r");
	L_KEY = ReadDispose(file_lkey, cfile_lkey, "D:\\", "r");
	at = (ReadDispose(tilits, ctilits, "D:\\", "r") == 1) ? false : true;
	yc = (ReadDispose(nore, cnore, "D:\\", "r") == 1) ? true : false;
	onss = (ReadDispose(fonss, cfonss, "D:\\", "r") == 1) ? true : false;
	rss1 = ReadDispose(rfss1, crfss1, "D:\\", "r", 16);
	lss1 = ReadDispose(lfss1, clfss1, "D:\\", "r", 16);
	rss2 = ReadDispose(rfss2, crfss2, "D:\\", "r", 24);
	lss2 = ReadDispose(lfss2, clfss2, "D:\\", "r", 24);
	rss3 = ReadDispose(rfss3, crfss3, "D:\\", "r", 32);
	lss3 = ReadDispose(lfss3, clfss3, "D:\\", "r", 32);
}

void mainLoad()
{
	ct();
	Sleep(200);
	Load();
	Read();
	prin();
}