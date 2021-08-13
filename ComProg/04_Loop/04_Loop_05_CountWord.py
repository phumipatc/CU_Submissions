"""
	Task	: 04_Loop_05_CountWord
	Author	: Phumipat C. [MAGCARI]
	Language: Python
	Created	: 12 August 2021 [11:21]
	Algo	: 
	Status	: 
"""
word = input()
sentence = input()

sp = ['"', '(', ')', ',', '.', "'"]
for x in sp:
    sentence = sentence.replace(x, ' ')

print(len([x for x in sentence.split() if x == word]))
