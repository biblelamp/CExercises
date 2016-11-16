#include <stdio.h>
#include <malloc.h>

typedef int T;

typedef struct Node
{
   T data;
   struct Node *left;
   struct Node *right;
   struct Node *parent;
} Node;

void printTree(Node *root, const char *dir, int level)
{
    if (root)
    {
        printTree(root->left, "left", level+1);
        printTree(root->right, "right", level+1);
        printf("lvl %d %s = %d\n", level, dir, root->data);
    }
}

Node* getFreeNode(T value, Node *parent)
{
    Node* tmp = (Node*) malloc(sizeof(Node));
    tmp->left = tmp->right = NULL;
    tmp->data = value;
    tmp->parent = parent;
    return tmp;
}

void insert(Node **head, int value)
{
    Node *tmp = NULL;
    Node *ins = NULL;
    if (*head == NULL)
    {
        *head = getFreeNode(value, NULL);
        return;
    }
    tmp = *head;
    while (tmp)
    {
        if (value > tmp->data)
        {
            if (tmp->right)
            {
                tmp = tmp->right;
                continue;
            }
            else
            {
                tmp->right = getFreeNode(value, tmp);
                return;
            }
        }
        else if (value < tmp->data)
        {
            if (tmp->left)
            {
                tmp = tmp->left;
                continue;
            }
            else
            {
                tmp->left = getFreeNode(value, tmp);
                return;
            }
       }
        else
        {
            exit(2);
        }
    }
}

int main(int argc, char *argv[])
{
    Node *Tree=NULL;
    insert(&Tree, 10);
    insert(&Tree, 5);
    insert(&Tree, 20);
    insert(&Tree, 15);
    printTree(Tree, "root", 0);
    return 0;
}
