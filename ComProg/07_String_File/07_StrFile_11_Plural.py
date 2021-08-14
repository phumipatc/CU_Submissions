"""
	Task	: 07_StrFile_11_Plural
	Author	: Phumipat C. [MAGCARI]
	Language: Python
	Created	: 13 August 2021 [15:34]
	Algo	: 
	Status	: 
"""
a = input()
n = len(a)

vowel = ['a', 'e', 'i', 'o', 'u']

if a[n-1] == 's' or a[n-1] == 'x' or a[n-2:] == 'ch':
    print(a + 'es')
elif a[n-1] == 'y' and a[n-2] not in vowel:
    print(a[:n-1] + 'ies')
else:
    print(a + 's')
