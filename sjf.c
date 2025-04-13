#include<stdio.h>
struct process
{
    int pid,at,tat,bt,ct,wt;
};
void sort_bt(struct process p[],int n)
{
    struct process temp;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(p[i].bt>p[j].bt)
            {
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }
}
int main()
{
    int current_time=0;
    float avg_tat=0,avg_wt=0;
  printf("Enter the number of process");
    int n;
    scanf("%d",&n);
    struct process p[n];
    printf("Enter arrival time and Burst Time");
    for(int i=0;i<n;i++)
    {
        p[i].pid=i+1;
        printf("For P%d",p[i].pid);
         p[i].at=0;
        printf("Burst Time");
        scanf("%d",&p[i].bt);
    }
    sort_bt(p,n);
    for(int i=0;i<n;i++)
    {
        p[i].ct=current_time+p[i].bt;
        p[i].tat=p[i].ct-p[i].at;
        p[i].wt=p[i].tat-p[i].bt;
        current_time=p[i].ct;
        avg_tat+=p[i].tat;
        avg_wt+=p[i].wt;
    }
    avg_tat/=n;
    avg_wt/=n;
    printf("\nProcess\tArrival Time\tBurst Time\tCompletition Time\tTurn Around Time\tWaiting Time\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
    }
    printf("Average Turn Around Time: %.2f",avg_tat);
    printf("Average Waiting Time: %.2f",avg_wt);
    
}
