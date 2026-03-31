#include <stdio.h>

int main() {
    int m, n;

    // Step 1: Input size
    scanf("%d %d", &m, &n);

    int matrix[m][n];

    // Step 2: Input matrix
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Step 3: Check if square
    if(m != n) {
        printf("Not a Symmetric Matrix");
        return 0;
    }

    // Step 4: Check symmetry
    int isSymmetric = 1;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(matrix[i][j] != matrix[j][i]) {
                isSymmetric = 0;
                break;
            }
        }
        if(isSymmetric == 0) break;
    }

    // Step 5: Output result
    if(isSymmetric)
        printf("Symmetric Matrix");
    else
        printf("Not a Symmetric Matrix");

    return 0;
}