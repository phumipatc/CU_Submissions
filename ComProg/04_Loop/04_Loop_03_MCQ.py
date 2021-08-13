"""
	Task	: 04_Loop_03_MCQ
	Author	: Phumipat C. [MAGCARI]
	Language: Python
	Created	: 12 August 2021 [11:14]
	Algo	: 
	Status	: 
"""
a = input()
b = input()
if len(a) != len(b):
    print('Incomplete answer')
    exit(0)
print(len([i for i in range(len(a)) if a[i] == b[i]]))
