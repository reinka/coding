import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation
from mpl_toolkits.mplot3d import Axes3D
#Plotting graphs

#points = np.arange(-5, 5, .01)
#
#dx,dy = np.meshgrid(points,points)
#z = (np.sin(dx) + np.sin(dy))

#plt.plot(z)
#plt.title("Plot for sin(x)+sin(y)")
#plt.savefig("plot.png")
#plt.close()
#plt.imshow(z)
#plt.plot(z)
#plt.imshow(z)
#plt.title("Plot for sin(x)+sin(y)")
#plt.colorbar()
#plt.savefig("sin(x)*sin(y).png")
#plt.show()

#x = np.linspace(0, 10, 1000)
#x_sample = np.linspace(0, 10, 6)
#y1 = np.array(3*x**7)
#y2 = np.exp(x)
#plt.plot(x, y1, '-b', label = "3x^7")
##plt.plot(x, y2, '-r', label = "exp")
##plt.plot(x_sample, y1, ':k', label = "sampled")
#plt.legend()
#plt.xlim(0, 5)
#plt.ylim(-1.5, 2000)
#plt.title("My baby's wish <3")
#plt.savefig("sin.png")
#plt.close()

fig = plt.figure()
ax = plt.axes(projection='3d')

z = np.linspace(0, 1, 100)
x = z * np.sin(20 * z)
y = z * np.cos(20 * z)

c = x + y

ax.scatter(x, y, z, c=c)
plt.savefig("3d.png")
plt.close()
plt.show()