#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
void displayNode(struct node *start)
{
    struct node *ptr;
    ptr = start;
    int sayac = 1;
    while (ptr->next != NULL)
    {
        printf("\n %d. deger : %d", sayac, ptr->data);
        ptr = ptr->next;
        sayac++;
    }
    printf("\n %d. deger : %d", sayac, ptr->data);
}
struct node *addLineerListInsert(struct node *start)
{
    struct node *newNode;
    int num;
    printf("\n Veri Giriniz: ");
    scanf("%d", &num);
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = num;
    newNode->prev = NULL;
    newNode->next = NULL;
    if (start == NULL)
    {
        start = newNode;
    }
    else
    {
        newNode->next = start;
        start->prev = newNode;
        start = newNode;
    }
    return start;
}

struct node *addLineerListEnd(struct node *start)
{
    struct node *newNode, *ptr;
    int num;
    printf("\n Veri Giriniz: ");
    scanf("%d", &num);
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = num;
    newNode->prev = NULL;
    newNode->next = NULL;
    if (start == NULL)
    {
        start = newNode;
    }
    else
    {
        ptr = start;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = newNode;
        newNode->prev = start;
    }
    return start;
}

struct node *addLineerListMiddle(struct node *start)
{
    struct node *newNode, *ptr;
    int value, pos;
    printf("\n Eklenecek sayi : ");
    scanf("%d", &value);

    printf("\n Eklenecek sira : ");
    scanf("%d", &pos);
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    if (start == NULL)
    {
        start = newNode;
    }
    else
    {
        ptr = start;
        while (ptr->data != pos)
        {
            ptr = ptr->next;
        }
        newNode->next = ptr->next;
        ptr->next->prev = newNode;
        ptr->next = newNode;
        newNode->prev = ptr;
    }
    return start;
}

void main()
{
    struct node *start = NULL;
    for (int i = 0; i < 5; i++)
    {
        start = addLineerListEnd(start);
    }
    displayNode(start);
    start = addLineerListMiddle(start);
    displayNode(start);

    // start = addLineerListInsert(start);
    // displayNode(start);
}