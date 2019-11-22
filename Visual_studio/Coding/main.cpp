#include <stdio.h>
#include <iostream>
#include <clocale>

using namespace std;

char coding(int* k, char temp_c)
{
	char a0, b;
	/*int n;*/
	a0 = a0 & 0;
	b = b & 0;
	for(int i = 0; i < 8; i++)
	{
		if ((temp_c & (1 << i)) != a0)
		{
			b = b | (1 << k[i]);
		}
	}

	return b;
};

int main()
{
	setlocale(LC_ALL,"RUSSIAN");
	char stroke[100];
	int k;
	int temp;
	int* key = (int*)calloc(8, sizeof(int));
	int* dekey = (int*)calloc(8, sizeof(int));
	bool error = false;
	do
	{
		if (error)
		{
			puts("�� ����� ������������ ����, ��������� ����");
			error = false;
		}
		else
		{
			puts("���������� ������� ����");
		}
        error = (scanf("%i", &k) == 0);
        gets(stroke);                           
        error = error || (strlen(stroke) != 0); 
        if (!(error))
		{
			for(int i = 0; i < 8; i++)  // ���� �����
			{
				if (k == 0)
				{
					error = true;
				}
				temp = k % 10 - 1;
				key[i] = temp;
				k = k / 10;
				for(int m = 0; m < i; m++)
				{
					if (key[m] == temp)
					{
						error = true;
					}
				}
			}
			if (k != 0)
			{
				error = true;
			}
		}
	}
	while (error);
	puts("���������� ������� �������������� ������");
	gets(stroke);
	int n = 0;
	while (stroke[n] != '\0') //������������ ���������
	{			
        stroke[n] = coding(key, stroke[n]);
		n++;
	}	
	puts(stroke); //����� ���������������
	n = 0;
	for(int i = 7; i >= 0; i--)
	{
		dekey[key[i]] = i;
	}
	while (stroke[n] != '\0')
	{			
        stroke[n] = coding(dekey, stroke[n]);
		n++;
	}
	puts(stroke); //����� ���������
	system("pause");
	return 0;
}