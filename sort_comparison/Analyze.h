
#include <time.h>
#include <intrin.h>

void fillMassiv(data* massiv, int count, int det)
{//Заполняет массив размера count случайными числами
	srand(det);
	for(int index = 0; index < count; index++)
	{
		massiv[index] = rand() % 100000;
		massiv[index] *= 1000;
		massiv[index] += rand() % 100000;
	}
}

void printMassiv(data* massiv, int count)//Выводит на экран массив размера count
{
	for(int i = 0; i < count; i++)
	{
		printf("%10d", massiv[i]);
	}
	printf("\n");
}


void analyze(char name[50], int border, void (*sortew)(data* massiv, int count, bool (*compare)(data a, data b)),bool (*compare)(data a, data b))
{
	data* massiv = (data*)malloc(10000000*sizeof(data));
	unsigned __int64 max;
	unsigned __int64 min;
	unsigned __int64 sum;
	int count;
	unsigned __int64 temp;//Время работы
	int random = 0;
	puts(name);
	puts("Количество                  min              average                  max");
	for(int m = 1; m <= border; m++)
	{
		count = pow(10, m);
		max = 0;
		min = 10000000000000;
		sum = 0;
		for(int k = 0; k < 10; k++)// 10 раз испытываем на данном количестве count
		{
			random++;
			fillMassiv(massiv, count, random);
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
		printf("%20I64d ", min);
		printf("%20I64d ", sum/10);
		printf("%20I64d \n", max);
	}
	free(massiv);
	printf("\n");
	return;
}
