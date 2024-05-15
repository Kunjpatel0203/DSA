#include <stdio.h>

struct poly
{
    int coeff;
    int expo;
};

int multiply(poly p1[10], poly p2[10], poly p3[10], int n1, int n2)
{
    int i, j, k;
    for (i = 0; i < n1; i++)
    {
        for (j = 0; j < n2; j++)
        {
            k = p1[i].expo + p2[j].expo;
            p3[k].coeff += p1[i].coeff * p2[j].coeff;
            p3[k].expo = k;
        }
    }
}

int main()
{
    poly p1[10], p2[10], p3[20]; // Resultant polynomial can have maximum 20 terms
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

    // Initialize p3 with zeros
    for (i = 0; i < 20; i++)
    {
        p3[i].coeff = 0;
        p3[i].expo = 0;
    }
 n3 = multiply(p1, p2, p3, n1, n2);

    printf("\nResultant polynomial after addition:\n");
    for (i = 0; i < n3; i++)
    {
        printf("%dx^%d", p3[i].coeff, p3[i].expo);
        if (i < n3 - 1)
            printf(" + "); 
    }
    

    return 0;
}
