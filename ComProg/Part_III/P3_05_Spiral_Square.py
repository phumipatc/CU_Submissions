"""
    Task	: P3_05_Spiral_Square
    Author	: Phumipat C. [MAGCARI]
    Language: Python
    Created	: 22 November 2021 [17:28]
    Algo	: 
    Status	: 
"""


def spiral_square(n):
    S = [[0 for j in range(n)] for i in range(n)]

    x, y = n-1, n-1
    dir = [(0, -1), (-1, 0), (0, 1), (1, 0)]
    now_dir = 0

    for i in range(n**2, 0, -1):
        S[x][y] = i

        # check if can move
        if x+dir[now_dir][0] < 0 or x+dir[now_dir][0] >= n or y+dir[now_dir][1] < 0 or y+dir[now_dir][1] >= n or S[x+dir[now_dir][0]][y+dir[now_dir][1]] != 0:
            now_dir = (now_dir+1) % 4

        x += dir[now_dir][0]
        y += dir[now_dir][1]

    return S


def print_square(S):
    for i in range(len(S)):
        print(' '.join([(2*' '+str(e))[-3:] for e in S[i]]))


exec(input().strip())
