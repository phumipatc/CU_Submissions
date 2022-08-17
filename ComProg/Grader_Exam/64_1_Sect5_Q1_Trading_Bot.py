"""
    Task	: 64_1_Sect5_Q1_Trading_Bot
    Author	: Phumipat C. [MAGCARI]
    Language: Python
    Created	: 23 November 2021 [10:02]
    Algo	: 
    Status	: Finished
"""
price = []

fast_ema = []
slow_ema = []


def alpha(period):
    return 2 / (period + 1)


weeks = int(input())
for i in range(weeks):
    weekprice = list(map(float, input().split(',')))
    for x in weekprice:
        price.append(x)

ans = False

for i in range(len(price)):
    if i == 6:
        fast_ema.append(sum(price[i-6:i+1])/7)
    elif i < 6:
        fast_ema.append(-1e9)
    else:
        fast_ema.append(price[i]*alpha(7)+fast_ema[i-1]*(1-alpha(7)))
    if i == 13:
        slow_ema.append(sum(price[i-13:i+1])/14)
    elif i < 13:
        slow_ema.append(-1e9)
    else:
        slow_ema.append(price[i]*alpha(14)+slow_ema[i-1]*(1-alpha(14)))
    if i < 14:
        continue
    if fast_ema[i] > slow_ema[i] and fast_ema[i-1] < slow_ema[i-1]:
        print('BUY at', '{:.2f}'.format(price[i]))
        ans = True
    elif fast_ema[i] < slow_ema[i] and fast_ema[i-1] > slow_ema[i-1]:
        print('SELL at', '{:.2f}'.format(price[i]))
        ans = True

if not ans:
    print('No results')
