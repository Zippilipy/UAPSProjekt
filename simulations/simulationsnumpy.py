import numpy as np
import time as t
import sys

def simulate(killcount, droprate):
    random_numbers = np.random.choice(range(1, droprate + 1), size = killcount)
    amount = np.count_nonzero(random_numbers == 1)
    return amount

def main():
    amount = int(sys.argv[1])
    for i in range(amount):
        start_time = t.time_ns()
        simulate(1_000_000, 256)
        end_time = t.time_ns()
        print(end_time - start_time)

if __name__ == '__main__':
    main()
