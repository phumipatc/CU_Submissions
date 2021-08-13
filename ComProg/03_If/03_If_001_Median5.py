"""
	Task	: 03_If_001_Median5
	Author	: Phumipat C. [MAGCARI]
	Language: Python
	Created	: 11 August 2021 [13:38]
	Algo	: 
	Status	: 
"""
a = int(input())
b = int(input())
c = int(input())
d = int(input())
e = int(input())
if a > b:
    a, b = b, a
if c > d:
    c, d = d, c
if a > c:
    b, d = d, b
    c = a
a = e

if a > b:
    a, b = b, a
if c > a:
    b, d = d, b
    a = c
if a > d:
    print(d)
else:
    print(a)
