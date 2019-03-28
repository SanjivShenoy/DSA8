#include<stdio.h>
#include<stdlib.h>
#define max(a,b) (a>b)?a:b

int n;

typedef struct tree
{
    int val; //val in node
    int nodecount; // number of nodes in subtree with current node as root
    int height;
    struct tree * parent;
    struct tree * left;
    struct tree * right;
}tree;

int height(tree * node)
{
    if (node == NULL)
        return -1;
    else
        return node->height;
}

int nodecount(tree * node)
{
    if (node == NULL)
        return 0;
    else
        return node->nodecount;
}

void update_height(tree * node)
{
    int s = height(node->left);
    int t = height(node->right);
    int max;
    if(s>t) max = s;
    else max = t;
    node->height = max + 1;
}

void update_nodecount(tree * node)
{
    node->nodecount = nodecount(node->left) + nodecount(node->right) + 1;
}


void left_rotate(tree * x, tree ** root)
{
    tree * y = x->right;
    y->parent = x->parent;
    if (y->parent == NULL)
    {
        *root = y;
    }
    else
    {
        if (y->parent->left == x)
            y->parent->left = y;
        else if(y->parent->right == x)
            y->parent->right = y;
    }
    x->right = y->left;
    if(x->right != NULL)
        x->right->parent = x;
    y->left = x;
    x->parent = y;
    update_height(x);
    update_height(y);
    update_nodecount(x);
    update_nodecount(y);

}

void right_rotate(tree * x, tree ** root)
{
    tree * y = x->left;
    y->parent = x->parent;
    if (y->parent == NULL)
        *root = y;
    else
    {
        if (y->parent->left == x)
            y->parent->left = y;
        else if(y->parent->right == x)
            y->parent->right = y;
    }
    x->left = y->right;
    if(x->left != NULL)
        x->left->parent = x;
    y->right = x;
    x->parent = y;
    update_height(x);
    update_height(y);
    update_nodecount(x);
    update_nodecount(y);
}

void rebalance(tree * node, tree ** root)
{
    while(node != NULL)
    {
        update_height(node);
        if (height(node->left) >= 2 + height(node->right))
        {
            if (height(node->left->left) >= height(node->left->right))
                right_rotate(node,root);
            else
            {
                left_rotate(node->left,root);
                right_rotate(node,root);
            }
        }
        else if (height(node->right) >= 2 + height(node->left))
        {
            if (height(node->right->right) >= height(node->right->left))
                left_rotate(node,root);
            else
            {
                right_rotate(node->right,root);
                left_rotate(node,root);
            }
        }
        node = node->parent;
    }
}

void insert(int a, tree * root, tree ** head)
{
    if(root->val == -1)
    {
        root->val = a;
        return;
    }

    root->nodecount++;

    if(a <= root->val && root->left == NULL)
    {
        tree * temp = (tree *)malloc(1*sizeof(tree));
        temp->val = a;
        temp->left = NULL; temp->right = NULL;
        root->left = temp;
        temp->parent = root;
        temp->nodecount = 1;
        rebalance(temp,head);
    }
    else if(a > root->val && root->right == NULL)
    {
        tree * temp = (tree *)malloc(1*sizeof(tree));
        temp->val = a;
        temp->left = NULL; temp->right = NULL;
        root->right = temp;
        temp->parent = root;
        temp->nodecount = 1;
        rebalance(temp,head);
    }
    else if(a <= root->val)
        insert(a,root->left,head);
    else if(a > root->val)
        insert(a,root->right,head);
}

void inorder(tree * node)
{
    if(node == NULL)
        return;

    inorder(node->left);
    printf("\nnode->val = %d ", node->val);
    printf("node->nodecount = %d\n", node->nodecount);
    printf("node->height = %d\n", node->height);
    inorder(node->right);
}

int main()
{
    scanf("%d", &n);
    tree * root = (tree *)malloc(1*sizeof(tree));
    root->left = NULL; root->right = NULL; root->parent = NULL;
    root->nodecount = 1; root->val = -1;
    for(int i=0; i<n; i++)
    {
        int x;
        scanf("%d",&x);
        insert(x,root,&root);
        // printf("\n---------------------\ni=%d\n\n",i);
        // inorder(root);
        // printf("\n---------------------\n");
    }
    inorder(root);

    for()
}
