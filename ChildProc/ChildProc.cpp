#include <stdio.h>
#include <Windows.h>
#include <locale.h>
#include <iostream>
#include <stdlib.h>

void main()
{
	setlocale(LC_ALL, "Russian");

	DWORD PID = GetCurrentProcessId();
//	DWORD priority = GetPriorityClass(hProc);
	std::cout << "Дочерний процесс" << std::endl;

	std::cout << "PID: " << PID << std::endl;
//	std::cout << "priority: " << priority << std::endl;

	getchar();
}