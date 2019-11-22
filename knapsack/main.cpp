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
	puts("Введите пожалуйста вместимость рюкзака");
	while (!result)
		{
             result = (scanf("%d", &WEIGHT) == 1);  // Считываем число и проверяем, что оно считалось
             gets(trash); // Считываем содержимое буфера входного потока до конца строки
                          // (если пользователь ввёл "aa", "aa55", "55aa", то соответственно в trash запишется "aa"
             result = result && (strlen(trash) == 0) && (WEIGHT > 0); // Проверяем, что считалось число, и что в trash пусто
			 if (!result)
				 puts("Вы ошиблись");
		}
	result = false;
	puts("Введите пожалуйста количество элементов");
	while (!result)
		{
             result = (scanf("%d", &n) == 1);  // Считываем число и проверяем, что оно считалось
             gets(trash); // Считываем содержимое буфера входного потока до конца строки
                          // (если пользователь ввёл "aa", "aa55", "55aa", то соответственно в trash запишется "aa"
             result = result && (strlen(trash) == 0) && (n > 0); // Проверяем, что считалось число, и что в trash пусто
			 if (!result)
				 puts("Вы ошиблись");
		}
	puts("Введите пожалуйста n раз вес и стоимость каждого элемента");
	element* elements = (element*)calloc((n + 1), sizeof(element));
	for(int k = 1; k <= n; k++)
	{
		result = false;
		while (!result)            // Всё аналогично
		{
			result = (scanf("%i%i", &elements[k].weight, &elements[k].price) == 2);
			gets(trash);
			result = result && (strlen(trash) == 0) && (elements[k].weight > 0) && (elements[k].price > 0);
			if (!result)
				puts("Вы ошиблись");
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
		//В будущем возможно условие на адекватность элементов
		massiv[i][tempWeight].price = tempPrice;//Добавляем сам элемент непосредственно, координаты предыдущего - (0, 0)
		massiv[i][tempWeight].flag = true;
		for(int w = 1; w < WEIGHT; w++)
		{
			if (massiv[i - 1][w].price != 0) //Смотрим на предыдущий набор элементов с весом w
			{//и если он не пуст
				if (massiv[i][w].price < massiv[i - 1][w].price) //Без добавления текущего
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
				if (w + tempWeight <= WEIGHT) //Добавляем текущий элемент
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
	//Непосредственно вывод результатов
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
	printf("Общая стоимость %i\n", maxPrice);
	puts("Необходимо взять элементы со следующими номерами");
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
