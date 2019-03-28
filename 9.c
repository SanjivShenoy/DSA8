#include<stdio.h>
#define INF 100000
#define min(a,b) (a<b)?a:b

int n, a[1005], size, sum, diff;

void swap(int p, int q)
{
    int temp = a[p];
    a[p] = a[q];
    a[q] = temp;
}

void shiftUp(int node)
{
    if(node != 1)
    {
        int parent = node/2;
        if(a[parent] > a[node])
        {
            swap(node,parent);
            shiftUp(parent);
        }
    }
}

void push(int val)
{
    size++;
    a[size] = val;
    shiftUp(size);
}

void minHeapify(int node)
{
    int num = min(a[node*2], a[node*2 + 1]);
    if(a[node] > num)
    {
        if(num == a[node*2])
        {
            swap(node,node*2);
            minHeapify(node*2);
        }
        else
        {
            swap(node, node*2+1);
            minHeapify(node*2+1);
        }
    }
}

void pop()
{
    swap(1,size);
    a[size] = INF;
    size--;
    minHeapify(1);
}

int main()
{
    int val;
    scanf("%d",&n);
    for(int i=0; i<1005; i++)
        a[i] = INF;
    for(int i=0; i<n; i++)
    {
        scanf("%d",&val);
        if(val > a[1])
        {
            // printf("val = %d\n",val);
            diff = val - a[1];
            sum+=diff;
            // printf("pop() = %d\n",a[1]);
            pop();
            push(val);
        }
        push(val);
    }

    printf("\nans = %d\n\n",sum);
    return 0;
}
