#include <stdio.h>
int q[100];
int f = -1;
int r = -1;
void insert(int n)
{
    if (f == -1)
    f = 0;
    r = r + 1;
    q[r] = n;
}
int delete()
{
    int n = q[f];
    f = f + 1;
    if (f > r)
    f = r = -1; 
    return n;
}
void main()
{
    int i, t = 0, p, tq, n, tottat = 0, totwt = 0;
    printf("How many processes\n");
    scanf("%d", &n);
    if (n == 0)
    {
        printf("No processes to schedule.\n");
        return;

    }

    int a[n][5], bt[n], exist[n];

    for (i = 0; i < n; i++)

        {

            printf("Enter process id:\n");

            scanf("%d", &a[i][0]);

            printf("Enter arrival time of %d\n", a[i][0]);

            scanf("%d", &a[i][1]);

            printf("Enter burst time of %d\n", a[i][0]);

            scanf("%d", &a[i][2]);

            bt[i] = a[i][2];

            exist[i] = 0;

        }

    printf("Enter time quantum\n");

    scanf("%d", &tq);



    int first_process = 0;

    for (i = 1; i < n; i++)

    {

        if (a[i][1] < a[first_process][1])

        {

            first_process = i;

        }

    }


    t = a[first_process][1];

    insert(first_process);

    exist[first_process] = 1;

    while (f != -1) 

    {

        p = delete();

        if (a[p][2] >= tq)

            {

                a[p][2] -= tq;

                t += tq;

            }

        else

            {

                t += a[p][2];

                a[p][2] = 0;
            }
        for (i = 0; i < n; i++)
        {
            if (exist[i] == 0 && a[i][1] <= t)
            {
                insert(i);
                exist[i] = 1;
            }
        }
        if (a[p][2] == 0)
        {
            a[p][4] = t - a[p][1]; 
            a[p][3] = a[p][4] - bt[p]; 
            tottat += a[p][4];
            totwt += a[p][3];
        }
        else
        {
            
        }
    }
    printf("pid\tat\tbt\ttat\twt\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\n", a[i][0], a[i][1], bt[i], a[i][4], a[i][3]);
    }
    printf("Average TAT: %.2f\n", (float)tottat / n);
    printf("Average WT: %.2f\n", (float)totwt / n);
}
