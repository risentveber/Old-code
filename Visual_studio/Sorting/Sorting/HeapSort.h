struct heaptype
{
	int size;
	int count;
	data* massiv;
};

void heapify(heaptype &heap, int index, bool (*compare)(data a, data b))
{
	int left = index*2 + 1;
	int right = left + 1;
	int max = left;
	if (heap.size > right)// двое потомков
	{
		if (compare(heap.massiv[left], heap.massiv[right]))
		{
			max = right;
		}
		if (compare(heap.massiv[index], heap.massiv[max]))
		{
			swap(heap.massiv[index], heap.massiv[max]);
			heapify(heap, max, compare);

		}

	}
	else
	{
		if (heap.size > left)// один потомок
		{
			if (compare(heap.massiv[index], heap.massiv[left]))
			{
				swap(heap.massiv[left], heap.massiv[index]);
			}
		}
	}
	
}

void heapsort(data* massiv, int count, bool (*compare)(data a, data b))
{
	heaptype heap;
	heap.size = count;
	heap.massiv = massiv;
	for(int i = count/2 -1; i >= 0; i--)//Построение кучи
	{
		heapify(heap, i, compare);
	}
	for(int i = count - 1; i > 0; i--)
	{
		swap(heap.massiv[0],heap.massiv[i]);
		heap.size--;
		heapify(heap, 0, compare);
	}


	return;
}
