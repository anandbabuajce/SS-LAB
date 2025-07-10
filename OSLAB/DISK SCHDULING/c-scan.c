#include<stdio.h>


void main(){
    int n,i,j,head,dist=0,A[20],low_bound,up_bound,temp;
    printf("Enter the number of tracks : ");
    scanf("%d",&n);
    printf("Enter the head position: ");
    scanf("%d",&head);
    A[0]=head;
    n=n+1;
    printf("Enter the low bound: ");
    scanf("%d",&low_bound);
    printf("Enter the up_bound: ");
    scanf("%d",&up_bound);
    printf("Enter the tracks");
    for(i=1;i<n;i++){
        scanf("%d",&A[i]);
    }
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(A[j]>A[j+1]){
                temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
            }
        }
    }
    for(i=0;i<n;i++){
        if(A[i]==head){
            j=i;
            break;
        }
    }

    printf("\n SERVICE ORDER: %d",A[j]);
    for(i=j+1;i<n;i++){
        printf(" -> %d ",A[i]);
    }
    dist+=up_bound-head;
    printf(" -> %d ",up_bound);
    printf(" -> %d ",low_bound);
    dist+=up_bound-low_bound;
    for(i=0;i<j;i++){
        printf(" -> %d ",A[i]);
    }
    dist+=A[j-1]-low_bound;
    printf("\nTotal head movement: %d",dist);
}

