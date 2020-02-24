#include<stdio.h>
#include<string.h>

char A[1000];
int l=0;

void destuffing()
{
    int i,c=0;
    for(i=0;i<l;++i)
    {
        if(A[i]==49)
        {
            ++c;
            if(c==5 && A[i+1]==48)
            {
                shift(i+1);
                c=0;
            }
        }
        else
            c=0;
    }
}

void shift(int k)
{
    int i=0;
    for(i=k;i<l;++i)
        A[i]=A[i+1];
    --l;
}

int main()
{
    printf("Enter your bit-stuffed message: ");
    scanf("%s", &A);
    l=strlen(A);
    printf("\nYour de-stuffed answer is: ");
    destuffing();
    int i;
    for(i=0;i<l;++i)
        printf("%c", A[i]);
    printf("\n");

    return 0;
}
