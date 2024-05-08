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

def invert_matrix(A):
    '''Take in a matrix A, returns the inverse'''    
    n = len(A)
    I = [[1 if i == j else 0 for j in range(n)] for i in range(n)]

    for i in range(n):
        pivot = A[i][i]
	#divides everything in the row
        for j in range(n):
            A[i][j] /= pivot
            I[i][j] /= pivot
        for k in range(n):
            if k != i:
                factor = A[k][i]
                for j in range(n):
                    A[k][j] -= factor * A[i][j]
                    I[k][j] -= factor * I[i][j]
    return I

start_time = time.time()
invert_matrix(create_matrix(100))
end_time = time.time()
elapsed_time = end_time - start_time
print(elapsed_time)
