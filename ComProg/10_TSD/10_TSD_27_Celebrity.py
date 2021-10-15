"""
    Task	: 10_TSD_27_Celebrity
    Author	: Phumipat C. [MAGCARI]
    Language: Python
    Created	: 07 October 2021 [14:46]
    Algo	:
    Status	:
"""


def knows(R, x, y):
    # return True if x knows y
    return (y in R[x])


def is_celeb(R, x):  # return True if a is celeb, otherwise return False
 # return False if x knows someone who is not him/herself
 # return False if there exists someone in R who don't know x
 # otherwise return True
    return (len(R[x]) == (1 if knows(R, x, x) else 0) and len([y for y in R if x in R[y] and y != x]) == len(R) - 1)


def find_celeb(R):
 # for each person x in the party
 # if x is celeb --> return x
 # if no celeb in the party --> return None
    # print(R)
    for x in R:
        if is_celeb(R, x):
            return x
    return None


def read_relations():
 # build a dictionary R from inputs
 # whose structure is shown in the example
    R = dict()
    while True:
        d = input().split()
        if len(d) == 1:
            break
        if d[0] in R:
            R[d[0]].add(d[1])
        else:
            R[d[0]] = set()
            R[d[0]].add(d[1])
        if d[1] not in R:
            R[d[1]] = set()
    return R


def main():
    R = read_relations()
    c = find_celeb(R)
    if c == None:
        print('Not Found')
    else:
        print(c)


exec(input().strip())
