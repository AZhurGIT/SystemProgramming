#include <Windows.h>
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <iostream>
#include <stdlib.h>

#define BUF_SIZE 256
TCHAR szName[] = TEXT("MyFileMappingObject");
CHAR szMsg[] = ("Сообщение из разделяемой памяти");

void main()
{
	HANDLE hMapFile;
	LPCTSTR pBuf;

	setlocale(LC_ALL, "Russian");
	hMapFile = CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, BUF_SIZE, szName);
	pBuf = (LPTSTR)MapViewOfFile(hMapFile, FILE_MAP_ALL_ACCESS, 0, 0, BUF_SIZE);
	CopyMemory((LPVOID)pBuf, szMsg, strlen(szMsg));
	system("pause");
	UnmapViewOfFile(pBuf);
	CloseHandle(hMapFile);
	getchar();
}