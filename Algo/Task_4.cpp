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

struct LoopElements {
	unsigned int headIndex = 0;
	unsigned int tailIndex = 0;
	unsigned int length = 0;
	unsigned int size = 8;
	double *arr = new double[8];
};

struct LinkedElement {
	double data;
	LinkedElement *nextElement;
	LinkedElement *previousElement;
};

struct LinkedElements {
	LinkedElement *head = NULL;
	LinkedElement *tail;
	unsigned int length = 0;
};

void increaseArray(Elements *element) {
	double *temp = new double[element->size * 2];
	for (int i = 0; i < element->size; i++) {
		temp[i] = element->arr[i];
	}
	element->size *= 2;
	element->arr = temp;
}

void pushLinkedStack(double data, LinkedElements *elements) {
	LinkedElement *element = new LinkedElement;
	element->data = data;
	if (elements->length == 0) {
		elements->head = element;
	}
	else {
		element->previousElement = elements->head;
		elements->head->nextElement = element;
		elements->head = element;
	}
	elements->length++;
}

LinkedElement popLinkedStack(LinkedElements *elements) {
	if (elements->length == 0) {
		cout << "No elements in stack" << endl;
	}
	else {
		LinkedElement *result = elements->head;
		elements->head = elements->head->previousElement;
		elements->length--;
		return *result;
	}
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

void pushLoopQueue(double data, LoopElements *elements) {
	if (elements->length == elements->size) {
		cout << "Enter element is impossible" << endl;
	}
	else {
		elements->arr[elements->tailIndex] = data;
		elements->length++;
		if (elements->tailIndex == elements->size - 1) {
			elements->tailIndex = 0;
		}
		else {
			elements->tailIndex++;
		}
	}
}

double popLoopQueue(LoopElements *elements) {
	if (elements->length == 0) {
		cout << "No elements in queue" << endl;
	}
	else {
		double result = elements->arr[elements->headIndex];
		elements->length--;
		if (elements->headIndex == elements->size - 1) {
			elements->headIndex = 0;
		}
		else {
			elements->headIndex++;
		}
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

int main4() {
	int n;
	double data;
	int iterator;

	cout << "Test array queue" << endl;
	cout << "Enter count element in queue" << endl;
	cin >> n;
	Elements queue;
	for (int i = 0; i < n; i++) {
		cout << "Enter " << i << " element in queue" << endl;
		cin >> data;
		pushArrayQueue(data, &queue);
	}

	cout << "Print all elements from queue" << endl;
	iterator = 0;
	while (queue.length != 0) {
		cout << iterator++ << " element: " << popArrayQueue(&queue) << endl;
	}

	cout << "Test loop queue" << endl;
	LoopElements loopQueue;
	cout << "Enter 10 elements in queue" << endl;
	for (int i = 0; i < 10; i++) {
		cout << "Enter " << i << " element in loop queue" << endl;
		cin >> data;
		pushLoopQueue(data, &loopQueue);
	}

	cout << "Pop 3 elements from loop queue" << endl;
	for (int i = 0; i < 3; i++) {
		cout << i << " element: " << popLoopQueue(&loopQueue) << endl;
	}

	cout << "Enter 3 elements in loop queue" << endl;

	for (int i = 0; i < 3; i++) {
		cin >> data;
		pushLoopQueue(data, &loopQueue);
	}

	cout << "Print all elements from loop queue" << endl;
	iterator = 0;
	while (loopQueue.length != 0) {
		cout << iterator++ << " element: " << popLoopQueue(&loopQueue) << endl;
	}

	cout << "Test array stack" << endl;
	cout << "Enter count elements in stack" << endl;
	cin >> n;
	Elements arrayStack;
	for (int i = 0; i < n; i++) {
		cout << "Enter " << i << " element in stack" << endl;
		cin >> data;
		pushArrayStack(data, &arrayStack);
	}

	cout << "Print all element from stack" << endl;
	iterator = 0;
	while (arrayStack.length != 0) {
		cout << iterator++ << " element: " << popArrayStack(&arrayStack) << endl;
	}

	cout << "Test linked stack" << endl;
	cout << "Enter count elements in stack" << endl;
	cin >> n;
	LinkedElements linkedStack;
	for (int i = 0; i < n; i++) {
		cout << "Enter " << i << " element in stack" << endl;
		cin >> data;
		pushLinkedStack(data, &linkedStack);
	}

	cout << "Print all elements from linked stack" << endl;
	iterator = 0;
	while (linkedStack.length != 0) {
		cout << iterator++ << " element in linked stack: " << popLinkedStack(&linkedStack).data << endl;
	}

	cout << "Test priority queue" << endl;
	cout << "Enter count elements in priority queue" << endl;
	cin >> n;
	Elements priorityQueue;
	for (int i = 0; i < n; i++) {
		cout << "Enter " << i << " element in priority queue" << endl;
		cin >> data;
		pushArrayQueue(data, &priorityQueue);
	}

	cout << "Print all elements from priority queue" << endl;
	iterator = 0;
	while (priorityQueue.length != 0) {
		cout << iterator++ << " element in priority queue: " << popPriorityQueue(&priorityQueue) << endl;
	}
	return 0;
}