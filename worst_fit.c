#include <stdio.h>
int main(){
    int block,process;
    printf("Enter no. of memory blocks: ");
    scanf("%d", &block);
    int blocks[block];
    printf("Enter sizes of memory blocks:\n");
    for (int i = 0; i < block; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &blocks[i]);
    }
    printf("\nEnter no. of processes: ");
    scanf("%d", &process);
    int processes[process],alloc[process];
    printf("Enter sizes of processes:\n");
    for(int i=0;i<process;i++){
        printf("Process %d: ",i+1);
        scanf("%d", &processes[i]);
        alloc[i]=-1; 
    }
    for (int i=0;i<process;i++){
        int worstIdx=-1;
        for (int j=0;j<block;j++) {
            if (blocks[j]>=processes[i]){
                if (worstIdx==-1||blocks[j]>blocks[worstIdx]) {
                    worstIdx=j;
                }
            }
        }
        if (worstIdx != -1) {
            alloc[i] = worstIdx;
            blocks[worstIdx] -= processes[i]; 
        }
    }
    printf("\nProcess No.\tProcess Size\tBlock No.\n");
    for (int i = 0; i < process; i++) {
        printf("%d\t\t%d\t\t", i + 1, processes[i]);
        if (alloc[i] != -1)
            printf("%d\n", alloc[i] + 1);
        else
            printf("Not Allocated\n");
    }
    return 0;
}