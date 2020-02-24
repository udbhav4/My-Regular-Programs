#include<stdio.h>

int B[20], C[20], n, tq;

void input()
{
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("\n\n");

    // Taking input of the burst time
    int i;
    for(i=0;i<n;++i)
    {
        printf("Enter burst time for process %d: ", (i+1));
        scanf("%d", &B[i]);
    }
    printf("\n");

    // Taking input of time quantum
    printf("Enter the time quantum: ");
    scanf("%d", &tq);
    printf("\n\n");
}

void round_robin()
{
    int i=0;
    int c=0;    // counter for total time lapsed at any given moment.
    int k=-1;    // counter that fills the array for completion time.
    while(k!=n-1)
    {
        if(i==n)
            i=0;

        if(B[i]==0)
            ++i;

        else if(B[i]<=tq)
        {
            c+=B[i];
            B[i]=0;
            C[++k]=c;
            ++i;
        }

        else
        {
            c+=tq;
            B[i]-=tq;
            ++i;
        }
    }
}

void display()
{
    printf("\nCompletion time for all the processes are as follows: \n\n");
    int i;
    for(i=0;i<n;++i)
        printf("Completion time for process %d is: %d\n", (i+1), C[i]);
}

int main()
{
    input();
    round_robin();
    display();
    return 0;
}
