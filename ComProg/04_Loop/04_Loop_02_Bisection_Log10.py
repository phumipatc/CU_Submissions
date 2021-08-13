"""
	Task	: 04_Loop_02_Bisection_Log10
	Author	: Phumipat C. [MAGCARI]
	Language: Python
	Created	: 11 August 2021 [23:20]
	Algo	:
	Status	:
"""
a = float(input())
l = 0
r = a
mid = (l+r)/2
while abs(a-10**mid) > 10**(-10)*max(a, 10**mid):
    # print(mid, 10**mid)
    if 10**mid > a:
        r = mid
    else:
        l = mid
    mid = (l+r)/2

print(round(mid, 6))
