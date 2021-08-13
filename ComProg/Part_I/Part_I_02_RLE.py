"""
	Task	: Part_I_02_RLE
	Author	: Phumipat C. [MAGCARI]
	Language: Python
	Created	: 12 August 2021 [13:04]
	Algo	: 
	Status	: 
"""
cmd = input()
if cmd == 'str2RLE':
    a = input()
    n = len(a)
    a = a+' '

    idx = 0

    for i in range(n):
        if a[i] != a[i+1]:
            print(a[idx], i-idx+1, end=' ')
            idx = i+1
elif cmd == 'RLE2str':
    a = input().split()
    for i in range(0, len(a), 2):
        print(a[i]*int(a[i+1]), end='')
else:
    print('Error')
