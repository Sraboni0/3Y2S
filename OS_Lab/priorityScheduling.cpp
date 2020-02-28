#include<bits/stdc++.h>
using namespace std;

bool sortbysec(const pair<int,int> &a,const pair<int,int> &b)
{
	return (a.second > b.second);
}

int main()
{
    vector<pair<int ,int > >pr;

    int burst_time[20],priority[200],p[20],wt[20],tat[20],i,j,n,total=0,pos,temp;
    float avg_wt,avg_tat;
    printf("Enter number of process:");
    scanf("%d",&n);

    printf("\nEnter Burst Time and Priority\n");
    for(i=0;i<n;i++)
    {
        printf("Process: %d:",i+1);
        scanf("%d %d",&burst_time[i],&priority[i]);
        pr.push_back(make_pair(i+1,priority[i]));
        p[i]=i+1;
    }
    sort(pr.begin(),pr.end(),sortbysec);

    for (int i = 0; i< pr.size(); i++)
    {
        cout<<pr[i].first<<" "<<burst_time[i]<<" "<<pr[i].second<<endl;
    }


    return 0;
}
