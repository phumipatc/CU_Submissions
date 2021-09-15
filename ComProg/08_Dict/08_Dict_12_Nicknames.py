"""
    Task	: 08_Dict_12_Nicknames
    Author	: Phumipat C. [MAGCARI]
    Language: Python
    Created	: 15 September 2021 [18:59]
    Algo	:
    Status	:
"""
n = int(input())
full = {}
nick = {}
for i in range(n):
    a, b = [x for x in input().split()]
    full[a] = b
    nick[b] = a

m = int(input())
for i in range(m):
    name = input().strip()
    if name in full:
        print(full[name])
    elif name in nick:
        print(nick[name])
    else:
        print('Not found')
