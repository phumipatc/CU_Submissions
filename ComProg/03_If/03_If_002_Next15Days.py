"""
	Task	: 03_If_002_Next15Days
	Author	: Phumipat C. [MAGCARI]
	Language: Python
	Created	: 11 August 2021 [13:41]
	Algo	: 
	Status	: 
"""
d, m, y = [int(x) for x in input().split()]
y -= 543

n = 31
month30 = [4, 6, 9, 11]
if m in month30:
    n = 30
else:
    if m == 2:
        n = 28
        if y % 400 == 0 or (y % 4 == 0 and y % 100 != 0):
            n = 29
d = d+15
if d > n:
    d -= n
    m += 1
if m > 12:
    m -= 12
    y += 1
y += 543
print('/'.join([str(d), str(m), str(y)]))
