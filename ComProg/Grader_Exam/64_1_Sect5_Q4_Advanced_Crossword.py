"""
    Task	: 64_1_Sect5_Q4_Advanced_Crossword
    Author	: Phumipat C. [MAGCARI]
    Language: Python
    Created	: 23 November 2021 [09:49]
    Algo	: 
    Status	: Finished
"""
dir = [(-1, 0), (0, -1), (1, 0), (0, 1)]
ans = []


def dfs(x, y, cnt):
    # print('processing:', x, y, cnt)
    global ans
    ans.append((x, y))
    mark[x][y] = True
    if cnt == len(target)-1:
        print(ans)
        exit(0)
    for dx, dy in dir:
        nx, ny = x + dx, y + dy
        # print(table[nx][ny] == target[cnt+1])
        if 0 <= nx < n and 0 <= ny < m and table[nx][ny] == target[cnt+1] and not mark[nx][ny]:
            dfs(nx, ny, cnt + 1)
    ans.pop()
    mark[x][y] = False


table = []

n, m = map(int, input().split())
mark = [[False for j in range(m)] for i in range(n)]
# print(mark)
for i in range(n):
    inp = input().strip()
    table.append(inp)
target = input().strip()

for i in range(n):
    for j in range(m):
        if table[i][j] == target[0]:
            dfs(i, j, 0)
