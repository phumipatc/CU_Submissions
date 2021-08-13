"""
	Task	: 03_If_03_Gymnastic_Score
	Author	: Phumipat C. [MAGCARI]
	Language: Python
	Created	: 11 August 2021 [18:36]
	Algo	: 
	Status	: 
"""
a, b, c, d = [float(x) for x in input().split()]

if a > b:
    a, b = b, a
if b > c:
    b, c = c, b
if c > d:
    c, d = d, c

if d < c:
    c, d = d, c
if c < b:
    b, c = c, b
if b < a:
    a, b = b, a

print(round((b+c)/2, 2))
