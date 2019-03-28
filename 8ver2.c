#include<stdio.h>

int n, a[1005][1005], count, flag;

int main()
{
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%d",&a[i][j]);

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            for(int sr=0; sr<n-j; sr++)
                for(int sc=0; sc<n-i; sc++)
                {
                    flag = 0;
                    for(int p=i; p<=i+sc; p++)
                        for(int q=j; q<=j+sr; q++)
                        {
                            if(a[p][q] == 1 && flag == 0)
                                flag = 1;
                            else if(a[p][q] == 1 && flag>=1)
                                flag = 2;
                        }
                    if(flag == 1)
                        count++;
                }
        }
    printf("\n%d\n\n",count);
    return 0;
}
