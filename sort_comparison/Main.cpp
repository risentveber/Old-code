#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <clocale>


using namespace std;
typedef int data;

#include "Functions.h"
#include "QuickSort.h"
#include "Analyze.h"
#include "HeapSort.h"
#include <math.h>
#include "Mergesort.h"

bool compare(data a, data b)
{
	bool result = false;
	if (a < b)
	{
		result = true;
	}
	return result;
}

int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	puts("Время работы указано в тактах");
	printf("\n");
	analyze("Bublesort", 4, &bublesort, &compare);
	analyze("Insertionsort", 4, &insertionsort, &compare);
	analyze("Mergesort", 7, &mergesort, &compare);
	analyze("Shellsort", 7, &shellsort, &compare);
	analyze("Heapsort", 7, &heapsort, &compare);
	analyze("QuicksortOPTIMFA", 7, &quicksortoptima, &compare);
	analyze("Quicksort", 7, &quicksort, &compare);
	analyze("Systemsort", 7, &systemsort, &compare);

	/*data a[100];
	fillMassiv(a, 100, 50);
	quicksortoptima(a, 100, &compare);
	printMassiv(a, 100);*/
	system("pause");
	return 0;
}
