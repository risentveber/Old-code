#include <iostream>

using namespace std;
int partition(int* a, int left, int right)
{
    int bar = a[(left+right)/2];//элемент, являющийся разделителем
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
    if (left < right) //сортировка продолжается только в случае,
        {	              //когда сортируемый отрезок имеет больше 1 элемента

            int bar = partition(a, left, right); //разбиение
            quicks(a,left, bar);                 //вызов сортировки для правого подмассива
            quicks(a, bar+1, right);             //вызов сортировки для левого подмассива

        }
    return 0;
};

int main()
{
    int* mass = (int*)malloc(sizeof(int)*10); //Выделние прмяти под массив

    for(int i=0; i < 10; i++)//Ввод значений массива
        cin >> mass[i];

    quicks(mass, 0, 9);// непосредственно сортировка массив

    for(int i=0; i < 10; i++)//Вывод значений массива
        cout <<	mass[i] << " ";
    cout << endl;
    free(mass);
}
