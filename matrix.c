#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define R1 5 //50257 
#define C1 3 //12288
#define R2 3 //12288
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

void multiplyMatrix(int m1[][C1], int m2[][C2]) {
	int result[R1][C2];

	printf("Resultant Matrix is:\n");

	for (int i = 0; i < R1; i++) {
		for (int j = 0; j < C2; j++) {
			result[i][j] = 0;

			for (int k = 0; k < R2; k++) {
				result[i][j] += m1[i][k] * m2[k][j];
			}

			printf("%d\t", result[i][j]);
		}

		printf("\n");
	}
}

int main() {
	srand(time(NULL));

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

	for (int i = 0; i < R1; i++) {
		free(m1[i]);
	}
	free(m1);

	for (int i = 0; i < R2; i++) {
		free(m2[i]);
	}
	free(m2);

	//multiplyMatrix(m1, m2);

	return 0;
}
