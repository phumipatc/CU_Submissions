"""
    Task	: 10_TSD_38_Sky_Train
    Author	: Phumipat C. [MAGCARI]
    Language: Python
    Created	: 15 October 2021 [16:59]
    Algo	: 
    Status	: 
"""
name = input().split()
g = {}
while len(name) == 2:
    u, v = name
    if u in g:
        g[u].append(v)
    else:
        g[u] = [v]
    if v in g:
        g[v].append(u)
    else:
        g[v] = [u]

    name = input().split()

mark = {}
queue = []
queue.append([name[0], 0])

ans = set()

while queue:
    now = queue.pop(0)
    # print(now)
    if now[1] > 2:
        break
    ans.add(now[0])
    mark[now[0]] = True
    for x in (g[now[0]] if now[0] in g else []):
        if x not in mark:
            queue.append([x, now[1]+1])
print('\n'.join(sorted(ans)))
