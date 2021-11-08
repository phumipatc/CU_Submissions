"""
    Task	: P3_10_NumPy_function
    Author	: Phumipat C. [MAGCARI]
    Language: Python
    Created	: 08 November 2021 [14:32]
    Algo	: 
    Status	: 
"""
import numpy as np


def eq(A, B, p):
    return np.equal(A, B).sum() * 100 >= p * A.size


def closest_point_indexes(points, p):
    x = points[:, 0]
    y = points[:, 1]

    dist = (x-p[0])**2 + (y-p[1])**2
    num = np.arange(points.shape[0])

    return num[dist == dist.min()]


def number_of_inversions(A):
    cnt = 0
    for i in range(A.size):
        cnt += np.less(A[i:], A[i]).sum()
    return cnt


exec(input().strip())
