import matplotlib.pyplot as plt
import numpy as np

l = [float(x) for x in input('Input Length: ').split()]
t = [float(x) for x in input('Input Time: ').split()]

T = [x / 10 for x in t]
T2 = [x**2 for x in T]

print("Period")
print('\n'.join([str(x) for x in T]))

print("Quadratic Period")
print('\n'.join([str(x) for x in T2]))

plt.plot(l, T2, 'o')

z = np.polyfit(l, T2, 1)
p = np.poly1d(z)
plt.plot(l, p(l), "r--")

plt.xlabel('Length')
plt.ylabel('Quadratic Period')
# plt.axis([0, 100, 0, 4])

plt.show()

print()
print("x")
print('\n'.join([str(x) for x in l]))

print("y")
print('\n'.join([str(x) for x in T2]))

print("Quadratic x")
print('\n'.join([str(x**2) for x in l]))

print("xy")
print('\n'.join([str(l[i] * T2[i]) for i in range(len(l))]))
