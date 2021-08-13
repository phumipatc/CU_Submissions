"""
	Task	: 02_StrList_06_AddVector
	Author	: Phumipat C. [MAGCARI]
	Language: Python
	Created	: 11 August 2021 [12:20]
	Algo	: 
	Status	: 
"""
a = input()
a = a[1:len(a)-1]

b = input()
b = b[1:len(b)-1]

n = [float(x.strip()) for x in a.split(',')]
m = [float(x.strip()) for x in b.split(',')]

print(n, '+', m, '=', [n[i] + m[i] for i in range(0, len(n))])
