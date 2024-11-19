#include <stdio.h>
#include <stdlib.h>

// Array kullanrak stack oluşturma işlemleri
const int max = 5;
int top = -1;

void pushArray(int dizi[], int value)
{
    if (top == max)
    {
        printf("dizi doldu");
    }
    else
    {
        top++;
        dizi[top] = value;
    }
}

void displayArray(int dizi[])
{
    for (int i = 0; i <= top; i++)
    {
        printf("\n%d. eleman : %d", i + 1, dizi[i]);
    }
}

int peekArray(int dizi[])
{
    if (top != -1)
    {
        return dizi[top];
    }
}
void popArray(int dizi[])
{
    if (top == -1)
    {
        printf("Eleman yok!");
        return;
    }
    else
    {
        dizi[top] = 0;
        top--;
    }
}

// Struct kullanarak stack oluşturma

struct stack
{
    int data;
    struct stack *next;
};

struct stack *pushList(struct stack *top, int value)
{
    struct stack *newNode;
    newNode = (struct stack *)malloc(sizeof(struct stack));
    newNode->data = value;
    if (top == NULL)
    {
        top = newNode;
        top->next = NULL;
    }
    else
    {
        newNode->next = top;
        top = newNode;
    }
    return top;
}

struct stack *popList(struct stack *top)
{

    if (top == NULL)
    {
        printf("Listede silinecek eleman yok!");
    }
    else
    {
        if (top->next != NULL)
        {
            struct stack *ptr;
            ptr = top;
            top = top->next;
            free(ptr);
        }
        else
        {
            free(top);
        }
    }
    return top;
}

void displayList(struct stack *top)
{
    struct stack *ptr;
    ptr = top;
    while (ptr != NULL)
    {
        printf("\ndeger : %d", ptr->data);
        ptr = ptr->next;
    }
}
struct stack *peekList(struct stack *top)
{
    if (top != NULL)
    {
        return top;
    }
    return NULL;
}
void main()
{
    // int dizi[max];
    // pushArray(dizi, 5);
    // displayArray(dizi);
    // popArray(dizi);
    // displayArray(dizi);
    // printf("%d", peekArray(dizi));

    struct stack *top = NULL;
    top = pushList(top, 8);
    top = pushList(top, 12);
    top = pushList(top, 15);
    displayList(top);
    top = popList(top);
    displayList(top);
}
