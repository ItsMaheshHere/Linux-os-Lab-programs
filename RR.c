#include <stdio.h>
int main()
{
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], rt[n], tat[n], wt[n];

    int i, tq, time, rem=n;
    float sum_tat = 0, sum_wt = 0, avg_tat, avg_wt;

    for (i = 0; i < n; i++){
        printf("Enter arrival time of P%d in ms: ", i);
        scanf("%d", &at[i]);
        printf("Enter burst time of P%d in ms: ", i);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }

    printf("Enter Time Quantum in ms: ");
    scanf("%d", &tq);
    printf("\nProcess\tTAT(ms)\tWT(ms)\n");

    for (time = 0, i = 0; rem != 0;){
        if (rt[i] > 0 && at[i] <= time){
            if (rt[i] <= tq){
                time += rt[i];
                rt[i] = 0;
            }else{
                rt[i] = rt[i] - tq;
                time = time + tq;
            }
            if(rt[i] == 0){
                rem--;
                tat[i] = time - at[i];
                wt[i] = tat[i] - bt[i];
                printf("P%d\t%d\t%d\n", i, tat[i], wt[i]);
                sum_tat = sum_tat + tat[i];
                sum_wt = sum_wt + wt[i];
            }
        }
        i = (i + 1) % n;
    }

    avg_tat = sum_tat/n;
    avg_wt = sum_wt/n;
    printf("\nAverage Turnaround Time = %.2f ms", avg_tat);
    printf("\nAverage Waiting Time = %.2f ms", avg_wt);
    return 0;
}