#include<stdio.h>

int A[200000];

int* func(int* scores, int* alice, int alice_count, int scores_count)
{
    int i=0;

    //Finding rank of Alice initially.
    int r=1;
    for(i=1;i<scores_count;++i)
    {
        if(*(scores+i) < *(scores+i-1))
            ++r;
    }
    ++r;

    //Calculating rank of Alice.
    int c=scores_count-1;
    for(i=0;i<alice_count;i++)
    {
        while( (*(scores+c) <= *(alice+i)) && c>-1)
        {
            --r;
            --c;
            while( (*(scores+c) == *(scores+c+1)) && c>-1)
                --c;
        }
        A[i]=r;

        if(c<0)
            break;
    }

    for(;i<alice_count;++i)
        A[i]=r;

    return A;
}

int main()
{
    int i=0;
    int scores_count, alice_count;
    int scores[200000], alice[200000];
    int* p;

    scanf("%d", &scores_count);
    for(i=0;i<scores_count;++i)
    {
        scanf("%d", &(*(scores+i)));
    }

    scanf("%d", &alice_count);
    for(i=0;i<alice_count;i++)
    {
        scanf("%d", &(*(alice+i)));
    }

    p=func(scores,alice,alice_count,scores_count);

    for(i=0;i<alice_count;++i)
    {
        printf("%d\n", *(p+i));
    }

    return 0;
}
