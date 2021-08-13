"""
	Task	: 01_Expr_04_Body_Surface_Area
	Author	: Phumipat C. [MAGCARI]
	Language: Python
	Created	: 10 August 2021 [14:39]
	Algo	: 
	Status	: 
"""
import math
w = float(input())
h = float(input())

print(math.sqrt(w*h)/60)
print(0.024265*(w**0.5378)*(h**0.3964))
print(0.0333*(w**(0.6157-0.0188*math.log10(w)))*(h**0.3))
