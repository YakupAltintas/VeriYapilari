#include <stdio.h>
#include <stdlib.h>

const int max = 5;
int dizi[5];
int front = -1;
int rear = -1;
void insertQueque()
{
    int value;
    printf("Bir eleman giriniz: ");
    scanf("%d", &value);
    if (front == -1 && rear == -1)
    {
        front++;
        rear++;
        dizi[rear] = value;
    }
    else if (rear != max - 1)
    {
        rear++;
        dizi[rear] = value;
    }
}
void displayQueue()
{
    for (int i = front; i <= rear; i++)
    {
        printf("\n%d", dizi[i]);
    }
}
int peekQueue()
{
    if (front != -1)
    {
        return front;
    }
    else
    {
        return -1;
    }
}

int deleteElement()
{
    if (front == -1 && front > rear)
    {
        return -1;
    }
    else
    {
        front++;
        return dizi[front - 1];
    }
}

struct node
{
    int data;
    struct node *next;
};
struct q
{
    struct node *front;
    struct node *rear;
};

void displayList(struct q *q)
{
    struct node *ptr;
    ptr = q->front;
    while (ptr != NULL)
    {
        printf("\n%d", ptr->data);
        ptr = ptr->next;
    }
}

struct q *insertList(struct q *q)
{

    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Listeye eklenecek eleman: ");
    int value;
    scanf("%d", &value);
    newNode->data = value;
    newNode->next = NULL;
    if (q->front == NULL)
    {
        q->front = newNode;
        q->rear = newNode;
    }
    else
    {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    return q;
}

struct q *deleteList(struct q *q)
{
    struct node *ptr;
    ptr = q->front;
    q->front = q->front->next;
    free(ptr);
    return q;
}
// listler ile queue(kuyruk) oluşturma
void main()
{
    // for (int i = 0; i < 5; i++)
    // {
    //     insertQueque();
    // }
    // displayQueue();
    // deleteElement();
    // deleteElement();
    // displayQueue();

    struct q *list = (struct q *)malloc(sizeof(struct q));
    list->front = NULL;
    list->rear = NULL;
    for (int i = 0; i < 5; i++)
    {
        list = insertList(list);
    }
    displayList(list);
    list = deleteList(list);
    displayList(list);
}
