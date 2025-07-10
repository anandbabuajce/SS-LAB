#include<stdio.h>

void main(){
    int n,i,j,head,dist=0,A[20];
    printf("Enter the number of tracks : ");
    scanf("%d",&n);
    printf("Enter the head position: ");
    scanf("%d",&head);
    A[0]=head;
    n=n+1;
    printf("Enter the tracks");
    for(i=1;i<n;i++){
        scanf("%d",&A[i]);
    }
    printf("Service order : %d",head);
    for(i=1;i<n;i++){
        printf(" -> %d",A[i]);
        if(A[i]>A[i-1]){
            dist+=A[i]-A[i-1];
        }
        else{
            dist+=A[i-1]-A[i];
        }
    }
    printf("\n Total head movements: %d",dist);
}
