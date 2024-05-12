import numpy as np
import math
import time as t
import sys

def sieve_of_eratosthenes(n):
    primes = np.ones(n + 1, dtype=bool)
    primes[0:2] = False  # 0 and 1 are not prime

    for i in range(2, int(math.sqrt(n)) + 1):
        if primes[i]:
            multiplier = 0
            j = i * i + multiplier * i
            while(j<n):
                primes[j] = False
                multiplier += 1
                j = i * i + multiplier * i

    return np.nonzero(primes)[0]

def main():
    amount = int(sys.argv[1])
    for i in range(0, amount):
        start_time = t.time_ns()
        prime_numbers = sieve_of_eratosthenes(1_000_000)
        end_time = t.time_ns()
        print(end_time - start_time)

if __name__ == "__main__":
    main()
