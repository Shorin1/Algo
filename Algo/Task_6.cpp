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

void quickSort(double *arr, int length) {

}

void main() {
	double *arr = new double[10];
	
	
}