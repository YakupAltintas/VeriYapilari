#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// dizinin elemanlarının bellek adreslerini yazdırma
void arrayAdress()
{
    int arr[] = {1, 2, 3, 4, 5};
    int *ptr;
    ptr = &arr[0];
    printf("\n Address of array : %p %p %p %p", arr, &arr[0], &arr, ptr);
}

// 2 diziyi birleştiri ve sıralar
void arrayMerge()
{
    int dizi1[5] = {3, 5, 8, 6, 9};
    int dizi2[5] = {2, 12, 4, 7, 22};
    int merge[10];

    for (int i = 0; i < 5; i++)
    {
        merge[i] = dizi1[i];
    }
    for (int i = 5; i < 10; i++)
    {
        merge[i] = dizi2[i - 5];
    }
    // 1 3 2
    for (int i = 0; i < 9; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < 10; j++)
        {
            if (merge[j] < merge[min_idx])
            {
                min_idx = j;
            }
        }
        if (min_idx != i)
        {
            int temp = merge[i];
            merge[i] = merge[min_idx];
            merge[min_idx] = temp;
        }
    }

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", merge[i]);
    }
}
// dizinin ortasına eleman ekleme
void elemanEkle()
{
    int dizi[50] = {3, 8, 5, 2};
    int n = 3;
    int pos = 1;
    for (int i = n; i >= pos; i--)
    {
        dizi[i + 1] = dizi[i];
    }
    dizi[pos] = 11;
    for (int i = 0; i <= n + 1; i++)
    {
        printf("%d ", dizi[i]);
    }
}

// dizinin ortasından eleman silme
void elemanSilme()
{
    int pos = 2;
    int N = 4;
    int dizi[5] = {34, 56, 23, 6, 7};

    for (int i = pos; i < N; i++)
    {
        dizi[i] = dizi[i + 1];
    }
    dizi[N] = 0;
    N - 1;
    for (int j = 0; j < N; j++)
    {
        printf("%d\n", dizi[j]);
    }
}

// en küçük indexi bulma
void enKucukIndex()
{
    int a[5] = {15, 28, 10, 7, 8};
    int enKucuk = 100;
    int index = 0;
    for (int i = 0; i < 5; i++)
    {
        if (enKucuk > a[i])
        {
            enKucuk = a[i];
            index = i;
        }
    }
    printf("deger :%d \n index: %d", enKucuk, index);
}

// en büyük değeri bulma
int enBuyuk()
{
    int a[5] = {5, 9, 65, 3, 7};
    int enBuyuk = 0;
    for (int i = 0; i < 5; i++)
    {
        if (enBuyuk <= a[i])
        {
            enBuyuk = a[i];
        }
    }

    return enBuyuk;
}

// dizi içindeki çift sayıları toplama
void ciftTopla()
{
    int a[5] = {5, 9, 2, 3, 4};
    int toplam = 0;

    for (int i = 0; i < 5; i++)
    {
        if (a[i] % 2 == 0)
        {
            toplam += a[i];
        }
    }
    printf("%d", toplam);
}

// sturct tanımala
typedef struct
{
    char name[20];
    char department[20];
    float fees;
    Student *next;
} Student;

void structTanimla()
{
    Student student1;
    student1.fees = 5;
    strcpy(student1.name, "name");
    strcpy(student1.department, "name");
    printf("%s", student1.name);
}

// hafta5
//  kendine referans yöntemi
struct node
{
    int data;
    struct node *next;
};

// liste üzerindeki her işlemde başlangıç node'u döndürülür.Başlangıç Nodu döndürülmeyen liste kaybolur!

// Liste oluşturma
struct node *create(struct node *start)
{
    int num;
    struct node *newNode, *ptr;
    printf("\n -1 girene kadar deger girin");
    printf("\n deger giriniz: ");
    scanf("%d", &num);

    while (num != -1)
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = num;
        if (start == NULL)
        {
            newNode->next = NULL;
            start = newNode;
        }
        else
        {
            ptr = start;
            while (ptr->next != NULL)
                ptr = ptr->next;
            ptr->next = newNode;
            newNode->next = NULL;
        }

        printf("\n Enter the data: ");
        scanf("%d", &num);
        printf("\n Number: %d", num);
    }
    return start;
}

// Liste elemanlarında gezinme
struct node *searchNode(struct node *start)
{

    struct node *ptr;
    ptr = start;
    while (ptr != NULL)
    {
        printf("\n %d", ptr->data);
        ptr = ptr->next;
    }
    return start;
}
// listenin başına eleman ekleme
struct node *insert_First(struct node *start)
{
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = 48;
    newNode->next = start;
    start = newNode;
    return start;
}
struct node *insert_End(struct node *start)
{
    struct node *newNode, *ptr;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = 52;
    ptr = start;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = newNode;
    newNode->next = NULL;
    return start;
}
// yukarıdaki donksiyonları aşağıda çağırısanız tüm kodlar sorunsuz çalışır!.

struct node *countNode(struct node *start)
{
    int sayac = 0;
    struct node *ptr;
    ptr = start;
    while (ptr != NULL)
    {
        ptr = ptr->next;
        sayac++;
    }
    printf("\n count: %d", sayac);
    return start;
}

// struct node *findNode(struct node *start)
// {
//     int deger;
//     printf("\n aranacak deger giriniz: ");
//     scanf("%d", &deger);

//     int *findElement;
//     struct node *ptr;
//     ptr = start;
//     while (ptr != NULL)
//     {
//         if (ptr->data == deger)
//         {
//             findElement = ptr;
//             printf("\n bellek adresi: %d", findElement);
//         }
//         ptr = ptr->next;
//     }
//     printf("\n bellek adresi: %d", findElement);
//     return start;
// }

struct node *insert_bag(struct node *start)
{
    struct node *newNode, *ptr, *prePtr;
    int num, value;
    printf("veri gir: ");
    scanf("%d", &num);
    printf("veri gir: ");
    scanf("%d", &value);
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = num;
    ptr = start;
    prePtr = ptr;
    while (prePtr->data != value)
    {
        prePtr = ptr;
        ptr = ptr->next;
    }
    prePtr->next = newNode;
    newNode->next = ptr;
    return start;
}
struct node *insert_MidAdd(struct node *start)
{
    struct node *newNode, *ptr, *prePtr;
    int num, value;
    printf("veri gir: ");
    scanf("%d", &num);
    printf("onune eklenecek veri: ");
    scanf("%d", &value);
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = num;
    ptr = start;
    prePtr = ptr;
    while (ptr->data != value)
    {
        prePtr = ptr;
        ptr = ptr->next;
    }
    prePtr->next = newNode;
    newNode->next = ptr;
    return start;
}

// listenin ilk elemanını siler
struct node *remove_firstNode(struct node *start)
{
    struct node *ptr;
    ptr = start;
    start = ptr->next;
    free(ptr);
    return start;
}

// listenin son elemanını siler
struct node *remove_endNode(struct node *start)
{
    struct node *ptr, *prePtr;
    ptr = start;
    prePtr = ptr;
    while (ptr->next != NULL)
    {
        prePtr = ptr;
        ptr = ptr->next;
    }
    free(ptr);
    prePtr->next = NULL;
    return start;
}

struct node *remove_midNode(struct node *start)
{
    struct node *ptr, *prePtr;
    int value;
    printf("\nsonrasinda silinecek veri: ");
    scanf("%d", &value);
    ptr = start;
    prePtr = ptr;
    while (ptr->data != value)
    {
        prePtr = ptr;
        ptr = ptr->next;
    }
    prePtr = ptr;
    ptr = ptr->next;
    prePtr->next = ptr->next;
    free(ptr);
    return start;
}
// hafta 6
//  döngüsel listenin başına eleman ekleme
struct node *addListFirst(struct node *start)
{
    struct node *newNode, *ptr;
    int num;
    printf("\n Veri Giriniz: ");
    scanf("%d", &num);
    newNode = (struct node *)malloc(sizeof(struct node));
    if (start == NULL)
    {
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
        start = newNode;
        return start;
    }
}

struct node2
{
    struct node2 *prev;
    int data;
    struct node2 *next;
};

struct node2 *insert_beg2(struct node2 *start)
{
    int num;
    struct node2 *newNode;
    newNode = (struct node2 *)malloc(sizeof(struct node2));
    printf("\n Deger giriniz : ");
    scanf("%d", &num);
    newNode->data = num;
    if (start == NULL)
    {
        newNode->next = NULL;
        newNode->prev = NULL;
        start = newNode;
    }
    else
    {
        newNode->next = start;
        start->prev = newNode;
        newNode->prev = NULL;
        start = newNode;
    }
    return start;
}

void display(struct node2 *start)
{
    struct node2 *ptr;
    ptr = start;
    while (ptr != NULL)
    {
        printf("\n data : %d", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{

    // enKucukIndex();
    // struct node *start = NULL;
    // start = create(start);
    // start = searchNode(start);
    // start = remove_midNode(start);
    // start = searchNode(start);
    // start = findNode(start);
    // start = countNode(start);
    // start = insert_First(start);
    // start = insert_End(start);
    // start = searchNode(start);
    struct node2 *start = NULL;
    start = insert_beg2(start);
    start = insert_beg2(start);
    display(start);
    return 0;
}