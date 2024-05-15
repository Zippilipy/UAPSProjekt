#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
# define N 5


// Function to find the cofactor of a given matrix
void get_cofactor(double matrix[N][N], double temp[N][N], int p, int q, int n) {
    int i = 0, j = 0;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (row != p && col != q) {
                temp[i][j++] = matrix[row][col];
                if (j == n - 1) {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

// Calculates the determinant of a matrix
int det(double matrix[N][N], int n){
	int determinant = 0;
	if(n == 1){
		return matrix[0][0];
	}else if(n == 2){
		return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
	}

	double temp[N][N];
	int sign = 1;

	for(int i = 0; i < n; i++){
		get_cofactor(matrix, temp, 0, i, n);
		determinant += sign * matrix[0][i] * det(temp, n - 1);

        // terms are to be added with alternate sign
        sign = -sign;
	}


	return determinant; 
}	


int main() {
        clock_t start, end;
        double cpu_time_used;
		int determinant = 0, row, column;
        start = clock(); 
        int DIMENSION = 100;
        double matrix[DIMENSION][DIMENSION];


		// Creates an identity matrix
        int identity[DIMENSION][DIMENSION];
        for(row = 0; row < DIMENSION; row++){
                for(column = 0; column < DIMENSION; column++){
                        if(column == row){
                                identity[row][column] = 1;
                        }else{
                                identity[row][column] = 0;
                        }
                }
        }


		while(determinant == 0){
			// Creates the new matrix
        	int row, column;
        	srand(time(NULL));
        	for(row = 0; row < DIMENSION; row++){
               	for(column = 0; column < DIMENSION; column++){
                    matrix[row][column] = rand();    
            	}
        	}

			// calculates the determinant
			determinant = det(matrix, N); 

		}

        
        int i,j,k;
        for(i = 0; i < DIMENSION; i++){
                double pivot = matrix[i][i];
                for(j = 0; j < DIMENSION; j++){
                        matrix[i][j] = matrix[i][j]/pivot;
                        identity[i][j] = identity[i][j]/pivot;
                }    
                for(k = 0; k < DIMENSION; k++){
                        if(k!=i){
                                int factor = matrix[k][i];
                                for(j = 0; j < DIMENSION; j++){
                                        matrix[k][j] = matrix[k][j] - factor * matrix[i][j];
                                        identity[k][j] = identity[k][j] - factor * identity[i][j];
                                }
                        }
                }
		}
		end = clock();
		cpu_time_used = end - start;	
		printf("%f", cpu_time_used);
		return 0;
}
