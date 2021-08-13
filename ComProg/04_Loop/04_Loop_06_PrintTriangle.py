"""
	Task	: 04_Loop_06_PrintTriangle
	Author	: Phumipat C. [MAGCARI]
	Language: Python
	Created	: 12 August 2021 [11:35]
	Algo	: 
	Status	: 
"""
n = int(input())
print(' '*(n-1) + '*')
for i in range(2, n):
    print(' '*(n-i) + '*' + ' '*(2*i-3) + '*')
print('*'*(2*n-1))
