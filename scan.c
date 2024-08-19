#include<stdio.h>
#include<stdlib.h>
#define left 0
#define right 1

int search(int arr[], int n, int target) {  
for (int i = 0; i< n; i++) {  
if (arr[i] == target) {  
return i;  
        }  
    }  
return -1;  
}  
void sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
          
            // Swap if the element found is greater than the
            // next element
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void main(){
    int n,seek=0,head,temp,dir,head_index;
    printf("Enter the no.of track: ");
    scanf("%d",&n);
    int lim=n+3;
    int a[lim];
    printf("Enter the Request Sequence(0-199): ");
    for(int i =0;i<n;i++) scanf("%d",&a[i]);
    printf("Enter the Initial Postion: ");
    scanf("%d",&head); a[n+2]=head;a[n]=0;a[n+1]=199;
    printf("Enter the Direction 0 for left, 1 for right: ");
    scanf("%d",&dir);
    printf("SCAN DISK SCHEDULING ALGO:  \n");
    sort(a,lim);
   
    if(dir == right) //Right
    {
        head_index=search(a,lim,head);
        for(int i = head_index ; i < lim ;i++){
            printf(" ==> %d",a[i]);
        }
        for(int i = head_index - 1; i >=0 ;i--){
            printf(" ==> %d",a[i]);
        }
        seek= abs(a[lim-1]-head + 199-a[1]);
    }
     else
     { //left
        head_index=search(a,lim,head);
        for(int i = head_index ; i >= 0 ;i--){
            printf(" ==> %d",a[i]);
        }
        for(int i = head_index + 1; i < lim-1 ;i++){
            printf(" ==> %d",a[i]);
        }
        seek=head + a[lim-2];
    }
    printf("\nNo.of Seek operaion: %d",seek);
}