#include <stdio.h>
#define MAX_PROCESS 10
#define MAX_RESOURCE 10
int main()
{
    int allocation[MAX_PROCESS][MAX_RESOURCE];
    int max[MAX_PROCESS][MAX_RESOURCE];
    int available[MAX_RESOURCE];
    int need[MAX_PROCESS][MAX_RESOURCE];
    int work[MAX_RESOURCE];
    int finish[MAX_PROCESS];
    int safe_sequence[MAX_PROCESS];
    int num_processes, num_resources, i, j;
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);
    printf("Enter the number of resources: ");
    scanf("%d", &num_resources);
    // Input allocation matrix
    printf("Enter the allocation matrix:\n");
    for (i = 0; i < num_processes; i++)
    {
        printf("Process %d: ", i + 1);
        for (j = 0; j < num_resources; j++)
        {
            scanf("%d", &allocation[i][j]);
        }
    }
    // Input max matrix
    printf("Enter the max matrix:\n");
    for (i = 0; i < num_processes; i++)
    {
        printf("Process %d: ", i + 1);
        for (j = 0; j < num_resources; j++)
        {
            scanf("%d", &max[i][j]);
        }
    }
    // Input available resources
    printf("Enter the available resources: ");
    for (j = 0; j < num_resources; j++)
    {
        scanf("%d", &available[j]);
    }
    // Calculate the need matrix
    for (i = 0; i < num_processes; i++)
    {
        for (j = 0; j < num_resources; j++)
        {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
    // Initialize work and finish arrays
    for (j = 0; j < num_resources; j++)
    {
        work[j] = available[j];
    }
    for (i = 0; i < num_processes; i++)
    {
        finish[i] = 0;
    }
    // Banker's Algorithm
    int count = 0;
    while (count < num_processes)
    {
        int found = 0;
        for (i = 0; i < num_processes; i++)
        {
            if (finish[i] == 0)
            {
                int flag = 1;
                for (j = 0; j < num_resources; j++)
                {
                    if (need[i][j] > work[j])
                    {
                        flag = 0;
                        break;
                    }
                }
                if (flag == 1)
                {
                    for (j = 0; j < num_resources; j++)
                    {
                        work[j] += allocation[i][j];
                    }
                    safe_sequence[count] = i;
                    finish[i] = 1;
                    found = 1;
                    count++;
                }
            }
        }
        if (found == 0)
        {
            break;
        }
    }
    // Check if the system is in a safe state
    if (count == num_processes)
    {
        printf("The system is in a safe state.\n");
        printf("Safe sequence: ");
        for (i = 0; i < num_processes; i++)
        {
            printf("%d ", safe_sequence[i]);
        }
        printf("\n");
    }
    else
    {
        printf("The system is not in a safe state.\n");
    }
    return 0;
}