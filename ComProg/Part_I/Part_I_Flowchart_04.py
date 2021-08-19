"""
    Task	: Part_I_Flowchart_04
    Author	: Phumipat C. [MAGCARI]
    Language: Python
    Created	: 19 August 2021 [21:43]
    Algo	:
    Status	:
"""
x1 = input().strip()
x2 = input().strip()
x3 = input().strip()

x = x1+x2+x3

if not len(x) == 9:
    print('ERROR')
else:
    win = '-'
    i = 0
    while i < 3:
        if x[3*i] == x[3*i+1] == x[3*i+2]:
            win = x[3*i]
            break
        elif x[i] == x[i+3] == x[i+6]:
            win = x[i]
            break
        i += 1
    if win == '-':
        if x[0] == x[4] == x[8]:
            win = x[0]
        if x[3] == x[4] == x[6]:
            win = x[6]
    if win == '-':
        print('???')
    else:
        print(win)
