#include <stdio.h>
#include <string.h>

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

    for (int i = 0; i < 10 - 1; i++)
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
// dizinin ortasına eleman ekleme 1 2 3 4 5 p=2
void elemanEkle()
{

    int dizi[50] = {3, 8, 24, 2};
    int n = 4;
    int pos = 1;

    for (int i = n; i >= pos; i--)
    {
        dizi[i + 1] = dizi[i];
    }
    dizi[pos] = 11;
    for (int i = 0; i <= n; i++)
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

    for (int i = pos; i <= N - 1; i++)
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
    int enBuyuk = 100;
    int index = 0;
    int index2 = 0;

    for (int i = 0; i < 5; i++)
    {
        if (enBuyuk > a[i])
        {
            enBuyuk = a[i];
            index2 = index;
        }
        index++;
    }
    printf("deger :%d \n index: %d", enBuyuk, index2);
}

// en büyük değeri bulma
int buyuk()
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
} Student;

void structTanimla()
{
    Student student1;
    student1.fees = 5;
    strcpy(student1.name, "name");
    strcpy(student1.department, "name");
    printf("%s", student1.name);
}
int main()
{
}