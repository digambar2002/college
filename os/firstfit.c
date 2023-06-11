#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int main()
{
    int i, j, n, nr;
    int size[10], req[10], fm[10], fn[10];
    int intfrg;
    printf("Enter the number of blocks of memory: ");
    scanf("%d", &n);
    printf("Enter the size of each memory block:\n");
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &size[i]);
    }
    printf("Enter the number of memory requests: ");
    scanf("%d", &nr);
    printf("Enter the size of each memory request:\n");
    for (i = 1; i <= nr; i++)
    {
        scanf("%d", &req[i]);
    }
    for (i = 1; i <= n; i++)
    {
        fm[i] = 0;
    }
    for (i = 1; i <= nr; i++)
    {
        fn[i] = 0;
    }
    printf("\nAllocation by First Fit:\n");
    for (j = 1; j <= nr; j++)
    {
        for (i = 1; i <= n; i++)
        {
            if (size[i] >= req[j] && fm[i] == 0 && fn[j] == 0)
            {
                fm[i] = 1;
                fn[j] = 1;
                intfrg = size[i] - req[j];
                printf("%d memory size is allocated to %d and internal fragmentation is %d.\n", req[j],
                       size[i], intfrg);
                break;
            }
        }
        if (fn[j] == 0)
        {
            printf("%d is not allocated.\n", req[j]);
        }
    }
    getch();
    return 0;
}
