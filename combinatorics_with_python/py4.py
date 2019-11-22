# -*- coding: utf-8 -*-
import itertools
from math import ceil

n = int(input("Please enter n "))
k = int(input("Please enter k "))
t = int(input("Please enter t "))

if not(t > 2*k - n and 2 <= t and t <= k and k <= n):
    raise ValueError("the input doesn't satisfy theorem's conditions")


r = (t - 1)*(k - t + 1)/(n - 2*(k-t+1)) - 1
r = int(ceil(r))#округляем в большую сторону

#разделяем все элементы на два диапазона [1, t + 2*r] и [t + 2*r + 1, n]
for e_f in range(t + r, min(t + 2*r, k) + 1): # e_f - количество элементов в ребре из начального диапазона
    for i in itertools.combinations(range(1, t+2*r +1), e_f): #выбираем часть ребра из первого диапазона мощности e_f
        for y in itertools.combinations(range(t+2*r + 1, n + 1), k - e_f): #выбираем оставшуюся часть ребра из второго диапазона
            for tmp in i + y :
                print(tmp, end = " ")
                print("")

