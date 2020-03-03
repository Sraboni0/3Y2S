#include<bits/stdc++.h>
using namespace std;
int main()
{
    int bursttime[100],waitingtime[100],turnaroundtime[100],b[100];
    int i,n,time,count=0;
    float totalwt=0,totalTT=0,avgwt,avgtt;
    int timeSlice=2;
    bool flag[100];

    printf("Enter total number of process : ");
    scanf("%d",&n);

    printf("\nEnter the burst time.");
    for(i=0;i<n;i++)
    {
        scanf("%d",&bursttime[i]);
        b[i] = bursttime[i];
    }
    int index =0;

    for (int i = 0; i < n; ++i) {
            turnaroundtime[i]=0;
            flag[i]=false;
    }

    int cnt=0;
    for (int time = 0; count !=n; ++time)
     {


        if(bursttime[index] -timeSlice<0)
        {
            cnt+= bursttime[index];
            bursttime[index]=0;
        }
        else if( bursttime[index] == 0  )
        {
            if(!flag[index])
            {
                flag[index] = true;
                count++;
               turnaroundtime[index] = cnt;
               bursttime[index]=0;
            }

        }
        else{
            bursttime[index] -= timeSlice;
            cnt+=timeSlice;
        }

        cout<<"Turn : "<<turnaroundtime[index]<<endl;
        index = (index+1)%n;
     }

     printf("Process BurstTime WaitingTime Turnaroundtime\n");
     for (int i = 0; i < n; ++i)
     {
         waitingtime[i] = turnaroundtime[i] - b[i];
         printf("\n   %d \t    %d \t     %d \t    %d",i+1,b[i],waitingtime[i],turnaroundtime[i]);
        totalwt = totalwt + waitingtime[i];
        totalTT = totalTT + turnaroundtime[i];
     }
    return 0;
}
