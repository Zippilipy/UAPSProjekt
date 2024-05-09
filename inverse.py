# Uses numpy
import time
import numpy as np

DIMENSION = 20

start_time = time.time()

# Calculates and prints an array
A = np.array([np.random.rand(DIMENSION,DIMENSION)])
print(A)

# Finds the inverse of a matrix
determinant = 0

# ensures that the matrix is inversible
while determinant == 0:
	matrix = np.linalg.inv(A)
	determinant = np.linalg.det(matrix)
	if determinant != 0:
		print("determinant is ", determinant)


end_time = time.time()
elapsed_time = end_time - start_time

# Prints end time
print(elapsed_time)
