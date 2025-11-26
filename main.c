#include <stdio.h>
int main(){
    int i,n,bt[n],wt[n],tat[n],sum_wt=0,sum_tat=0;
    float avg_wt=0,avg_tat=0;
    printf("Enter number of process:-");
    scanf("%d",&n);
    printf("Enter Burst time:-");
    for (i=0;i<n;i++){
        scanf("%d",&bt[i]);
    }

    wt[0]=0;
    for (i=1;i<n;i++){
        wt[i]=wt[i-1]+bt[i-1];
    }

    for(i=0;i<n;i++){
        tat[i]=wt[i]+bt[i];
        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    for (i=0;i<n;i++){
        printf("Waiting time for P%d=%d\n",i,wt[i]);
    }
    for (i=0;i<n;i++){
        printf("turn around time for P%d=%d\n",i,tat[i]);
    }
    printf("Avg Waiting Time=%.2f\n",avg_wt/n);
    printf("Avg turn around time=%.2f",avg_tat/n);
}