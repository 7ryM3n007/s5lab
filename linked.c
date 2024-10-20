#include<stdio.h>
void main()
{
    int n,i,j,allocated[10],start[10],block[10][10],size[10];
    for(i=0;i<10;i++)
    {
        allocated[i]=0;
    }
    printf("Enter the no of files");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        int validStart=0;
        while(!validStart)
        {
            printf("Enter start block");
            scanf("%d",&start[i]);
            if(allocated[start[i]]==0)
            {
                allocated[start[i]]=1;
                block[i][0]=start[i];
                validStart=1;            
            }
            else
            {
                printf("Start block already allocated");
            }
        }
        printf("Enter the no of blocks");
        scanf("%d",&size[i]);
        printf("Enter the blocks");
        for(j=1;j<=size[i];j++)
        {
            int validBlock=0;
            while(!validBlock)
            {
                scanf("%d",&block[i][j]);
                if(allocated[block[i][j]]==0)
                {
                    allocated[block[i][j]]=1;
                    validBlock=1;
                }
                else
                {
                    printf("Already allocated");
                }
            }
        }
    }
    printf("File no\tstart\tsize");
    for(i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t",i+1,start[i],size[i]);
        for(j=1;j<size[i];j++)
        {
            printf("%d -->",block[i][j]);
        }
        printf("%d",block[i][size[i]]);
    }
}