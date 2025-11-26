#include <stdio.h>

int main() {
    int n;
    
    printf("Enter no. of processes: ");
    scanf("%d", &n);
    
    int pid[n], at[n], bt[n], pr[n], ct[n], tat[n], wt[n];
    int bt_rem[n]; 
    
    int time = 0, completed = 0;
    float total_tat = 0, total_wt = 0;
    
    for (int i = 0; i < n; i++) {
        pid[i] = i + 1; 
        
        printf("Enter AT, BT & priority for P%d: ", pid[i]);
        scanf("%d %d %d", &at[i], &bt[i], &pr[i]); 
        
        bt_rem[i] = bt[i]; 
    }
    
    while (completed < n) {
        int idx = -1;       
        int best_pr = 9999; 
        
        for (int i = 0; i < n; i++) {
            if (at[i] <= time && bt_rem[i] > 0) {
                if (pr[i] < best_pr) {
                    best_pr = pr[i];
                    idx = i;
                }
                else if (pr[i] == best_pr && at[i] < at[idx]) {
                     idx = i;
                }
            }
        }
        
        if (idx != -1) {
            bt_rem[idx]--; 
            time++;        
            
            if (bt_rem[idx] == 0) {
                ct[idx] = time;
                tat[idx] = ct[idx] - at[idx];
                wt[idx] = tat[idx] - bt[idx];
                
                completed++;
                total_tat += tat[idx];
                total_wt += wt[idx];
            }
        } else {
            time++; 
        }
    }
    
    printf("\n\nProcess\tAT\tBT\tPRI\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n", 
               pid[i], at[i], bt[i], pr[i], ct[i], tat[i], wt[i]);
    }
    
    printf("\nAvg TAT = %.2f\n", total_tat / n);
    printf("Avg WT = %.2f\n", total_wt / n);
    
    return 0;
}