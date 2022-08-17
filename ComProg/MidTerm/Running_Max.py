"""
    Task	: Running_Max
    Author	: Phumipat C. [MAGCARI]
    Language: Python
    Created	: 30 September 2021 [09:37]
    Algo	: 
    Status	: 
"""
num = [float(x) for x in input().split()]
k = int(num[0])
num = num[1:]

for i in range(len(num)):
    print(max(num[i:i+k]), end=' ')
