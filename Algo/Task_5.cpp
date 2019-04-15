#include "pch.h"
#include <cstdlib>;
#include <windows.h>;
#include <iostream>

using namespace std;

/*Elements* head;
Elements* tail;

struct Elements {
	double data;
	Elements* nextElement;
	Elements* previousElement;
};

void pushQueue(double data) {
	Elements element;
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

Elements popQueue() {
	if (head != NULL) {
		Elements result = *head;
		head = head->previousElement;
		return result;
	}
}

Elements getQueue(unsigned int item) {
	Elements result = *tail;
	for (int i = 0; i < item; i++) {
		result = *result.nextElement;
	}
	return result;
}

void pushStack(double data) {
	Elements element;
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

Elements popStack() {
	if (head != NULL) {
		Elements result = *head;
		head = head->previousElement;
		return result;
	}
}*/