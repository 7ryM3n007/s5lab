#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
struct block{
    char a[20];
    int start_block,size,alloc[25];
};
bool cmparray(int a[],int b[],int na,int nb){
    for(int i =0;i<na;i++){
        for(int j=0;j<nb;j++){
            if(a[i]==b[j]) return false;
        }
    }
    return true;
}
bool avail(struct block m[],struct block b,int nb,int tmp_size ){
    for(int i =0;i<nb;i++){
        if( m[i].start_block == b.start_block ) return false;
    }
    for(int j =0;j<nb;j++){
        if(cmparray(&b.start_block,&m[j].start_block,tmp_size,m[j].size)) return true; 
        else return false;
    }    
    

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
       /* if(i!=0 && ! avail(b,tmp,i,tmp.size)){ 
            printf("ERROR: File have same starting address!!\n");
            i--; continue;
        }*/
        for(int j =0;j<tmp.size;j++)
        {   
            if(j==0){
                tmp.alloc[j]=tmp.start_block;
                continue;
            }
            do{    
                tmp.alloc[j]=rand() % 65;
                if(i==0) break;
                }
            while( ! avail(b,tmp,i,j));
        }

        printf("Blocks allocated: ");
        for(int j = 0; j < tmp.size; j++) {
            printf("%d ", tmp.alloc[j]);
        }
        printf("\n");
        b[i]=tmp;
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