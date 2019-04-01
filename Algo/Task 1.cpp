#include "pch.h"
#include <cstdlib>;
#include <windows.h>;
#include <iostream>

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	double array1[3];
	double *pointer2;
	unsigned int array3[3];
	unsigned int(*pointer4)[3];
	char array5[3][3][3];
	char(*pointer6)[3][3];

	cout << "1.	Çíà÷åíèÿ â ìàññèâå ¹1" << endl;
	for (int i = 0; i < 3; i++) {
		cout << array1[i] << "\t";
	}

	cout << endl << "2.	Ââåäèòå çíà÷åíèÿ â ìàññèâ ¹1" << endl;
	for (int i = 0; i < 3; i++) {
		cin >> array1[i];
	}

	cout << endl << "3.	Íîâûå çíà÷åíèÿ â ìàññèâå ¹1" << endl;
	for (int i = 0; i < 3; i++) {
		cout << array1[i] << "\t";
	}
	cout << endl << *(array1 + 2) << endl;

	cout << endl << "4.	Ïðèñâîèòü óêàçàòåëþ ¹2 àäðåñ ìàññèâà ¹1, âûâåñòè íà ýêðàí àäðåñà ìàññèâà è óêàçàòåëÿ è ñîäåðæèìîå óêàçàòåëÿ" << endl;
	pointer2 = array1;
	cout << "Àäðåñà ìàññèâà: " << &array1 << endl;
	cout << "Àäðåñà óêàçàòåëÿ: " << pointer2 << endl;
	cout << "Ñîäåðæèìîå óêàçàòåëÿ ¹ 2" << endl;
	for (int i = 0; i < 3; i++) {
		cout << pointer2[i] << "\t";
	}

	cout << endl << "6.	Ïîâòîðèòü ïóíêòû 1 – 3 äëÿ ñòàòè÷åñêîãî ìàññèâà ¹3" << endl;
	cout << "Ïðîâåðèòü ñîäåðæèìîå ìàññèâà ¹3" << endl;
	for (int i = 0; i < 3; i++) {
		cout << array3[i] << "\t";
	}
	cout << endl << "Ââåñòè äàííûå â ìàññèâ ¹3" << endl;
	for (int i = 0; i < 3; i++) {
		cin >> array3[i];
	}
	cout << endl << "Åùå ðàç ïðîâåðèòü ñîäåðæèìîå ýòîãî ìàññèâà" << endl;
	for (int i = 0; i < 3; i++) {
		cout << array3[i] << "\t";
	}

	cout << endl << "7.	Èñïîëüçóÿ èìåþùèéñÿ óêàçàòåëü ¹2, ñîçäàòü äèíàìè÷åñêèé ìàññèâ è ïîâòîðèòü äëÿ íåãî ïóíêòû 1 – 3" << endl;
	int n = 0;
	cout << "Ââåäèòå ðàçìåð ìàññèâà" << endl;
	cin >> n;
	pointer2 = new double[n];
	cout << "Ïðîâåðèòü ñîäåðæèìîå óêàçàòåëÿ ¹2" << endl;
	for (int i = 0; i < n; i++) {
		cout << pointer2[i] << "\t";
	}
	cout << endl << "Ââåñòè äàííûå â óêàçàòåëü ¹2" << endl;
	for (int i = 0; i < n; i++) {
		cin >> pointer2[i];
	}
	cout << endl << "Åùå ðàç ïðîâåðèòü ñîäåðæèìîå ýòîãî óêàçàòåëÿ" << endl;
	for (int i = 0; i < n; i++) {
		cout << pointer2[i] << "\t";
	}

	cout << endl << "8.	Óäàëèòü äèíàìè÷åñêèé ìàññèâ. Èñïîëüçóÿ óêàçàòåëü ¹4, ñîçäàòü äâóìåðíûé äèíàìè÷åñêèé ìàññèâ è ïîâòîðèòü äëÿ íåãî ïóíêòû 2, 3. Ñäåëàòü âûâîäû. Óäàëèòü äâóìåðíûé äèíàìè÷åñêèé ìàññèâ." << endl;
	delete[] pointer2;
	pointer4 = new unsigned int[3][3];
	cout << endl << "Ââåñòè äàííûå â óêàçàòåëü ¹4" << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << "Ââîä ýëåìåíòà " << "[" << i << "][" << j << "]  " << endl;
			cin >> pointer4[i][j];
		}
	}
	cout << endl << "Ïðîâåðèòü ñîäåðæèìîå ýòîãî óêàçàòåëÿ" << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
		{
			cout << pointer4[i][j] << "\t";
		}
		cout << endl;
	}
	for (int i = 0; i < 3; i++) {
		//delete[] pointer4[i];
	}
	delete[] pointer4;

	cout << endl << "9.	Âûâåñòè íà ýêðàí ëþáîé èç ýëåìåíòîâ òðåõìåðíîãî ìàññèâà ¹5, èñïîëüçóÿ îïåðàöèþ èíäåêñàöèè" << endl;
	cout << endl << "Ýëåìåíò íîìåð 2, 1, 2 â ìàññèâå ¹ 5" << endl;
	cout << array5[2][1][2] << endl;

	cout << endl << "10.	Ïîâòîðèòü ïóíêò 9, èñïîëüçóÿ èìÿ ìàññèâà êàê óêàçàòåëü è îïåðàöèþ äîñòóïà ïî óêàçàòåëþ" << endl;
	cout << endl << "Ýëåìåíò íîìåð 2, 1, 2 â ìàññèâå ¹ 5" << endl;
	cout << *(*(*(array5 + 2) + 1) + 2) << endl;

	cout << endl << "11.	Ïðèñâîèòü óêàçàòåëþ ¹6 íà äâóìåðíûé ìàññèâ àäðåñ òðåõìåðíîãî ìàññèâà ¹5. Ïîâòîðèòü äëÿ ýòîãî óêàçàòåëÿ ïóíêò 10" << endl;
	pointer6 = array5;
	cout << endl << "Ýëåìåíò íîìåð 2, 1, 2 â óêàçàòåëå ¹ 6" << endl;
	cout << *(*(*(pointer6 + 2) + 1) + 2) << endl;

	return 1;
}