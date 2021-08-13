"""
	Task	: 03_If_003_Flowchart-If-Else
	Author	: Phumipat C. [MAGCARI]
	Language: Python
	Created	: 11 August 2021 [13:56]
	Algo	:
	Status	:
"""
a, b, c, d = [int(x) for x in input().split()]
if a > b:
    a, b = b, a
    if d >= a:
        if c > d:
            c -= a
    else:
        c += a
    b = a+c+d
else:
    if c > a >= b:
        d += a
    if d > c:
        b += 2
    else:
        b *= 2
print(a, b, c, d)
