"""
	Task	: 04_Loop_01_Average
	Author	: Phumipat C. [MAGCARI]
	Language: Python
	Created	: 11 August 2021 [23:17]
	Algo	: 
	Status	: 
"""
num = input()
sum = n = 0
while num != 'q':
    sum += float(num)
    n += 1
    num = input()
if n == 0:
    print('No Data')
else:
    print(round(sum/n, 2))
