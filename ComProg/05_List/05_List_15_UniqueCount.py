"""
	Task	: 05_List_15_UniqueCount
	Author	: Phumipat C. [MAGCARI]
	Language: Python
	Created	: 12 August 2021 [23:23]
	Algo	: 
	Status	: 
"""
a = [int(x) for x in input().split()]
a.sort()

ans = []
cnt = 0
for i in range(len(a)):
    if i == len(a)-1 or a[i] != a[i+1]:
        cnt += 1
        ans.append(a[i])
print(cnt)
print(ans[:10])
