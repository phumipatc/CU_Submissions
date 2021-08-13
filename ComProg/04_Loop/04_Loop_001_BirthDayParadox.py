"""
	Task	: 04_Loop_001_BirthDayParadox
	Author	: Phumipat C. [MAGCARI]
	Language: Python
	Created	: 11 August 2021 [23:07]
	Algo	: 
	Status	: 
"""
p = float(input())

k = t = 1
t = t*(365-(k-1))/365

while 1-t < p:
    k += 1
    t = t*(365-(k-1))/365
print(k)
