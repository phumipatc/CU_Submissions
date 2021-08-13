"""
	Task	: 01_Expr_02_Quadratic_Root
	Author	: Phumipat C. [MAGCARI]
	Language: Python
	Created	: 10 August 2021 [14:47]
	Algo	: 
	Status	: 
"""
import math
a = float(input())
b = float(input())
c = float(input())

print(round((-b-math.sqrt(b**2-4*a*c))/(2*a), 3), round((-b+math.sqrt(b**2-4*a*c))/(2*a), 3))
