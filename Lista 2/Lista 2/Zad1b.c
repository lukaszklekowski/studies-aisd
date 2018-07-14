#include <stdio.h>
#include <stdlib.h>


int swap = 0, comparise = 0;
int size=0;
int tmp[100000];
int print = 0;

void merge(int *arr, int start, int mid, int end)
{
    int i,j,q;
    for (i=start; i<=end; i++) {
        tmp[i]=arr[i];
    }
    i=start; j=mid+1; q=start;
    while (i<=mid && j<=end) {
        comparise ++;
        if (tmp[i]<tmp[j]) {
            swap++;
            arr[q++] = tmp[i++];
        }
        else {
            swap++;
            arr[q++] = tmp[j++];
        }
    }
    while (i<=mid) {
        swap++;
        arr[q++]=tmp[i++];
    }
    if(print == 0) {
        printf("[");
        for (int k = start; k <= end; k++) {
            if (k == end) {
                printf("%d", arr[k]);
            } else {
                printf("%d|", arr[k]);
            }
        }
        printf("]");
        printf("\n");
    }
}


void mergesort(int *arr, int start, int end)
{
    int mid;
    if (start<end) {
        mid=(start+end)/2;
        mergesort(arr, start, mid);
        mergesort(arr, mid+1, end);
        merge(arr, start, mid, end);
    }
}

int main() {
    int i;

    FILE *file;
    file = fopen("merge sort.txt", "w");

    int action = 0;

    printf("Wybierz sposob generowania danych:\n"
                   "1. Losowy ciag\n"
                   "2. Ciag posortowany malejaco.\n");
    scanf("%d",&action);

    printf("Podaj rozmiar danych:\n");
    scanf("%d", &size);

    int arr[size];

    if(action == 1){
        for(int i = 0; i < size; i++){
            arr[i] = rand() % 100;
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

    printf("Zbior przed sortowaniem:\n");
    for (i=0; i<size; i++)
        printf("%d ", arr[i]);

    printf("\n");

    mergesort(arr, 0,size-1);

    printf("\nZbior po sortowaniu:\n");
    for (i=0; i<size; i++)
        printf("%d ", arr[i]);
    size = 100;
    print = 1;

    while(size<=30000){
        swap = 0;
        comparise =0;
        int arr[size];

        for(int k = 0; k<100; k++) {
            for(int i = 0; i<size; i++){
                arr[i] = rand();
            }
            mergesort(arr, 0, size - 1);
        }
        comparise = comparise/100;
        swap = swap/100;
        fprintf(file,"%d %d %d\n", size, comparise, swap);
        size = size+100;
        //printf("%d\n",size);
    }

    return 0;

}