#include<stdio.h>

#include<stdlib.h>

#include<string.h>

int main() {
  FILE * fp1, * fp2;
  char ch, data;
  int choice = 0, status;
  do {
    printf("\nFile handling\n");
    printf("1. Create the file\n");
    printf("2. Open the file\n");
    printf("3. Write in File\n");
    printf("4. Read File \n");
    printf("5. Append\n");
    printf("6. Copy. \n");
    printf("7. Rename \n");
    printf("8. Exit \n");
    printf("Enter your choice: ");
    scanf("%d", & choice);
    switch (choice) {
    case 1:
      fp1 = fopen("textfile.txt", "w");
      if (fp1 == NULL) {
        printf("Error Creating file");
      }
      printf("File Created Successfully\n");
      fclose(fp1);
      break;
    case 2:
      fp1 = fopen("textfile.txt", "r");
      if (fp1 == NULL) {
        printf("Error Opening file");
      }
      printf("File opened Successfully\n");
      fclose(fp1);
      break;
    case 3:
      fp1 = fopen("textfile.txt", "w");
      if (fp1 == NULL) {
        printf("Error writing in the file");
      }
      fprintf(fp1, " Welcome to Operating system lab \n");
      fprintf(fp1, " File Handling Concepts \n");
      printf("Data Written Successfully\n");
      fclose(fp1);
      break;
    case 4:
      fp1 = fopen("textfile.txt", "r");
      printf("This is content of file\n");
      while ((ch = fgetc(fp1)) != EOF) {
        printf("%c", ch);
      }
      printf("\n");
      fclose(fp1);
      break;
    case 5:
      fp1 = fopen("textfile.txt", "a");
      if (fp1 == NULL) {
        printf("Error");
      }
      fputs(" Data is appended to exixting data \n", fp1);
      printf(" Data appended Successfully\n");
      fclose(fp1);
      break;
    case 6:
      fp1 = fopen("textfile.txt", "r");
      if (fp1 == NULL) {
        printf("Error");
      }
      fp2 = fopen("textcopy.txt", "w");
      if (fp2 == NULL) {
        printf("Error");
      }
      while (ch = fgetc(fp1) != EOF) {
        fputc(ch, fp2);
      }
      printf("File Copied\n");
      fclose(fp1);
      fclose(fp2);
      break;
    case 7:
      status = rename("textfile.txt", "textrename.txt");
      if (status == 0) {
        printf("The file is renamed successfully.\n");
      } else {
        printf("Unable to rename.\n");
      }
      fclose(fp1);
      break;
    case 8:
      exit(0);
      break;
    default:
      printf("Valid choice");
      break;
    }
  } while (choice != 8);
}