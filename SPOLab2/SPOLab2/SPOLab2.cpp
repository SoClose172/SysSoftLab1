// SPOLab2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <windows.h>
#include "conio.h"
#include <vector>
//#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;
const int Length = 200 * 1024;//200 kb
unsigned char *buffer;

int num;
int test = 0;



DWORD WINAPI threadFunc(LPVOID);

int main()
{
	buffer = (unsigned char*)malloc(Length);//Выделение памяти

	srand(time(NULL));
	for (int i = 0; i <= Length; i++)
	{
		buffer[i] = (int)rand() % Length + 1;
	}
	HANDLE thread = CreateThread(NULL, 0, threadFunc, NULL, 0, NULL);
	ResumeThread(thread);

	WaitForSingleObject(thread, 0);

	_getch();
	return 0;
}

DWORD WINAPI threadFunc(LPVOID n)
{
	std::ofstream out;          // поток для записи
	out.open("c:\\Test\\1.txt"); // окрываем файл для записи
	if (out.is_open())
	{

		// здесь каждые 5кбайт переносим запись на другую строчку
		for (int i = 0; i < Length; i++) {
			if (i != 0 && i % (5 * 1024) == 0)
				out << "\n";
			out << std::to_string(buffer[i]) << " ";
		}

	}
	out.close();

	std::cout << "End of program" << std::endl;
	return 0;
}