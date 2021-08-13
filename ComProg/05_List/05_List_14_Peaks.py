"""
	Task	: 05_List_14_Peaks
	Author	: Phumipat C. [MAGCARI]
	Language: Python
	Created	: 12 August 2021 [23:28]
	Algo	: 
	Status	: 
"""
a = [float(x) for x in input().split()]

ans = len([i for i in range(1, len(a)-1) if a[i] > a[i-1] and a[i] > a[i+1]])

print(ans)
