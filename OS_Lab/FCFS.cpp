#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N,burst_time[200],waitingTime[200],tat[200],avgWaitingTime=0,avtat=0,i,j;
    printf("Enter total number of processes:");
    scanf("%d",&N);

    printf("\nEnter Process Burst Time\n");
    for(i=0;i<N;i++)
    {
        printf("Process No: [%d]:",i+1);
        scanf("%d",&burst_time[i]);
    }

    int toWait = 0;
    waitingTime[0] = 0;

    for (int i = 0; i < N; i++)
    {
        waitingTime[i+1] = burst_time[i]+waitingTime[i];
        toWait +=waitingTime[i];
        cout<<"Waiting Time: "<<waitingTime[i]<<endl;

    }

    cout<<"Average Waiting Time: "<<toWait/N<<endl;

    cout<<"Process No :\t"<<"BurstTime\t"<<"waitingTime"<<endl;
    for (int i = 0; i < N; i++)
    {
        cout<<"P["<<i+1<<"] \t\t"<<burst_time[i]<<"\t\t"<<waitingTime[i]<<endl;
    }

    return 0;
}
