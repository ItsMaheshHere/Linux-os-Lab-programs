#include <stdio.h>
int main()
{
    int a,k,j,element,n,i,x,size;
    int arr[100];
    printf("Enter no. of elements:-");
    scanf("%d",&n);
    printf("Enter Elements:-\n");
    for (i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter element to insert\n");
    scanf("%d", &x);
    printf("Enter index:-");
    scanf("%d",&i);
    size=n-1;
    for (k=0; k<n; k++)
    {
        if(i==k+1)
        {
            for (j=size; j>0; j--)
            {
                if (i==j+1)
                {
                    break;
                }
                else {
                    element=arr[j];
                    arr[j+1]=element;
                    arr[j]=arr[j-1];
                }
            }
        }
    }
    a=i-1;
    arr[a]=x;
    printf("The array is:\n");
    for (k=0;k<=n;k++)
    {
        printf("%d ",arr[k]);
    }
    return 0;
}