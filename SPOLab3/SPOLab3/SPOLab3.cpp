// SPOLab3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <windows.h>
#include "conio.h"

#include <string>

#include <chrono>

using namespace std;
const int Length1 = 128 * 1024;//128 kb
const int Length2 = 256 * 1024;//256 kb
// что означает unsigned
unsigned char *buffer1;
unsigned char *buffer2;


DWORD WINAPI threadFunc1(LPVOID);
DWORD WINAPI threadFunc2(LPVOID);

int main()
{
	// это массив потоков?
	HANDLE threads[2];

	threads[0] = CreateThread(NULL, 0, threadFunc1, NULL, 0, NULL);
	threads[1] = CreateThread(NULL, 0, threadFunc2, NULL, 0, NULL);


	// что делает эта функция?
	WaitForMultipleObjects(2, threads, true, 0);

	_getch();
	return 0;
}

DWORD WINAPI threadFunc1(LPVOID n)
{

	auto begin = chrono::high_resolution_clock::now();

	buffer1 = (unsigned char*)malloc(Length1);//Выделение памяти

	free(buffer1);
	// что делает эта функция?
	auto end = chrono::high_resolution_clock::now();

	std::cout << "End of thread1 in: " + to_string(chrono::duration_cast<chrono::nanoseconds>(end - begin).count()) + "ns\n";
	return 0;
}
DWORD WINAPI threadFunc2(LPVOID n)
{
	auto begin = chrono::high_resolution_clock::now();

	buffer2 = (unsigned char*)malloc(Length2);//Выделение памяти

	free(buffer2);

	auto end = chrono::high_resolution_clock::now();

	std::cout << "End of thread2 in: " + to_string(chrono::duration_cast<chrono::nanoseconds>(end - begin).count()) + "ns\n";
	return 0;
}