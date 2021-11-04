"""
    Task	: 11_NumPy_22_Outer_Product
    Author	: Phumipat C. [MAGCARI]
    Language: Python
    Created	: 04 November 2021 [18:01]
    Algo	: 
    Status	: 
"""
import numpy as np


def mult_table(nrows, ncols):
    return np.outer(np.arange(1, nrows+1), np.arange(1, ncols+1))


exec(input().strip())
