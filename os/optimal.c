#include <stdio.h>
#include <stdlib.h>
int main() {
 int i, j, k, n, size, pageFaults = 0;
 
 printf("Enter the total number of pages: ");
 scanf("%d", &n);
 
 int pages[n];
 printf("Enter the page sequence: ");
 for (i = 0; i < n; i++) {
 scanf("%d", &pages[i]);
 }
 
 printf("Enter the number of frames: ");
 scanf("%d", &size);
 
 int frames[size];
 for (i = 0; i < size; i++) {
 frames[i] = -1; // Initialize frames as empty (-1 indicates an empty frame)
 }
 
 printf("\nOptimal Page Replacement Algorithm\n");
 
 for (i = 0; i < n; i++) {
 int page = pages[i];
 int pageFound = 0; // Flag to indicate if the page is already in memory
 
 // Check if the page is already in memory
 for (j = 0; j < size; j++) {
 if (frames[j] == page) {
 pageFound = 1;
 break;
 }
 }
 
 // If the page is not in memory, find the optimal page to replace
 if (!pageFound) {
 int optimalIndex = -1; // Initialize with -1 (no optimal page found)
 
 // Find the index of the page that will not be used for the longest duration
 for (j = 0; j < size; j++) {
 int currentPage = frames[j];
 int nextPageIndex = -1;
 
 // Find the index of the next occurrence of the current page
 for (k = i + 1; k < n; k++) {
 if (pages[k] == currentPage) {
 nextPageIndex = k;
 break;
 }
 }
 
 // If the current page will not be used anymore, replace it
 if (nextPageIndex == -1) {
 optimalIndex = j;
 break;
 }
 
 // If no optimal index is set yet, or the current page's next occurrence is farthest, update the 
// optimal index
 if (optimalIndex == -1 || nextPageIndex > optimalIndex) {
 optimalIndex = j;
 }
 }
 
 // Replace the optimal page with the current page
 frames[optimalIndex] = page;
 pageFaults++;
 }
 
 // Print the current state of frames
 printf("Page: %d\tFrames: ", page);
 for (j = 0; j < size; j++) {
 if (frames[j] == -1) {
 printf("-");
 } else {
 printf("%d", frames[j]);
 }
 printf("\t");
 }
 printf("\n");
 }
 
 printf("\nTotal page faults: %d\n", pageFaults);
 
 return 0;
}