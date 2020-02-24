#include<stdio.h>
#include<string.h>

char A[100];
int f;

void input()
{
    printf("Enter your bit message: ");
    scanf("%s", &A);
    printf("Enter the number of frames for the message: ");
    scanf("%d", &f);
}

void checksum()
{
    int l=strlen(A);
    int M[l];
    int i=0,j=0;
    for(i=0;i<l;++i)
        M[i]=A[i]-48;

    //Filling message in frames in a 2D array.
    int fsize=l/f;
    int C[f][fsize];
    int k=0;
    for(i=0;i<f;++i)
    {
        for(j=0;j<fsize;++j)
        {
            C[i][j]=M[k++];
        }
    }

    //Calculation begins.
    int add[fsize+1];
    for(i=fsize-1;i>=0;--i)
        add[i+1]=C[0][i];

    int carry=0;
    for(k=1;k<f;++k)
    {
        for(i=fsize-1;i>=0;--i)
        {
            int r=add[i+1]+C[k][i]+carry;

            if(r==2)
            {
                add[i+1]=0;
                carry=1;
            }
            else if(r==3)
            {
                add[i+1]=1;
                carry=1;
            }
            else
            {
                add[i+1]=r;
                carry=0;
            }
        }

        add[0]=carry;
        if(add[0]==1)
        {
            int x=0;
            for(x=fsize;x>=1;--x)
            {
                int r=add[x]+carry;

                if(r==2)
                {
                    add[x]=0;
                    carry=1;
                }
                else if(r==3)
                {
                    add[x]=1;
                    carry=1;
                }
                else
                {
                    add[x]=r;
                    carry=0;
                }
            }
        }
        carry=0;
    }

    //Complementing checksum.
    for(i=fsize;i>=1;--i)
    {
        if(add[i]==1)
            add[0];
        else
            add[1];
    }

    display(add,fsize);
}

void display(int add[], int fsize)
{
    int i=0;
    printf("\nThe checksum is: ");
    for(i=1;i<=fsize;++i)
        printf("%d",add[i]);
}

int main()
{
    input();
    checksum();
    return 0;
}
