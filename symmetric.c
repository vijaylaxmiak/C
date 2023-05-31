//To find the given matrix is asymmetric or symmetric

#include <stdio.h>
#define MAX_SIZE 10

int is_symmetric(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                return 0;
            }
        }
    }
return 1; 
}
int main() {
    int matrix[MAX_SIZE][MAX_SIZE];
    int size, i, j;

    printf("Enter the size of the square matrix: ");
    scanf("%d", &size);

    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    if (is_symmetric(matrix, size)) {
        printf("The matrix is symmetric.\n");
    } else {
        printf("The matrix is asymmetric.\n");
    }
  return 0;
}
