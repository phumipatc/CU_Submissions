"""
    Task	: 09_MoreDC_31_Primitive_Pythagorean_Triple
    Author	: Phumipat C. [MAGCARI]
    Language: Python
    Created	: 06 October 2021 [11:57]
    Algo	: 
    Status	: 
"""
import math


def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a


def is_coprime(a, b, c):
    return (gcd(gcd(a, b), c) == 1)


def primitive_Pythagorean_triples(max_len):
    triple = []
    for k in range(1, max_len+1):
        for i in range(1, k):
            j = math.sqrt(k**2-i**2)
            if round(j) == j and j > i and is_coprime(i, j, k):
                triple.append([i, int(j), k])
    return triple


exec(input().strip())
