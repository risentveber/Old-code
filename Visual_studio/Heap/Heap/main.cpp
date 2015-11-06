#include <iostream>
#include <clocale>
using namespace std;
typedef int data;

struct heaptype
{
	int size;
	int maxsize;
	data* massiv;
};

bool compare(data a, data b) // a < b
{
	bool result = false;
	if (a < b)
	{
		result = true;
	}
	return result;
}

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

void heapInsert(heaptype &heap, data item, bool (*compare)(data a, data b))
{
	int i = heap.size;
	heap.size++;
	if (heap.size > heap.maxsize)
	{
		heap.maxsize *= 2;
		heap.massiv = (data*)realloc(heap.massiv, heap.maxsize*sizeof(data));
	}
	while ((i > 0) && compare(heap.massiv[i/2], item))
	{
		heap.massiv[i] = heap.massiv[i/2];
		i = i/2;
	}
	heap.massiv[i] = item;
}

data heapGet(heaptype &heap ,bool (*compare)(data a, data b))
{
	data result = heap.massiv[0];
	if (heap.size != 0)
	{
		swap(heap.massiv[0], heap.massiv[heap.size - 1]);
		heap.size--;
		heapify(heap, 0, compare);
		
	}

	return result;
}

void main()
{
	heaptype heap;
	heap.maxsize = 2;
	heap.size = 0;
	heap.massiv = (data*)malloc(2*sizeof(data));
	char command[30];
	char buffer[30];
	data item;
	/*gets(command);*/
	while (strncmp("exit", command, 30) != 0)
	{
		gets(command);
	
		if (strncmp("max", command, 30) == 0)
		{
			if (heap.size != 0)
			{
			printf("%d\n", heap.massiv[0]);
			}
		}
		else
		{
			if (strncmp("getmax", command, 30) == 0)
			{
				if (heap.size != 0)
				{
					printf("%d\n", heapGet(heap, compare));
				}
			}
			else
			{
				item = atoi(command);
				_itoa( item, buffer, 10 );
				if (strncmp(buffer, command, 30) == 0)
				{
				heapInsert(heap, item, &compare);
				}
				else
				{
					puts("Input error");
				}

			}
			
		}
		

	};
	free(heap.massiv);
	system("pause");
	return;
}