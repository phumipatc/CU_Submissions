"""
	Task	: 03_If_08_Day_of_Year
	Author	: Phumipat C. [MAGCARI]
	Language: Python
	Created	: 11 August 2021 [18:48]
	Algo	: 
	Status	: 
"""
d = int(input())
m = int(input())
y = int(input())
y -= 543

cnt = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

sum = sum(cnt[:m])
if y % 400 == 0 or (y % 4 == 0 and y % 100 != 0):
    if m > 2:
        sum += 1
print(sum+d)
