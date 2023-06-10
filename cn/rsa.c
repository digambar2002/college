#include <stdio.h>

#include <math.h>

int main()

{

    int p, q, n, phi, d, e, i, j, CT, PT;

    printf("\nEnter First Prime no");

    scanf("%d", &p);

    printf("\nEnter Second Prime no");

    scanf("%d", &q);

    n = p * q;

    phi = (p - 1) * (q - 1);

    printf("\nchose e such that it is relatively prime to\t %d", phi);

    scanf("%d", &e);

    for (d = 1; d < phi; d++)

    {

        if (((d * e) % phi) == 1)

            break;
    }

    printf("\n Enter the plain text char");

    scanf("%d", &PT);

    CT = 1;

    for (i = 0; i < e; i++)

        CT = CT * PT % n;

    printf("\n After Encryption %d", CT);

    PT = 1;

    for (i = 0; i < d; i++)

        PT = PT * CT % n;

    printf("\nAfter Decreption %d\n", PT);

    return 0;
}