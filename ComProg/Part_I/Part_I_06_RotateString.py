"""
    Task	: Part_I_06_RotateString
    Author	: Phumipat C. [MAGCARI]
    Language: Python
    Created	: 20 August 2021 [14:53]
    Algo	:
    Status	:
"""
cmd = input()
n = int(input())
a = []
m = 0
for i in range(n):
    b = input().strip()
    a.append(b)
    if m != 0 and m != len(b):
        print('Invalid size')
        exit(0)
    m = len(b)

if cmd == '90':
    for j in range(m):
        for i in range(n-1, -1, -1):
            print(a[i][j], end='')
        print()
elif cmd == '180':
    for i in range(n-1, -1, -1):
        for j in range(m-1, -1, -1):
            print(a[i][j], end='')
        print()
else:
    for i in range(n):
        for j in range(m-1, -1, -1):
            print(a[i][j], end='')
        print()
