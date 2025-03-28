#include<stdio.h>
//Function to implement First Fit Algorithm
void firstFit(int blockSize[], int m, int processSize[],int n) {
    int allocation[n];
    for (int i=0;i<n;i++){
        allocation[i] = -1; //Initialize all allocatiuons to -1 (not allocated)
    }
    for (int i=0;i<n;i++) { //Iterate through processes
        for (int j=0;j<m;j++) { //Iterate through memory blocks
            if(blockSize[j]>=processSize[i]){
                allocation[i]=j; //Allocate block j to process i
                blockSize[j]-=processSize[i]; //Reduce available block size
                break;
            }
        }
    }
    
    printf("\nFirst Fit Allocation:\n");
    for (int i=0;i<n;i++){
        if (allocation[i]!=-1)
            printf("Process %d allocated to block %d\n",i+1,allocation[i]+1);
        else
            printf("Process %d not allocated\n",i+1);
    }
}

int main(){
    int blockSize[]={100,500,200,300,600};
    int processSize[]={212,417,112,426};
    int m = sizeof(blockSize)/sizeof(blockSize[0]);
    int n = sizeof(processSize)/sizeof(processSize[0]);
    firstFit(blockSize,m,processSize,n);
    
    return 0;
}