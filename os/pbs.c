#include<stdio.h>
int main()
{
 int n, bt[20], priority[20], wt[20], tat[20], avwt = 0, avtat = 0, i, j;
 printf("Enter the total number of processes (maximum 20): ");
 scanf("%d", &n);
 printf("\nEnter the Burst Time and Priority for each process:\n");
 for (i = 0; i < n; i++)
 {
 printf("P[%d] Burst Time: ", i + 1);
 scanf("%d", &bt[i]);
 printf("P[%d] Priority: ", i + 1);
 scanf("%d", &priority[i]);
 }
 // Sorting the processes based on priority using Selection Sort
 for (i = 0; i < n - 1; i++)
 {
 int max_priority = priority[i];
 int max_priority_index = i;
 for (j = i + 1; j < n; j++)
 {
 if (priority[j] < max_priority)
 {
 max_priority = priority[j];
 max_priority_index = j;
 }
 }
 // Swapping priority
 int temp_priority = priority[i];
 priority[i] = priority[max_priority_index];
 priority[max_priority_index] = temp_priority;
 // Swapping burst time
 int temp_bt = bt[i];
 bt[i] = bt[max_priority_index];
 bt[max_priority_index] = temp_bt;
 }
 wt[0] = 0; // Waiting time for the first process is 0
 // Calculating waiting time
 for (i = 1; i < n; i++)
 {
 wt[i] = 0;
 for (j = 0; j < i; j++)
 {
 wt[i] += bt[j];
 }
 }
 printf("\nProcess\tBurst Time\tPriority\tWaiting Time\tTurnaround Time");
 // Calculating turnaround time
 for (i = 0; i < n; i++)
 {
 tat[i] = bt[i] + wt[i];
 avwt += wt[i];
 avtat += tat[i];
 printf("\nP[%d]\t%d\t\t%d\t\t%d\t\t%d", i + 1, bt[i], priority[i], wt[i], tat[i]);
 }
 avwt /= i;
 avtat /= i;
 printf("\n\nAverage Waiting Time: %d", avwt);
 printf("\nAverage Turnaround Time: %d", avtat);
 return 0;
}