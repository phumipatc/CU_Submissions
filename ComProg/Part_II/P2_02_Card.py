"""
    Task	: P2_02_Card
    Author	: Phumipat C. [MAGCARI]
    Language: Python
    Created	: 15 September 2021 [22:55]
    Algo	: 
    Status	: 
"""
types = {
    'C': 1,
    'D': 2,
    'H': 3,
    'S': 4
}
val = {
    'A': 1,
    '2': 2,
    '3': 3,
    '4': 4,
    '5': 5,
    '6': 6,
    '7': 7,
    '8': 8,
    '9': 9,
    'T': 10,
    'J': 11,
    'Q': 12,
    'K': 13
}


def cal(a, b):
    if a[0] == b[0]:
        return types[a[1]]-types[b[1]]
    else:
        return val[a[0]]-val[b[0]]


card = input().strip()
card = [card[i:i+2] for i in range(0, len(card), 2)]
ans = ['%+d' % (cal(card[i], card[i+1])) if cal(card[i], card[i+1]) != 0 else '0' for i in range(len(card)-1)]
print(''.join(ans))
