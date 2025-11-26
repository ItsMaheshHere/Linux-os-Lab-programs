#include <stdio.h>
int main()
{
    int memory;
    printf("Enter the size of memory");
    scanf("%d",&memory);
    int files[memory],index[memory],i,n,count=0,idx;
    for(i=0;i<memory;i++){
        files[i]=1;
    }
    printf("Enter the indexed block");
    scanf("%d",&idx);
    if(files[idx]==1){
        printf("Memory Preallocated");
        return 0;
    }else{
        files[idx]=1;
    }
    printf("Enter number of blocks needed for file: ");
    scanf("%d",&n);
    printf("Enter block indexes:\n");
    for (i=0;i<n;i++){
        scanf("%d",&index[i]);
        if(files[index[i]]==1){
            printf("Block preallocated");
        }else{
            files[index[i]]=1;
            count++;
        }
    }
    if(count==n){
        printf("File allocated Successfully");
        printf("Index block %d points to blocks ",idx);
        for(i=0;i<n;i++){
            printf("%d",index[i]);
        }
    }
    return 0;
}
