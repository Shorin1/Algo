#include "pch.h"
#include <cstdlib>;
#include <windows.h>;
#include <iostream>
#include <limits.h>

using namespace std;

struct Element {
	unsigned int length = 0;
	unsigned int size;
	double *arr;
};

void increaseArray(Element *element) {
	double *temp = new double[element->size * 2];
	for (int i = element->size - 1; i > -1; i--) {
		temp[i + element->size] = element->arr[i];
	}
	element->size *= 2;
	element->arr = temp;
}

void pushArrayQueue(double data, Element *element) {
	if (element->size == element->length) {
		increaseArray(element);
	}
	element->arr[element->size - element->length++ - 1] = data;
}

double popArrayQueue(Element *element) {
	double result = element->arr[element->size - 1];
	for (int i = element->size - 1; i > element->size - element->length - 1; i--) {
		element->arr[i] = element->arr[i - 1];
	}
	element->length--;
	return result;
}

void pushLoopQueue(double data, Element *element) {
	if (element->length != element->size) {
		element->arr[element->size - element->length++ - 1] = data;
	}
	else {
		for (int i = element->size - 1; i > 0; i--) {
			element->arr[i] = element->arr[i - 1];
		}
		element->arr[0] = data;
	}
}

double popLoopQueue(double data, Element *element) {
	double result = element->arr[element->size - 1];
	for (int i = element->size - 1; i > element->size - element->length - 1; i--) {
		element->arr[i] = element->arr[i - 1];
	}
	element->arr[element->size - --element->length - 1] = data;
	return result;
}

void pushArrayStack(double data, Element *element) {
	if (element->length == element->size) {
		increaseArray(element);
		for (int i = element->length - 1; i < element->size - 2; i++) {
			element->arr[i] = element->arr[i + 1];
		}
		element->arr[element->size - 1] = data;
		element->length++;
	}
}

double popArrayStack(Element *element) {
	double result = element->arr[element->size - 1];
	for (int i = element->size - 1; i > 0; i--) {
		element->arr[i] = element->arr[i - 1];
	}
	element->length--;
	return result;
}

void pushLoopStack(double data, Element *element) {
	for (int i = 0; i < element->size - 2; i++) {
		element->arr[i] = element->arr[i + 1];
	}
	element->arr[element->size - 1] = data;
}

double popLoopStack(Element *element) {
	double result = element->arr[element->size - 1];
	for (int i = element->size - 1; i > 0; i--) {
		element->arr[i] = element->arr[i - 1];
	}
	return result;
}

double popPriorityQueue(Element *element) {
	double minValue = DBL_MAX;
	unsigned int minValuePosition;
	for (int i = 0; i < element->size; i++) {
		if (element->arr[i] < minValue) {
			minValue = element->arr[i];
			minValuePosition = i;
		}
	}

	for (int i = minValuePosition; i > 0; i--) {
		element->arr[i] = element->arr[i - 1];
	}

	element->size--;
	return minValue;
}

int main() {

}