#include<stdio.h>

struct process{
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
    int visited;
    int remaining;
}p[20];

int front=-1,rear=-1,queue[20];

void push( int i){
    if(front==-1 && rear==-1){
        front=0;
    }
    queue[++rear]=i;
}
int pop(){
    if(front==-1 || front>rear){
        return -1;
    }else{
        int elem=queue[front++];
        if(front>rear){
            front=rear=-1;
        }
        return elem;
    }
}

void main(){
    int i,j,k,time,count,n,z=0,elem,qua;
    printf("Enter the number of process: ");
    scanf("%d",&n);
    printf("Enter the time quantum: ");
    scanf("%d",&qua);
    for(i=0;i<n;i++){
        printf("Enter the pid,at,bt: ");
        scanf("%d%d%d",&p[i].pid,&p[i].at,&p[i].bt);
        p[i].remaining=p[i].bt;
        p[i].visited=0;
    }
    count=0;
    time=0;
    while(count<n){
        for(i=0;i<n;i++){
            if(p[i].at<=time && p[i].visited==0){
                push(i);
                p[i].visited=1;
            }
        }
        k=0;
        elem=pop();
        if(elem==-1){
            time++;
            z++;
        }
        else{
            if(z!=0){
                printf("%d >>>>>>>>>>>> %d  -> idle\n",time-z,time);
                z=0;
            }
            printf("%d >>>>>>>>>>>> ",time);
            while(k<qua && p[elem].remaining>0){
                p[elem].remaining--;
                time++;
                k++;
                for(i=0;i<n;i++){
                    if(p[i].at<time && p[i].visited==0){
                        push(i);
                        p[i].visited=1;
                    }
                }
            }
            printf("%d -> p%d\n",time,p[elem].pid);
            if(p[elem].remaining==0){
                p[elem].ct=time;
                p[elem].tat=p[elem].ct-p[elem].at;
                p[elem].wt=p[elem].tat-p[elem].bt;
                count++;

            }else{
                push(elem);
            }
        }
    }
    printf("pid\tat\tbt\tct\ttat\twt\n");
    printf("------------------------------------------------------------------------------------\n");
    for(i=0;i<n;i++){
        printf("p%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
        printf("------------------------------------------------------------------------------------\n");
    }
}
