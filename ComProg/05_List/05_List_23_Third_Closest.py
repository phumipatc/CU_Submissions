"""
	Task	: 05_List_23_Third_Closest
	Author	: Phumipat C. [MAGCARI]
	Language: Python
	Created	: 14 August 2021 [10:59]
	Algo	: 
	Status	: 
"""


def cmp(a, b):
    da = a[1]*a[1] + a[2]*a[2]
    db = b[1]*b[1] + b[2]*b[2]
    return da < db


n = int(input())
coor = []
for i in range(1, n+1):
    x, y = [float(x) for x in input().split()]
    coor.append((i, (x, y)))
coor = sorted(coor, key=lambda x: (x[1][0]*x[1][0] + x[1][1]*x[1][1]))

print('#'+str(coor[2][0])+':', coor[2][1])
