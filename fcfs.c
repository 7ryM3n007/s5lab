#include<stdio.h>
struct process{
        int at,bt,ct,tat,wt,completed,order;
    };
void main(){
    int np,progress=0,currenttime=0,totaltat=0,totalwt=0;
    printf("Enter the No.of Process: ");
    scanf("%d",&np);
    struct process p[np];
    for(int i =0;i<np;i++){
        printf("Enter the order and bt of process %d: ",i+1);
        scanf("%d%d",&p[i].order,&p[i].bt);
        p[i].at=0;
    }
    while(progress<np){
        int order_index =-1;
        for(int i =0;i<np;i++){
            if(p[i].at<=currenttime && p[i].completed!=1)
            {
                if(order_index ==-1   || p[order_index].order > p[i].order) order_index=i;

            }
        }
        if(order_index==-1) currenttime++;
        else {
            p[order_index].ct=currenttime+p[order_index].bt;
            currenttime+=p[order_index].bt;
            progress++;

            p[order_index].completed=1;
            
            
            p[order_index].tat=p[order_index].ct;
            p[order_index].wt=p[order_index].tat-p[order_index].bt;
            totaltat=totaltat+p[order_index].tat;

            totalwt=totalwt+p[order_index].wt;
        }

    }
    printf("\nprocess\t\torder\tbursttime\tcompleteiontime\tturnaroundtime\twaitingtime\t\n");

    for(int i=0;i<np;i++)

    {

        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i+1,p[i].order,p[i].bt,p[i].ct,p[i].tat,p[i].wt);

    }

    printf("average tat: %.2f\n",(float)totaltat/np);

    printf("average wt: %.2f\n",(float)totalwt/np);

}