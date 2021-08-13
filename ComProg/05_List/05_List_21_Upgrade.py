"""
    Task	: 05_List_21_Upgrade
    Author	: Phumipat C. [MAGCARI]
    Language: Python
    Created	: 12 August 2021 [23:36]
    Algo	:
    Status	:
"""
id = []
g = []

a = input()
while a != 'q':
    x, y = a.split()
    id.append(x)
    g.append(y)
    a = input()
a = [x for x in input().split()]
for x in a:
    idx = id.index(x)
    if g[idx] == 'A':
        continue
    if len(g[idx]) == 1:
        if g[idx] == 'F':
            g[idx] = 'D'
        else:
            g[idx] = g[idx]+'+'
    else:
        g[idx] = g[idx][0]
        g[idx] = chr(ord(g[idx])-1)
for i in range(len(id)):
    print(id[i], g[i])
