"""
    Task	: P3_01_Gray
    Author	: Phumipat C. [MAGCARI]
    Language: Python
    Created	: 04 November 2021 [21:52]
    Algo	: 
    Status	: 
"""
n = int(input())
k = int(input())

# Check if n and k is valid
if (n < 1 or n > 15) and (k < 1 or k > 100):
    print("Invalid n and k")
    exit(0)
if n < 1 or n > 15:
    print("Invalid n")
    exit(0)
if k < 1 or k > 100:
    print("Invalid k")
    exit(0)

ans = ['0', '1']
for i in range(n-1):
    ans = ['0' + x for x in ans] + ['1' + x for x in ans[::-1]]

print(''.join([str(i) + '-'*(n + (1 if i != k else 0) - len(str(i))) for i in range(1, k+1)]))
for i in range(0, len(ans), k):
    print(','.join(ans[i:i+k]))
