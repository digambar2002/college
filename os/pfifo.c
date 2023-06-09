#include <stdio.h>
#include <stdlib.h>
int main() {
 int i, j, k, n, size, pageFaults = 0, currentPage = 0;
 
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
 
 printf("\nFIFO Page Replacement Algorithm\n");
 
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
 
 // If the page is not in memory, replace the oldest page
 if (!pageFound) {
 frames[currentPage] = page;
 currentPage = (currentPage + 1) % size; // Update the index of the oldest page
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