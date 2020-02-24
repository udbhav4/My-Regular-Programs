#include<stdio.h>

int main()
{
    int n,i,j,k, A[10], B[20][20];
    printf("Enter the number of numbers you want to enter: ");
    scanf("%d", &n);

    for(i=0;i<n;++i)
    {
        printf("Enter number %d: ", (i+1));
        scanf("%d", &A[i]);
    }

    // Making pattern
    for(k=0;k<n;++k)
    {
        for(i=k;i<(2*n-1)-k;++i)
        {
            for(j=k;j<(2*n-1)-k;++j)
            {
                B[i][j]=A[n-k-1];
            }
        }
    }

    // Printing pattern
    for(i=0;i<2*n-1;++i)
    {
        for(j=0;j<2*n-1;++j)
        {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }

    return 0;
}
