from scipy.integrate import odeint  
import numpy as np                   
import matplotlib.pyplot as plt
import math

def f(y, x):
    y1, y2, y3 = y
    return [y2, y1, math.sin(x) - 5.0*y3 + 4.0*y3 - 4.0*y1]

x = np.arange(0.0, 2.0, 0.1)    # Массив точек интегрирования.
y0 = [1.0, 0, 0]    # Список начальных значений ( y'(0) = 1, y(0) = 1 ).
 
sol = odeint(f, y0, x)
#for i in range(len(sol)):
#    print (sol[i])    # Решение в точке x[0] = 0

fig1 = plt.figure()
ax1 = fig1.add_subplot()

fig2 = plt.figure()
ax2 = fig2.add_subplot()



ax1.plot(x, sol[:, 0], 'b', label='y')
ax1.plot(x, sol[:, 1], 'g', label='p_y')


ax1.legend(loc='best')

ax1.grid()
                 # Отобразить.

ax2.plot(sol[:, 0], sol[:, 1], 'r', label='y and p2_y')
ax2.legend(loc='best')

ax2.grid()
plt.show()
