"""
    Task	: 09_MoreDC_24_Cartoons
    Author	: Phumipat C. [MAGCARI]
    Language: Python
    Created	: 06 October 2021 [15:42]
    Algo	: 
    Status	: 
"""
a = input().strip()
anim = dict()
cnt = 1
while a != 'q':
    name, t = a.split(', ')
    if t in anim:
        anim[t].append(name)
    else:
        anim[t] = [cnt, name]
        cnt += 1
    a = input().strip()

ans = sorted(anim.items(), key=lambda x: (x[1][0]))
for x in ans:
    print(x[0]+':', ', '.join(x[1][1:]))
