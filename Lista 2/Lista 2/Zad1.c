#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *file;
    file = fopen("insertion sort.txt", "w");

    int action = 0, size = 0;

    int swap = 0, compare = 0;

    printf("Wybierz sposób generowania danych:\n"
                   "1. Losowy ciąg\n"
                   "2. Ciąg posortowany malejąco.\n");
    scanf("%d",&action);

    printf("Podaj rozmiar danych:\n");
    scanf("%d", &size);

    int arr[size];
    int i = 0, j = 0, x = 0;

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
            printf ("Błędne dane");
            return 1;
        }
    }


    for(i = 0; i < size; i++) printf("%d ",arr[i]);
    printf("\n");

    for(j = size - 2; j >= 0; j--)
    {
        x = arr[j];
        i = j + 1;
        while((i < size) && (x > arr[i]))
        {
            arr[i - 1] = arr[i];
            i++;
        }

        arr[i - 1] = x;
        for(int k = 0; k < size; k++) {
            if(k==i-1) {
                printf("(%d) ", arr[k]);
            }else {
                if (k == j) {
                    printf("[] %d ", arr[k]);
                } else {
                    printf("%d ", arr[k]);
                }
            }
        }
        printf("\n");
    }



    printf("Po sortowaniu:\n\n");
    for(i = 0; i < size; i++) printf("%d ",arr[i]);
    printf("\n");

    size =100 ;
    while(size <= 10000){
        swap = 0;
        compare = 0;
        int arr[size];


        for(int k = 0; k<50; k++) {
            for(int i = 0; i<size; i++){
                arr[i] = rand() % 1000;
            }
            for (j = size - 2; j >= 0; j--) {
                x = arr[j];
                i = j + 1;
                while ((i < size) && (x > arr[i])) {
                    swap++;
                    compare++;
                    arr[i - 1] = arr[i];
                    i++;
                }
                swap ++;
                arr[i - 1] = x;
            }
        }
        compare = compare/100;
        swap =swap/100;
        fprintf(file,"%d %d %d\n", size, compare, swap);
       // printf("%d\n", size);
        size = size+100;

    }
    return 0;
}