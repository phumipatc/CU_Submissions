"""
	Task	: 04_Loop_04_Parenthesis
	Author	: Phumipat C. [MAGCARI]
	Language: Python
	Created	: 12 August 2021 [11:17]
	Algo	: 
	Status	: 
"""
a = input()
b = ''
for x in a:
    if x == '(':
        b = b+'['
    elif x == '[':
        b = b+'('
    elif x == ')':
        b = b+']'
    elif x == ']':
        b = b+')'
    else:
        b = b+x
print(b)
