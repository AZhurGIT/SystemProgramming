#include <stdio.h>
#include <Windows.h>
#include <locale.h>
#include <iostream>
#include <stdlib.h>


void main()
{
	STARTUPINFO startupInfo;
	PROCESS_INFORMATION processInformation;
	TCHAR commandLine[] = TEXT("ChildProc");
	setlocale(LC_ALL, "Russian");
	ZeroMemory(&startupInfo, sizeof(startupInfo));
	startupInfo.cb = sizeof(startupInfo);
	
	DWORD PID = GetCurrentProcessId();
	HANDLE hProc = OpenProcess(PROCESS_QUERY_INFORMATION, TRUE, PID);
	if(!hProc)
	{
		std::cout << "Ошибка создания процесаа: " << GetLastError() << std::endl;
	}
		
	DWORD priority = GetPriorityClass(hProc);
	std::cout << "Родительский процесс" << std::endl;
	std::cout << "PID: " << PID << std::endl;
	std::cout << "hProc: " << hProc << std::endl;
	std::cout << "priority: " << priority << std::endl;
	
	WaitForSingleObject(hProc, INFINITE);
	std::cout << "Дочерний процесс закончил работу";
	getchar();
}