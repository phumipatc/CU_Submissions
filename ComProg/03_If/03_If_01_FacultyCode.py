"""
	Task	: 03_If_01_FacultyCode
	Author	: Phumipat C. [MAGCARI]
	Language: Python
	Created	: 11 August 2021 [18:30]
	Algo	: 
	Status	: 
"""
n = input()

if len(n) != 2 or not n.isnumeric():
    print('Error')
    exit(0)
n = int(n)
if n <= 2 or (20 <= n <= 40) or n == 51 or n == 53 or n == 55 or n == 58:
    print('OK')
else:
    print('Error')
