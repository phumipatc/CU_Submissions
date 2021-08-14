"""
	Task	: 06_Function_11_Binary_Adder
	Author	: Phumipat C. [MAGCARI]
	Language: Python
	Created	: 14 August 2021 [11:52]
	Algo	: 
	Status	: 
"""
a, b = input().split()

print(bin(int(a, 2)+int(b, 2))[2:])
