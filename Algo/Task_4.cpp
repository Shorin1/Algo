#include "pch.h"
#include <cstdlib>;
#include <windows.h>;
#include <iostream>
#include <limits.h>

using namespace std;

struct Elements {
	unsigned int length = 0;
	unsigned int size = 8;
	double *arr = new double[8];
};

void increaseArray(Elements *element) {
	double *temp = new double[element->size * 2];
	for (int i = 0; i < element->size; i++) {
		temp[i] = element->arr[i];
	}
	element->size *= 2;
	element->arr = temp;
}

void pushArrayQueue(double data, Elements *element) {
	if (element->size == element->length) {
		increaseArray(element);
	}
	element->arr[element->length++] = data;
}

double popArrayQueue(Elements *element) {
	if (element->length == 0) {
		cout << "No element in this queue" << endl;
	}
	else {
		double result = element->arr[0];
		for (int i = 0; i < element->length - 1; i++) {
			element->arr[i] = element->arr[i + 1];
		}
		element->length--;
		return result;
	}
}

void pushLoopQueue(double data, Elements *element) {
	if (element->length != element->size) {
		element->arr[element->length++] = data;
	}
	else {
		for (int i = 0; i < element->size - 1; i++) {
			element->arr[i] = element->arr[i + 1];
		}
		element->arr[element->size - 1] = data;
	}
}

double popLoopQueue(Elements *element) {
	if (element->length == 0) {
		cout << "No element in this queue" << endl;
	}
	else {
		double result = element->arr[0];
		for (int i = 0; i < element->length - 1; i++) {
			element->arr[i] = element->arr[i + 1];
		}
		element->length--;
		return result;
	}
}

void pushArrayStack(double data, Elements *element) {
	if (element->length == element->size) {
		increaseArray(element);
	}
	element->arr[element->length++] = data;
}

double popArrayStack(Elements *element) {
	if (element->length == 0) {
		cout << "No elelement in this stack" << endl;
	}
	else {
		double result = element->arr[element->length-- - 1];
		return result;
	}
}

void pushLoopStack(double data, Elements *element) {
	if (element->length != element->size) {
		element->arr[element->length++] = data;
	}
	else {
		for (int i = 0; i < element->size - 1; i++) {
			element->arr[i] = element->arr[i + 1];
		}
		element->arr[element->size - 1] = data;
	}
	
}

double popLoopStack(Elements *element) {
	double result = element->arr[element->length-- - 1];
	return result;
}

double popPriorityQueue(Elements *element) {
	if (element->length == 0) {
		cout << "No element in this queue" << endl;
	}
	else {
		double minValue = DBL_MAX;
		unsigned int minValuePosition;
		for (int i = 0; i < element->length; i++) {
			if (element->arr[i] < minValue) {
				minValue = element->arr[i];
				minValuePosition = i;
			}
		}

		for (int i = minValuePosition; i < element->length - 1; i++) {
			element->arr[i] = element->arr[i + 1];
		}

		element->length--;
		return minValue;
	}
}

int main() {
	int n;
	double data;
	int iterator;

	/*cout << "Test array queue" << endl;
	cout << "Enter count element in queue" << endl;
	cin >> n;
	Elements queue;
	for (int i = 0; i < n; i++) {
		cout << "Enter " << i << " element in queue" << endl;
		cin >> data;
		pushArrayQueue(data, &queue);
	}

	cout << "Print all elements in queue" << endl;
	iterator = 0;
	while (queue.length > 0) {
		cout << iterator++ << " element: " << popArrayQueue(&queue) << endl;
	}*/

	/*Elements loopQueue;
	cout << "Test loop queue" << endl;
	cout << "Enter 10 elements in queue" << endl;
	for (int i = 0; i < 10; i++) {
		cout << "Enter " << i << " element in loop queue" << endl;
		cin >> data;
		pushLoopQueue(data, &loopQueue);
	}

	cout << "Print all elements in loop queue" << endl;
	iterator = 0;
	while (loopQueue.length > 0) {
		cout << iterator++ << " element: " << popLoopQueue(&loopQueue) << endl;
	}*/

	/*cout << "Test array stack" << endl;
	cout << "Enter count elements in stack" << endl;
	cin >> n;
	Elements arrayStack;
	for (int i = 0; i < n; i++) {
		cout << "Enter " << i << " element in stack" << endl;
		cin >> data;
		pushArrayStack(data, &arrayStack);
	}

	cout << "Print all element in stack" << endl;
	iterator = 0;
	while (arrayStack.length != 0) {
		cout << iterator++ << " element: " << popArrayStack(&arrayStack) << endl;
	}*/

	/*cout << "Test loop stack" << endl;
	Elements loopStack;
	cout << "Enter 10 elements in stack" << endl;
	for (int i = 0; i < 10; i++) {
		cout << "Enter " << i << " element in loop stack" << endl;
		cin >> data;
		pushLoopStack(data, &loopStack);
	}

	cout << "Print all elements in loop stack" << endl;
	iterator = 0;
	while (loopStack.length != 0) {
		cout << iterator++ << " element in loop stack: " << popLoopStack(&loopStack) << endl;
	}*/

	cout << "Test priority queue" << endl;
	cout << "Enter count elements in priority queue" << endl;
	cin >> n;
	Elements priorityQueue;
	for (int i = 0; i < n; i++) {
		cout << "Enter " << i << " element in priority queue" << endl;
		cin >> data;
		pushArrayQueue(data, &priorityQueue);
	}

	cout << "Print all elements in priority queue" << endl;
	iterator = 0;
	while (priorityQueue.length != 0) {
		cout << iterator++ << " element in priority queue: " << popPriorityQueue(&priorityQueue) << endl;
	}


	return 0;
}