#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i, j, k, n, size, pageFaults = 0;

    printf("Enter the total number of pages: ");
    scanf("%d", &n);

    int pages[n];
    printf("Enter the page sequence: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &pages[i]);
    }

    printf("Enter the number of frames: ");
    scanf("%d", &size);

    int frames[size];
    for (i = 0; i < size; i++)
    {
        frames[i] = -1; // Initialize frames as empty (-1 indicates an empty frame)
    }

    printf("\nLRU Page Replacement Algorithm\n");

    for (i = 0; i < n; i++)
    {
        int page = pages[i];
        int pageFound = 0; // Flag to indicate if the page is already in memory

        // Check if the page is already in memory
        for (j = 0; j < size; j++)
        {
            if (frames[j] == page)
            {
                pageFound = 1;
                break;
            }
        }

        // If the page is not in memory, find the least recently used page and replace it
        if (!pageFound)
        {
            int leastRecent = n; // Initialize with a large value

            // Find the least recently used page in memory
            for (j = 0; j < size; j++)
            {
                int currentPage = frames[j];
                int recentIndex = -1;

                // Find the index of the most recent occurrence of the current page
                for (k = i - 1; k >= 0; k--)
                {
                    if (pages[k] == currentPage)
                    {
                        recentIndex = k;
                        break;
                    }
                }

                // Update the leastRecent if the current page is least recently used
                if (recentIndex == -1)
                {
                    leastRecent = j;
                    break;
                }

                if (recentIndex < leastRecent)
                {
                    leastRecent = j;
                }
            }

            // Replace the least recently used page with the current page
            frames[leastRecent] = page;
            pageFaults++;
        }

        // Print the current state of frames
        printf("Page: %d\tFrames: ", page);
        for (j = 0; j < size; j++)
        {
            if (frames[j] == -1)
            {
                printf("-");
            }
            else
            {
                printf("%d", frames[j]);
            }
            printf("\t");
        }
        printf("\n");
    }

    printf("\nTotal page faults: %d\n", pageFaults);

    return 0;
}