"""
    Task	: P2_05_Anagram2
    Author	: Phumipat C. [MAGCARI]
    Language: Python
    Created	: 15 September 2021 [23:41]
    Algo	: 
    Status	: 
"""
cnt = {}

a = input().strip()
for x in a.lower():
    if not x.isalpha():
        continue
    if x in cnt:
        cnt[x] += 1
    else:
        cnt[x] = 1

b = input().strip()
for x in b.lower():
    if not x.isalpha():
        continue
    if x in cnt:
        cnt[x] -= 1
    else:
        cnt[x] = -1

ans_a = {}
ans_b = {}
for x, y in cnt.items():
    if y == 0:
        continue
    if y > 0:
        ans_a[x] = abs(y)
    else:
        ans_b[x] = abs(y)

print(a)
if ans_a == {}:
    print('', '-', 'None')
for x, y in sorted(ans_a.items()):
    print('', '-', 'remove', y, x + ("'s" if y != 1 else ''))

print(b)
if ans_b == {}:
    print('', '-', 'None')
for x, y in sorted(ans_b.items()):
    print('', '-', 'remove', y, x + ("'s" if y != 1 else ''))
