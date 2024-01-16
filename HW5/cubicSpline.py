from scipy.interpolate import CubicSpline
import numpy as np
import matplotlib.pyplot as plt


plt.plot()
print('please click twice on the plot')
clicks = []
for i in range(8):
    clicks.append(plt.ginput())
'''
print('your clicks were at locations:')
print(clicks)
print(clicks[0][0][0])
'''
x = []
y = []

for i in range(len(clicks)):
    x.append(clicks[i][0][0])
    y.append(clicks[i][0][1])

if np.any(np.diff(x) < 0):
    indexes = np.argsort(x).astype(int)
    x = np.array(x)[indexes]
    y = np.array(y)[indexes]

f = CubicSpline(x, y, bc_type='natural')
x_new = np.linspace(min(x), max(x), 100)
y_new = f(x_new)

plt.plot(x_new, y_new)
plt.scatter(x, y)
plt.title('Cubic Spline Interpolation')
plt.show()
