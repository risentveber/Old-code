#include <iostream>

using namespace std;
int partition(int* a, int left, int right)
{
	int bar = a[(left+right)/2];//�������, ���������� ������������
	int i = left-1;
	int j = right+1;
	while (true)
	{
		do
		++i;
		while (a[i] < bar);
		do
		--j;
		while (a[j] > bar);
		if (i < j)
			swap(a[i], a[j]);
		else
			break;
		}
	return j;
};

int quicks(int* a,int left ,int right)
{
	if (left < right) //���������� ������������ ������ � ������, 
	{	              //����� ����������� ������� ����� ������ 1 ��������
	
		int bar = partition(a, left, right); //���������
		quicks(a,left, bar);                 //����� ���������� ��� ������� ����������
		quicks(a, bar+1, right);             //����� ���������� ��� ������ ����������

	}
	return 0;
};

int main()
{
	int* mass = (int*)malloc(sizeof(int)*10); //�������� ������ ��� ������

	for(int i=0; i < 10; i++)//���� �������� �������

		cin >> mass[i];
	quicks(mass, 0, 9);// ��������������� ���������� ������
	
	for(int i=0; i < 10; i++)//����� �������� �������
		cout <<	mass[i] << " ";
	cout << endl;
    free(mass);
	system("pause");
	return 0;
}