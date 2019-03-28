#include<stdio.h>

int n, a[1005], sum;

int min(int s, int e)
{
    int min = 999;
    for(int i = s; i<=e; i++)
        if(a[i] < min)
            min = a[i];
    return min;
}

int main()
{
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);

    for(int i=0; i<n; i++)
        for(int j=0; j<n-i; j++)
            sum+=min(j, j+i);

    printf("\n%d\n\n",sum);
    return 0;
}
