#include <stdio.h>

struct poly
{
    int coeff;
    int expo;
};

int mult(poly p1[10], poly p2[10], poly p3[10], int n1, int n2);

int main()
{
    poly p1[10], p2[10], p3[10];
    int n1, n2, n3, i;

    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &n1);

    printf("Enter the coefficients and exponents for the first polynomial:\n");
    for (i = 0; i < n1; i++)
    {
        printf("Coefficient %d: ", i + 1);
        scanf("%d", &p1[i].coeff);
        printf("Exponent %d: ", i + 1);
        scanf("%d", &p1[i].expo);
    }

    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d", &n2);

    printf("Enter the coefficients and exponents for the second polynomial:\n");
    for (i = 0; i < n2; i++)
    {
        printf("Coefficient %d: ", i + 1);
        scanf("%d", &p2[i].coeff);
        printf("Exponent %d: ", i + 1);
        scanf("%d", &p2[i].expo);
    }

    n3 = mult(p1, p2, p3, n1, n2);

    printf("\nResultant polynomial after multiplication:\n");
    for (i = 0; i < n3; i++)
    {
        printf("%dx^%d", p3[i].coeff, p3[i].expo);
        if (i < n3 - 1)
            printf(" + ");
    }

    return 0;
}

int mult(poly p1[10], poly p2[10], poly p3[10], int n1, int n2)
{
    int i, j, k, next3, flag;
    int ex, co;
    i = next3 = 0;
    while (i < n1)
    {
        j = 0;
        while (j < n2)
        {
            ex = p1[i].expo + p2[j].expo;
            co = p1[i].coeff * p2[j].coeff;
            k = flag = 0;
            while (k < next3 && !flag)
            {
                if (p3[k].expo == ex)
                {
                    flag = 1;
                    break;
                }
                else
                    k++;
            }
            if (flag == 1)
                p3[k].coeff = p3[k].coeff + co;
            else
            {
                p3[next3].expo = ex;
                p3[next3].coeff = co;
                next3++;
            }
            j++;
        }
        i++;
    }
    return next3;
}
