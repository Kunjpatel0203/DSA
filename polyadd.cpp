#include <stdio.h>

struct poly
{
    int coeff;
    int expo;
};

//int add(poly p1[10], poly p2[10], poly p3[10], int t1, int t2);



int add(poly p1[10], poly p2[10], poly p3[10], int t1, int t2)
{
    int i, j, k;
    int t3;
    i = j = k = 0;
    while (i < t1 && j < t2)
    {
        if (p1[i].expo == p2[j].expo)
        {
            p3[k].coeff = p1[i].coeff + p2[j].coeff;
            p3[k].expo = p1[i].expo;
            i++;
            j++;
            k++;
        }
        else if (p1[i].expo > p2[j].expo)
        {
            p3[k].coeff = p1[i].coeff;
            p3[k].expo = p1[i].expo;
            i++;
            k++;
        }
        else
        {
            p3[k].coeff = p2[j].coeff;
            p3[k].expo = p2[j].expo;
            j++;
            k++;
        }
    }
    while (i < t1)
    {
        p3[k].coeff = p1[i].coeff;
        p3[k].expo = p1[i].expo;
        i++;
        k++;
    }
    while (j < t2)
    {
        p3[k].coeff = p2[j].coeff;
        p3[k].expo = p2[j].expo;
        j++;
        k++;
    }
    t3 = k;
    return t3;
}


int main()
{
    poly p1[10], p2[10], p3[10];
    int t1, t2, t3, i;

    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &t1);

    printf("Enter the coefficients and exponents for the first polynomial:\n");
    for (i = 0; i < t1; i++)
    {
        printf("Coefficient %d: ", i + 1);
        scanf("%d", &p1[i].coeff);
        printf("Exponent %d: ", i + 1);
        scanf("%d", &p1[i].expo);
    }

    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d", &t2);

    printf("Enter the coefficients and exponents for the second polynomial:\n");
    for (i = 0; i < t2; i++)
    {
        printf("Coefficient %d: ", i + 1);
        scanf("%d", &p2[i].coeff);
        printf("Exponent %d: ", i + 1);
        scanf("%d", &p2[i].expo);
    }

    t3 = add(p1, p2, p3, t1, t2);

    printf("\nResultant polynomial after addition:\n");
    for (i = 0; i < t3; i++)
    {
        printf("%dx^%d", p3[i].coeff, p3[i].expo);
        if (i < t3 - 1)
            printf(" + ");
    }

    return 0;
}

