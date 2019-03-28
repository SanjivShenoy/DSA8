#include<stdio.h>
#include<math.h>

int a[1005], n, ans;

void sort()
{
    for(int i=0; i<n-1; i++)
        for(int j=0; j<n-i-1; j++)
            if(a[j] < a[j+1])
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
}

int main()
{
    int i = 0;
    while(scanf("%d", &a[i++])){}
    n = i-1;

    sort();

    for(int i=0; i<n; i+=2)
    {
        ans+=(a[i]*pow(10,i/2) + a[i+1]*pow(10,i/2));
        //printf("a[%d] = %d a[%d] = %d ans = %d\n\n",i,a[i],i+1,a[i+1],ans);
    }

    printf("\n%d\n\n", ans);
    return 0;
}
