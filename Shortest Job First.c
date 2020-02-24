#include<stdio.h>

int main()
{
    int P[20], B[20], n=0;

    //Taking input
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    printf("\n");
    int i=0;
    for(i=0;i<n;++i)
    {
        printf("Enter burst time for process %d: ",(i+1));
        scanf("%d",&B[i]);
        P[i]=i+1;
    }


    //Sorting
    int j=0;
    for(i=0;i<n-1;++i)
    {
        for(j=0;j<i-n-1;++j)
        {
            if(B[j]>B[j+1])
            {
                //Sorting burst time
                int t=B[j];
                B[j]=B[j+1];
                B[j+1]=t;

                //Sorting process number according to burst time
                t=P[j];
                P[j]=P[j+1];
                P[j+1]=t;
            }
        }
    }


    //Calculating waiting time
    int W[20];
    W[0]=0;
    for(i=1;i<n;++i)
    {
        W[i]=W[i-1]+B[i-1];
    }


    //Putting processes in original order
    for(i=0;i<n-1;++i)
    {
        for(j=0;j<i-n-1;++j)
        {
            if(P[j]>P[j+1])
            {
                //Sorting process number
                int t=P[j];
                P[j]=P[j+1];
                P[j+1]=t;

                //Sorting waiting time according to process number
                t=W[j];
                W[j]=W[j+1];
                W[j+1]=t;
            }
        }
    }


    //Printing waiting time for each process
    for(i=0;i<n;++i)
    {
        printf("Waiting time for process %d: %d \n",(i+1),W[i]);
    }

    return 0;
}
