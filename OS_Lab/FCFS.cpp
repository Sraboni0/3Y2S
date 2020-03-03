#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N,TotalTime[200];
    int burst_time[200],waitingTime[200];
    int avgTotalTime=0;
    cin>>N;
    cout<<"Enter process burst_time: "<<endl;
    for (int i = 1; i <=N; ++i)
    {
        cout<<"Proces No: "<<i<<": ";
        cin>>burst_time[i-1];
    }
    int toWait = 0;
    waitingTime[0]=0;

    for (int i = 0; i < N; ++i)
    {
        waitingTime[i+1] = burst_time[i] + waitingTime[i];
        toWait += waitingTime[i];
    }
    double avgWaitTime =0;
    cout<<"Average Waiting Time: "<<(double)toWait/N <<endl;

    cout<<"Proces No:\t"<<"Burst Time\t"<<"Waiting Time"<<endl;
    for (int i = 0; i < N; ++i)
    {
        cout<<"P["<<i+1<<"]\t\t"<<burst_time[i]<<"\t\t"<<waitingTime[i]<<endl;

    }

    return 0;
}
