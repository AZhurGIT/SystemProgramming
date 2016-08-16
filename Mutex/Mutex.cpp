#include <Windows.h>

DWORD dwCounter = 0;

DWORD WINAPI Thread(CONST LPVOID lpParam)
{
	CONST HANDLE hMutex = (CONST HANDLE)lpParam;
	for (DWORD i = 0; i < 100; ++i)
	{
		WaitForSingleObject(hMutex, INFINITE);
		dwCounter++;
		ReleaseMutex(hMutex);
	}
	ExitThread(0);
}

int main(void)
{
	TCHAR szMessage[255];
	DWORD dwTemp, i;
	HANDLE hThreads[10];
	CONST HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONST HANDLE hMutex = CreateMutex(NULL, FALSE, NULL);
	for (i = 0; i < 10; ++i)
	{
		hThreads[i] = CreateThread(NULL, 0, &Thread, hMutex, 0, NULL);

	}
	WaitForMultipleObjects(10, hThreads, TRUE, INFINITE);
	wsprintf(szMessage, TEXT("Counter value = %d"), dwCounter);
	WriteConsole(hStdOut, szMessage, lstrlen(szMessage), NULL, NULL);
	system("pause");
	for (i = 0; i < 10; ++i)
	{
		CloseHandle(hThreads[i]);
	}
	CloseHandle(hMutex);
	exit(0);

}
