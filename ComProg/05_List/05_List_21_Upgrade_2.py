"""
	Task	: 05_List_21_Upgrade_2
	Author	: Phumipat C. [MAGCARI]
	Language: Python
	Created	: 14 August 2021 [00:33]
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
a = [[id[i], g[i]] for i in range(len(id))]
for x in sorted(a):
    print(x[0], x[1])
