"""
    Task	: 08_Dict_31_Cash
    Author	: Phumipat C. [MAGCARI]
    Language: Python
    Created	: 15 September 2021 [16:03]
    Algo	:
    Status	:
"""


def total(pocket):
    return sum([x*pocket[x] for x in pocket])


def take(pocket, money_in):
    for x in money_in:
        if x in pocket:
            pocket[x] += money_in[x]
        else:
            pocket[x] = money_in[x]


def pay(pocket, amt):
    ret = {}
    for x in pocket:
        if amt >= x:
            ret[x] = min(amt//x, pocket[x])
            amt -= min(amt//x, pocket[x]) * x
            # print(amt)
    if amt != 0:
        return {}
    for x in ret:
        pocket[x] -= ret[x]
    return ret


exec(input().strip())
