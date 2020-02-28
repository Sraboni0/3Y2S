#include<stdio.h>
#include<conio.h>
int main()
{
 int bursttime[100],waitingtime[100],turnaroundtime[100],b[100];
 int i,n,time,count=0;
 float totalwt=0,totalTT=0,avgwt,avgtt;

    printf("Enter total number of process : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\nEnter the burst time of %d process : ",i+1);
        scanf("%d",&bursttime[i]);
        b[i] = bursttime[i];
    }
    i=0;

    for(time=0;count!=n;time++)
    {
        while(bursttime[i] == 0)
        {
            i=(i+1)%n;
        }
    bursttime[i]--;
    if(bursttime[i]==0)
    {
        turnaroundtime[i] = time+1;
        count++;
    }
         i = (i+1)%n;
    }
 printf("\nprocess   burst   waitng   turnaround   ");
 for(i=0;i<n;i++)
 {  waitingtime[i] = turnaroundtime[i] - b[i];
    printf("\n   %d \t    %d \t     %d \t    %d",i+1,b[i],waitingtime[i],turnaroundtime[i]);
    totalwt = totalwt + waitingtime[i];
    totalTT = totalTT + turnaroundtime[i];
 }
 printf("\n  %d  %f  %f",n,totalwt,totalTT);
 avgwt = totalwt / n;
 avgtt = totalTT / n;
 printf("\nAverage waiting time is %f",avgwt);
 printf("\nAverage turnaround time is %f ",avgtt);
    
    return 0;
}