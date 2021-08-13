"""
	Task	: 02_StrList_01_CitizenID
	Author	: Phumipat C. [MAGCARI]
	Language: Python
	Created	: 10 August 2021 [14:54]
	Algo	:
	Status	:
"""
ID = input()
check = (11-(sum([(13-i)*int(ID[i]) for i in range(0, 12)]) % 11)) % 10
print(ID[0:1], ID[1:5], ID[5:10], ID[10:12], check)
