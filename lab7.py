from scipy.integrate import odeint
import numpy as np
import matplotlib.pyplot as plt
import math

def f(z, x):
    z1, z2, z3 = z
    return [z2, z3, math.sin(x) + 5.0*z3 - 4.0*z2 + 4.0*z1]

x = np.linspace(0.0, 2.0, 21)
y0 = [1.0, 0.0, 0.0]

sol = odeint(f, y0, x)
for i in range(len(sol)):
    print (x[i], sol[i])

fig1 = plt.figure("y(x) and y'(x)")
ax1 = fig1.add_subplot()

fig2 = plt.figure("y'(y)")
ax2 = fig2.add_subplot()

fig3 = plt.figure()
ax3 = fig3.add_subplot()

data1 = np.loadtxt("y.txt")
ax1.plot(x, sol[:, 0], 'b--', label='y.py')
ax1.plot(data1[:,0], data1[:,1], 'b', label='y.cpp')
data2 = np.loadtxt("d_y.txt")
ax1.plot(x, sol[:, 1], 'g--', label='d_y.py')
ax1.plot(data2[:,0], data2[:,1], 'g', label='d_y.cpp')
ax1.legend(loc='best')
ax1.grid()
fig1.savefig("g1.png")


data3 = np.loadtxt("d2_y.txt")
ax2.plot(sol[:, 0], sol[:, 1], 'r--', label='y and d2_y.py')
ax2.plot(data3[:,0], data3[:,1], 'r', label='y and d2_y.cpp')
ax2.legend(loc='best')
ax2.grid()
fig2.savefig("g2.png")


ax3.plot(x, data1[:,1]-sol[:, 0], 'r', label = 'y')
ax3.plot(x, data2[:,1]-sol[:, 1], 'r--', label = 'd_y')
ax3.legend(loc='best')
ax3.grid()
fig3.savefig("g3.png")
plt.show()
