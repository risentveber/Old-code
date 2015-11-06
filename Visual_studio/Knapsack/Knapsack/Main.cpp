#include <stdio.h>
#include <stdlib.h>
#include <clocale>
#include <string>

using namespace std;
struct tablo
{
	int price;
	bool flag;
	int x;
	int y;
};

struct element
{
	int weight;
	int price;
};

void main()
{
	setlocale(LC_ALL, "RUSSIAN");
	int n;
	int WEIGHT;
	int tempWeight;
	int tempPrice;
	char trash[100];
	bool result = false;
	puts("������� ���������� ����������� �������");
	while (!result)
		{
             result = (scanf("%d", &WEIGHT) == 1);  // ��������� ����� � ���������, ��� ��� ���������
             gets(trash); // ��������� ���������� ������ �������� ������ �� ����� ������
                          // (���� ������������ ��� "aa", "aa55", "55aa", �� �������������� � trash ��������� "aa"
             result = result && (strlen(trash) == 0) && (WEIGHT > 0); // ���������, ��� ��������� �����, � ��� � trash �����
			 if (!result) 
				 puts("�� ��������");
		} 
	result = false;
	puts("������� ���������� ���������� ���������");
	while (!result)
		{
             result = (scanf("%d", &n) == 1);  // ��������� ����� � ���������, ��� ��� ���������
             gets(trash); // ��������� ���������� ������ �������� ������ �� ����� ������
                          // (���� ������������ ��� "aa", "aa55", "55aa", �� �������������� � trash ��������� "aa"
             result = result && (strlen(trash) == 0) && (n > 0); // ���������, ��� ��������� �����, � ��� � trash �����
			 if (!result) 
				 puts("�� ��������");
		} 
	puts("������� ���������� n ��� ��� � ��������� ������� ��������");
	element* elements = (element*)calloc((n + 1), sizeof(element));
	for(int k = 1; k <= n; k++)
	{
		result = false;
		while (!result)            // �� ����������
		{
			result = (scanf("%i%i", &elements[k].weight, &elements[k].price) == 2);            
			gets(trash);
			result = result && (strlen(trash) == 0) && (elements[k].weight > 0) && (elements[k].price > 0);
			if (!result)
				puts("�� ��������");
		}		
	}
	tablo** massiv = (tablo**)calloc((n + 1), sizeof(tablo*));
	for(int k = 0; k <= n; k++)
	{
		massiv[k] = (tablo*)calloc((WEIGHT + 1), sizeof(tablo));
	}
	for(int i = 1; i <= n; i++)
	{
		tempWeight = elements[i].weight;
		tempPrice = elements[i].price;
		//� ������� �������� ������� �� ������������ ���������
		massiv[i][tempWeight].price = tempPrice;//��������� ��� ������� ���������������, ���������� ����������� - (0, 0)
		massiv[i][tempWeight].flag = true;
		for(int w = 1; w < WEIGHT; w++)
		{
			if (massiv[i - 1][w].price != 0) //������� �� ���������� ����� ��������� � ����� w 
			{//� ���� �� �� ����
				if (massiv[i][w].price < massiv[i - 1][w].price) //��� ���������� ��������
				{
					massiv[i][w].price = massiv[i - 1][w].price;
					massiv[i][w].flag = false; 
					if (massiv[i - 1][w].flag)
					{
						massiv[i][w].x = i - 1;
						massiv[i][w].y = w;
					}
					else
					{
						massiv[i][w].x = massiv[i - 1][w].x;
						massiv[i][w].y = massiv[i - 1][w].y;
					}
				}
				if (w + tempWeight <= WEIGHT) //��������� ������� �������
				{
					if(massiv[i][w + tempWeight].price < massiv[i - 1][w].price + tempPrice)
					{
						massiv[i][w + tempWeight].price = massiv[i - 1][w].price + tempPrice;
						massiv[i][w + tempWeight].flag = true;
						if (massiv[i - 1][w].flag)
						{
							massiv[i][w + tempWeight].x = i - 1;
							massiv[i][w + tempWeight].y = w;
						}
						else
						{
							massiv[i][w + tempWeight].x = massiv[i - 1][w].x;
							massiv[i][w + tempWeight].y = massiv[i - 1][w].y;
						}
					}
				}
			}
		}
	}
	//��������������� ����� �����������
	int maxPrice = 0;
	int tempX = n;
	int tempY = 0;
	for(int w = 1; w <= WEIGHT; w++)
	{
		if (massiv[n][w].price > maxPrice)
		{
			maxPrice = massiv[n][w].price;
			tempY = w;
		}
	}
	int x;
	int y;
	if (!(massiv[tempX][tempY].flag))
	{
		
		x = massiv[tempX][tempY].x;
		y = massiv[tempX][tempY].y;
		tempX = x;
		tempY = y;
	}
	printf("����� ��������� %i\n", maxPrice);
	puts("���������� ����� �������� �� ���������� ��������");
	do
	{
		printf("%i\n", tempX);
		x = massiv[tempX][tempY].x;
		y = massiv[tempX][tempY].y;
		tempX = x;
		tempY = y;
	}
	while ((tempX != 0) && (tempY != 0));
	system("pause");
	return;
}