"""
	Task	: 04_Loop_10_Bisection_Log10_2
	Author	: Phumipat C. [MAGCARI]
	Language: Python
	Created	: 12 August 2021 [11:58]
	Algo	: 
	Status	: 
"""
a = float(input())
l = 0
r = len(str(int(round(a))))
mid = (l+r)/2
while abs(a-10**mid) > 10**(-10)*max(a, 10**mid):
    # print(mid, 10**mid)
    if 10**mid > a:
        r = mid
    else:
        l = mid
    mid = (l+r)/2

print(round(mid, 6))
