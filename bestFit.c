#include<stdio.h>
// Function to implement Best Fit Algorithm
void bestFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
    
    for (int i = 0; i < n; i++) {
        allocation[i] = -1; // Initialize all allocations to -1 (not allocated)
    }

    // Iterate through each process
    for (int i = 0; i < n; i++) {
        int bestIndex = -1;

        // Iterate through each memory block
        for (int j = 0; j < m; j++) {
            // If the block can accommodate the process and the block is not yet used
            if (blockSize[j] >= processSize[i]) {
                if (bestIndex == -1 || blockSize[bestIndex] > blockSize[j]) {
                    bestIndex = j; // Update the best block index
                }
            }
        }

        // If a suitable block is found, allocate it
        if (bestIndex != -1) {
            allocation[i] = bestIndex;
            blockSize[bestIndex] -= processSize[i]; // Reduce the block size
        }
    }

    // Display the allocation result
    printf("\nBest Fit Allocation:\n");
    for (int i = 0; i < n; i++) {
        if (allocation[i] != -1)
            printf("Process %d allocated to block %d\n", i + 1, allocation[i] + 1);
        else
            printf("Process %d not allocated\n", i + 1);
    }
}

int main() {
    int blockSize[] = {100, 500, 200, 300, 600};
    int processSize[] = {212, 417, 112, 426};
    int m = sizeof(blockSize) / sizeof(blockSize[0]);
    int n = sizeof(processSize) / sizeof(processSize[0]);
    
    bestFit(blockSize, m, processSize, n);
    
    return 0;
}
