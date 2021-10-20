import numpy as np
import matplotlib.pyplot as plt
import os
import math

os.system('cls')
print('Section 1')
X0 = float(input('x0: '))
F = [float(x) for x in input('F: ').split()]
DeltaX = [float(x)-X0 for x in input('X: ').split()]

# plt.scatter(DeltaX, F)

# z = np.polyfit(DeltaX, F, 1)
# p = np.poly1d(z)
# x_data = [0] + DeltaX
# plt.plot(x_data, p(x_data), "r--")
# plt.title("y=%.6fx + %.6f" % (z[0], z[1]))

# plt.scatter(0, 0)

# plt.show()

# exit()
os.system('cls')
print('Section 2')
Period = [float(x)/10 for x in input('Time: ').split()]
DeltaX = [float(x)-X0 for x in input('X: ').split()]
m = float(input('Slope from section 1: '))
c = float(input('y-intercept from section 1: '))

Omega = [round(2*math.pi/x, 3) for x in Period]
print(Omega)
Omega2 = [round(x**2, 3) for x in Omega]
print(Omega2)
F = [round(m*x+c, 3) for x in DeltaX]
print(F)

plt.scatter(Omega2, F)

z = np.polyfit(Omega2, F, 1)
p = np.poly1d(z)
x_data = [0] + Omega2
plt.plot(x_data, p(x_data), "r--")
plt.title("y=%.6fx + %.6f" % (z[0], z[1]))

plt.scatter(0, 0)

plt.show()
