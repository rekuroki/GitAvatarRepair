// GitAvatarRepair.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#define _CRT_NON_CONFORMING_SWPRINTFS
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<fstream>
#include<string>
#include <vector>
#include <windows.h>
#include <wininet.h>
#include <tchar.h>
#include <string>
#include<stdio.h>
#include "ErrShow.h"
#pragma comment(lib,"Wininet.lib")
using namespace std;
constexpr auto N = 524288;
void uchar2char(BYTE str1[], char* str2);
constexpr auto MAXSIZE = 524288;
void urlopen(const _TCHAR*, const _TCHAR* agent);
std::string& trim(std::string &s);
int _tmain()
{
	fstream f("conf.ini");
	string s1, s2;
	getline(f, s1,'\n');
	getline(f, s2,'\n');
	wchar_t   *   n1 = new  wchar_t[s1.size()];
	swprintf(n1, L"%S ", s1.c_str());
	wchar_t   *   n2 = new  wchar_t[s2.size()];
	swprintf(n2, L"%S ", s2.c_str());
		urlopen(n1,n2 );
	return 0;
}
void urlopen(const _TCHAR* url, const _TCHAR* agent)
{
	size_t ustrlen(BYTE s[]);
	HINTERNET hSession = InternetOpen(agent, INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0);
	if (hSession != NULL)
	{
		HINTERNET hHttp = InternetOpenUrl(hSession, url, NULL, 0, INTERNET_FLAG_DONT_CACHE, 0);
		if (hHttp != NULL)
		{
			BYTE Temp[MAXSIZE];
			ULONG Number = 1;
			std::string tp2;
			while (Number > 0)
			{
				InternetReadFile(hHttp, Temp, MAXSIZE - 1, &Number);
				Temp[Number] = '\0';
				char*tp = (char*)calloc(ustrlen(Temp), sizeof(char));
				uchar2char(Temp, tp);
				tp2 += tp;
				free(tp);
			}
			char yn;
			notice(tp2.substr(tp2.find("<object>") + 10, tp2.find("</object>") - 11).data());
			notice("需要直接覆写hosts文件吗?\n(y/N)");
			cin >> yn;
			string rz = tp2.substr(tp2.rfind("<code>"), tp2.rfind("</code>"));
			trim(rz);
			if (yn != 'y' || yn != 'Y'){
				std::cout <<rz.substr(8, rz.size()-40);
		}
		else {

		}
			InternetCloseHandle(hHttp);
			hHttp = NULL;
		}
		InternetCloseHandle(hSession);
		hSession = NULL;
	}
}
void uchar2char(BYTE str1[], char* str2) {
	!str1 || !str2 ? void(error("ERROR")), exit(-1) : (void)0;
	size_t ustrlen(BYTE s[]);
	for (size_t i=0; i < ustrlen(str1); ++i)
		i[str2] = (char)i[str1];
}
size_t ustrlen(BYTE s[])
{
	size_t ilength = 0;
	while (*s++ != '\0')
		ilength++;
	return ilength;
}


std::string& trim(std::string &s)
{
	if (s.empty())
	{
		return s;
	}

	s.erase(0, s.find_first_not_of(" "));
	s.erase(s.find_last_not_of(" ") + 1);
	return s;
}