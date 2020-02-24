#include <stdio.h>

int main()
{
    int n;
    printf("Enter your number: ");
    scanf("%d", &n);

    int A[159], length=1,j=0,i=0,c=0,r;
    A[0]=1;
    for(i=n;i>=2;--i)
    {
        while(j<=(length-1))
        {
            if(j==(length-1))
            {
                r=i*A[j]+c;

                if((r/100) >= 1)
                    length+=2;
                else if((r/10) >= 1)
                    length++;

                while(r!=0)
                {
                    A[j++]=r%10;
                    r/=10;
                }
            }

            else
            {
                r=i*A[j]+c;
                A[j++]=r%10;
                c=r/10;
            }
        }
        j=0;
        c=0;
    }

    //Printing the answer.
    for(i=length-1;i>=0;--i)
        printf("%d",A[i]);

    return 0;
}
