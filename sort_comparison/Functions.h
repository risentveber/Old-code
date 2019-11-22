

typedef int data;


void systemsort(data* massiv, int count, bool (*compare)(data a, data b))
{
	sort(massiv, massiv+count);
}

void bublesort(data* massiv, int count, bool (*compare)(data a, data b))
{
	bool flag = true;
	int m;
	for(int i = 0; (i < count) && flag; i++)
	{
		flag = false;
		for(m = count - 1; m > i ; m--)
		{
			if (compare(massiv[m], massiv[m - 1]))
			{
				swap(massiv[m], massiv[m - 1]);
				flag = true;
			}
		}
	}
}

void shellsort(data* massiv, int count, bool (*compare)(data a, data b))
{
	int gap, i, j;
	data temp;
	for (gap = count/2; gap > 0; gap /= 2)
		for (i = gap; i < count; i++)
			for (j = i - gap; j >= 0 && compare(massiv[j + gap], massiv[j]); j -= gap){
				temp = massiv[j];
				massiv[j] = massiv[j + gap];
				massiv[j + gap] = temp;
			}
}
