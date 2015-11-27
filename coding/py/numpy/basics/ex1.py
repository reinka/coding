import numpy as np
from numpy.random import randn
import matplotlib.pyplot as plt
import matplotlib.animation as animation

#Plotting graphs

#x = np.array(11)
#print x
#print np.shape(x), x.ndim, x.dtype, type(x)
#
#A = np.array([1,1,2,3,5,8,13,21])
#
#B = np.array([	[[111,112], [121, 122]],
#				[[211,212], [221, 222]],
#				[[311,312], [321, 322]] ])
#print B, B.ndim, B.shape, B[0][1][0]
#
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

#numpy where
A = np.array([1, 2, 3, 4])
B = np.array([100, 200, 300, 400])
condition = np.array([True, True, False, False])
answer = [(A_val if cond else B_val) for A_val, B_val, cond in zip(A, B, condition)]
print answer

answer2 = np.where(condition,A,B)
print answer2

arr = randn(5,5)
print arr

print np.where(arr<0, 0, arr)#"where arr element < 0, replace it with zero, otherwise leave that array value"

arr = np.array([[1,2,3],[4,5,6],[7,8,9]])
print arr.sum()
print arr.sum(0)
print arr.mean()
print arr.std()
print arr.var()

bool_arr = np.array([True, False, True])
print bool_arr.any()
print bool_arr.all()


#Sort 
arr = randn(5)
print arr
arr.sort()
print arr