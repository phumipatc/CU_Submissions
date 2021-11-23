"""
    Task	: P3_02_Giant_Checker
    Author	: Phumipat C. [MAGCARI]
    Language: Python
    Created	: 22 November 2021 [19:17]
    Algo	: 
    Status	: 
"""
a = input()
alphabet = []
for i in range(26):
    alphabet.append(chr(ord('a') + i))
for i in range(26):
    alphabet.append(chr(ord('A') + i))


if len(a) <= 3:
    a = a.strip()
    row = a[0]
    col = a[1:].strip()
else:
    a = a.split(',')
    if 'row' in a[0]:
        row = a[0][a[0].find('=')+1:].strip()
        col = a[1][a[1].find('=')+1:].strip()
    else:
        col = a[0][a[0].find('=')+1:].strip()
        row = a[1][a[1].find('=')+1:].strip()
    # print(row, col)


invalid_row = False
invalid_col = False

if not row.isalpha() or row not in alphabet:
    invalid_row = True
if not col.isdigit() or not 1 <= int(col) <= 52:
    invalid_col = True

if invalid_row and invalid_col:
    print("Invalid row and column")
elif invalid_row:
    print("Invalid row")
elif invalid_col:
    print("Invalid column")
else:
    print("Black" if int(col) % 2 == alphabet.index(row) % 2 else "White")
