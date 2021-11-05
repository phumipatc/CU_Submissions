"""
    Task	: 12_Class_34_Piggy_Bank_2
    Author	: Phumipat C. [MAGCARI]
    Language: Python
    Created	: 06 November 2021 [00:25]
    Algo	: 
    Status	: 
"""


class piggybank:
    def __init__(self):
        self.coins = dict()
        self.all = 0

    def add(self, v, n):
        v = float(v)
        if v in self.coins:
            if self.all + n > 100:
                return False
            self.coins[v] += n
            self.all += n
        else:
            if self.all + n > 100:
                return False
            self.coins[v] = n
            self.all += n
        return True

    def __float__(self):
        # return value * key
        return float(sum(v * self.coins[v] for v in self.coins))

    def __str__(self):
        return '{' + ', '.join(str(v) + ':' + str(self.coins[v]) for v in sorted(self.coins)) + '}'


cmd1 = input().split(';')
cmd2 = input().split(';')
p1 = piggybank()
p2 = piggybank()
for c in cmd1:
    eval(c)
for c in cmd2:
    eval(c)
