#include <stdio.h>

#define N 4   // number of rows
#define M 3   // number of columns

// Practice questions and codes from lecture num 3:
int main() {
    int array[N][M];
    int i, j, sum;

    // Read the array
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            scanf("%d", &array[i][j]); 
        }
    }

    // Print the sum of each row
    /* 
    for (i = 0; i < N; i++) {
        sum = ____(a)____;
        for (j = ____(b)____; j < ____(c)____; j++) {
            sum += ____(d)____;
        }
        printf("Row %d sum: %d\n", i, ____(e)____);
    }
    */
    
    return 0;
}

