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

    for (int i = 0; i <n; ++i)
    {
        pos = i;
        for (int j = i+1; j < n; ++j)
        {
            if(burst_time[j]<burst_time[pos])
                pos=j;
        }
        swap(burst_time[pos],burst_time[i]);
        swap(p[i],p[pos]);
    }

    wt[0] = 0;
    for (int i = 0; i < n; ++i)
    {
        wt[i+1] = wt[i]+burst_time[i];
        total +=wt[i];
    }
    avg_wt=(float)total/n;
    total=0;

    cout<<"Process \t   burst_time \t Waiting Time \t Turnaround"<<endl;
    for (int i = 0; i < n; ++i)
    {
        tat[i] = burst_time[i] +wt[i];
        total+=tat[i];
        cout<<"process: "<<p[i]<<"\t \t"<<burst_time[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i]<<endl;
    }
    printf("\n\nAverage Waiting Time=%f",avg_wt);
    printf("\nAverage Turnaround Time=%f\n",avg_tat);
    avg_tat = (float)total/n;

    return 0;
}
