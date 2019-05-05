#include "pch.h"
#include <cstdlib>
#include <windows.h>
#include <iostream>

using namespace std;

struct List {

	struct Element {
		double data;
		Element *nextElement = NULL;
	};

	Element *head = NULL;
	unsigned int size = 0;

	void add(double data, unsigned int index) {
		if (index <= size) {

			Element *elem = new Element;
			elem->data = data;

			if (index == 0) {

				if (size == 0) {
					head = elem;
				}
				else {
					elem->nextElement = head;
					head = elem;
				}

			}
			else {
				Element *prevElem = get(index - 1);

				elem->nextElement = prevElem->nextElement;
				prevElem->nextElement = elem;
			}

			size++;
		}
	}

	void remove(unsigned int index) {
		if (index <= size) {
			Element *removeElem;

			if (index == 0) {
				removeElem = head;

				if (size > 1) {
					head = head->nextElement;
				}
			}
			else {
				Element *prevElem = get(index - 1);
				removeElem = prevElem->nextElement;
				prevElem->nextElement = removeElem->nextElement;
			}

			delete[] removeElem;
			size--;
		}
	}

	Element* get(unsigned int index) {

		if (index <= size) {
			Element *elem = head;

			for (int i = 0; i < index; i++) {
				elem = elem->nextElement;
			}

			return elem;
		}
	}
};

int lineSearchArr(double *arr, int length, double key) {
	
	for (int i = 0; i < length; i++) {

		if (arr[i] == key) {
			return i;
		}

	}

	return -1;
}

int lineSearchList(List *list, double key) {

	for (int i = 0; i < list->size; i++) {

		if (list->get(i)->data == key) {
			return i;
		}

	}

	return -1;
}

int binarySearchArr(double *arr, int length, double key) {
	int mid, left = 0, rigth = length - 1;

	while (left != rigth) {
		mid = left + (rigth - left) / 2;

		if (arr[mid] == key) {
			return mid;
		}
		else if (arr[mid] < key) { // key - справа
			left = mid;
		}
		else if (arr[mid] > key) { // key - слева
			rigth = mid;
		}
	}

	return -1;
}

int binarySearchList(List *list, double key) {
	int mid, left = 0, rigth = list->size - 1;

	while (left != rigth) {
		mid = left + (rigth - left) / 2;

		if (list->get(mid)->data == key) {
			return mid;
		}
		else if (list->get(mid)->data < key) { // key - справа
			left = mid;
		}
		else if (list->get(mid)->data > key) { // key - слева
			rigth = mid;
		}
	}

	return -1;
}

void main() {
	double arr[5];

	for (int i = 0; i < 5; i++) {
		arr[i] = i + 10;
	}

	cout << lineSearchArr(arr, 5, 13) << endl;

	cout << binarySearchArr(arr, 5, 13) << endl;

	List *list = new List();

	for (int i = 0; i < 5; i++) {
		list->add(i + 10, i);
	}

	cout << lineSearchList(list, 13) << endl;

	cout << binarySearchList(list, 13) << endl;
}