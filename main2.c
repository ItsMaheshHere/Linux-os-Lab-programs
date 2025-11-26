#include <stdio.h>
int main()
{
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    int pid[n], at[n], bt[n], ct[n], tat[n], wt[n], completed[n];
    int i, time = 0, completed_count = 0;
    float total_tat = 0, total_wt = 0;
    for (i = 0; i < n; i++){
        pid[i] = i + 1;
        printf("Enter Arrival Time and Burst Time for Process %d: ", pid[i]);
        scanf("%d %d", &at[i], &bt[i]);
        completed[i] = 0;
    }

    while (completed_count < n)
    {
        int idx = -1;
        int min_bt = 9999;
        for (i = 0; i < n; i++){
            if (at[i] <= time && completed[i] == 0 && bt[i] < min_bt){
                min_bt = bt[i];
                idx = i;
                printf("\nProcess %d scheduled.", idx);
            }
        }
        if (idx != -1){
            time += bt[idx];
            ct[idx] = time;
            tat[idx] = ct[idx] - at[idx];
            wt[idx] = tat[idx] - bt[idx];
            completed[idx] = 1;
            completed_count++;
            total_tat += tat[idx];
            total_wt += wt[idx];
        }else{
            time++;
        }
    }
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }
    printf("\nAverage Turnaround Time = %.2f", total_tat / n);
    printf("\nAverage Waiting Time = %.2f\n", total_wt / n);
    return 0;
}