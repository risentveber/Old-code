# -*- coding: utf-8 -*-

mass = [1, 1] #инициализируем для p(0) и p(1)

def calculate_p(n): #функция для индуктивного вычисления p(n)
    global mass
    result = 0
    i = 0 #счетчик суммы
    k = -1 #множитель отвечающий за (-1)^(i + 1) в началее рекуррентной суммы
    while True:
        k *= -1 #изменяем множитель
        i += 1 #и счетчик
        tmp = n - (3*i*i - i)//2 # аргумент первого рекурсивного слагаемого
        if (tmp >= 0): #прибавляем его если нужно
            result += k*mass[tmp]

        tmp = n - (3*i*i + i)//2 # аргумент второго рекурсивного слагаемого
        if (tmp >= 0): #прибаляем его если нужно
            result += k*mass[tmp]
        else: #больше нечего прибавлять
            return result

def p(n):
    global mass
    if n < 0:
        raise ValueError("unexpected n < 0")
    if n + 1 > len(mass):
        for i in range(len(mass), n + 1): #добавляем нужные для вычисления элементы
            mass += [calculate_p(i)]
    return mass[n]



num = int(input("Please enter the number "))
print("the number of unordered partitions of", num, "is", p(num))
