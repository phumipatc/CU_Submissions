"""
	Task	: 03_If_06_RegisteredMail
	Author	: Phumipat C. [MAGCARI]
	Language: Python
	Created	: 11 August 2021 [18:17]
	Algo	: 
	Status	: 
"""
n = int(input())

if n <= 100:
    print('18')
elif n <= 250:
    print('22')
elif n <= 500:
    print('28')
elif n <= 1000:
    print('38')
elif n <= 2000:
    print('58')
else:
    print('Reject')
