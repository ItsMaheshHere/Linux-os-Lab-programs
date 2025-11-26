#include<stdio.h>
#include<stdlib.h>
int main(){
    int n,req[50],head,i,j,temp,seek=0,diff;
    int max,choice,direction;
    while(1){
        printf("\n1.FCFS\n2.SCAN\n3.C-SCAN\n4.Exit\nEnter choice: ");
        scanf("%d",&choice);
        if(choice==4)break;
        printf("Enter number of disk requests: ");
        scanf("%d",&n);
        printf("Enter the requests sequence: ");
        for(i=0;i<n;i++)scanf("%d",&req[i]);
        printf("Enter initial head position: ");
        scanf("%d",&head);
        printf("Enter maximum disk size: ");
        scanf("%d",&max);
        seek=0;
        switch(choice){
            case 1:
                for(i=0;i<n;i++){
                    diff=abs(req[i]-head);
                    seek+=diff;
                    head=req[i];
                }
                printf("Total Seek Time(FCFS)=%d\n",seek);
                break;
            case 2:
                printf("Enter direction (1 for high, 0 for low): ");
                scanf("%d",&direction);
                req[n]=head;
                n++;
                for(i=0;i<n-1;i++){
                    for(j=0;j<n-i-1;j++){
                        if(req[j]>req[j+1]){
                            temp=req[j];
                            req[j]=req[j+1];
                            req[j+1]=temp;
                        }
                    }
                }
                int pos;
                for(i=0;i<n;i++)if(req[i]==head){pos=i;break;}
                if(direction==1){
                    for(i=pos;i<n;i++){
                        diff=abs(req[i]-head);
                        seek+=diff;
                        head=req[i];
                    }
                    if(head!=max-1){
                        seek+=abs((max-1)-head);
                        head=max-1;
                    }
                    for(i=pos-1;i>=0;i--){
                        diff=abs(req[i]-head);
                        seek+=diff;
                        head=req[i];
                    }
                }else{
                    for(i=pos;i>=0;i--){
                        diff=abs(req[i]-head);
                        seek+=diff;
                        head=req[i];
                    }
                    if(head!=0){
                        seek+=head;
                        head=0;
                    }
                    for(i=pos+1;i<n;i++){
                        diff=abs(req[i]-head);
                        seek+=diff;
                        head=req[i];
                    }
                }
                printf("Total Seek Time(SCAN)=%d\n",seek);
                break;
            case 3:
                printf("Enter direction (1 for high, 0 for low): ");
                scanf("%d",&direction);
                req[n]=head;
                n++;
                for(i=0;i<n-1;i++){
                    for(j=0;j<n-i-1;j++){
                        if(req[j]>req[j+1]){
                            temp=req[j];
                            req[j]=req[j+1];
                            req[j+1]=temp;
                        }
                    }
                }
                for(i=0;i<n;i++)if(req[i]==head){pos=i;break;}
                if(direction==1){
                    for(i=pos;i<n;i++){
                        diff=abs(req[i]-head);
                        seek+=diff;
                        head=req[i];
                    }
                    seek+=abs((max-1)-head);
                    head=0;
                    seek+=max-1;
                    for(i=0;i<pos;i++){
                        diff=abs(req[i]-head);
                        seek+=diff;
                        head=req[i];
                    }
                }else{
                    for(i=pos;i>=0;i--){
                        diff=abs(req[i]-head);
                        seek+=diff;
                        head=req[i];
                    }
                    seek+=head;
                    head=max-1;
                    seek+=max-1;
                    for(i=n-1;i>pos;i--){
                        diff=abs(req[i]-head);
                        seek+=diff;
                        head=req[i];
                    }
                }
                printf("Total Seek Time(C-SCAN)=%d\n",seek);
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}