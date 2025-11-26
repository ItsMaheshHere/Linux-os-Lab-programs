#include <stdio.h> 
#include <stdlib.h> 
struct Process { 
    int pid;
    int arrival;
    int burst;
    int completion;
    int waiting;
    int turnaround;
    int type;
};
void sortByArrival(struct Process pa[], int n){
    int i, j;
    struct Process temp;
    for(i = 0; i < n-1; i++){
        for(j = i+1; j < n; j++){
            if(pa[i].arrival > pa[j].arrival){
                temp = pa[i];
                pa[i] = pa[j];
                pa[j] = temp;
            }
        }
    }
}
int main(){
    int n, i, time = 0;
    printf("Enter total number of processes: ");
    scanf("%d", &n);
    struct Process p[n], sys[n], user[n];
    int sysCount = 0, userCount = 0;
    for(i = 0; i < n; i++){
        printf("\nEnter details for Process %d\n", i+1);
        p[i].pid = i+1;
        printf("Arrival Time: ");
        scanf("%d", &p[i].arrival);
        printf("Burst Time: ");
        scanf("%d", &p[i].burst);
        printf("Type (0 = System, 1 = User): ");
        scanf("%d", &p[i].type);
        if(p[i].type == 0){
            sys[sysCount++] = p[i];
        }else{
            user[userCount++] = p[i];
        }
    }
    sortByArrival(sys, sysCount);
    sortByArrival(user, userCount);
    printf("\n--- Multi-Level Queue Scheduling (System > User, FCFS in each queue) ---\n");
    printf("\nSystem Processes Execution Order:\n");
    for(i = 0; i < sysCount; i++){
        if(time < sys[i].arrival)
        time = sys[i].arrival; 
        sys[i].completion = time + sys[i].burst; 
        sys[i].turnaround = sys[i].completion - sys[i].arrival; 
        sys[i].waiting = sys[i].turnaround - sys[i].burst; 
        time += sys[i].burst; 
        printf("P%d (AT=%d, BT=%d) -> CT=%d, TAT=%d, WT=%d\n", 
        sys[i].pid, sys[i].arrival, sys[i].burst, 
        sys[i].completion, sys[i].turnaround, sys[i].waiting); 
    }
    printf("\nUser Processes Execution Order:\n");
    for(i = 0; i < userCount; i++){
        if(time < user[i].arrival)
            time = user[i].arrival;
        user[i].completion = time + user[i].burst;
        user[i].turnaround = user[i].completion - user[i].arrival;
        user[i].waiting = user[i].turnaround - user[i].burst;
        time += user[i].burst;
        printf("P%d (AT=%d, BT=%d) -> CT=%d, TAT=%d, WT=%d\n",
        user[i].pid, user[i].arrival, user[i].burst,
        user[i].completion, user[i].turnaround, user[i].waiting);
    }
    return 0;
}