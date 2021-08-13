"""
	Task	: 05_List_16_Collatz
	Author	: Phumipat C. [MAGCARI]
	Language: Python
	Created	: 12 August 2021 [23:31]
	Algo	: 
	Status	: 
"""
n = int(input())

num = [str(n)]
while n != 1:
    if n % 2 == 0:
        n = n // 2
    else:
        n = 3*n + 1
    num.append(str(n))
# print(len(num)-15)
print('->'.join(num[max(0, len(num)-15):]))
