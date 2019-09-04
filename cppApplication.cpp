// cppApplication.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <Windows.h>

using namespace std;

#define invisible

void Visibility();

int main()
{
	Visibility();
	const char* output = "Rammstein";
	const size_t len = strlen(output) + 1;
	HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE, len);
	memcpy(GlobalLock(hMem), output, len);
	GlobalUnlock(hMem);
	OpenClipboard(0);
	EmptyClipboard();
	SetClipboardData(CF_TEXT, hMem);
	CloseClipboard();

	char * text = NULL; // сюда запишем текст
	//Открываем Clipboard
	if (OpenClipboard(0))
	{
		HANDLE hData = GetClipboardData(CF_TEXT);
		text = (char*)GlobalLock(hData);
		GlobalUnlock(hData);
		CloseClipboard();
	}
	cout << text << endl;
	//system("pause");
}


void Visibility(){
#ifdef visible
	ShowWindow(FindWindowA("ConsoleWindowClass", NULL), 1); // visible window
#endif // visible

#ifdef invisible
	ShowWindow(FindWindowA("ConsoleWindowClass", NULL), 0); // invisible window
#endif // invisible
}
