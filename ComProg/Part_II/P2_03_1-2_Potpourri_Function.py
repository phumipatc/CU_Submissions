"""
    Task	: 2_Potpourri_Function
    Author	: Phumipat C. [MAGCARI]
    Language: Python
    Created	: 15 September 2021 [23:20]
    Algo	:
    Status	:
"""


def convex_polygon_area(p):
    p += [p[0]]
    return abs(sum(p[i][0]*p[i+1][1] - p[i][1]*p[i+1][0] for i in range(len(p)-1))/2)


def is_heterogram(s):
    s = sorted([x.lower() for x in s if x.isalpha()])
    return [i for i in range(len(s)-1) if s[i] == s[i+1]] == []


def replace_ignorecase(s, a, b):
    ret = ''
    i = 0
    while i < len(s):
        if s[i:i+len(a)].lower() == a.lower():
            ret += b
            i += len(a)
        else:
            ret += s[i]
            i += 1
    return ret


def top3(votes):
    return [x[0] for x in sorted(votes.items(), key=lambda x:(-x[1], x[0]))][0:3]


for k in range(2):
    exec(input().strip())
