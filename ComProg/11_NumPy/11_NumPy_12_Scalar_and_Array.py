"""
    Task	: 11_NumPy_12_Scalar_and_Array
    Author	: Phumipat C. [MAGCARI]
    Language: Python
    Created	: 24 October 2021 [12:44]
    Algo	: 
    Status	: 
"""
import numpy as np


def toCelsius(f):
    return np.array([(x-32)*5/9 for x in f])


def BMI(wh):
    return np.array([weight / (height/100)**2 for weight, height in wh])


def distanceTo(p, Points):
    return np.array([np.sqrt((p[0]-x[0])**2 + (p[1]-x[1])**2) for x in Points])


exec(input().strip())
