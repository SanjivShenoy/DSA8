#include<stdio.h>
#define INF 1000000

int maxheap[1005], minheap[1005], odd, less, minsize, maxsize;
/*
if odd == 1: median is root of heap in in which last value entered.
if odd == 0: median is avg of roots on both heaps.

if less == 1 && odd == 1: last value entered in minheap
if less == 0 && odd == 1: last value entered in maxheap
*/

int maxi(int a, int b)
{
    if(maxheap[a] > maxheap[b])
        return a;
    else
        return b;
}

int mini(int a, int b)
{
    if(minheap[a] < minheap[b])
        return a;
    else
        return b;
}

void swap(int a, int b, int arr[])
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void shiftUp(int node, int min)
{
    if(min == 1)
    {
        if(node != 1)
        {
            int parent = node/2;
            if(minheap[parent] > minheap[node])
            {
                swap(parent, node, minheap);
                shiftUp(parent,1);
            }
        }
    }
    else
    {
        if(node != 1)
        {
            int parent = node/2;
            if(maxheap[parent] < maxheap[node])
            {
                swap(parent, node, maxheap);
                shiftUp(parent,0);
            }
        }
    }

}

void push(int a, int min)
{
    if(min == 1)
    {
        minsize++;
        minheap[minsize] = a;
        shiftUp(minsize, 1);
    }
    else
    {
        maxsize++;
        maxheap[maxsize] = a;
        shiftUp(maxsize,0);
    }
}

void heapify(int node, int min)
{
    if(min == 1)
    {
        int left = node*2;
        int right = node*2 + 1;
        int minimum = mini(left,right);
        if(node > minimum)
        {
            if(minimum == left)
            {
                swap(node, left, minheap);
                heapify(left,1);
            }
            else
            {
                swap(node, right, minheap);
                heapify(right, 1);
            }
        }
    }
    else
    {
        int left = node*2;
        int right = node*2 + 1;
        int max = maxi(left,right);
        if(node < max)
        {
            if(max == left)
            {
                swap(node, left, maxheap);
                heapify(left,0);
            }
            else
            {
                swap(node, right, maxheap);
                heapify(right, 0);
            }
        }
    }
}

int pop(int min)
{
    if(min == 1)
    {
        if(minsize == 0)
            return -1;
        else
        {
            swap(1,minsize,minheap);
            int val = minheap[minsize];
            minsize--;
            heapify(1,1);
            return val;
        }
    }
    else
    {
        if(maxsize == 0)
            return -1;
        else
        {
            swap(1,maxsize,maxheap);
            int val = minheap[minsize];
            maxsize--;
            heapify(1,0);
            return val;
        }
    }
}

int top(int min)
{
    if(min == 1)
    {
        if(minsize == 0)
            return -1;
        return minheap[1];
    }
    else
    {
        if(maxsize == 0)
            return -1;
        return maxheap[1];
    }
}

int main()
{
    for(int i=0; i<1005; i++)
    {
        minheap[i] = INF;
        maxheap[i] = -1;
    }

    int median = 0;
    int n, a[1005];
    scanf("%d",&n);

    for(int i=1; i<=n; i++)
    {
        int val;
        scanf("%d",&val);
        if(val > median)
        {
            if(less==1 && odd==1)
            {
                push(val, 1);
                int x = pop(1);
                push(x,0);
                x = top(1);
                int y = top(0);
                printf("%f ",(float)(x+y)/2);
                less = 1;
                odd = (odd+1)%2;
            }
            else
            {
                push(val, 1);
                odd = (odd+1)%2;
                if(odd == 1)
                {
                    int z = top(1);
                    printf("%f ",(float)z);
                }
                else
                {
                    int x = top(0);
                    int y = top(1);
                    printf("%f ",(float)(x+y)/2);
                }
                less = 1;
            }
        }
        else
        {
            if(less==0 && odd==1)
            {
                push(val, 0);
                int x = pop(0);
                push(x,1);
                x = top(0);
                int y = top(1);
                printf("%f ",(float)(x+y)/2);
                less = 0;
                odd = (odd+1)%2;
            }
            else
            {
                push(val, 0);
                odd = (odd+1)%2;
                if(odd == 1)
                {
                    int z = top(0);
                    printf("%f ",(float)z);
                }
                else
                {
                    int x = top(0);
                    int y = top(1);
                    printf("%f ",(float)(x+y)/2);
                }
                less = 0;
            }
        }
    }


    return 0;
}
