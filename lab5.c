#include <stdio.h>

int main() {
    int n = 4; // Total number of processes
    
    // Arrays for storing times
    int bTime[4];  // Burst Time
    int wTime[4];  // Waiting Time
    int tATime[4]; // Turnaround Time
    
    // Hardcoded process burst times according to the CS604P lab manual
    bTime[0] = 10; // P0
    bTime[1] = 4;  // P1
    bTime[2] = 6;  // P2
    bTime[3] = 8;  // P3
    
    float avgWTime = 0;
    float avgtATime = 0;
    
    // First process doesn't wait (Arrival time is assumed to be 0)
    wTime[0] = 0; 
    
    // 1. Loop for calculating Waiting Time (wTime) for each process
    for(int i = 1; i < n; i++) { 
        wTime[i] = wTime[i-1] + bTime[i-1]; 
    }
    
    // 2. Loop for calculating Turnaround Time (tATime) and cumulative sums
    for(int i = 0; i < n; i++) { 
        tATime[i] = wTime[i] + bTime[i]; 
        avgWTime = avgWTime + wTime[i];
        avgtATime = avgtATime + tATime[i]; 
    }
    
    // Compute averages
    avgWTime = avgWTime / n;
    avgtATime = avgtATime / n;
    
    // Display results in a clear format
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(int i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\n", i, bTime[i], wTime[i], tATime[i]);
    }
    
    printf("\nAverage Waiting Time: %.2f", avgWTime);
    printf("\nAverage Turnaround Time: %.2f\n", avgtATime);
    
    return 0;
}