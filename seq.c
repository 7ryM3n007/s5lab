#include<stdio.h>
#include<string.h>
struct block{
    char a[20];
    int start_block,size,alloc[25];
};
int avail(struct block m[],struct block b,int nb){
    for(int i =0;i<nb;i++){
        if( m[i].start_block == b.start_block ) return 0;
    }
    for(int j=0;j<b.size;j++){
        for(int l =0;l< nb;l++){
            for(int k=0;k<m[j].size;k++){
                if(b.alloc[j]==m[l].alloc[k]) return 0;
            }
        }
    }
    return 1;    
    

}
void main(){
    int nf;
    printf("Enter the no.of Files: ");
    scanf("%d",&nf);
    struct block b[nf],tmp;
    for(int i =0;i<nf;i++){
        printf("Enter the name of file %d: ",i+1);
        scanf("%s",tmp.a);
        printf("Starting address: ");
        scanf("%d",&tmp.start_block);
        printf("Enter the size: ");
        scanf("%d",&tmp.size);
        for(int j =0;j<tmp.size;j++)
        {
            tmp.alloc[j]=tmp.start_block +j;
        }

        if(i==0 || avail(b,tmp,i)){
            b[i]=tmp;
        }
        else {
            i--;
            printf("This file can't be allocated!!\n");
        }
    }
    printf("\n +----------------------------+\n");
    for(int i =0;i<nf;i++){
        printf("Name of file %d: %s\n",i+1 ,b[i].a);
    
        printf("Starting addr of file %d:  %d\n",i+1 ,b[i].start_block);
        
        printf("Size of file %d: %d\n",i+1 ,b[i].size);
        printf("Blocks allocated: ");
        for(int j = 0; j < b[i].size; j++) {
            printf("%d ", b[i].alloc[j]);
        }
        printf("\n");
    printf("\n +----------------------------+\n");

    }
}