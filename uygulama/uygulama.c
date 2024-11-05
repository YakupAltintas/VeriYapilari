#include <stdio.h>>
#include <stdlib.h>>

struct node
{
    int data;
    struct node *next;
};

void searchNode(struct node *start)
{
    struct node *ptr;
    ptr = start;
    while (ptr->next != start)
    {
        printf("\n %d", ptr->data);
        ptr = ptr->next;
    }
    printf("\n %d", ptr->data);
}

struct node *addListFirst(struct node *start)
{
    struct node *newNode, *ptr;
    int num;
    printf("\n Veri Giriniz: ");
    scanf("%d", &num);
    newNode = (struct node *)malloc(sizeof(struct node));
    if (start == NULL)
    {
        newNode->data = num;
        start = newNode;
        start->next = start;
    }
    else
    {
        newNode->data = num;
        ptr = start;
        while (ptr->next != start)
        {
            ptr = ptr->next;
        }
        newNode->next = start;
        ptr->next = newNode;
        start = newNode;
        return start;
    }
}

struct node *addListEnd(struct node *start)
{
    struct node *newNode, *ptr;
    int num;
    printf("\n Veri Giriniz: ");
    scanf("%d", &num);
    newNode = (struct node *)malloc(sizeof(struct node));
    if (start == NULL)
    {
        newNode->data = num;
        start = newNode;
        start->next = start;
    }
    else
    {
        newNode->data = num;
        ptr = start;
        while (ptr->next != start)
        {
            ptr = ptr->next;
        }
        ptr->next = newNode;
        newNode->next = start;
        return start;
    }
}
struct node *deleteListEnd(struct node *start)
{
    struct node *ptr, *preptr;
    preptr = start;
    ptr = start;
    while (ptr->next != start)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = ptr->next;
    free(ptr);
    return start;
}

int main()
{
    struct node *start = NULL;
    for (size_t i = 0; i < 3; i++)
    {
        start = addListEnd(start);
    }
    searchNode(start);
    start = addListFirst(start);
    searchNode(start);
    return 0;
}