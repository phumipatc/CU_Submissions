"""
    Task	: 10_TSD_33_Polynomial
    Author	: Phumipat C. [MAGCARI]
    Language: Python
    Created	: 07 October 2021 [15:13]
    Algo	: 
    Status	: 
"""


def add_poly(p1, p2):
    d = dict()
    for x, y in p1:
        d[y] = x
    for x, y in p2:
        if y in d:
            d[y] += x
        else:
            d[y] = x
    d = sorted(d.items(), key=lambda x: (-x[0]))
    return [(x, y) for y, x in d if x != 0]


def mult_poly(p1, p2):
    d = dict()
    for w, x in p1:
        for y, z in p2:
            if x+z in d:
                d[x+z] += w*y
            else:
                d[x+z] = w*y
    d = sorted(d.items(), key=lambda x: (-x[0]))
    return [(x, y) for y, x in d if x != 0]


for i in range(3):
    exec(input().strip())
