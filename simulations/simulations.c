#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int simulate(int killcount, int droprate) {
    int amount = 0;
    for (int i = 0; i < killcount; i++) {
        if (rand() % droprate == 0) {
            amount++;
        }
    }
    return amount;
}

int main(int argc, char *argv[]) {
    int amount = atoi(argv[1]);
    srand(time(NULL));

    for (int i = 0; i < amount; i++) {
        struct timespec start_time, end_time;
        clock_gettime(CLOCK_MONOTONIC_RAW, &start_time);
        simulate(1000000, 256);
        clock_gettime(CLOCK_MONOTONIC_RAW, &end_time);
        long long elapsed_ns = (end_time.tv_sec - start_time.tv_sec) * 1000000000LL + (end_time.tv_nsec - start_time.tv_nsec);
        printf("%lld\n", elapsed_ns);
    }

    return 0;
}
