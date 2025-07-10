#include<stdio.h>

struct process{
    int pid;
    int at;
    int bt;
    int priority;
    int ct;
    int tat;
    int wt;
    int visited;
}p[20];

void main(){
    int i,j,n,time,count,min;
    printf("Enter the number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
            printf("\nEnter process id,at,bt: ");
            scanf("%d%d%d",&p[i].pid,&p[i].at,&p[i].bt);
            p[i].visited=0;
            printf("Enter the priority: ");
            scanf("%d",&p[i].priority);
    }
    time=0;
    count=0;
    while(count<n){
        min=-1;
        for(i=0;i<n;i++){
            if(p[i].at<=time && p[i].visited==0){
                if(min==-1 || p[i].priority<p[min].priority){
                    min=i;
                }
            }
        }
        if(min==-1){
            time++;
        }else{
            printf("%d ->>>>>>>>>> ",time);
            time=time+p[min].bt;
            printf("%d ->p%d\n",time,p[min].pid);
            p[min].ct=time;
            p[min].tat=p[min].ct-p[min].at;
            p[min].wt=p[min].tat-p[min].bt;
            p[min].visited=1;
            count++;
        }

    }
    printf("pid\tat\tbt\tprio\tct\ttat\twt\n");
    printf("------------------------------------------------------------------------------------\n");
    for(i=0;i<n;i++){
        printf("p%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].priority,p[i].ct,p[i].tat,p[i].wt);
        printf("------------------------------------------------------------------------------------\n");
    }
}

