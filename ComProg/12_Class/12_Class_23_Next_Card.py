"""
    Task	: 12_Class_23_Next_Card
    Author	: Phumipat C. [MAGCARI]
    Language: Python
    Created	: 06 November 2021 [00:04]
    Algo	:
    Status	:
"""


class Card:
    def __init__(self, value, suit):
        self.value = value
        self.suit = suit

    def __str__(self):
        return '(' + self.value + ' ' + self.suit + ')'

    def next1(self):
        order = ['3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K', 'A', '2']
        suits = ['club', 'diamond', 'heart', 'spade']
        idx_order = order.index(self.value)
        idx_suit = suits.index(self.suit) + 1
        if idx_suit > 3:
            idx_suit = 0
            idx_order += 1
            if idx_order > 12:
                idx_order = 0
        return Card(order[idx_order], suits[idx_suit])

    def next2(self):
        ret = self.next1()
        self.value, self.suit = ret.value, ret.suit


n = int(input())
cards = []
for i in range(n):
    value, suit = input().split()
    cards.append(Card(value, suit))
for i in range(n):
    print(cards[i].next1())
print("----------")
for i in range(n):
    print(cards[i])
print("----------")
for i in range(n):
    cards[i].next2()
    cards[i].next2()
    print(cards[i])
