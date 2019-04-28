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
				Element *nextElem = get(index);
				Element *prevElem = prevElem->nextElement;

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
				removeElem = get(index);

				Element *nextElem = removeElem->nextElement;;
				Element *prevElem = removeElem->prevElement;;

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

				tail->nextElement = head;
				head->prevElement = tail;
			}
			else if (index == size) {
				tail->nextElement = elem;

				elem->nextElement = head;
				elem->prevElement = tail;

				tail = elem;
			}
			else {
				Element *prevElem = get(index);
				Element *nextElem = prevElem->nextElement;

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
				removeElem = get(index);

				Element *nextElem = removeElem->nextElement;	
				Element *prevElem = removeElem->prevElement;

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

void main5() {
	/*List list;

	for (int i = 0; i < 5; i++) {
		list.add(i, i);
	}

	for (int i = 0; i < 5; i++) {
		cout << list.get(i)->data << endl;
	}

	for (int i = 0; i < list.size; i++) {
		cout << list.get(i)->data;
	}*/

	/*LinkedList ll;
	double data;

	for (int i = 0; i < 5; i++) {
		ll.add(i, i);
	}

	ll.remove(3);

	for (int i = 0; i < ll.size; i++) {
		cout << ll.get(i)->data << endl;
	}*/

	/*List list;
	double data;

	for (int i = 0; i < 5; i++) {
		list.add(i, i);
	}

	List::Element *head = list.head;

	while (head != NULL) {
		cout << head->data << endl;
		head = head->nextElement;
	}*/

	LoopList ll;

	for (int i = 0; i < 5; i++) {
		ll.add(i, i);
	}

	LoopList::Element *head = ll.head;

	for (int i = 0; i < 20; i++) {
		cout << head->data << endl;
		head = head->nextElement;
	}
}