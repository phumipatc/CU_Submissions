"""
    Task	: Lap10
    Author	: Phumipat C. [MAGCARI]
    Language: Python
    Created	: 08 November 2021 [09:26]
    Algo	: 
    Status	: 
"""
import numpy as np
import matplotlib.pyplot as plt

dist = 42 / 100
density_metal = 7800
density_solution = 1050

diameter = np.array([2.33, 3.2, 4.02, 4.83, 5.48, 6.44])
radius = diameter / 2000

time = np.array([24.35, 18.08, 13.11, 9.46, 7.14, 5.57])

velocity = dist / time
print("velocity:", velocity)

radius_2 = radius ** 2
print("radius_2:", radius_2)

plt.scatter(radius_2, velocity)

z = np.polyfit(radius_2, velocity, 1)
p = np.poly1d(z)
x_data = [0] + list(radius_2)
plt.plot(x_data, p(x_data), "r--")
plt.title("y=%.6fx + %.6f" % (z[0], z[1]))

plt.scatter([0], [0])

plt.show()
