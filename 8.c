#include<stdio.h>

int n, a[1005][1005], ZeroRight[1005][1005], ZeroLeft[1005][1005],ans;

void calcZeroRight()
{
    for (int i = 0; i < n; i++)
        for (int j = n - 1; j >= 0; j--)
        {

            if (a[i][j])
                continue;
            if (j != n - 1)
                ZeroRight[i][j] += ZeroRight[i][j + 1];

            ZeroRight[i][j] += 1;
        }
}

void calcZeroLeft()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (a[i][j])
                continue;
            if (j != 0)
                ZeroLeft[i][j] += ZeroLeft[i][j - 1];

            ZeroLeft[i][j] += 1;
        }
}

int subMatrices(int m, int n)
{
    return (m*(m+1)*n*(n+1)/4);
}

int main()
{
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%d",&a[i][j]);

    calcZeroRight();
    calcZeroLeft();

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            if(a[i][j])
            {
                int k = i-1;
                while(k != -1 && a[k][j] != 1){ k--; }
                int top = k+1;

                k = i+1;
                while(k != n && a[k][j] != 1){ k++; }
                int bottom = k-1;
                int left = 999, right = 999;
                for(k=top; k<=bottom; k++)
                {
                    if(j == n-1)
                        right = 0;
                    else if(ZeroRight[k][j+1] < right)
                        right = ZeroRight[k][j+1];

                    if(j == 0)
                        left = 0;
                    else if(ZeroLeft[k][j-1] < left)
                        left = ZeroLeft[k][j-1];
                }
                left = j - left;
                right = j + right;

                int l = right - left + 1;
                int b = bottom - top + 1;
                int count = 0;

                int w = j - left;
                count += subMatrices(w,b);
                printf("count1 = %d\n",count);
                int x = right - j;
                count += subMatrices(x,b);
                printf("count2 = %d\n",count);
                int y = i - top;
                count += subMatrices(l,y);
                printf("count3 = %d\n",count);
                int z = bottom - i;
                count += subMatrices(l,z);
                printf("count4 = %d\n",count);

                count -= subMatrices(w,y);
                printf("count5 = %d\n",count);
                count -= subMatrices(x,y);
                printf("count6 = %d\n",count);
                count -= subMatrices(w,z);
                printf("count7 = %d\n",count);
                count -= subMatrices(x,z);
                printf("count8 = %d\n---------------\n",count);

                printf("count = %d ans = %d\n", count, ans);
                printf("top = %d bottom = %d\n",top,bottom);
                printf("left = %d right = %d\n",left,right);
                printf("l = %d b = %d total = %d", l, b, subMatrices(l,b));
                ans += subMatrices(l,b) - count;
            }
        }
    printf("\n%d\n\n",ans);
}
