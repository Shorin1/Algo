#define _CRT_SECURE_NO_WARNINGS

#include "pch.h"
#include <cstdlib>
#include <windows.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdarg.h>
#include <stdlib.h>

using namespace std;

struct MyStruct
{
	char number;
	char studentFirstName[30];
	char *studentSecondName;
	unsigned int length;
	unsigned int *arr;
};

void readBinaryFile(MyStruct &s, FILE *file) {
	fread((&s.number), sizeof(s.number), 1, file);
	fread((&s.studentFirstName), sizeof(s.studentFirstName), 1, file);
	fread((&s.studentSecondName), sizeof(s.studentSecondName), 1, file);
	fread((&s.length), sizeof(s.length), 1, file);
	fread((&s.arr), s.length * sizeof(s.arr), s.length, file);
}

void writeToBinaryFile(MyStruct &s, FILE *file) {
	fwrite((&s.number), sizeof(s.number), 1, file);
	fwrite((&s.studentFirstName), sizeof(s.studentFirstName), 1, file);
	fwrite((&s.studentSecondName), sizeof(s.studentSecondName), 1, file);
	fwrite((&s.length), sizeof(s.length), 1, file);
	fwrite((&s.arr), s.length * sizeof(s.arr), s.length, file);
}

void readTextFile(MyStruct &s, FILE *file) {
	fscanf(file, "Number: %c\n", &s.number);
	fscanf(file, "First name: %s\n", s.studentFirstName);
	s.studentSecondName = new char[30];
	fscanf(file, "Second name: %s\n", s.studentSecondName);
	fscanf(file, "Length: %u\n", &s.length);
	s.arr = new unsigned int[s.length];
	for (int i = 0; i < s.length; i++) {
		fscanf(file, "%u; ", &s.arr[i]);
	}
}

void writeToTextFile(MyStruct &s, FILE *file) {
	fprintf(file, "Number: %c\nFirst name: %s\nSecond name: %s\nLength: %u\n", s.number, s.studentFirstName, s.studentSecondName, s.length);
	for (int i = 0; i < s.length; i++) {
		fprintf(file, "%u; ", s.arr[i]);
	}
}

void initNumber(MyStruct &t) {
	cout << "Enter student number: ";
	cin >> t.number;
}

void initString(MyStruct &t) {
	cout << "Enter student first name: ";
	cin >> t.studentFirstName;
	cout << "Enter student second name: ";
	t.studentSecondName = new char[30];
	cin >> t.studentSecondName;
}

void initArr(MyStruct &t) {
	cout << "Enter array length: ";
	cin >> t.length;
	t.arr = new unsigned int[t.length];
	for (int i = 0; i < t.length; i++) {
		cout << i << " element of array: ";
		cin >> t.arr[i];
	}
}

void initMyStruct(MyStruct &t) {
	initNumber(t);
	initString(t);
	initArr(t);
}

void printNumber(MyStruct *t) {
	cout << "Student number: " << t->number << endl;
}

void printString(MyStruct *t) {
	cout << "Student first name: " << t->studentFirstName << endl;
	cout << "Student second name: " << t->studentSecondName << endl;
}

void printArr(MyStruct *t) {
	for (int i = 0; i < t->length; i++) {
		cout << i << " element of array: " << t->arr[i] << endl;
	}
}

void writeStructToConsole(MyStruct t) {
	printNumber(&t);
	printString(&t);
	printArr(&t);
}

FILE *file;

int main3() {
	MyStruct *writeStructs = new MyStruct[3];
	MyStruct *readTextStructs = new MyStruct[3];
	MyStruct *readBinaryStructs = new MyStruct[3];

	cout << "Init write structs" << endl;
	for (int i = 0; i < 3; i++) {
		initMyStruct(writeStructs[i]);
	}

	cout << "Write structs to files" << endl;
	for (int i = 0; i < 3; i++) {
		char *fileName = new char[100];
		sprintf(fileName, "text_%d", i);
		file = fopen(fileName, "wt");
		writeToTextFile(writeStructs[i], file);
		fclose(file);
		cout << i << " struct was written to text file" << endl;
		sprintf(fileName, "binary_%d", i);
		file = fopen(fileName, "wt");
		writeToBinaryFile(writeStructs[i], file);
		fclose(file);
		cout << i << " struct was written to binary file" << endl;
	}

	cout << "Read structs from text file" << endl;
	for (int i = 0; i < 3; i++) {
		char *fileName = new char[100];
		sprintf(fileName, "text_%d", i);
		file = fopen(fileName, "rt");
		readTextFile(readTextStructs[i], file);
		fclose(file);
		cout << i << " struct was read from text file" << endl;
	}

	cout << "Write structs to binary file" << endl;
	for (int i = 0; i < 3; i++) {
		char *fileName = new char[300];
		sprintf(fileName, "binary_%d", i);
		file = fopen(fileName, "rt");
		readBinaryFile(readBinaryStructs[i], file);
		fclose(file);
		cout << i << " struct was written to binary file" << endl;
	}

	cout << "Output text struct" << endl;
	for (int i = 0; i < 3; i++) {
		cout << i << " text struct" << endl;
		writeStructToConsole(readTextStructs[i]);
	}

	cout << "Output binary struct" << endl;
	for (int i = 0; i < 3; i++) {
		cout << i << " binary struct" << endl;
		writeStructToConsole(readBinaryStructs[i]);
	}
	return 0;
}
