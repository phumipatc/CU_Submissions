"""
	Task	: 01_Expr_06_Duration
	Author	: Phumipat C. [MAGCARI]
	Language: Python
	Created	: 10 August 2021 [14:34]
	Algo	: 
	Status	: 
"""
h1 = int(input())
m1 = int(input())
s1 = int(input())
h2 = int(input())
m2 = int(input())
s2 = int(input())

h2 += 24

hr = h2-h1
mi = m2-m1
se = s2-s1
if se < 0:
    mi -= 1
    se += 60
if mi < 0:
    hr -= 1
    mi += 60
hr %= 24
print(':'.join([str(hr), str(mi), str(se)]))
