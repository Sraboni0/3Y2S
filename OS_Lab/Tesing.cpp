#include<bits/stdc++.h>
using namespace std;

bool sortbySec(const pair<int,int>&a,const pair<int,int>&b)
{
    return (a.second<b.second);
}
int main()
{
    vector< pair<int,int> > pr;

    int burst_time[20],priority[20],p[20];
    int wt[20],tat[20],i,j,N,total=0,pos,temp;
    float avg_wt=0,avg_tat=0;

    cout<<"Enter Number of Process: ";
    cin>>N;

    cout<<"\t Burst_time \t priority"<<endl;
    for (int i = 0; i < N; ++i)
    {
        cout<<"Process "<<i+1<<": ";
        cin>>burst_time[i]>>priority[i];
        pr.push_back(make_pair(i,priority[i]));
        //p[i] = i+1;
    }

    sort(pr.begin(),pr.end(),sortbySec);

    for (int i = 0; i < pr.size(); ++i)
    {
        int tmp = pr[i].first;
        cout<<pr[i].first<<" "<<burst_time[tmp]<<" "<<pr[i].second<<endl;

    }
    wt[pr[0].first]=0;
    tat[pr[0].first] = burst_time[pr[0].first];

    for (int i = 1; i < N; ++i)
    {
        int tmp =pr[i-1].first;
        int tmp2 = pr[i].first;

        wt[tmp2] =wt[tmp] + burst_time[tmp];
        //cout<<"Tmp: "<<tmp<<" Waiting: "<<wt[tmp]<<endl;
        total +=wt[tmp];
        tat[tmp2] = wt[tmp2]+burst_time[tmp2];
    }

     cout<<"Process \t   burst_time \t Waiting Time \t Turnaround"<<endl;
     for (int i = 0; i < N; ++i)
     {
         int tmp =pr[i].first;
         cout<<"P["<<tmp+1<<"]\t\t"<<" "<<burst_time[tmp]<<"\t\t"<<wt[tmp]<<"\t\t"<<tat[tmp]<<endl;
     }

    return 0;
}
