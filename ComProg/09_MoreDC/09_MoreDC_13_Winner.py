"""
    Task	: 09_MoreDC_13_Winner
    Author	: Phumipat C. [MAGCARI]
    Language: Python
    Created	: 06 October 2021 [15:14]
    Algo	: 
    Status	: 
"""
n = int(input())

mark = dict()
for i in range(n):
    winner, loser = input().split()
    if winner in mark and mark[winner] != 0:
        mark[winner] = 1
    if winner not in mark:
        mark[winner] = 1
    mark[loser] = 0

ans = []
for x in mark.items():
    if x[1] == 0:
        continue
    ans.append(x[0])
print(sorted(ans))
