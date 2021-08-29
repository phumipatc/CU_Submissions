"""
    Task	: 07_StrFile_32_Password_Strength
    Author	: Phumipat C. [MAGCARI]
    Language: Python
    Created	: 27 August 2021 [22:25]
    Algo	:
    Status	:
"""


def no_lowercase(t: str):
    a = [x for x in t if x.islower()]
    return len(a) == 0


def no_uppercase(t: str):
    a = [x for x in t if x.isupper()]
    return len(a) == 0


def no_number(t: str):
    a = [x for x in t if x.isnumeric()]
    return len(a) == 0


def no_symbol(t: str):
    a = [x for x in t if not x.isalnum()]
    return len(a) == 0


def character_repetition(t: str):
    t = t.lower()
    for i in range(len(t)-4+1):
        # print(t[i], t[i+1], t[i+2], t[i+3])
        if t[i] == t[i+1] == t[i+2] == t[i+3]:
            return True
    return False


def check(t: str, a: str):
    t = t.lower()
    for i in range(len(a)-4+1):
        ret = t.find(a[i:i+4])
        if ret != -1:
            return True
    a = a[::-1]
    for i in range(len(a)-4+1):
        ret = t.find(a[i:i+4])
        if ret != -1:
            return True
    return False


def number_sequence(t: str):
    a = '01234567890'
    return check(t, a)


def letter_sequence(t: str):
    a = 'abcdefghijklmnopqrstuvwxyz'
    return check(t, a)


def keyboard_pattern(t: str):
    a = 'qwertyuiop'
    if check(t, a):
        return True

    a = 'asdfghjkl'
    if check(t, a):
        return True

    a = 'zxcvbnm'
    if check(t, a):
        return True

    a = '!@#$%^&*()_+'
    if check(t, a):
        return True

    return False


# -----------------------------
passw = input().strip()
errors = []
if len(passw) < 8:
    errors.append("Less than 8 characters")
if no_lowercase(passw):
    errors.append("No lowercase letters")
if no_uppercase(passw):
    errors.append("No uppercase letters")
if no_number(passw):
    errors.append("No numbers")
if no_symbol(passw):
    errors.append("No symbols")
if character_repetition(passw):
    errors.append("Character repetition")
if number_sequence(passw):
    errors.append("Number sequence")
if letter_sequence(passw):
    errors.append("Letter sequence")
if keyboard_pattern(passw):
    errors.append("Keyboard pattern")

if len(errors) == 0:
    print("OK")

for x in errors:
    print(x)
