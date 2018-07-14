#include <stdio.h>
#include <stdlib.h>


int print = 0;
int comparise = 0, swap =0 ;
int partition(int *arr, int p, int r, int s)
{
    int x = arr[p];
    int i = p, j = r, tmp;
    while (1)
    {
        while (arr[j] > x) {
            j--;
            comparise++;
        }
        while (arr[i] < x) {
            comparise++;
            i++;
        }
        if (i < j)
        {
            swap++;
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
            if(print == 0) {
                for (int k = 0; k < s; k++) {
                    if (k == p) {
                        printf("[%d] ", arr[p]);
                    } else {
                        if (k == i - 1 || k == j + 1) {
                            printf("(%d) ", arr[k]);
                        } else {
                            printf("%d ", arr[k]);
                        }
                    }
                }
                printf("\n");
            }
        }
        else
            return j;
    }

}

void quicksort(int *arr, int p, int r, int s)
{
    int q;
    if (p < r) {
        q = partition(arr, p, r, s);
        quicksort(arr, p, q, s);
        quicksort(arr, q + 1, r, s);
    }
}

int main()
{
    int i;


    FILE *file;
    file = fopen("quick sort.txt", "w");

    int action = 0, size = 0;

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
            printf("%d ",arr[i]);
        }
    }else {
        if (action == 2) {
            for(int i = 0; i<size; i++){
                arr[i] = size - i;
            }
        } else {
            printf ("Błędne dane");
            return 1;
        }
    }

    quicksort(arr,0,size-1, size);
    size = 100;
    print = 1;

    while(size<=20000){
        swap = 0;
        comparise =0;
        int arr[size];
        for(int k = 0; k < 100; k++) {
            for (int i = 0; i < size; i++) {
                arr[i] = rand();
            }
            quicksort(arr, 0, size - 1, size);
        }
        comparise = comparise/100;
        swap = swap/100;
        fprintf(file,"%d %d %d\n", size, comparise, swap);
        size = size+100;
       // printf("%d\n",size);
    }



    return 0;


}
