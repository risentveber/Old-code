#include <iostream>
#include <string>
using namespace std;

int size;
char** split(char* str, char* separator)
{
    int n=0;
    int l;
    for(int i = 0; separator[i] != '\0'; ++i)
        ++n;
    size=1;
    char** aaa = (char**)malloc(sizeof(char*));
    aaa[0] = (char*) malloc(sizeof(char));
    int* acount = (int*)malloc(sizeof(int));
    acount[0] = 1;
    aaa[0][0] = '\0';
    bool flag;
    for(int i = 0; str[i] != '\0'; ++i )
    {
        l=i;
        flag = true;
        for(int j = 0; str[i+j] == separator[j]; ++j)
            if (j+1==n)
            {
                ++size;
                aaa = (char**)realloc(aaa,sizeof(char*)*size);// увеличиваем количество указателей на подстроки
                acount = (int*)realloc(acount,sizeof(int)*size);// увеличиваем количество количеств символов подстрок соответственно
                acount[size-1] =   1; // количество символов в подстроке size
                aaa[size-1] = (char*)malloc(sizeof(char)*acount[size-1]);
                aaa[size-1][acount[size-1]-1]='\0';
                i=i+j;
                flag = false;

            };
        if (flag)
        {
            ++acount[size-1];
            aaa[size-1] = (char*)realloc(aaa[size-1],sizeof(char)*(acount[size-1]+1));
            aaa[size-1][acount[size-1]-2]=str[i];
            aaa[size-1][acount[size-1]-1]='\0';
        }
    };
    free(acount);
    return aaa;
};

int main()
{
    char* a;
    char* b;
    char c;
    int count_a=0;
    int count_b=0;
    a = (char*)malloc(sizeof(char));
    b = (char*)malloc(sizeof(char));

    do//Посимвольный ввод строки - данных
    {
        cin.get(c);
        ++count_a;
        a = (char*)realloc(a,sizeof(char)*(count_a + 1));
        a[count_a - 1] = c;
    }
    while (c != '\n');
    a[count_a - 1] = '\0';

    do//Посимвольный ввод строки - разделителя
    {
        cin.get(c);
        ++count_b;
        b = (char*)realloc(b,sizeof(char)*(count_b + 1));
        b[count_b - 1] = c;
    }
    while (c != '\n');
    b[count_b - 1] = '\0';


    char** mmm;
    mmm = (char**)malloc(sizeof(char*)*1000);
    mmm = split(a, b);
    for(int i = 0; i<size; ++i)
    {
        cout << mmm[i] << endl;//вывод строки
        free(mmm[i]);//очистка соответсвующей памяти
    };

    free(a);
    free(b);
}
