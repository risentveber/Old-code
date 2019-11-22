# -*- coding: utf-8 -*-

def p(n):
    if n < 0:
        raise ValueError("unexpected n < 0")
    if n == 1 or n == 0: #база рекурсивного спуска
        return 1;
    result = 0
    i = 0 #счетчик суммы
    k = -1 #множитель отвечающий за (-1)^(i + 1) в началее рекуррентной суммы
    while True:
        k *= -1 #изменяем множитель
        i += 1 #и счетчик
        tmp = n - (3*i*i - i)/2 # аргумент первого рекурсивного слагаемого
        if (tmp >= 0): #прибавляем его если нужно
            result += k*p(tmp)

        tmp = n - (3*i*i + i)/2 # аргумент второго рекурсивного слагаемого
        if (tmp >= 0): #прибаляем его если нужно
            result += k*p(tmp)
        else: #больше нечего прибавлять
            return result

num = int(input("Please enter the number "))
print("the number of unordered partitions of", num, "is", p(num))
