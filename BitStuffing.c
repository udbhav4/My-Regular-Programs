#include<stdio.h>

char A[1000];
int l=0;

void convert()
{
    int i=0, c=0;
    for(i=0;i<l;++i)
    {
        if(A[i]==49)
        {
            ++c;
            if(c==6)
            {
                A[i]=48;
                c=0;
            }
        }

        else
            c=0;
    }
}

int main()
{
    printf("Enter your bit message: ");
    scanf("%s", &A);
    printf("\nYour bit-stuffed answer is: \n");
    int i=0;
    l=sizeof(A)/sizeof(A[0]);
    convert();
    for(i=0;i<l;++i)
    {
        printf("%c", A[i]);
    }
    printf("\n");

    return 0;
}
