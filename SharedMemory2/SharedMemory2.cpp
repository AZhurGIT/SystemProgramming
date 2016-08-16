#include <Windows.h>
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <iostream>
#include <stdlib.h>

#define BUF_SIZE 256
TCHAR szName[] = TEXT("MyFileMappingObject");

void main()
{
	HANDLE hMapFile;
	LPCTSTR pBuf;

	setlocale(LC_ALL, "Russian");
	hMapFile = OpenFileMapping(FILE_MAP_ALL_ACCESS,false,szName);
	pBuf = (LPTSTR)MapViewOfFile(hMapFile, FILE_MAP_ALL_ACCESS, 0, 0, BUF_SIZE);
	std::cout << (LPSTR)pBuf;
	UnmapViewOfFile(pBuf);
	CloseHandle(hMapFile);
	getchar();
}