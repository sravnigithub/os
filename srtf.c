#include<stdio.h>
#define MAX_SIZE 10

int main() {
    int n, i, j, time = 0;
    int at[MAX_SIZE], bt[MAX_SIZE], rt[MAX_SIZE], ct[MAX_SIZE];
    int wt[MAX_SIZE] = {0}, tat[MAX_SIZE] = {0}, response[MAX_SIZE] = {0};
    int done = 0, shortest, prev_shortest = 0, complete = 0;

    // Input
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the arrival time and burst time for each process:\n");
    for(i = 0; i < n; i++) {
        printf("P%d: ", i+1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];
    }

    // SRTF Scheduling
    while(complete != n) {
        shortest = -1;
        for(i = 0; i < n; i++) {
            if(at[i] <= time && rt[i] > 0) {
                if(shortest == -1 || rt[i] < rt[shortest]) {
                    shortest = i;
                }
            }
        }

        if(shortest == -1) {
            time++;
        } else {
            if(prev_shortest != shortest) {
                response[shortest] = time - at[shortest];
            }

            rt[shortest]--;
            time++;

            if(rt[shortest] == 0) {
                ct[shortest] = time;
                tat[shortest] = ct[shortest] - at[shortest];
                wt[shortest] = tat[shortest] - bt[shortest];
                complete++;
            }

            prev_shortest = shortest;
        }
    }

    // Output
    printf("\nProcess\tAT\tBT\tCT\tWT\tTAT\tRT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], ct[i], wt[i], tat[i], response[i]);
    }

    // Average waiting time, turnaround time, and response time
    float avg_wt = 0, avg_tat = 0, avg_rt = 0;
    for(i = 0; i < n; i++) {
        avg_wt += wt[i];
        avg_tat += tat[i];
        avg_rt += response[i];
    }
    avg_wt /= n;
    avg_tat /= n;
    avg_rt /= n;

    printf("\nAverage Waiting Time: %.2f", avg_wt);
    printf("\nAverage Turnaround Time: %.2f", avg_tat);
    printf("\nAverage Response Time: %.2f", avg_rt);

    return 0;
}
