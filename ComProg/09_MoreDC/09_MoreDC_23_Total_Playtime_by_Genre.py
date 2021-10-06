"""
    Task	: 09_MoreDC_23_Total_Playtime_by_Genre
    Author	: Phumipat C. [MAGCARI]
    Language: Python
    Created	: 06 October 2021 [15:32]
    Algo	: 
    Status	: 
"""


def cal(t):
    min, sec = t.split(':')
    return int(min)*60 + int(sec)


def rev(t):
    return str(t // 60) + ':' + ('0' if t % 60 < 10 else '') + str(t % 60)


n = int(input())
d = dict()
for i in range(n):
    name, singer, genre, time = input().split(', ')
    if genre in d:
        d[genre] += cal(time)
    else:
        d[genre] = cal(time)
ans = sorted(d.items(), key=lambda x: (-x[1]))
for x in ans[:3]:
    print(x[0], '-->', rev(x[1]))
