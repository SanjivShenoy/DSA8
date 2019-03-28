#include<stdio.h>

int at[1005], bt[1005], tat;

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

int main()
{
    int n;
    for(int i=1; i<=n; i++)
        scanf("%d%d",&at[i],&bt[i]);
    sort();
    int time = 0;
    i=1; j=1;
    while(j != n+1)
    {
        while(at[i] <= time && i <= n)
        {
            push(bt[i]);
            i++;
        }
        int x = pop();
        if(x == -1)
        {
            time = at[i];
            push(bt[i]);
            i++;
            continue;
        }
        time = time + x;
        j++;
    }
    return 0;
}
