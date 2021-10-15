"""
    Task	: 09_MoreDC_12_Union_Intersection
    Author	: Phumipat C. [MAGCARI]
    Language: Python
    Created	: 06 October 2021 [15:09]
    Algo	: 
    Status	: 
"""
n = int(input())

union = set()
intersect = dict()
for i in range(n):
    a = set([int(x) for x in input().split()])
    for x in a:
        union.add(x)
        if x in intersect:
            intersect[x] += 1
        else:
            intersect[x] = 1

print(len(union))

cnt = 0
for x in intersect.items():
    if x[1] == n:
        cnt += 1
print(cnt)
