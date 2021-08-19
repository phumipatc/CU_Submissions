"""
    Task	: 06_Func_31_Refractor
    Author	: Phumipat C. [MAGCARI]
    Language: Python
    Created	: 19 August 2021 [20:52]
    Algo	:
    Status	:
"""

mname = ["Jan", "Feb", "Mar", "Apr",
         "May", "Jun", "Jul", "Aug",
         "Sep", "Oct", "Nov", "Dec"]


def read_date():
    ret = [x for x in input().split()]
    ret[1] = mname.index(ret[1])+1
    return [int(x) for x in ret]


def zodiac(d, m):
    if d >= 22 and m == 3 or d <= 21 and m == 4:
        z1 = "Aries"
    elif d >= 22 and m == 4 or d <= 21 and m == 5:
        z1 = "Taurus"
    elif d >= 22 and m == 5 or d <= 21 and m == 6:
        z1 = "Gemini"
    elif d >= 22 and m == 6 or d <= 21 and m == 7:
        z1 = "Cancer"
    elif d >= 22 and m == 7 or d <= 21 and m == 8:
        z1 = "Leo"
    elif d >= 22 and m == 8 or d <= 21 and m == 9:
        z1 = "Virgo"
    elif d >= 22 and m == 9 or d <= 21 and m == 10:
        z1 = "Libra"
    elif d >= 22 and m == 10 or d <= 21 and m == 11:
        z1 = "Scorpio"
    elif d >= 22 and m == 11 or d <= 21 and m == 12:
        z1 = "Sagittarius"
    elif d >= 22 and m == 12 or d <= 20 and m == 1:
        z1 = "Capricorn"
    elif d >= 21 and m == 1 or d <= 20 and m == 2:
        z1 = "Aquarius"
    elif d >= 21 and m == 2 or d <= 21 and m == 3:
        z1 = "Pisces"
    return z1


def days_in_feb(y):
    if y % 400 == 0 or (y % 4 == 0 and y % 100 != 0):
        return 29
    return 28


month31 = [1, 3, 5, 7, 8, 10, 12]


def days_in_month(m, y):
    if m == 2:
        return days_in_feb(y)
    if m in month31:
        return 31
    return 30


def days_in_between(d1, m1, y1, d2, m2, y2):
    ret = d2 + days_in_month(m1, y1) - d1 + int((y2-y1-1)*365.25)
    ret += sum([days_in_month(m, y1) for m in range(m1+1, 13)])
    ret += sum([days_in_month(m, y2) for m in range(1, m2)])
    return ret


def main():
    d1, m1, y1 = read_date()
    d2, m2, y2 = read_date()
    print(zodiac(d1, m1), zodiac(d2, m2))
    print(days_in_between(d1, m1, y1, d2, m2, y2))


exec(input().strip())
