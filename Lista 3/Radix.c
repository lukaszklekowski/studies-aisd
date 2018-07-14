
#include<stdio.h>
#include <stdlib.h>

int compares = 0;
int swap = 0;
int printing = 0;

int getMax(int *arr, int size)
{
    int m = arr[0];
    for (int i = 1; i < size; i++)
        if (arr[i] > m)
            m = arr[i];
    return m;
}


void countSort(int *arr, int size, int rad)
{
    int temp[size];
    int i, count[10] = {0};


    for (i = 0; i < size; i++)
        count[ (arr[i]/rad)%10 ]++;


    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];


    for (i = size- 1; i >= 0; i--)
    {
        swap++;
        temp[count[ (arr[i]/rad)%10 ] - 1] = arr[i];
        count[ (arr[i]/rad)%10 ]--;
    }


    for (i = 0; i < size; i++) {
        swap++;
        arr[i] = temp[i];
    }
}


void radixsort(int *arr, int size)
{

    int m = getMax(arr, size);


    for (int rad = 1; m/rad > 0; rad *= 10) {
        countSort(arr, size, rad);
        if(printing == 0) {
            printf("\nSortowanie wg.: %d's\n", rad);
            print(arr, size);
        }
    }
}

void print(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
}

int main()
{

    FILE *file;
    file = fopen("radixsort1333.txt", "w");
    int size =0;
    int action= 0;

    printf("Wybierz sposob generowania danych:\n"
                   "1. Losowy ciag\n"
                   "2. Ciag posortowany malejaco.\n");
    scanf("%d",&action);

    printf("Podaj rozmiar danych:\n");
    scanf("%d", &size);

    int arr[size];

    if(action == 1){
        for(int i = 0; i < size; i++){
            arr[i] = rand();
        }
    }else {
        if (action == 2) {
            for(int i = 0; i<size; i++){
                arr[i] = size - i;
            }
        } else {
            printf ("Bledne dane");
            return 1;
        }
    }

    print(arr,size);

    radixsort(arr,size);

    printing = 1;


    size =100 ;

     while(size <= 10000){
         compares = 0;
         swap = 0;

         int arr[size];
         for(int i = 0; i<size; i++){
             arr[i] = rand() % 1000;
         }

         for(int j = 0;j<100; j++) {
             radixsort(arr, size);
         }
         compares = compares/100;
         swap = swap/100;
         fprintf(file,"%d %d %d\n", size, compares, swap);
         size+=100;
        // printf("%d\n", size);
     }

     return 0;
 }