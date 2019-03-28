#include<stdio.h>
#define INF 100

int n, at[1005], bt[1005], bta[1005], ata[1005], tat;
int ptr=1, ptr2 = 1;

void sort()
{
    for(int i=1; i<n; i++)
        for(int j=1; j<=n-i; j++)
            if(at[j] > at[j+1])
            {
                int temp = at[j];
                at[j] = at[j+1];
                at[j+1] = temp;
                temp = bt[j];
                bt[j] = bt[j+1];
                bt[j+1] = temp;
            }
}

void sort2()
{
    int num = ptr - 1;
    for(int i=1; i<num; i++)
        for(int j=1; j<=num-i; j++)
            if(bta[j] > bta[j+1])
            {
                int temp = bta[j];
                bta[j] = bta[j+1];
                bta[j+1] = temp;
                temp = ata[j];
                ata[j] = ata[j+1];
                ata[j+1] = temp;
            }
}

int main()
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d%d",&at[i],&bt[i]);
    sort();
    for(int i=0; i<1005; i++)
        ata[i] = bta[i] = INF;
    int time = 0;
    int i=1, j=1;
    while(ptr2 != n+1)
    {
        while(at[i] <= time && i <= n)
        {
            ata[ptr] = at[i];
            bta[ptr++] = bt[i];
            fflush(stdout);
            printf("hello");
            sort2();
            printf("hi");
            for(int i=1; i<=ptr-1; i++)
                printf("%d ",bta[i]);
            i++;
        }
        int x = bta[ptr2];
        int y = ata[ptr2];
        bta[ptr2] = INF;
        ata[ptr2] = INF;
        if(x == INF)
        {
            time = at[i];
            ata[ptr] = at[i];
            bta[ptr++] = bt[i];
            i++;
            continue;
        }
        time = time + x;
        tat += (time - y);
        ptr2++;
    }
    printf("ans = %f\n",((float)tat/n));
    return 0;
}
