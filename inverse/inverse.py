""" Implements the algorithm in the most effective way """
import time
import numpy as np

DIMENSION = 500 
MIN = 0
MAX = 100

start_time = time.time()

DETERMINANT = 0

while DETERMINANT != 0:
    matrix = np.array([np.random.randint(MIN,MAX, size=(DIMENSION,DIMENSION))])
    DETERMINANT = np.linalg.det(matrix)
    print(matrix)
    inverse = np.linalg.inv(matrix)
    if DETERMINANT != 0:
        print("determinant is ", DETERMINANT)


end_time = time.time()
elapsed_time = end_time - start_time

# Prints end time
print(elapsed_time)
