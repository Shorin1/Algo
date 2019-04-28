#include "pch.h"
#include <cstdlib>;
#include <windows.h>;
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
				Element *prevElem;
				prevElem = head;
				prevElem = get(index);

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
				Element *prevElem = head;
				prevElem = get(index - 1);
				removeElem = prevElem->nextElement;
				prevElem->nextElement = removeElem->nextElement;
			}

			delete[] removeElem;
			size--;
		}
	}

	Element* get(unsigned int index) {
		if (index < size) {
			Element *elem = head;

			for (int i = 0; i < index; i++) {
				elem = elem->nextElement;
			}

			return elem;
		}
	}
};

struct LinkedList {

	struct Element {
		double data;
		Element *nextElement = NULL;
		Element *prevElement = NULL;
	};

	Element *head = NULL;
	Element *tail = NULL;
	unsigned int size = 0;

	void add(double data, unsigned int index) {
		if (index <= size) {

			Element *elem = new Element;
			elem->data = data;

			if (index == 0) {
				if (size == 0) {
					head = elem;
					tail = elem;
				} 
				else {
					elem->nextElement = head;
					head = elem;
				}
			}
			else if (index == size) {
				tail->nextElement = elem;
				elem->prevElement = tail;
				tail = elem;
			}
			else {
				Element *nextElem;
				Element *prevElem;

				prevElem = get(index);
				nextElem = prevElem->nextElement;

				elem->nextElement = nextElem;
				elem->prevElement = prevElem;

				nextElem->prevElement = elem;
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
			else if (index == size) {
				removeElem = tail;

				if (size > 1) {
					tail = tail->prevElement;
				}
			}
			else {
				Element *nextElem;
				Element *prevElem;

				prevElem = get(index - 1);
				nextElem = prevElem->nextElement;

				removeElem = prevElem->nextElement;

				prevElem->nextElement = nextElem;
				nextElem->prevElement = prevElem;
			
			}

			delete[] removeElem;
			size--;
		}
	}

	Element* get(unsigned int index) {
		if (index < size) {
			Element *elem = head;

			for (int i = 0; i < index; i++) {
				elem = elem->nextElement;
			}

			return elem;
		}
	}
};

struct LoopList {
	struct Element {
		double data;
		Element *nextElement;
		Element *prevElement;
	};

	Element *head;
	Element *tail;
	unsigned int size = 0;

	void add(double data, unsigned int index) {
		if (index <= size) {

			Element *elem = new Element;
			elem->data = data;

			if (index == 0) {
				if (size == 0) {
					head = elem;
					tail = elem;
				}
				else {
					elem->nextElement = head;
					head = elem;
				}
			}
			else if (index == size) {
				tail->nextElement = elem;
				elem->prevElement = tail;
				tail = elem;
			}
			else {
				Element *nextElem;
				Element *prevElem;

				prevElem = get(index);
				nextElem = prevElem->nextElement;

				elem->nextElement = nextElem;
				elem->prevElement = prevElem;

				nextElem->prevElement = elem;
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
			else if (index == size) {
				removeElem = tail;

				if (size > 1) {
					tail = tail->prevElement;
				}
			}
			else {
				Element *nextElem;
				Element *prevElem;

				prevElem = get(index - 1);
				nextElem = prevElem->nextElement;

				removeElem = prevElem->nextElement;

				prevElem->nextElement = nextElem;
				nextElem->prevElement = prevElem;

			}

			delete[] removeElem;
			size--;
		}
	}

	Element* get(unsigned int index) {
		if (index < size) {
			Element *elem = head;

			for (int i = 0; i < index; i++) {
				elem = elem->nextElement;
			}

			return elem;
		}
	}
};

void main() {
	/*List list;
	double data;

	for (int i = 0; i < 5; i++) {
		cin >> data;
		list.add(data, i);
	}

	for (int i = 0; i < 5; i++) {
		data = list.get(i)->data;
		cout << data << endl;
	}

	for (int i = 0; i < 5; i++) {
		cout << list.get(0)->data << endl;
		list.remove(0);
	}

	for (int i = 0; i < list.size; i++) {
		cout << list.get(i)->data;
	}*/

	/*LinkedList ll;
	double data;

	for (int i = 0; i < 5; i++) {
		ll.add(i, i);
	}

	for (int i = 0; i < ll.size; i++) {
		cout << ll.get(i)->data << endl;
	}*/
}