void insertionsort(data* massiv, int count, bool (*compare)(data a, data b))
{
	int j;
	data temp;
	for (int i = 1; i < count; i++) {
        temp = massiv[i];
        for (j = i - 1; j >= 0; j--) {
			if (compare(temp, massiv[j])){
				massiv[j + 1] = massiv[j];}
			else{
				break;}}
		massiv[j + 1] = temp;}
}


int partition(data* massiv, int left, int right, bool (*compare)(data a, data b))
{
	data bar = massiv[(left+right)/2];
	int left_i = left - 1;
	int right_i = right + 1;
	bool flag = true;
	while (flag)
	{
		do
		{
			left_i++;
		}
		while (compare(massiv[left_i], bar ));

		do
		{
			right_i--;
		}
		while (compare(bar, massiv[right_i]));

		if (left_i < right_i)
		{
			std::swap(massiv[left_i], massiv[right_i]);
		}
		else
		{
			flag = false;

		}
	}

	return right_i;
}


void quickSort(data* massiv, int left, int right, bool (*compare)(data a, data b))
{
	if (left < right)
	{
		int bar = partition(massiv, left, right, compare);
		quickSort(massiv, left, bar, compare);
		quickSort(massiv, bar + 1, right, compare);
	}
	return;
}

void quickSortOPTIMA(data* massiv, int left, int right, bool (*compare)(data a, data b))
{
	if (right - left > 10)
	{
		int bar = partition(massiv, left, right, compare);
		quickSortOPTIMA(massiv, left, bar, compare);
		quickSortOPTIMA(massiv, bar + 1, right, compare);
	}
	else
	{
		bublesort(&massiv[left], right - left + 1, compare);
	}
	return;
}

void quicksort(data* massiv, int count, bool (*compare)(data a, data b))//Реализация под анализ
{
	quickSort(massiv,0,count-1,compare);
}

void quicksortoptima(data* massiv, int count, bool (*compare)(data a, data b))//Реализация под анализ
{
	quickSortOPTIMA(massiv,0,count-1,compare);
}
