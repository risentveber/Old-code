#include <cstdio>
#include <cstring>
#include <clocale> 

int main()
{
	setlocale(LC_ALL, "RUSSIAN");
       int d;
       char trash[1024];
       bool result = false;

       while (!result)
       {
             printf("������� �����:\n");
             result = (scanf("%d", &d) == 1);  // ��������� ����� � ���������, ��� ��� ���������
             gets(trash); // ��������� ���������� ������ �������� ������ �� ����� ������
                          // (���� ������������ ��� "aa", "aa55", "55aa", �� �������������� � trash ��������� "aa"
             result = result && (strlen(trash) == 0); // ���������, ��� ��������� �����, � ��� � trash �����
       } 

       int d1, d2;
       result = false;

       while (!result)            // �� ����������
       {
             printf("������� ��� �����:\n");
             result = (scanf("%d %d", &d1, &d2) == 2);            
             gets(trash);
             result = result && (strlen(trash) == 0);
       }

}