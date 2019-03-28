#include<stdio.h>

int n, k, a[1000];
int count;

void sort()
{
    for(int i=0; i<n-1; i++)
        for(int j=0; j<n-i-1; j++)
            if(a[j] > a[j+1])
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
}

int main()
{
    scanf("%d%d",&n,&k);
    for(int i=0; i<n; i++)
        scanf("%d", &a[i]);
    sort();
    int m = n;
    while(a[0] < k && count != m-1)
    {
        count++;
        int val = a[0] + 2*a[1];
        // printf("a[0] = %d a[1] = %d val = %d",a[0], a[1], val);
        int j = 2;
        while(a[j] < val && j<=(n-1)){j++;}
        for(int i=2; i<j; i++)
            a[i-2] = a[i];
        a[j-2] = val;
        for(int i=j; i<n; i++)
            a[i-1] = a[i];
        n--;
    }
    if(a[0] >= k)
        printf("\n%d\n\n",count);
    else
        printf("\nNot possible\n\n");
    return 0;
}
