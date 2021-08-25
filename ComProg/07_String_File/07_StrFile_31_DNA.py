"""
	Task	: 07_StrFile_31_DNA
	Author	: Phumipat C. [MAGCARI]
	Language: Python
	Created	: 21 August 2021 [23:33]
	Algo	:
	Status	:
"""
DNA = input().strip().upper()
cmd = input().strip()

if DNA.strip('ATCG') != '':
    print('Invalid DNA')
    exit(0)

if cmd == 'R':
    for x in DNA[::-1]:
        if x == 'A':
            print('T', end='')
        elif x == 'T':
            print('A', end='')
        elif x == 'C':
            print('G', end='')
        elif x == 'G':
            print('C', end='')
elif cmd == 'F':
    print('A=%d, T=%d, G=%d, C=%d' % (DNA.count('A'), DNA.count('T'), DNA.count('G'), DNA.count('C')))
else:
    target = input().strip()
    cnt = 0
    for i in range(len(DNA)-len(target)+1):
        if DNA[i:i+len(target)] == target:
            cnt += 1
    print(cnt)
