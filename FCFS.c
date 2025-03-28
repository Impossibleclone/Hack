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

void findCompletionTime(Process p[], int n) {
    int time = 0;
    for (int i = 0; i < n; i++) {
         if (time < p[i].arrival) {
             time=p[i].arrival;
        }
        time += p[i].burst;
        p[i].completion = time;
        p[i].turnaround = p[i].completion - p[i].arrival;
        p[i].waiting = p[i].turnaround - p[i].burst;
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
    for (int i=0; i<n; i++){
        p[i].pid = i+1;
        printf("P%d Arrival Time: ", i+1);
        scanf("%d", &p[i].arrival);
        printf("P%d Burst Time: ", i+1);
        scanf("%d", &p[i].burst);
    }

    // Sorting processes by arrival time
    for (int i=0; i < n - 1; i++) {
        for (int j = 0; j<n-i-1; j++) { 
            if (p[j].arrival > p[j + 1].arrival) { 
                Process temp = p[j]; 
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
    findCompletionTime(p, n);
    displayProcessTable(p, n);
            return 0;
}