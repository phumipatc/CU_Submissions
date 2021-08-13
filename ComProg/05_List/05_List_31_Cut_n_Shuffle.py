"""
	Task	: 05_List_31_Cut_n_Shuffle
	Author	: Phumipat C. [MAGCARI]
	Language: Python
	Created	: 11 August 2021 [15:26]
	Algo	:
	Status	:
"""
card = [x for x in input().split()]
cmd = input()
for x in cmd:
    if x == 'C':
        card[:len(card)//2], card[len(card)//2:] = card[len(card)//2:], card[:len(card)//2]
    elif x == 'S':
        l = card[:len(card)//2]
        r = card[len(card)//2:]
        for idx in range(0, len(card)//2):
            card[2*(idx)] = l[idx]
            card[2*(idx)+1] = r[idx]
for x in card:
    print(x, end=' ')
