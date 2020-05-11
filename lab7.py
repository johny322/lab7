from scipy.integrate import odeint  
import numpy as np                   
import matplotlib.pyplot as plt
import math

def f(y, x):
    y1, y2, y3 = y
    return [y2, y1, math.sin(x) - 5.0*y3 + 4.0*y3 - 4.0*y1]

x = np.arange(0.0, 2.0, 0.1)    
y0 = [1.0, 0, 0]    
 
sol = odeint(f, y0, x)
#for i in range(len(sol)):
#    print (sol[i])

fig1 = plt.figure("y(x)")
ax1 = fig1.add_subplot()

fig2 = plt.figure("y'(x)")
ax2 = fig2.add_subplot()

fig3 = plt.figure("y'(y)")
ax3 = fig3.add_subplot()

data1 = np.loadtxt("y.txt")
ax1.plot(x, sol[:, 0], 'b--', label='y.py')
ax1.plot(data1[:,0], data1[:,1], 'b', label='y.cpp')
ax1.legend(loc='best')
ax1.grid()

data2 = np.loadtxt("p_y.txt")
ax2.plot(x, sol[:, 1], 'g--', label='p_y.py')
ax2.plot(data2[:,0], data2[:,1], 'g', label='p_y.cpp')


ax2.legend(loc='best')

ax2.grid()

data3 = np.loadtxt("y_and_p_y.txt")
ax3.plot(sol[:, 0], sol[:, 1], 'r--', label='y and p2_y.py')
ax3.plot(data3[:,0], data3[:,1], 'r', label='y and p2_y.cpp')
ax3.legend(loc='best')

ax3.grid()
plt.show()
