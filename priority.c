#include<stdio.h>
struct process{
    int pid,at,bt,ct,tat,wt,pr;
};
void sort(struct process p[],int n)
{
    struct process temp;
   for(int i=0;i<n;i++)
   {
       for(int j=i+1;j<n;j++)
       {
           if(p[i].pr>p[j].pr)
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
    printf("\nPriority Schedule\n");
    printf("Enter the numberof process");
    int n;
    scanf("%d",&n);
    struct process p[n];
  
        printf("\nEnter the Arrival TIme and Burst time and priority for each process");
        for(int i=0;i<n;i++)
        {
            p[i].pid=i+1;
            printf("\nEnter arrival Time");
            scanf("%d",&p[i].at);
            printf("\nBurst time");
            scanf("%d",&p[i].bt);
            printf("Priority");
            scanf("%d",&p[i].pr);
            
            
        }
     sort(p,n);
    for(int i=0;i<n;i++)
    {
        p[i].ct= current_time+p[i].bt;
        p[i].tat=p[i].ct-p[i].at;
        p[i].wt=p[i].tat-p[i].bt;
        current_time=p[i].ct;
        avg_tat+=p[i].tat;
        avg_wt+=p[i].wt;
    }
    avg_tat/=n;
    avg_wt/=n;

        printf("Process\tArrival Time\tBurst Time\tPriority\tCompletion Time\tTurn Around Time\tWaiting Time\n");
        for(int i=0;i<n;i++)
   {
       printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\n",p[i].pid,p[i].at,p[i].bt,p[i].pr,p[i].ct,p[i].tat,p[i].wt);
       
   }
   printf("\nAverage Turn Around Time: %.2f",avg_tat);
   printf("\nAverage Waitng Timw: %.2f",avg_wt);
}
        
    
