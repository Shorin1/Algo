#include "pch.h"
#include <cstdlib>
#include <windows.h>
#include <iostream>

using namespace std;
/*
struct MyStruct
{
	char studentFirstName[30];
	char *studentSecondName;
	char number;
	unsigned int *arr;
	unsigned int length;
};

void initMyStruct(MyStruct &t);

void initArr(MyStruct &t);

void printArr(MyStruct *t);

void initString(MyStruct &t);
         
void printString(MyStruct *t);

void initNumber(MyStruct &t);

void printNumber(MyStruct *t);

void initMyStruct(MyStruct &t) {
	initArr(t);
	printArr(&t);
	initString(t);
	printString(&t);
	initNumber(t);
	printNumber(&t);
}

void initArr(MyStruct &t) {
	cout << "������ ������� unsigned int arr = ";
	cin >> t.length;
	t.arr = new unsigned int[t.length];\
	cout << "������� �������� � ������ unsigned int arr" << endl;
	for (int i = 0; i < t.length; i++) {
		cout << "t.arr[" << i << "] = ";
		cin >> t.arr[i];
	}
}

void printArr(MyStruct *t) {
	cout << "����� �������" << endl;
	for (int i = 0; i < t->length; i++) {
		cout << "t.arr[" << i << "] = " << t->arr[i] << endl;
	}
}

void initString(MyStruct &t) {
	cout << "������� �������� � ������ � 1 - ��� ��������" << endl;
	cin >> t.studentFirstName;
	cout << "������� �������� � ������ � 2 - ������� ��������" << endl;
	t.studentSecondName = new char[30];
	cin >> t.studentSecondName;
}

void printString(MyStruct *t) {
	cout << "��� ��������: " << t->studentFirstName << endl;
	cout << "������� ��������: " << t->studentSecondName << endl;
}

void initNumber(MyStruct &t) {
	cout << "������� ����� ��������" << endl;
	cin >> t.number;
}

void printNumber(MyStruct *t) {
	cout << "����� �������� = " << t->number << endl;
}

void deleteAll(MyStruct *t) {
	delete[] t->studentSecondName;
	delete[] t->arr;
}

int main2() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	MyStruct myStruct;
	MyStruct *myStructPointer = new MyStruct[3];
	cout << "������������� ������ ���������" << endl;
	initMyStruct(myStruct);
	for (int i = 0; i < 3; i++) {
		cout << "������������� " << i << " �������� ������� ��������" << endl;
		initMyStruct(myStructPointer[i]);
	}

	deleteAll(&myStruct);
	for (int i = 0; i < 3; i++) {
		deleteAll(&myStructPointer[i]);
	}

	{
		MyStruct localStruct;
		initArr(localStruct);
	}

	//printArr(&localstruct);
	return 0;
}*/