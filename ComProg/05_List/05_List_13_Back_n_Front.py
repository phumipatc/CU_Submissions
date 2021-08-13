"""
	Task	: 05_List_13_Back_n_Front
	Author	: Phumipat C. [MAGCARI]
	Language: Python
	Created	: 12 August 2021 [23:16]
	Algo	: 
	Status	: 
"""
n = int(input())
a = []
for i in range(n):
    num = int(input())
    a.append(num)

b = [int(x) for x in input().split()]
for x in b:
    a.append(x)

num = int(input())
while num != -1:
    a.append(num)
    num = int(input())

ans = []
if len(a) % 2 == 0:
    for i in range(len(a)-1, -1, -2):
        ans.append(a[i])
else:
    for i in range(len(a)-2, -1, -2):
        ans.append(a[i])
for i in range(0, len(a), 2):
    ans.append(a[i])

print(ans)
