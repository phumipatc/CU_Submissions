"""
	Task	: 07_StrFile_22_Anagram
	Author	: Phumipat C. [MAGCARI]
	Language: Python
	Created	: 14 August 2021 [00:30]
	Algo	: 
	Status	: 
"""
a = sorted(input().replace(' ', '').lower())
b = sorted(input().replace(' ', '').lower())
# print(a, b)
print('YES' if a == b else 'NO')
