// ThreadsEducation1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <windows.h>
#include "conio.h"
#include <fstream>
#include <string>


using namespace std;
const int Length =1 * 1024;
unsigned char *buffer = new unsigned char[Length];

int num;
int test = 0;


DWORD WINAPI thread2(LPVOID);
DWORD WINAPI thread3(LPVOID);

int main()
{
	// create threats
	HANDLE thread1 = CreateThread(NULL, 0, thread3, NULL, 0, NULL);
	HANDLE thread = CreateThread(NULL, 0, thread2, thread1, 0, NULL);
	// stop threads
	SuspendThread(thread);
	SuspendThread(thread1);

	//ResumeFirstThread
	ResumeThread(thread);

	
	_getch();
	return 0;
}

DWORD WINAPI thread2(HANDLE thread1 )
{
	
	for (int i = 0; i<= Length; i++)
	{
		buffer[i] = (int)rand() % Length + 1;
	}
	for (int i = 0; i <= Length; i++)
	{
		cout << (int)buffer[i] << " ";
		cout << endl;
		
		if (i == Length)
		{
			ResumeThread(thread1);
		}
		
	}
	//delete[]buffer;
	
	
	
	//cout << "wwwwwwwwwwwwwwwwwwww";
	
	return 0;
}
DWORD WINAPI thread3(LPVOID n )
{
	cout << "All Right";
	ofstream out;          // поток для записи
	out.open("c:\\Test\\1.txt"); // окрываем файл для записи
	if (out.is_open())
	{
		for (int i = 0; i <= Length; i++) {
			out << std::to_string(buffer[i]) << " ";
		}

	}
	out.close();
	delete[]buffer;
	return 0;
}