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
        allocation[i] = -1; // Initialize allocation to -1 (not allocated)
    }
    // First-Fit allocation
    for (int i = 0; i < n; i++) { // For each process
        for (int j = 0; j < m; j++) { // Search through blocks
            // Check if the block size is sufficient for the process
            if (blockSize[j] >= processSize[i]) {
                allocation[i] = j; // Allocate the process to this block 'j'
                blockSize[j] -= processSize[i]; // Reduce the remaining block size
                break; // Move to the next process
            }
        }
    }

    // Display the results
    printf("\nFirst-Fit Allocation:\n");
    printf("Process No.\tProcess Size\tBlock No.\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);
        
        if (allocation[i] != -1) {
            printf("%d\n", allocation[i] + 1); // Block numbers are 1-based for display
        } else {
            printf("Not Allocated\n");
        }
    }
    return 0;
}