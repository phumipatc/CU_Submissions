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
    return A[::-1, c]


def get_odd_rows(A):
    return A[1::2]


def get_even_column_last_row(A):
    return A[-1, ::2]


def get_diagonal1(A):
    return A.diagonal()


def get_diagonal2(A):
    return np.fliplr(A).diagonal()


exec(input().strip())
