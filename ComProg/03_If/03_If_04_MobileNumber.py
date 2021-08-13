"""
	Task	: 03_If_04_MobileNumber
	Author	: Phumipat C. [MAGCARI]
	Language: Python
	Created	: 11 August 2021 [18:40]
	Algo	: 
	Status	: 
"""
n = input()
if len(n) != 10 or n[0] != '0' or (n[1] != '6' and n[1] != '8' and n[1] != '9'):
    print('Not a mobile number')
else:
    print('Mobile number')
