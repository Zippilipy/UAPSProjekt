#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define R1 1000 //50257 
#define C1 500 //12288
#define R2 500 //12288
#define C2 1 //1

float random_number() {
	return ((float)(rand() % 200) - 100) / 10.0;
}

void generate_matrix(float **matrix, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			matrix[i][j] = random_number();
		}
	}
}

void softmax(float *matrix) {
	float max_val = matrix[0];
	for (int i = 1; i < R1 * C2; i++) {
		if (matrix[i] > max_val) {
			max_val = matrix[i];
		}
	}

	float exp_sum = 0.0;
	for (int i = 0; i < R1 * C2; i++) {
		matrix[i] = exp(matrix[i] - max_val);
		exp_sum += matrix[i];
	}

	for (int i = 0; i < R1 * C2; i++) {
		matrix[i] /= exp_sum;
	}
}

float** multiply_matrix(float **m1, float **m2) {
	float **result = (float **)malloc(R1 * sizeof(float *));
	for (int i = 0; i < R1; i++) {
		result[i] = (float *)malloc(C2 * sizeof(float));
	}
	for (int i = 0; i < R1; i++) {
		for (int j = 0; j < C2; j++) {
			result[i][j] = 0;
		}
	}

	for (int i = 0; i < R1; i++) {
		for (int j = 0; j < C2; j++) {
			for (int k = 0; k < R2; k++) {
				result[i][j] += m1[i][k] * m2[k][j];
			}

		}
	}
	return result;
}

int main(int argc, char *argv[]) {
	int amount = atoi(argv[1]);
	srand(time(NULL));
	for (int q = 0; q < amount; q++) {
		float **m1 = (float **)malloc(R1 * sizeof(float *));
		for (int i = 0; i < R1; i++) {
			m1[i] = (float *)malloc(C1 * sizeof(float));
		}

		float **m2 = (float **)malloc(R2 * sizeof(float *));
		for (int i = 0; i < R2; i++) {
			m2[i] = (float *)malloc(C2 * sizeof(float));
		}

		generate_matrix(m1, R1, C1);
		generate_matrix(m2, R2, C2);

		struct timespec start_time, end_time;
		clock_gettime(CLOCK_MONOTONIC_RAW, &start_time);

		float **result = multiply_matrix(m1, m2);

		float *matrix_flat = (float *)malloc(R1 * C2 * sizeof(float));
		for (int i = 0; i < R1; i++) {
			for (int j = 0; j < C2; j++) {
				matrix_flat[i * C2 + j] = result[i][j];
			}
		}

		softmax(matrix_flat);

		float max_val = matrix_flat[0];
		for (int i = 0; i < R1 * C2; i++) {
			if (matrix_flat[i] > max_val) {
				max_val = matrix_flat[i];
			}
		}

		clock_gettime(CLOCK_MONOTONIC_RAW, &end_time);
		long long elapsed_ns = (end_time.tv_sec - start_time.tv_sec) * 1000000000LL + (end_time.tv_nsec - start_time.tv_nsec);
		printf("%lld\n", elapsed_ns);

		for (int i = 0; i < R1; i++) {
			free(result[i]);
		}
		free(result);

		for (int i = 0; i < R1; i++) {
			free(m1[i]);
		}
		free(m1);

		for (int i = 0; i < R2; i++) {
			free(m2[i]);
		}
		free(m2);
	}

	return 0;
}
