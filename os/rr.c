#include <stdio.h>
int main()
{
    int n, quantum, bt[20], wt[20], tat[20], rem_bt[20], time = 0, i, flag;
    printf("Enter the total number of processes (maximum 20): ");
    scanf("%d", &n);
    printf("Enter the time quantum: ");
    scanf("%d", &quantum);
    printf("Enter the Burst Time for each process:\n");
    for (i = 0; i < n; i++)
    {
        printf("P[%d]: ", i + 1);
        scanf("%d", &bt[i]);
        rem_bt[i] = bt[i];
    }
    while (1)
    {
        flag = 0;
        for (i = 0; i < n; i++)
        {
            if (rem_bt[i] > 0)
            {
                flag = 1;
                if (rem_bt[i] > quantum)
                {
                    time += quantum;
                    rem_bt[i] -= quantum;
                }
                else
                {
                    time += rem_bt[i];
                    wt[i] = time - bt[i];
                    rem_bt[i] = 0;
                }
            }
        }
        if (flag == 0)
            break;
    }
    for (i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
    }
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time");
    for (i = 0; i < n; i++)
    {
        printf("\nP[%d]\t%d\t\t%d\t\t%d", i + 1, bt[i], wt[i], tat[i]);
    }
    return 0;
}