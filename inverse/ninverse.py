'''Calculates the inverse of an arbitrary matrix, without using numpy'''
import sys
import random
import time
MAX = 100
MIN = 1

def create_matrix(dimension):
    '''Generates a random square matrix with certain dimensions'''
    matrix = []
    rows = 0
    while rows < dimension:
        row = []
        for _ in range(0, dimension):
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
            if pivot != 0:
                a[i][j] = a[i][j]/ pivot
                identity[i][j] = identity[i][j]/ pivot
        for k in range(n):
            if k != i:
                factor = a[k][i]
                for j in range(n):
                    a[k][j] = a[k][j] -  factor * a[i][j]
                    identity[k][j] = identity[k][j] - factor * identity[i][j]
    return identity

def determinant(matrix):
    ''' Calculates the determinant of a matrix'''
    if len(matrix) != len(matrix[0]):
        raise ValueError("Matrix must be square")

    det = 1
    n = len(matrix)

    for i in range(n):
        if matrix[i][i] == 0:
            # Find a row to swap with
            for j in range(i + 1, n):
                if matrix[j][i] != 0:
                    matrix[i], matrix[j] = matrix[j], matrix[i]
                    det = -det
                    break
            else:
                return 0

        for j in range(i + 1, n):
            factor = matrix[j][i] / matrix[i][i]
            for k in range(i, n):
                matrix[j][k] -= factor * matrix[i][k]

    for i in range(n):
        det *= matrix[i][i]

    return det

times = int(sys.argv[1])
B = 0
while B < times:
    start_time = time.time_ns()

    DETERMINANT = 0

    while DETERMINANT == 0:
        new_matrix = create_matrix(100)
        DETERMINANT = determinant(new_matrix)

    invert_matrix(create_matrix(100))
    end_time = time.time_ns()
    elapsed_time = end_time - start_time
    print(elapsed_time)
    B = B + 1
