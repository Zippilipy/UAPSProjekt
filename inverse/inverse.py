""" Finds an invertible matrix, then inverts it"""
import sys
import time
import numpy as np

times = int(sys.argv[1])

DIMENSION = 100
MIN = 0
MAX = 100

i = 0
while i < times:
    start_time = time.time_ns()

    DETERMINANT = 0

    while DETERMINANT == 0:
        matrix = np.array([np.random.randint(MIN,MAX, size=(DIMENSION,DIMENSION))])
        DETERMINANT = np.linalg.det(matrix)
        inverse = np.linalg.inv(matrix)

    end_time = time.time_ns()
    elapsed_time = end_time - start_time

    # Prints end time
    print(elapsed_time)
    i = i + 1
