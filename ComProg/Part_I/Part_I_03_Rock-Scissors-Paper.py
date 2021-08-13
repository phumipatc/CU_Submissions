"""
    Task	: Part_I_03_RSP
    Author	: Phumipat C. [MAGCARI]
    Language: Python
    Created	: 12 August 2021 [13:10]
    Algo	:
    Status	:
"""
m = int(input())
p1 = p2 = 0
cnt = 0
while cnt != 3*m and p1 != m and p2 != m:
    a, b = [x for x in input().split()]
    cnt += 1
    if a == 'R':
        if b == 'R':
            continue
        elif b == 'S':
            p1 += 1
        else:
            p2 += 1
    elif a == 'S':
        if b == 'R':
            p2 += 1
        elif b == 'S':
            continue
        else:
            p1 += 1
    else:
        if b == 'R':
            p1 += 1
        elif b == 'S':
            p2 += 1
        else:
            continue
print(p1, p2)
if cnt == 3*m and p1 != m and p2 != m:
    print('Tie')
else:
    print('Player', 1 if p1 > p2 else 2, 'wins')
