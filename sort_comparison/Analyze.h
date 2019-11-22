#include <stdlib.h>
#include <stdio.h>
#include <cmath>
#include <time.h>
#include <string>

typedef int data;

void fillArray(data* massiv, int count, int det)
{//Заполняет массив размера count случайными числами
	srand(det);
	for(int index = 0; index < count; index++)
	{
		massiv[index] = rand() % 100000;
		massiv[index] *= 1000;
		massiv[index] += rand() % 100000;
	}
}

void printArray(data* massiv, int count)//Выводит на экран массив размера count
{
	for(int i = 0; i < count; i++)
	{
		printf("%10d", massiv[i]);
	}
	printf("\n");
}

void analyze(const char name[100], int border, void (*sortew)(data* massiv, int count, bool (*compare)(data a, data b)),bool (*compare)(data a, data b))
{
	data* massiv = (data*)malloc(10000000*sizeof(data));
	unsigned long int max;
	unsigned long int min;
	unsigned long int sum;
	int count;
	unsigned long int temp;//Время работы
	int random = 0;
	puts(name);
	printf("Количество                  min              average                  max\n");
	for(int m = 1; m <= border; m++)
	{
		count = pow(10, m);
		max = 0;
		min = 10000000000000;
		sum = 0;
		for(int k = 0; k < 10; k++)// 10 раз испытываем на данном количестве count
		{
			random++;
			fillArray(massiv, count, random);
			temp = __rdtsc();
			sortew(massiv, count, compare);
			temp = __rdtsc() - temp;
			sum += temp;
			if (temp > max)
			{
				max = temp;
			}
			if (temp < min)
			{
				min = temp;
			}
		}
		printf("%10i ", count);
		printf("%20lu ", min);
		printf("%20lu ", sum/10);
		printf("%20lu \n", max);
	}
	free(massiv);
	printf("\n");
	return;
}
