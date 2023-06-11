#include <stdio.h>
int main()
{
    int n, bt[20], wt[20], tat[20], avwt = 0, avtat = 0, i, j;
    printf("Enter the total number of processes (maximum 20): ");
    scanf("%d", &n);
    printf("\nEnter the Burst Time for each process:\n");
    for (i = 0; i < n; i++)
    {
        printf("P[%d]: ", i + 1);
        scanf("%d", &bt[i]);
    }
    // Sorting the burst time in ascending order using Selection Sort
    for (i = 0; i < n - 1; i++)
    {
        int min = i;
        for (j = i + 1; j < n; j++)
        {
            if (bt[j] < bt[min])
                min = j;
        }
        int temp = bt[min];
        bt[min] = bt[i];
        bt[i] = temp;
    }
    wt[0] = 0; 
    
    // Waiting time for the first process is 0
    // Calculating waiting time
    for (i = 1; i < n; i++)
    {
        wt[i] = 0;
        for (j = 0; j < i; j++)
        {
            wt[i] += bt[j];
        }
    }
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time");
    // Calculating turnaround time
    for (i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
        avwt += wt[i];
        avtat += tat[i];
        printf("\nP[%d]\t%d\t\t%d\t\t%d", i + 1, bt[i], wt[i], tat[i]);
    }
    avwt /= i;
    avtat /= i;
    printf("\n\nAverage Waiting Time: %d", avwt);
    printf("\nAverage Turnaround Time: %d", avtat);
    return 0;
}
