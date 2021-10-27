"""
    Task	: 11_NumPy_13_Logistic_Regression
    Author	: Phumipat C. [MAGCARI]
    Language: Python
    Created	: 24 October 2021 [12:50]
    Algo	: 
    Status	: 
"""
import numpy as np


def p(X: np.array):
    logitx = -3.98 + X[:, 0]*0.1 + X[:, 1]*0.5
    return 1/(1+np.e**(-logitx))


exec(input().strip())
