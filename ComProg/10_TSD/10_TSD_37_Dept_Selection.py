"""
    Task	: 10_TSD_37_Dept_Selection
    Author	: Phumipat C. [MAGCARI]
    Language: Python
    Created	: 15 October 2021 [16:51]
    Algo	: 
    Status	: 
"""
dept = {}

for i in range(int(input())):
    id, num = [x for x in input().split()]
    dept[id] = int(num)

data = []
for i in range(int(input())):
    temp = input().split()
    temp[0], temp[1] = float(temp[1]), temp[0]
    data.append(temp)
data.sort(reverse=True)

ans = {}
for x in data:
    for y in x[2:]:
        if dept[y] == 0:
            continue
        dept[y] -= 1
        ans[x[1]] = y
        break
for x in sorted(ans):
    print(x, ans[x])
