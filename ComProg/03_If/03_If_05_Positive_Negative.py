"""
	Task	: 03_If_05_Positive_Negative
	Author	: Phumipat C. [MAGCARI]
	Language: Python
	Created	: 11 August 2021 [18:46]
	Algo	: 
	Status	: 
"""
n = int(input())

if n < 0:
    ans1 = 'negative'
elif n == 0:
    ans1 = 'zero'
else:
    ans1 = 'positive'

if n % 2 == 0:
    ans2 = 'even'
else:
    ans2 = 'odd'
print(ans1, ans2, sep='\n')
