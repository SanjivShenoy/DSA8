#include<stdio.h>

int stack[1005], minStack[1000], tos = -1, tosMin= -1, val, flag;

void push(int a)
{
    stack[++tos] = a;
}

int pop()
{
    if(tos == -1)
        return -1;
    else
        return stack[tos--];
}

void pushMin(int a)
{
    minStack[++tosMin] = a;
}

int popMin()
{
    if(tosMin == -1)
        return -1;
    else
        return minStack[tosMin];
}

void removeMin()
{
    tosMin--;
}

int main()
{
    int input;
    printf("Enter \n1: To push \n2: To pop \n3: To get MIN\n4: To exit\n\n");
    scanf("%d", &input);

    while(input != 4)
    {
        if(input == 1)
        {
            printf("\nEnter val: ");
            scanf("%d",&val);
            push(val);
            printf("pushed...\n");
            if(flag == 0 || val <= minStack[tosMin])
            {
                pushMin(val);
                flag = 1;
            }
        }
        else if(input == 2)
        {
            int item = pop();
            if(tos == -1) flag = 0;
            if(item == -1)
                printf("\nStack is empty\n");
            else
            {
                printf("Poped val = %d\n",item);
                if(item == popMin())
                {
                    removeMin();
                }
            }
        }
        else if(input == 3)
        {
            int item = popMin();
            if(item == -1)
                printf("\nStack is empty\n");
            else
                printf("Min val = %d\n",item);
        }
        scanf("%d",&input);
    }

    return 0;
}
