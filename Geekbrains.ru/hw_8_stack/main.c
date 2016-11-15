#include <stdio.h>
#include <malloc.h>
#define T char
#define zero '\0'

struct TNode
{
    T value ; // data
    struct TNode * next ; // a pointer to the next item in the list
};

typedef struct TNode Node;

struct Stack
{
    Node * head;
    int size;
    int maxSize;
};

struct Stack Stack;

void push(T value)
{
    if (Stack.size >= Stack.maxSize)
    {
        printf("Error stack size.\n");
        return;
    }
    Node * tmp = (Node *) malloc(sizeof (Node));
    if (tmp != NULL) // check error after memory allocation
    {
        tmp -> value = value;
        tmp -> next = Stack.head;
        Stack.head = tmp;
        Stack.size++;
    }
    else printf("Memory allocation error.\n");
}

T pop () {
    if (Stack.size == 0 )
    {
        printf("Stack is empty.\n");
        return zero;
    }
    Node * next = NULL;
    T value;
    value = Stack.head -> value;
    next = Stack.head;
    Stack.head = Stack.head -> next;
    free(next);
    Stack.size--;
    return value;
}

void printStack ()
{
    Node * current = Stack.head;
    while (current != NULL)
    {
        printf("%c ", current -> value);
        current = current -> next;
    }
}

int main()
{
    Stack.maxSize = 100;
    Stack.head = NULL;
    push('a');
    push('b');
    push('c');
    push('d');
    push('e');
    push('f');
    printStack();
    printf("\n");
    printf("%c\n", pop());
    printf("%c\n", pop());
    printStack();
    return 0;
}
