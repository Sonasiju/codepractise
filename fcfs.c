
#include<stdio.h>
struct process{
    int pid;
    int at;
    int bt;
    int tat;
    int ct;
    int wt;
};
void sort(struct process p[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
        if(p[j].at<p[i].at)
        {
            struct process temp = p[i];
            p[i]=p[j];
            p[j]=temp;
        }
        
    }
        
    }
}


int main()
{
   printf("\nFirst Come FIrst Served\n");
 printf("ENter the number of processes");
   int n;
  
    scanf("%d",&n);
       struct process p[n];
     
    
   int currenttime=0;
  float avg_tat=0,avg_wt=0;
   
   printf("Enter the arrival time and burst time for each process\n");
   for(int i=0;i<n;i++)
   {
       
    printf("\nFor P%d enter AT:",i+1);
    p[i].pid=i+1;
        scanf("%d",&p[i].at);
    printf("\nEnter Burst Time");
    scanf("%d",&p[i].bt);
   }
 
    sort(p,n);
    
  
   for(int i=0;i<n;i++)
   {
       p[i].ct = currenttime + p[i].bt ;
       p[i].tat=p[i].ct - p[i].at;
       p[i].wt = p[i].tat - p[i].bt;
       currenttime=p[i].ct;
       avg_tat+=p[i].tat;
       avg_wt+=p[i].wt;
   }
   avg_tat/=n;
   avg_wt/=n;
   printf("\nProcess\tArrival Time\tBurst Time\tCompletion Time\tTurn Around Time\tWaiting Time\n");
   for(int i=0;i<n;i++)
   {
       printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
       
   }
   printf("\nAverage Turn Around Time: %.2f",avg_tat);
   printf("\nAverage Waitng Timw: %.2f",avg_wt);
}

