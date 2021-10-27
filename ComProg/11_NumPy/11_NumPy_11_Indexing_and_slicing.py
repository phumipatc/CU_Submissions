"""
    Task	: 11_Numpy_11_Indexing_and_slicing
    Author	: Phumipat C. [MAGCARI]
    Language: Python
    Created	: 24 October 2021 [12:28]
    Algo	: 
    Status	: 
"""
import numpy as np
# A is a 2-d array


def get_column_from_bottom_to_top(A, c):
    return np.array([x[c] for x in reversed(A)])


def get_odd_rows(A):
    return np.array([val for idx, val in enumerate(A) if idx % 2])


def get_even_column_last_row(A):
    return np.array([val for idx, val in enumerate(A[-1]) if idx % 2 == 0])


def get_diagonal1(A):
    return np.array([A[i][i] for i in range(len(A))])


def get_diagonal2(A):
    return np.array([A[i][len(A)-i-1] for i in range(len(A))])


exec(input().strip())
