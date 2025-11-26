#include <stdio.h>

int main() {
    int m, n;
    
    // Get number of memory blocks
    printf("Enter number of memory blocks: ");
    scanf("%d", &m);
    
    int blockSize[m];
    printf("Enter size of each block:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &blockSize[i]);
    }
    
    // Get number of processes
    printf("Enter number of processes: ");
    scanf("%d", &n);
    int processSize[n], allocation[n];
    printf("Enter size of each process:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &processSize[i]);
        allocation[i] = -1; // Initialize allocation to -1 (not allocated) [cite: 54]
    }

    // Best-Fit allocation 
    for (int i = 0; i < n; i++) { // For each process 
        int bestIdx = -1; // Index of the best fit block found so far [cite: 58]
        
        for (int j = 0; j < m; j++) { // Search through blocks 
            // 1. Check if the block size is sufficient for the process
            if (blockSize[j] >= processSize[i]) {
                // 2. Check if this is the first fit found, OR if it's a smaller fit than the previous best
                if (bestIdx == -1 || blockSize[j] < blockSize[bestIdx]) {
                    bestIdx = j; // Update the index to the current block [cite: 64]
                }
            }
        }
        
        // If a best-fit block was found (bestIdx is not -1) 
        if (bestIdx != -1) { 
            allocation[i] = bestIdx; // Allocate the process to this block 
            blockSize[bestIdx] -= processSize[i]; // Reduce the remaining block size 
        }
    }

    // Display the results
    printf("\nBest-Fit Allocation:\n");
    printf("Process No.\tProcess Size\tBlock No.\n");
    
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);
        
        if (allocation[i] != -1) {
            printf("%d\n", allocation[i] + 1); // Block numbers are 1-based for display [cite: 81]
        } else {
            printf("Not Allocated\n");
        }
    }
    
    return 0;
}