#include <stdio.h>
#include <omp.h>


void calculateCube(int start, int end) {
    #pragma omp parallel for
    for (int i = start; i <= end; i++) {
        int cube = i * i * i;
        printf("Cube of %d is: %d\n", i, cube);
    }
}



int main() {
    int N = 10; // Number of elements
    int range_start = 1; // Start of the range
    int range_end = N; // End of the range
    printf("Parallel Execution:\n");
    double start_parallel = omp_get_wtime(); // Start measuring time
    calculateCube(range_start, range_end); // Calculate cube in parallel
    double end_parallel = omp_get_wtime(); // End measuring time
    printf("Parallel Execution Time: %lf seconds\n", end_parallel - start_parallel);
    return 0;
}
