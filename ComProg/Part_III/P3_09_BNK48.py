"""
    Task	: P3_09_BNK48
    Author	: Phumipat C. [MAGCARI]
    Language: Python
    Created	: 22 November 2021 [18:15]
    Algo	: 
    Status	: 
"""
like = dict()
total_point = dict()
number_people = dict()
number_kami = dict()

inp = input().split()
while len(inp) != 1:
    name, idol, point = inp
    point = int(point)

    if name not in like:
        like[name] = dict()
    if idol not in like[name]:
        like[name][idol] = point
    else:
        like[name][idol] += point

    if idol not in total_point:
        total_point[idol] = point
    else:
        total_point[idol] += point
    if idol not in number_kami:
        number_kami[idol] = 0
    inp = input().split()

for x in like.items():
    for y in x[1].items():
        if y[0] not in number_people:
            number_people[y[0]] = 1
        else:
            number_people[y[0]] += 1
    kami = sorted(x[1].items(), key=lambda x: (-x[1], x[0]))[0][0]
    number_kami[kami] += 1

if inp[0] == '1':
    ans = sorted(total_point.items(), key=lambda x: (-x[1], x[0]))[:3]
    print(', '.join(x[0] for x in ans))
elif inp[0] == '2':
    ans = sorted(number_people.items(), key=lambda x: (-x[1], x[0]))[:3]
    print(', '.join(x[0] for x in ans))
elif inp[0] == '3':
    ans = sorted(number_kami.items(), key=lambda x: (-x[1], x[0]))[:3]
    print(', '.join(x[0] for x in ans))
