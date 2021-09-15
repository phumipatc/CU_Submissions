"""
	Task	: 08_Dict_11_Reverse_n_Keys
	Author	: Phumipat C. [MAGCARI]
	Language: Python
	Created	: 15 September 2021 [18:56]
	Algo	: 
	Status	: 
"""


def reverse(d):
    return {y: x for x, y in d.items()}


def keys(d, v):
    return [x for x, y in d.items() if y == v]


exec(input().strip())
