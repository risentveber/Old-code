# -*- coding: utf-8 -*-

def fibonacci_number(n):
    if n <= 0:
        raise ValueError("wrong value < 0")
    if n == 1 or n == 2:
        return 1
    else:
        m1 = 1
        m2 = 1
        for i in range(2, n):
            tmp = m1
            m1 = m2
            m2 = m1 + tmp
        return m2

num = int(input("Please enter the number "))

print(fibonacci_number(num))
