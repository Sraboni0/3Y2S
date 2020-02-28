#include<bits/stdc++.h>
using namespace std;

int main()
{
    int burst_time[20],p[20],wt[20],tat[20],i,j,n,total=0,pos,temp;
    float avg_wt,avg_tat;
    printf("Enter number of process:");
    scanf("%d",&n);

    printf("\nEnter Burst Time:\n");
    for(i=0;i<n;i++)
    {
        printf("Process: %d:",i+1);
        scanf("%d",&burst_time[i]);
        p[i]=i+1;
    }

    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(burst_time[j]<burst_time[pos])
                pos=j;
        }
        cout<<"Sortest Burst Time of position: "<<pos<<endl;

        swap(burst_time[i],burst_time[pos]);
        swap(p[i],p[pos]);
    }

    wt[0]=0;
    for(i=0;i<n;i++)
    {
        wt[i+1]=burst_time[i]+wt[i];
        total+=wt[i];
    }

    avg_wt=(float)total/n;

    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        tat[i]=burst_time[i]+wt[i];
        total+=tat[i];
        printf("\nProcess: %d\t\t  %d\t\t    %d\t\t\t%d",p[i],burst_time[i],wt[i],tat[i]);
    }

    avg_tat=(float)total/n;
    printf("\n\nAverage Waiting Time=%f",avg_wt);
    printf("\nAverage Turnaround Time=%f\n",avg_tat);

    return 0;
}
