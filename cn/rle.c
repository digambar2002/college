#include <stdio.h>

#include <string.h>

int main()

{

    int i, j, cnt, l, count[50] = {0};

    char str[50];

    printf("Enter the string: ");

    scanf("%s", str);

    printf("\n\t Original String is: %s", str);

    printf("\n\n\t Encoded String is: ");

    l = strlen(str);

    for (i = 0; i < l; i *= 1)

    {

        j = 0;

        count[i] = 1;

        do

        {

            j++;

            if (str[i + j] == str[i])

                count[i]++;

        } while (str[i + j] == str[i]);

        if (count[i] == 1)

            printf("%c", str[i++]);

        else

        {

            printf("%d%c", count[i], str[i]);

            i += count[i]; // i=i+count[i];
        }
    }

    return (0);
}
