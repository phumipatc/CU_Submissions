"""
	Task	: 02_StrList_04_NDigits
	Author	: Phumipat C. [MAGCARI]
	Language: Python
	Created	: 10 August 2021 [15:10]
	Algo	: 
	Status	: 
"""
m = int(input())
n = int(input())

print("%s%d" % (max(0, n-len((str(m))))*'0', m))
