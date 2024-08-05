

#include<stdio.h>

struct process

{

    int ct,at,wt,tat,bt,completed;

};

void main()

{

    int n;

    printf("enter the number of process:");

    scanf("%d",&n);

    struct process p[n];

    for(int i=0;i<n;i++)

    {

        printf("enter the arrival time and burst of process %d:",i+1);

        scanf("%d%d",&p[i].at,&p[i].bt);

    }

    int currenttime=0,totalpc=0,totaltat=0,totalwt=0;

    while(totalpc<n)

    {

        int min=-1;

        for(int i=0;i<n;i++)

        {

            if(p[i].at<=currenttime && p[i].completed!=1)

            {

                if(min==-1||p[i].bt<p[min].bt)

                {

                    min=i;

                }

            }

        }

        if(min==-1)

        {

            currenttime++;

        }

        else

        {

            p[min].ct=currenttime+p[min].bt;

            currenttime=currenttime+p[min].bt;

            p[min].completed=1;

            totalpc++;

            p[min].tat=p[min].ct-p[min].at;

            p[min].wt=p[min].tat-p[min].bt;

            totaltat=totaltat+p[min].tat;

            totalwt=totalwt+p[min].wt;

        }

    }

    printf("\nprocess\tarrivaltime\tbursttime\tcompleteiontime\tturnaroundtime\twaitingtime\t\n");

    for(int i=0;i<n;i++)

    {

        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i+1,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);

    }

    printf("average tat: %.2f\n",(float)totaltat/n);

    printf("average wt: %.2f\n",(float)totalwt/n);

    

}
