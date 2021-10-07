"""
    Task	: 09_MoreDC_25_Tiling_Puzzle
    Author	: Phumipat C. [MAGCARI]
    Language: Python
    Created	: 06 October 2021 [11:49]
    Algo	: 
    Status	: 
"""


def row_number(t, e):  # return row number of t containing e (top row is row #0)
    for i in range(len(t)):
        if e in t[i]:
            return i


def flatten(t):  # return a list of ints converted from list of lists of ints t
    ret = []
    for i in t:
        for j in i:
            if j != 0:
                ret.append(j)
    return ret


def inversions(x):  # return the number of inversions of list x
    cnt = 0
    for i in range(len(x)):
        for j in range(i+1, len(x)):
            if x[i] > x[j]:
                cnt += 1
    return cnt


def solvable(t):
    # return True if tiling t (list of lists of ints) is solvable
    # otherwise return False
    idx = row_number(t, 0)
    cnt = inversions(flatten(t))
    n = len(t)
    if n % 2 == 1 and cnt % 2 == 0:
        return True
    if n % 2 == 0 and cnt % 2 != idx % 2:
        return True
    return False


exec(input().strip())  # do not remove this lin
