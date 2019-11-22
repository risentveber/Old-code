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
        printf("Введите число:\n");
        result = (scanf("%d", &d) == 1);  // Считываем число и проверяем, что оно считалось
        gets(trash); // Считываем содержимое буфера входного потока до конца строки
        // (если пользователь ввёл "aa", "aa55", "55aa", то соответственно в trash запишется "aa"
        result = result && (strlen(trash) == 0); // Проверяем, что считалось число, и что в trash пусто
    }

    int d1, d2;
    result = false;

    while (!result)            // Всё аналогично
    {
        printf("Введите два числа:\n");
        result = (scanf("%d %d", &d1, &d2) == 2);
        gets(trash);
        result = result && (strlen(trash) == 0);
    }
}
