"""
	Task	: 05_Loop_11_Run-Length_Encoding
	Author	: Phumipat C. [MAGCARI]
	Language: Python
	Created	: 12 August 2021 [12:02]
	Algo	: 
	Status	: 
"""
a = input()
n = len(a)
a = a+' '

idx = 0

for i in range(n):
    if a[i] != a[i+1]:
        print(a[idx], i-idx+1, end=' ')
        idx = i+1
