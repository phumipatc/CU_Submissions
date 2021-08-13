"""
	Task	: 02_StrList_08_Decimal2Fraction
	Author	: Phumipat C. [MAGCARI]
	Language: Python
	Created	: 10 August 2021 [15:45]
	Algo	: 
	Status	: 
"""
import math

a, b, c = input().split(',')
# print(a, b, c)
# print(len(a), len(b), len(c))

n = int(a+b)
m = int(a+b+c)
# print(n, m)

up = m-n
down = (10**len(b+c))-(10**len(b))
# print(up, down)

print(up//math.gcd(up, down), '/', down//math.gcd(up, down))
