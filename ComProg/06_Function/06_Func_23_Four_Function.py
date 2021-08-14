"""
	Task	: 06_Func_23_Four_Function
	Author	: Phumipat C. [MAGCARI]
	Language: Python
	Created	: 14 August 2021 [12:21]
	Algo	: 
	Status	: 
"""


def make_int_list(x):
    return [int(y) for y in x.split()]


def is_odd(e):
    return True if e % 2 == 1 else False


def odd_list(alist):
    return [x for x in alist if is_odd(x)]


def sum_square(alist):
    return sum([x*x for x in alist])


exec(input().strip())
