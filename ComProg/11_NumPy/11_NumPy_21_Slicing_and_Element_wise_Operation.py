"""
    Task	: 11_NumPy_21_Slicing_and_Element_wise_Operation
    Author	: Phumipat C. [MAGCARI]
    Language: Python
    Created	: 04 November 2021 [21:40]
    Algo	: 
    Status	: 
"""
import numpy as np


def sum_2_rows(M):
    return M[::2, :] + M[1::2, :]


def sum_left_right(M):
    return M[:, :len(M[0])//2] + M[:, len(M[0])//2:]


def sum_upper_lower(M):
    return M[:len(M)//2, :] + M[len(M)//2:, :]


def sum_4_quadrants(M):
    return M[:len(M)//2, :len(M[0])//2] + M[:len(M)//2, len(M[0])//2:] + M[len(M)//2:, :len(M[0])//2] + M[len(M)//2:, len(M[0])//2:]


def sum_4_cells(M):
    return M[::2, ::2] + M[1::2, ::2] + M[::2, 1::2] + M[1::2, 1::2]


def count_leap_years(years):
    # years contains array of years
    # return number of leap years in years
    years = years - 543
    return np.sum(np.logical_and(years % 4 == 0, years % 100 != 0) | (years % 400 == 0))


exec(input().strip())
