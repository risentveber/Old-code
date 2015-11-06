#include <iostream>
#include <string>
#include <locale>

using namespace std;

int main()
{
	setlocale(LC_ALL,"RUSSIAN");
	int x=0; //itoa()
	bool mistake = false;
	bool step; //������� �������� ����������
	int sum=0;
	int n=0;// ���������� ���������
	int min, max;
	string s=" ";
	string s2;
	cout << "������� ����� ���� ������ ��������� ���� ������ �����" << endl;
	cout << "������� avg ����� ������� ������� �������� �������� �����" << endl;
	cout << "������� sum ����� ������� ����� �������� �����" << endl;
	cout << "������� min ����� ������� ����������� �� �������� �����" << endl;
	cout << "������� max ����� ������� ������������ �� �������� �����" << endl;
	cout << "������� clear ����� ������ �������� �����" << endl;
	cout << "������� q ����� ���������� ����" << endl;

	while (s !="q")
	{
		step = false;

		if (mistake) // ������ ���� ��� ����� �����
		{
			cout << "�� ��������, ��������� ����" << endl;
			mistake = false;
		};
		cin >> s;

		if (s=="sum")// ��� ������ ����� ����� �������������
		{
			cout << sum << endl;
			step = true;
		};

		if (s=="q")// ��������� ������� ����������� �����
			step = true;

		if (s == "avg") // ��� ������ �������� ���������������
	    {
			if (n != 0)
			{
				cout << sum/(n + 0.0) << endl;
				
			}
			else
				cout << "����� �������� �������� ����������: ������ ����" << endl;
			step = true;
		};

		if (s == "min")// ��� ������ ������������
	    {
			if ( n == 0)
				cout << "����� ������������ �������� ����������: ������ ����" << endl;
			else
				cout << min << endl;
			step = true;
		}; 

		if (s=="max")// ��� ������ �������������
	    {
			if (n==0)
				cout << "����� ������������� �������� ����������: ������ ����" << endl;
			else
				cout << max << endl;
			step = true;
		};

		if (s=="clear") // ��� ������ �������� ���������������
	    {
			n = 0;
			sum = 0;

			step = true;
		};
		if (!step)
		{
			x = atoi(s.c_str());
			char tmp[100];
			_itoa( x, tmp, 10 );
			s2 = tmp;
			if (s == s2 ) // ���� ��������� ������ �������� ������ ����� �� ��� � ���������� �
				          // ������� �������  atoi � �� ���� �������� � ������� � 
			{
				if (n == 0)  // ���� �������� ������ �� ��������� 
				{
					min = x;
					max = x;
				}
				else  // ���� �������� ������ ����
				{
					if (x < min)
						min = x;
					if (x > max)
						max = x;
				};

				sum += x;  //�������� �������������� ���������� � ���� �������� ������
				++n;
				
			}
			else // ���� ���� �������� ��������� ���� ������
				mistake = true;
		};
		


	};
	system("pause");

	return 0;
}