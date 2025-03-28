#include<stdio.h>
// Structure to hold Process Details
typedef struct {
    int pid;        // Process ID
    int arrival;     // Arrival Time
    int burst;     // Burst Time
    int completion;     // Completion Time
    int turnaround;     // Turnaround Time
    int waiting;     // Waiting Time
} Process;

void SJFScheduling(Process p[], int n) {
    int time = 0, completed = 0;
    while (completed < n) {
        int minIndex = -1, minBurst = 9999;
        
        // Find the process with the shortest burst time that has arrived
        for (int i = 0; i < n; i++) {
            if (p[i].arrival <= time && p[i].completion == 0 && p[i].burst < minBurst) {
                minBurst = p[i].burst;
                minIndex = i;
            }
        }

        if (minIndex == -1) {
            // If no process is available to execute, increment time
            time++;
        } else { 
            // Process is found, execute it
            time += p[minIndex].burst;
            p[minIndex].completion = time;
            p[minIndex].turnaround = p[minIndex].completion - p[minIndex].arrival;
            p[minIndex].waiting = p[minIndex].turnaround - p[minIndex].burst;
            completed++;
        }
    }
}

void displayProcessTable(Process p[], int n) {
    printf("\nProcess        AT        BT        CT        TAT        WT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].arrival, p[i].burst, p[i].completion, p[i].turnaround, p[i].waiting);
    }
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    Process p[n];
    printf("Enter Arrival Time and Burst Time for each process: \n");
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("P%d Arrival Time: ", i + 1);
        scanf("%d", &p[i].arrival);
        printf("P%d Burst Time: ", i + 1);
        scanf("%d", &p[i].burst);
        p[i].completion = 0;  // Initializing completion time to 0
    }

    // Sorting processes by arrival time
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].arrival > p[j + 1].arrival) {
                Process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    // Execute SJFScheduling algorithm
    SJFScheduling(p, n);
    
    // Display the result table
    displayProcessTable(p, n);

    return 0;
}
