"""
	Task	: 01_Expr_01_Stirling_Factorial
	Author	: Phumipat C. [MAGCARI]
	Language: Python
	Created	: 10 August 2021 [14:50]
	Algo	: 
	Status	: 
"""
import math

n = int(input())

print(math.sqrt(2*math.pi)*(n**(n+1/2))*(math.e**(-n+1/(12*n+1))))
print(math.sqrt(2*math.pi)*(n**(n+1/2))*(math.e**(-n+1/(12*n))))
