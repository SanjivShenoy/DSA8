#include<stdio.h>
#define min(a,b) (a<b)?a:b;

int n,k,a[1005], count;

int main()
{
    scanf("%d%d", &n, &k);
    char ch[1];
    for(int i=0; i<n; i++)
    {
        scanf("\n%s",ch);
        if(ch[0] == 'R')
            a[i] = 0;
        else if(ch[0] == 'Y')
            a[i] = 1;
        else
            a[i] = 2;
    }
    for(int i = 0; i<n; i++)
    {
        int val = 2 - a[i];
        // printf("\na[%d] = %d\n",i,a[i]);
        int x = min(n-1, i+k-1);
        count+=val;
        for(int j=i; j<=x; j++)
        {
            a[j]+=val;
            a[j]%=3;
        }
        // printf("\ni = %d, x = %d, val = %d\n",i,x,val);
    }
    printf("\n%d\n\n", count);
    return 0;
}
