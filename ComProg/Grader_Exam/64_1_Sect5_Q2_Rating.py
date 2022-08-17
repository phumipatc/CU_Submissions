"""
    Task	: 64_1_Sect5_Q2_Rating
    Author	: Phumipat C. [MAGCARI]
    Language: Python
    Created	: 23 November 2021 [09:20]
    Algo	:
    Status	: Finished
"""


def cal_rating(lv, score):
    return int(25*(lv+1)*score//1e7)


played = dict()

n = int(input())
for _ in range(n):
    inp = input().split(' | ')
    if inp[0] == 'Play':
        name, lv, score = inp[1:]
        lv = int(lv)
        score = int(score)
        rating = cal_rating(lv, score)
        if name not in played:
            played[name] = (rating, lv, score)
        elif played[name][0] < rating:
            played[name] = (rating, lv, score)
        elif played[name][0] == rating and played[name][1] < int(lv):
            played[name] = (rating, lv, score)
        elif played[name][0] == rating and played[name][1] == int(lv) and played[name][2] < int(score):
            played[name] = (rating, lv, score)
    elif inp[0] == 'Rating' and len(inp) == 2:
        name = inp[1]
        if name in played:
            print(played[name][0])
        else:
            print('0')
    elif inp[0] == 'Rating':
        # overall rating
        all = sorted(played.values(), key=lambda x: (-x[0]))
        print(sum([i[0] for i in all[:5]]))
    elif inp[0] == 'Detail':
        name = inp[1]
        if name not in played:
            print(name + ': No play history')
        else:
            print(' | '.join([name, str(played[name][1]), str(played[name][2]), str(played[name][0])]))
