#include<stdio.h>
#include<stdlib.h>
int main(){
    int n,f,i,j,k,pg[30],frame[10],count[10],time[10];
    int ch,flag,found,pos,min,pgfault=0;
    while(1){
        printf("\n1.FIFO\n2.LRU\n3.LFU\n4.Exit\nEnter choice: ");
        scanf("%d",&ch);
        if(ch==4)break;
        printf("Enter no. of pages: ");
        scanf("%d",&n);
        printf("Enter reference string: ");
        for(i=0;i<n;i++)scanf("%d",&pg[i]);
        printf("Enter number of frames: ");
        scanf("%d",&f);
        for(i=0;i<f;i++){
            frame[i]=-1;
            count[i]=0;
            time[i]=0;
        }
        pgfault=0;
        switch(ch){
            case 1:
                j=0;
                for(i=0;i<n;i++){
                    flag=0;
                    for(k=0;k<f;k++){
                        if(frame[k]==pg[i]){
                            flag=1;
                            break;
                        }
                    }
                    if(flag==0){
                        frame[j]=pg[i];
                        j=(j+1)%f;
                        pgfault++;
                    }
                    printf("\n");
                    for(k=0;k<f;k++){
                        if(frame[k]!=-1)printf("%d ",frame[k]);
                        else printf("- ");
                    }
                }
                printf("\nTotal Page Faults(FIFO)=%d\n",pgfault);
                break;
            case 2:
                for(i=0;i<n;i++){
                    flag=0;
                    for(j=0;j<f;j++){
                        if(frame[j]==pg[i]){
                            flag=1;
                            time[j]=i+1;
                            break;
                        }
                    }
                    if(flag==0){
                        int min_time=999,pos=0;
                        for(j=0;j<f;j++){
                            if(frame[j]==-1){
                                pos=j;
                                break;
                            }
                            if(time[j]<min_time){
                                min_time=time[j];
                                pos=j;
                            }
                        }
                        frame[pos]=pg[i];
                        time[pos]=i+1;
                        pgfault++;
                    }
                    printf("\n");
                    for(k=0;k<f;k++){
                        if(frame[k]!=-1)printf("%d ",frame[k]);
                        else printf("- ");
                    }
                }
                printf("\nTotal Page Faults(LRU)=%d\n",pgfault);
                break;
            case 3:
                for(i=0;i<n;i++){
                    flag=0;
                    for(j=0;j<f;j++){
                        if(frame[j]==pg[i]){
                            flag=1;
                            count[j]++;
                            break;
                        }
                    }
                    if(flag==0){
                        int min_count=999,pos=0;
                        for(j=0;j<f;j++){
                            if(frame[j]==-1){
                                pos=j;
                                break;
                            }
                            if(count[j]<min_count){
                                min_count=count[j];
                                pos=j;
                            }
                        }
                        frame[pos]=pg[i];
                        count[pos]=1;
                        pgfault++;
                    }
                    printf("\n");
                    for(k=0;k<f;k++){
                        if(frame[k]!=-1)printf("%d ",frame[k]);
                        else printf("- ");
                    }
                }
                printf("\nTotal Page Faults(LFU)=%d\n",pgfault);
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}