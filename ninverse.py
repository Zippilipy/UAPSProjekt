'''Calculates the inverse of an arbitrary matrix, without using numpy'''
import random
import time
MAX = 100
MIN = 0

def create_matrix(dimension):
    '''Generates a random square matrix with certain dimensions'''
    matrix = []
    rows = 0
    while rows < dimension:
        row = []
        for i in range(0, dimension):
            row.append(random.randint(MIN,MAX))
        matrix.append(row)
        rows += 1
    return matrix

def invert_matrix(a):
    '''Take in a matrix A, returns the inverse'''    
    n = len(a)
    identity = [[1 if i == j else 0 for j in range(n)] for i in range(n)]

    for i in range(n):
        pivot = a[i][i]
	#divides everything in the row
        for j in range(n):
            a[i][j] /= pivot
            identity[i][j] /= pivot
        for k in range(n):
            if k != i:
                factor = a[k][i]
                for j in range(n):
                    a[k][j] -= factor * a[i][j]
                    identity[k][j] -= factor * identity[i][j]
    return identity

def determinant(matrix):
	# gets the dimensions of the array
    rows = len(matrix)
    cols = len(matrix[0])
    det = 0

	# 1 x 1 matrix
    if rows == 1 and cols == 1:
        return matrix[0][0]

	# 2 x 2 matrix
    if rows == 2 and cols == 2:
        return matrix[0][0]*matrix[1][1] - matrix[1][0]*matrix[0][1]
    # Return decomposition of a matrix
    return det


start_time = time.time()
invert_matrix(create_matrix(100))
end_time = time.time()
elapsed_time = end_time - start_time
print(elapsed_time)
