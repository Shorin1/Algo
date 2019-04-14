#include "pch.h"
#include <cstdlib>;
#include <windows.h>;
#include <iostream>

using namespace std;

Element* head;
Element* tail;

struct Element {
	double data;
	Element* nextElement;
	Element* previousElement;
};

void pushQueue(double data) {
	Element element;
	element.data = data;
	if (head == NULL) {
		head = &element;
		tail = &element;
	}
	else {
		tail->previousElement = element;
		element.nextElement = tail;
		tail = &element;
	}
}

Element popQueue() {
	if (head != NULL) {
		Element result = *head;
		head = head->previousElement;
		return result;
	}
}

Element getQueue(unsigned int item) {
	Element result = *tail;
	for (int i = 0; i < item; i++) {
		result = *result.nextElement;
	}
	return result;
}

void pushStack(double data) {
	Element element;
	element.data = data;
	if (head == NULL) {
		head = &element;
	}
	else {
		head->nextElement = element;
		element.previousElement = head;
		head = &element;
	}
}

Element popStack() {
	if (head != NULL) {
		Element result = *head;
		head = head->previousElement;
		return result;
	}
}