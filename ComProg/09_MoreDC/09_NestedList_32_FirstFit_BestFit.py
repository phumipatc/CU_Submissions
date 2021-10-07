"""
    Task	: 09_MoreDC_32_FirstFit_BestFit
    Author	: Phumipat C. [MAGCARI]
    Language: Python
    Created	: 06 October 2021 [12:06]
    Algo	: 
    Status	: 
"""


def first_fit(L, e):
    ret = L
    for i in range(len(L)):
        if sum(L[i]) + e <= 100:
            ret[i].append(e)
            return ret
    ret.append([e])
    return ret


def best_fit(L, e):
    ret = L
    mx = idx = -1
    for i in range(len(L)):
        if sum(L[i]) + e > 100:
            continue
        if mx < sum(L[i]) + e:
            mx = sum(L[i]) + e
            idx = i
    if idx != -1:
        ret[idx].append(e)
    else:
        ret.append([e])
    return ret


def partition_FF(D):
    ret = []
    for x in D:
        ret = first_fit(ret, x)
    return ret


def partition_BF(D):
    ret = []
    for x in D:
        ret = best_fit(ret, x)
    return ret


exec(input().strip())
