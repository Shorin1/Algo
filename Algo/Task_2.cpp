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
	cout << "Размер массива unsigned int arr = ";
	cin >> t.length;
	t.arr = new unsigned int[t.length];\
	cout << "Введите значения в массив unsigned int arr" << endl;
	for (int i = 0; i < t.length; i++) {
		cout << "t.arr[" << i << "] = ";
		cin >> t.arr[i];
	}
}

void printArr(MyStruct *t) {
	cout << "Вывод массива" << endl;
	for (int i = 0; i < t->length; i++) {
		cout << "t.arr[" << i << "] = " << t->arr[i] << endl;
	}
}

void initString(MyStruct &t) {
	cout << "Введите значения в строку № 1 - имя студента" << endl;
	cin >> t.studentFirstName;
	cout << "Введите значения в строку № 2 - фамилия студента" << endl;
	t.studentSecondName = new char[30];
	cin >> t.studentSecondName;
}

void printString(MyStruct *t) {
	cout << "Имя студента: " << t->studentFirstName << endl;
	cout << "Фамилия студента: " << t->studentSecondName << endl;
}

void initNumber(MyStruct &t) {
	cout << "Введите номер студента" << endl;
	cin >> t.number;
}

void printNumber(MyStruct *t) {
	cout << "Номер студента = " << t->number << endl;
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
	cout << "Инициализация первой структуры" << endl;
	initMyStruct(myStruct);
	for (int i = 0; i < 3; i++) {
		cout << "Инициализация " << i << " элемента массива структур" << endl;
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