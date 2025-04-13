#include<stdio.h>
struct process {
    int pid;
    int at,tat,wt,ct,bt;
};
void roundRobin(struct process p[],int n,int tq)
{
    float avg_tat=0,avg_wt=0;
    int rem_bt[n];
    int remaining=n;
    int current_time=0;
    int completed=0;
    for(int i=0;i<n;i++)
    {
        rem_bt[i]=p[i].bt;
    }
  while(remaining>0)
    {
      for(int i=0;i<n;i++)
        {
            if(rem_bt[i]>0)
            {
                printf("%d -> P%d |\t",current_time,i+1);
        
            if(rem_bt[i]<=tq )
            {
                 
                p[i].ct=current_time + rem_bt[i];
                rem_bt[i]=0;
                remaining--;
                current_time=p[i].ct;
                completed=1;
                
            }
            else
            {
                
               rem_bt[i]-=tq;
               current_time +=tq;
                
            }}
        }
    }
    for(int i=0;i<n;i++)
    {
        p[i].tat=p[i].ct-p[i].at;
        p[i].wt=p[i].tat-p[i].bt;
        avg_tat+=p[i].tat;
        avg_wt+=p[i].wt;
    }
    avg_tat/=n;
    avg_wt/=n;
    printf("\nProcess\tArrival Time\tBurst Time\tCompletion Time\tTurn Around Time\tWaiting Time\n");
    
    for(int i=0;i<n;i++)
    {
    printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
    }
    printf("Average Turn Around Time :%.2f",avg_tat);
    printf("Average Waiting Time: %.2f",avg_wt);
    
    

}
int main()
{
    int tq;
    printf("\nRound Robin Scheduling\n");
    printf("Enter the number of process");
    int n;
 scanf("%d",&n);
   struct process p[n];
    printf("\nENter Arrival Time And Burst Time for each process\n");
    for(int i=0;i<n;i++)
    {
        p[i].pid=i+1;
        printf("\nFor P%d, Arrival Time:",p[i].pid);
        scanf("%d",&p[i].at);
        printf("\nEnter Burst Time");
        scanf("%d",&p[i].bt);
        
    }
    printf("\nEnter Time Quantum");
    scanf("%d",&tq);
    roundRobin(p,n,tq);
    
}