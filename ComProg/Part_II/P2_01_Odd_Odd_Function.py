"""
    Task	: P2_01_Odd_Odd_Function
    Author	: Phumipat C. [MAGCARI]
    Language: Python
    Created	: 15 September 2021 [22:45]
    Algo	: 
    Status	: 
"""


def is_odd(n):
    return n % 2 == 1


def has_odds(x):
    return get_odds(x) != []


def all_odds(x):
    return get_odds(x) == x


def no_odds(x):
    return not has_odds(x)


def get_odds(x):
    return [a for a in x if a % 2 == 1]


def zip_odds(a, b):
    a = [x for x in a if x % 2 == 1]
    b = [x for x in b if x % 2 == 1]
    ret = []
    i = j = 0
    while i < len(a) and j < len(b):
        ret += [a[i], b[j]]
        i += 1
        j += 1
    while i < len(a):
        ret += [a[i]]
        i += 1
    while j < len(b):
        ret += [b[j]]
        j += 1
    return ret


exec(input().strip())
