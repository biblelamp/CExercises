#include <stdio.h>
#include <malloc.h>
#define array_size(_a) (int)(sizeof _a / sizeof _a[0])

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
            break;
        }
    }
}

void preOrderTravers(Node *root)
{
    if (root)
    {
        printf("%d ", root->data);
        preOrderTravers(root->left);
        preOrderTravers(root->right);
    }
}

void inOrderTravers(Node *root)
{
    if (root)
    {
        inOrderTravers(root->left);
        printf("%d ", root->data);
        inOrderTravers(root->right);
    }
}

void postOrderTravers(Node *root)
{
    if (root)
    {
        postOrderTravers(root->left);
        postOrderTravers(root->right);
        printf("%d ", root->data);
    }
}

int main()
{
    Node *Tree=NULL;
    int a[] = {10, 5, 20, 15, 30, 25};
    for (int i = 0; i < array_size(a); i++)
        insert(&Tree, a[i]);
    printTree(Tree, "root", 0);
    printf("preOrder: ");
    preOrderTravers(Tree);
    printf("\n");
    printf("inOrder: ");
    inOrderTravers(Tree);
    printf("\n");
    printf("postOrder: ");
    postOrderTravers(Tree);
    printf("\n");
    return 0;
}
