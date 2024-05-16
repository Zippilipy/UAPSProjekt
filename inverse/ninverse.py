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
                    a[k][j] = a[k][j] -  factor * a[i][j]
                    identity[k][j] = identity[k][j] - factor * identity[i][j]
    return identity


def determinant(matrix):
    ''' Calculates the detrminant of a matrix'''
    det = 1
    n = len(matrix[0])
    for i in range(n):
        j = i + 1
        while j < n:
            k = i
            factor = matrix[j][i] / matrix[i][i]
            while k < n:
                matrix[j][k] = matrix[j][k] - factor * matrix[i][k]
                k = k + 1
            j = j + 1
    i = 0

    while i < n:
        det = det * matrix[i][i]
        i = i + 1
    return i

start_time = time.time_ns()

DETERMINANT = 0

while DETERMINANT == 0:
    new_matrix = create_matrix(100)
    DETERMINANT = determinant(new_matrix)

invert_matrix(create_matrix(100))
end_time = time.time_ns()
elapsed_time = end_time - start_time
print(elapsed_time)
