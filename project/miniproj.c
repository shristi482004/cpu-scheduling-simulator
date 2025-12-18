#include <stdio.h>

int main() {
    int n, i, j, time = 0, completed = 0, q;
    float totalWT = 0, totalTAT = 0, idleTime = 0;

    printf("\n=========== ROUND ROBIN CPU SCHEDULING ===========\n\n");
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], rt[n], ct[n], tat[n], wt[n], visited[n];

    for (i = 0; i < n; i++) {
        printf("\nEnter Arrival Time of P%d: ", i+1);
        scanf("%d", &at[i]);
        printf("Enter Burst Time of P%d: ", i+1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
        visited[i] = 0;
    }

    printf("\nEnter Time Quantum: ");
    scanf("%d", &q);

    printf("\n\n================== GANTT CHART ==================\n\n");
    printf("      ");
    
    int queue[100], front = 0, rear = 0;
    int lastProcess = -1;

    while (completed != n) {
        int executed = 0;

        for (i = 0; i < n; i++) {
            if (rt[i] > 0 && at[i] <= time) {
                executed = 1;

                if (rt[i] > q) {
                    printf("|  P%-2d  ", i+1);
                    time += q;
                    rt[i] -= q;
                } else {
                    printf("|  P%-2d  ", i+1);
                    time += rt[i];
                    rt[i] = 0;
                    ct[i] = time;
                    completed++;
                }
            }
        }

        if (!executed) {
            printf("| Idle ");
            time++;
            idleTime++;
        }
    }

    printf("|\n");

    printf("\n=================================================\n\n");


    printf("----------------------------------------------------------------------\n");
    printf("Process   AT    BT    CT    TAT    WT\n");
    printf("----------------------------------------------------------------------\n");

    for (i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        totalWT += wt[i];
        totalTAT += tat[i];

        printf("P%-8d %-5d %-5d %-5d %-7d %-5d\n",
               i+1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("----------------------------------------------------------------------\n");

    float avgWT = totalWT / n;
    float avgTAT = totalTAT / n;
    float cpu_util = ((time - idleTime) / time) * 100;

    printf("\nAverage Waiting Time     : %.2f", avgWT);
    printf("\nAverage Turnaround Time  : %.2f", avgTAT);
    printf("\nCPU Utilization          : %.2f%%\n", cpu_util);

    printf("\n=================================================\n");
    printf("              END OF SIMULATION                  \n");
    printf("=================================================\n");

    return 0;
}
