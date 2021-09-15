"""
    Task	: Part_I_04_Bowling
    Author	: Phumipat C. [MAGCARI]
    Language: Python
    Created	: 07 September 2021 [09:46]
    Algo	:
    Status	:
"""
pt = input().strip()
target = int(input())
idx = 1
cnt = 0

sc = [0 for i in range(12)]


def cal(i: int):
    if i >= len(pt):
        return 0
    x = pt[i]
    if x == 'X':
        return 10
    elif x == '/':
        return 10 - int(pt[i-1])
    else:
        return int(x)


for i in range(len(pt)):
    x = pt[i]
    if x == 'X':
        sc[idx] += cal(i) + (cal(i+1) + cal(i+2)) * (1 if idx != 10 else 0)
        if idx != 10:
            idx += 1
            cnt = 0
    elif x == '/':
        sc[idx] += cal(i) + cal(i+1) * (1 if idx != 10 else 0)
        if idx != 10:
            idx += 1
            cnt = 0
    else:
        sc[idx] += int(x)
        cnt += 1
        if cnt == 2:
            idx += 1
            cnt = 0

sc[10] += sc[11]
sc[11] = 0
if 1 <= target <= 10:
    print(sc[target])
else:
    print(sum(sc))
