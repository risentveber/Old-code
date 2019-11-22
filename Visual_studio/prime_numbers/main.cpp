#include <iostream>
#include <stdlib.h>
#include <string>
#include <clocale>

using namespace std;
bool prime(int x) //������� ����������� �������� �� ����� � �������
{
	bool a = true;
	int i=2;
	while (a && (i <= sqrt(x))) //�� ���������� ��� ��������� �������� �� 1 ��              
	{							//�/2 ��� ��� �������� �� ����� ���� ������ �/2
		if (!(x % i)) 
			a=false;
		++i;
	};
	return a;
};


int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	int x = 0;
	string s;
	cout << "���������� ������� ����������� ����� " << endl;
	cin >> x;
	while (x <= 0) // ��������� ������ �����
	{
		cout << "�� ��������� ������, ���������� ��������� ����" << endl;
		cin.clear();
		cin.sync();
		cin >> x;
	}
	cout << "������ ��� ������ ��������� �������� ����� �� �������� - prime ���"<< endl <<"���� ������ ����������-allp" << endl;
	cin >> s;

	while ((s != "prime") && (s != "allp")) // ��������� ������ �����
	{
		cout << "�� ��������� ������, ���������� ��������� ����" << endl;
		cin.clear();
		cin.sync();
		cin >> s;
	}

	if (s == "prime")
    { 
		if (prime(x)) 
			cout << "����� ��������� �������" << endl;
		else
			cout << "����� �� �������� �������" << endl;
	}
	else
	{
		for(int i=2; i < x; ++i) // ���������� ��� ����� �� 2 �� �-1
			if (prime(i))        // � ������� ������ ���� ��� �������
				cout << i << endl;
	};

	system("pause");
	return 0;
}