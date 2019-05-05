#include "pch.h"
#include <cstdlib>
#include <windows.h>
#include <iostream>

using namespace std;

void bubbleSort(double *arr, int length) {
	double temp;
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void partition(double *arr, int begin, int end) {
	double middle = arr[(begin + end) / 2];
	int left = begin, rigth = end;
	double temp;

	do {

		while (arr[left] < middle) {
			left++;
		}

		while (arr[rigth] > middle) {
			rigth--;
		}

		if (left <= rigth) {
			temp = arr[left];
			arr[left] = arr[rigth];
			arr[rigth] = temp;
			left++;
			rigth--;
		}

	} while (left <= rigth);

	if (begin < rigth) {
		partition(arr, begin, rigth);
	}

	if (end > left) {
		partition(arr, left, end);
	}
}

void quickSort(double *arr, int length) {
	partition(arr, 0, length - 1);
}

void main6() {
	double arr[5];

	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
	}

	quickSort(arr, 5);
	
	for (int i = 0; i < 5; i++) {
		cout << arr[i] << endl;
	}
}