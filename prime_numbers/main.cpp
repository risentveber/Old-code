#include <iostream>
#include <stdlib.h>
#include <string>
#include <clocale>
#include <cmath>

using namespace std;
bool prime(int x) //функция проверяющая является ли число х простым
{
    bool a = true;
    int i=2;
    while (a && (i <= sqrt(x))) //мы перебираем все возможные делители от 1 до
    {							//х/2 так как делитель не может быть больше х/2
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
    cout << "Пожалуйста введите натуральное число " << endl;
    cin >> x;
    while (x <= 0) // обработка ошибок ввода
    {
        cout << "Вы допустили ошибку, пожалуйста повторите ввод" << endl;
        cin.clear();
        cin.sync();
        cin >> x;
    }
    cout << "Введите тип работы программы проверка числа на простоту - prime" <<
        endl << "если Решето Эратосфена-allp" << endl;
    cin >> s;

    while ((s != "prime") && (s != "allp")) // Обработка ошибок ввода
    {
        cout << "Вы допустили ошибку, пожалуйста повторите ввод" << endl;
        cin.clear();
        cin.sync();
        cin >> s;
    }

    if (s == "prime")
    {
        if (prime(x))
            cout << "Число ялвляется простым" << endl;
        else
            cout << "Число не являестя простым" << endl;
    }
    else
    {
        for(int i=2; i < x; ++i) // перебираем все числа от 2 до х-1
            if (prime(i))        // и выводиь каждое если оно простое
                cout << i << endl;
    };

    return 0;
}
