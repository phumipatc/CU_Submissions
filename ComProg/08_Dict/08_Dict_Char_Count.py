"""
    Task	: 08_Dict_Char_Count
    Author	: Phumipat C. [MAGCARI]
    Language: Python
    Created	: 15 September 2021 [19:03]
    Algo	:
    Status	:
"""
s = input().strip().lower()

cnt = {}
for x in s:
    if not x.isalpha():
        continue
    if x in cnt:
        cnt[x] += 1
    else:
        cnt[x] = 1

ans = sorted(cnt.items(), key=lambda x: (-x[1], x[0]))
for x in ans:
    print(x[0], '->', x[1])
