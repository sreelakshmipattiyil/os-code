#include<stdio.h>
#include<string.h>
struct process
{
    int at;
    int bt;
    int ct;
    int st;
    int tat;
    int wt;
    int pr;
    char name[10];
} p[20],idle[20],temp;
int main()
{
    int n,check[20];
    float tat=0,wt=0;
    printf("Enter the no of process");
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        printf("Enter the process name");
        scanf("%s",p[i].name);
        printf("Enter the arrival time");
        scanf("%d",&p[i].at);
        printf("Enter the burst time");
        scanf("%d",&p[i].bt);
        printf("Enter the priority");
        scanf("%d",&p[i].pr);
    }
    int current_time=0;
    int completed=0;
    int index=0;
    while(completed!=n)
    {
        int loc=-1;
        int min=10000;
        for(int i=0; i<n; i++)
        {
            if(p[i].at<=current_time && check[i]!=1)
            {
                if(p[i].pr<min)
                {
                    min=p[i].pr;
                    loc=i;
                }
            }
            if(p[i].pr==min)
            {
                if(p[i].at<p[loc].at)
                {
                    min=p[i].pr;
                    loc=i;
                }
            }
        }
        if(loc!=-1)
        {
            p[loc].st=current_time;
            p[loc].ct=p[loc].st+p[loc].bt;
            p[loc].tat=p[loc].ct-p[loc].at;
            p[loc].wt=p[loc].tat-p[loc].bt;
            current_time=p[loc].ct;
            check[loc]=1;
            completed++;
            idle[index]=p[loc];
            index++;
        }
        else
            current_time++;
    }
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(p[j].at>p[j+1].at)
            {
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
    for(int i=0; i<n; i++)
    {
        tat+=p[i].tat;
        wt+=p[i].wt;
    }
    printf("\n");
    printf("process\tPR\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i=0; i<n; i++)
        printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i].name,p[i].pr,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
    printf("\n");
    printf("Gantt chart\n");
    for(int i=0; i<n; i++)
    {
        if(idle[i].st>idle[i-1].ct)
        {
            printf("|\tidle\t");
            printf("|\t%s\t",idle[i].name);
        }
        else
            printf("|\t%s\t",idle[i].name);
        if(i==n-1)
            printf("|");
    }
    printf("\n");
    printf("0\t\t");
    for(int i=0; i<n; i++)
    {
        if(idle[i].st>idle[i-1].ct)
            printf("%d\t\t%d\t\t",idle[i].st,idle[i].ct);
        else
            printf("%d\t\t",idle[i].ct);
    }
    printf("\n\nAverage turnaround time=%.2f",tat/n);
    printf("\nAverage waiting time=%.2f",wt/n);
}
/*
			OUTPUT

Enter the no of process3
Enter the process namep1
Enter the arrival time0
Enter the burst time2
Enter the priority1
Enter the process namep2
Enter the arrival time2
Enter the burst time3
Enter the priority4
Enter the process namep3
Enter the arrival time2
Enter the burst time1
Enter the priority2

process PR      AT      BT      CT      TAT     WT
p1      1       0       2       2       2       0
p2      4       2       3       6       4       1
p3      2       2       1       3       1       0

Gantt chart
|       p1      |       p3      |       p2      |
0               2               3               6

Average turnaround time=2.33
Average waiting time=0.33
*/
