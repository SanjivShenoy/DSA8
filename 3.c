#include<stdio.h>

char stack[1000];
int tos = -1;
char str[1000];

void push(char a)
{
    stack[++tos] = a;
}

char pop()
{
    if(tos == -1)
        return '\0';
    else
        return stack[tos--];
}

int main()
{
    scanf("\n%[^\n]s", str);
    int x = 0;
    while(str[x] != '\0')
    {
        if(str[x] == '(' || str[x] == '{' || str[x] == '[')
            push(str[x]);
        else if(str[x] == ')' || str[x] == '}' || str[x] == ']')
        {
            char temp;
            if(str[x] == ')') temp = '(';
            else if(str[x] == '}') temp = '{';
            else temp = '[';
            char ch = pop();
            if(ch == '\0' || ch != temp)
            {
                printf("\nFalse\n\n");
                return 0;
            }
        }
        else
        {
            x++;
            continue;
        }
        x++;
    }
    if(tos == -1)
        printf("\nTrue\n\n");
    else
        printf("\nFalse\n\n");
    return 0;
}
