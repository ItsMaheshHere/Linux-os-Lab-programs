#include <stdio.h>
int main()
{
    int n;
    printf("Enter the size of memory");
    scanf("%d",&n);
    int files[n], start, length, i;
    for(i=0; i<n; i++){
        files[i] = 0;}
    printf("Enter the starting block index (as per 0-based indexing) and length of the file: ");
    scanf("%d %d", &start, &length);

    for(i=start; i<start+length; i++) 
    {
        if(files[i] == 1) 
        {
            printf("Block %d already allocated!\n", i);
            return 0;
        }
        else
        {
            files[i] = 1;
        }
    }
    printf("File allocated from block %d to %d\n", start, start+length-1);
    printf("Disk status:\n");
    for(i=0; i<n; i++){
        printf("%d ", files[i]);
    }
    return 0;
}
