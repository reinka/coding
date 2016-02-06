import numpy as np
import itertools
import csv

arr = np.arange(5)
#print arr
#
#np.save("myarray", arr)
#arr = np.arange(10)
#print arr
#
#arr1 = np.load("myarray.npy")
#arr2 = arr
#
#np.savez("ziparray.npz", x=arr1,y=arr2)
#
#archive_array = np.load("ziparray.npz")
#print archive_array['x'], archive_array["y"]
#
#matrix = np.array([[1,2,3], [4,5,6]])
#np.savetxt("mytextarray.txt", arr, delimiter=",")
#
#arr = np.loadtxt("mytextarray.txt", delimiter=",")
#print "arr it is:",arr

matrix = np.loadtxt("20x20grid.txt", delimiter=" ")
#print matrix
#print matrix.shape

#four_times_five_matrix = matrix
#four_times_five_matrix.shape = (20, 4, 5)
#print four_times_five_matrix

#with open("20x20grid.txt", "r") as infile:
#	matrix = [map(int, line.split()) for line in infile]
#
#print matrix
matrix = matrix.astype(int)
print matrix

rows, cols, path_size = len(matrix), len(matrix[0]), 4
print rows, cols, path_size
maxp = max_product_diag_down_right = max_product_diag_down_left = 0


for i in range(rows):
	for j in range(cols):
		if j <= cols - path_size:
			max_product_horizontal_or_vertical = max(matrix[i][j]*matrix[i][j+1]*matrix[i][j+2]*matrix[i][j+3], matrix[j][i]*matrix[j+1][i]*matrix[j+2][i]*matrix[j+3][i])
		
		if j >= path_size and i <= rows - path_size:
			max_product_diag_down_left = matrix[i][j]*matrix[i+1][j-1]*matrix[i+2][j-2]*matrix[i+3][j-3] 
		if j <= cols - path_size and i <= rows - path_size:
			max_product_diag_down_right = matrix[i][j]*matrix[i+1][j+1]*matrix[i+2][j+2]*matrix[i+3][j+3]

		
		maxp = max(max_product_horizontal_or_vertical,max_product_diag_down_right,max_product_diag_down_left, maxp)
print maxp

#test = np.array([np.sum(matrix[0:3])])
#print test













#y = np.array(matrix).tolist()
#rint y

#with open('1k.txt') as inputfile:
#	number = list(csv.reader(inputfile))

#print number

