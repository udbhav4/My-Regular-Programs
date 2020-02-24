#include<stdio.h>

int main()
{
    printf("Enter the size of your array: ");
    int n=0;
    scanf("%d", &n);
    int i=0, A[n], B[n];
    for(int i=0;i<n;++i)
    {
        printf("Enter number %d: ",(i+1));
        scanf("%d", &A[i]);
    }

    int k=0,c=0,product=1;;
    for(i=0;i<=n;++i)
    {
        if(i==n)
        {
            B[k]=product;
            product=1;
            i=0;
            ++c;
            ++k;
            if(c==n)
                break;
        }
        if(i!=k)
            product*=A[i];
    }

    printf("\n");
    for(i=0;i<n;++i)
        printf("%d ", B[i]);

    return 0;
}
