"""
    Task	: 11_NumPy_23_Lower_Than_Mean
    Author	: Phumipat C. [MAGCARI]
    Language: Python
    Created	: 04 November 2021 [18:18]
    Algo	: 
    Status	: 
"""
import numpy as np
from numpy.core.fromnumeric import mean


def read_data():
    w = [float(e) for e in input().split()]
    weight = np.array(w)
    n = int(input())
    data = np.ndarray((n, 4), int)
    for i in range(n):
        data[i] = [int(e) for e in input().split()]
    return weight, data


def report_lower_than_mean(weight, data):
    sum = np.sum(weight * data[:, 1:], axis=1)
    ret = data[sum < np.mean(sum)][:, 0]
    if ret.size == 0:
        print("None")
    else:
        print(', '.join(map(str, ret)))


exec(input().strip())
