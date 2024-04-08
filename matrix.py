import random
import math
import time
import sys

R1 = 50257 #50257
C1 = 12288 #12288
R2 = 12288 #12288
C2 = 1 #1

def random_number():
    return (random.randint(-100, 100) / 10.0)

def generate_matrix(rows, cols):
    return [[random_number() for _ in range(cols)] for _ in range(rows)]

def softmax(matrix):
    max_val = max(matrix)
    exp_sum = sum(math.exp(x - max_val) for x in matrix)
    return [math.exp(x - max_val) / exp_sum for x in matrix]

def multiply_matrix(m1, m2):
    result = [[0.0] * C2 for _ in range(R1)]
    for i in range(R1):
        for j in range(C2):
            for k in range(R2):
                result[i][j] += m1[i][k] * m2[k][j]
    return result

def main():
    amount = int(sys.argv[1])
    random.seed(time.time())
    for q in range(amount):
        m1 = generate_matrix(R1, C1)
        m2 = generate_matrix(R2, C2)

        start_time = time.monotonic()
        result = multiply_matrix(m1, m2)
        matrix_flat = [result[i][j] for i in range(R1) for j in range(C2)]
        matrix_flat_softmax = softmax(matrix_flat)
        max_val = max(matrix_flat_softmax)
        elapsed_ns = (time.monotonic() - start_time) * 1e9

        print(int(elapsed_ns))

if __name__ == "__main__":
    main()
