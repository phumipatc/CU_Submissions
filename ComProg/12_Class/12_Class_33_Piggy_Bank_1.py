"""
    Task	: 12_Class_33_Piggy_Bank_1
    Author	: Phumipat C. [MAGCARI]
    Language: Python
    Created	: 06 November 2021 [00:22]
    Algo	: 
    Status	: 
"""


class piggybank:
    def __init__(self):
        self.ones = 0
        self.twos = 0
        self.fives = 0
        self.tens = 0

    def add1(self, n):
        self.ones += n

    def add2(self, n):
        self.twos += n

    def add5(self, n):
        self.fives += n

    def add10(self, n):
        self.tens += n

    def __int__(self):
        return self.ones + self.twos * 2 + self.fives * 5 + self.tens * 10

    def __lt__(self, rhs):
        return self.__int__() < rhs.__int__()

    def __str__(self):
        return '{' + '1:' + str(self.ones) + ', ' + '2:' + str(self.twos) + ', ' + '5:' + str(self.fives) + ', ' + '10:' + str(self.tens) + '}'


cmd1 = input().split(';')
cmd2 = input().split(';')
p1 = piggybank()
p2 = piggybank()
for c in cmd1:
    eval(c)
for c in cmd2:
    eval(c)
