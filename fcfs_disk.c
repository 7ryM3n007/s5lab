#include<stdio.h>
#include<stdlib.h>
void main(){
    int n,seek=0,head;
    printf("Enter the no.of track: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the Request Sequence: ");
    for(int i =0;i<n;i++) scanf("%d",&a[i]);
    printf("Enter the Initial Postion: ");
    scanf("%d",&head);
    printf("FCS DISK SCHEDULING ALGO:  \n");
    for(int i=0;i<n;i++){
        printf(" ==> %d",a[i]);
        seek+=abs(head-a[i]);
        head=a[i];

    }
    printf("\nNo.of Seek Operation: %d\n",seek);
}