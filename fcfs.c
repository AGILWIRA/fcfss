#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, pos, temp, bt[20], rt[20], wt[20], tat[20], avwt = 0, avtat = 0, i, j, avrt = 0;
    int indeks[20], arr[20], cpu[20], io[20];
    printf("\nEnter total process (3 - 1000):");
    scanf("%d", &n);
    if (n < 3 || n > 1000)
    {
        printf("Please input the correct number of process");
    }
    else
    {
        for (i = 0; i < n; i++)
        {
            printf("\n-- INPUT DATA --\n");
            printf("------------------");
            printf("\nInput data baris-%d\n", i + 1);
            printf("Task Name[%d]\t\t: ", i + 1);
            scanf("%d", &indeks[i]);
            printf("Arrival Time[%d]\t\t: ", i + 1);
            scanf("%d", &arr[i]);
            printf("CPU Time[%d]\t\t: ", i + 1);
            scanf("%d", &cpu[i]);
            printf("IO Time[%d]\t\t: ", i + 1);
            scanf("%d", &io[i]);
            printf("\nInput data %d succes\n\n", i + 1);
            bt[i] = arr[i] + cpu[i] + io[i];
        }

        for (i = 0; i < n; i++)
        {
            pos = i;
            for (j = i + 1; j < n; j++)
            {
                if (bt[j] < bt[pos])
                    pos = j;
            }

            temp = bt[i];
            bt[i] = bt[pos];
            bt[pos] = temp;

            temp = indeks[i];
            indeks[i] = indeks[pos];
            indeks[pos] = temp;
        }
        wt[0] = 0;
        for (i = 1; i < n; i++)
        {
            wt[i] = 0;
            for (j = 0; j < i; j++)
                wt[i] += bt[j];
        }

        rt[0] = 0;
        for (i = 0; i < n; i++)
        {
            rt[i] = 0;
            for (j = 0; j < i; j++)
                rt[i] = wt[i];
        }
        printf("\nProcess\t\tTask\t\tWaiting Time\t\tResponse Time\t\tTurnaround Time");

        for (i = 0; i < n; i++)
        {
            tat[i] = bt[i] + wt[i];
            avwt += wt[i];
            avtat += tat[i];
            avrt += rt[i];
            printf("\nP[%d]\t\t%d\t\t%d\t\t\t%d\t\t\t%d", i + 1, indeks[i], wt[i], rt[i], tat[i]);
        }

        avrt /= i;
        avwt /= i;
        avtat /= i;
        printf("\n\nAverage Waiting Time : %d", avwt);
        printf("\nAverage Response time : %d", avrt);
        printf("\nAverage Turnaround Time : %d\n", avtat);
    }
    return 0;
}