"""
	Task	: 02_StrList_07_Decryption
	Author	: Phumipat C. [MAGCARI]
	Language: Python
	Created	: 10 August 2021 [15:26]
	Algo	: 
	Status	: 
"""
n = input()
n = '0' + n

num = int(''.join([n[i] for i in range(4, 33, 7)])) + int(''.join([n[i] for i in range(8, 33, 5)]))+10000
ans1 = ''.join([str((num//1000) % 10), str((num//100) % 10), str((num//10) % 10)])

num = (sum([int(x) for x in ans1]) % 10) + 1
ans2 = chr(ord('A') + num - 1)
print(ans1+ans2)
