#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int currcomparesRS = 0;
int currcomparesS = 0;
int comparesRS = 0 ;
int comparesS = 0;
int avgcomparesRS = 0;
int mincomparesRS = INT_MAX;
int maxcomparesRS = INT_MIN;
int avgcomparesS = 0;
int mincomparesS = INT_MAX;
int maxcomparesS = INT_MIN;


int randomizedSelect(int *arrayToSort, int size, int element, int start, int end){

    if(start==end) {
        if(currcomparesRS<mincomparesRS){
            mincomparesRS=currcomparesRS;
        }
        if(currcomparesRS>maxcomparesRS){
            maxcomparesRS=currcomparesRS;
        }
        return arrayToSort[start];
    }

    int r=randPartition(arrayToSort,start,end);

    int k;
    k=r-start+1;

    currcomparesRS++;
    comparesRS++;

    if(element==k){
        if(currcomparesRS<mincomparesRS){
            mincomparesRS=currcomparesRS;
        }
        if(currcomparesRS>maxcomparesRS){
            maxcomparesRS=currcomparesRS;
        }
        return arrayToSort[r];
    }
    else {
        currcomparesRS++;
        comparesRS++;
        if (element < k) {
            return randomizedSelect(arrayToSort, size, element, start, r - 1);
        } else {
            currcomparesRS++;
            comparesRS++;
            if (element > k) {
                return randomizedSelect(arrayToSort, size, element - k, r + 1, end);
            }
        }
    }
}


int randPartition(int *arrayToSort,int start,int end){

    int pivotIndex = start+rand()%(end-start+1);
    int pivot = arrayToSort[pivotIndex];
    swap(arrayToSort,pivotIndex,end);
    int storeIndex = start;

    for(int i=start; i<=end-1; i++){
        currcomparesRS++;
        comparesRS++;
        if(arrayToSort[i] < pivot){
            swap(arrayToSort,i,storeIndex);
            storeIndex++;
        }
    }
    swap(arrayToSort,storeIndex,end);

    return storeIndex;
}


void printArray(int *arrayToSort, int size){

    printf("\n");
    for(int i=0;i<size;i++){
        printf("%d ", arrayToSort[i]);
    }
    printf("\n");
}


void swap(int *arr, int first, int second){

    int temp;

    temp=arr[first];
    arr[first]=arr[second];
    arr[second]=temp;
}


void random(int *arrayToSort, int size){

    for(int i=0;i<size;i++){
        arrayToSort[i]= rand();
    }
}


void permutation(int *arrayToSort, int size){

    for(int i=0;i<size;i++)
        arrayToSort[i]=i+1;


    for(int i = size-1; i > 0; i--){
        int j = rand() % (i+1);
        swap(arrayToSort, i, j);
    }
}


int select(int *arrayToSort, int left, int right, int searchedElement, int size){

    comparesS++;
    currcomparesS++;

    if(left==right) {
        if(currcomparesS<mincomparesS){
            mincomparesS=currcomparesS;
        }
        if(currcomparesS>maxcomparesS){
            maxcomparesS=currcomparesS;
        }
        return left;
    }

    int pivotIndex=pivot(arrayToSort,left,right,size);
    pivotIndex=partition(arrayToSort,left,right,pivotIndex);
    currcomparesS++;
    comparesS++;
    if(pivotIndex==searchedElement){
        if(currcomparesS<mincomparesS){
            mincomparesS=currcomparesS;
        }
        if(currcomparesS>maxcomparesS){
            maxcomparesS=currcomparesS;
        }
        return pivotIndex;
    } else {
        currcomparesS++;
        comparesS++;
        if (searchedElement < pivotIndex) {
            return select(arrayToSort, left, pivotIndex - 1, searchedElement, size);
        } else {
            currcomparesS++;
            comparesS++;
            if (searchedElement > pivotIndex) {
                return select(arrayToSort, pivotIndex + 1, right, searchedElement, size);
            }
        }
    }

}

int pivot(int *arrayToSort,int left, int right, int sizeOfSequence){

    int subRight;
    int m;
    int i;

    comparesS++;
    if(right-left<5)
        return sort(arrayToSort,left,right);
    int j = left;
    for(int i=left;i<right;i+=5){

        subRight=i+4;
        currcomparesS++;
        comparesS++;
        if(subRight>right)
            subRight=right;

        m=sort(arrayToSort,i,subRight);

        swap( arrayToSort, m, j++ );

    }
    return select(arrayToSort,left,j-1,(j-1+left)/2,sizeOfSequence);
}


int partition(int *arrayToSort, int start, int end, int pivotIndex){

    int storeIndex;
    int pivot = arrayToSort[pivotIndex];

    swap(arrayToSort,pivotIndex,end);
    storeIndex=start;

    int i;


    for(i=start; i<=end; i++){
        currcomparesS++;
        comparesS++;
        if(arrayToSort[i] < pivot){
            swap(arrayToSort,i,storeIndex);
            storeIndex++;
        }
    }
    swap(arrayToSort,end,storeIndex);


    return storeIndex;
}

int sort(int *arrayToSort,int left, int right){

    int key;
    int k;
    int min;
    int max;

    min=left;
    max=right;

    for(int j=min;j<=max;j++){

        key=arrayToSort[j];
        k=j-1;

        while(k>=min && arrayToSort[k]>key){
            arrayToSort[k+1]=arrayToSort[k];
            k--;
        }
        arrayToSort[k+1]=key;
    }

    return (right+left)/2;
}


int main(){

    int size;
    int action;
    int element;

    FILE *fileRS, *fileS;
    fileS = fopen("selection.txt", "w");
    fileRS = fopen("randselection.txt", "w");

        printf("\nWybierz jedna z opcji:");
        printf("\n1. Permutation Randomized Select");
        printf("\n2. Random Randomized Select");
        printf("\n3. Permutation Select");
        printf("\n4. Random Select");

        printf("\nOpcja: ");
        scanf("%d", &action);

        printf("Rozmiar tablicy: ");
        scanf("%d", &size);

        printf("Numer statystyki pozycyjnej: ");
        scanf("%d", &element);

        int arrayToSort[size];

        if(action == 1) {

            if (element > size || element == 0) {
                printf("\n\nZle dane\n\n");
            } else {

                permutation(arrayToSort, size);

                if (size <= 15) {
                    printArray(arrayToSort, size);
                }

                int number = randomizedSelect(arrayToSort, size, element, 0, size - 1);
                printf("Wynik: %d\n", number);
                if (size <= 15) {
                    sort(arrayToSort, 0, size - 1);
                    for (int i = 0; i < size; i++) {
                        if (i + 1 == element) {
                            printf("[%d] ", arrayToSort[i]);
                        } else {
                            printf("%d ", arrayToSort[i]);
                        }
                    }
                }

            }

        }
            if( action == 2) {

                    if (element > size || element == 0) {
                        printf("\n\nwrong data\n\n");
                    } else {
                        random(arrayToSort, size);

                        if (size <= 15) {
                            printArray(arrayToSort, size);
                        }

                        int number = randomizedSelect(arrayToSort,size,element,0,size-1);

                        printf("Wynik: %d\n", number);
                        if (size <= 15) {
                            sort(arrayToSort, 0, size - 1);
                            for(int i=0;i<size;i++){
                                if(i+1 == element) {
                                    printf("[%d] ", arrayToSort[i]);
                                }else{
                                    printf("%d ", arrayToSort[i]);
                                }
                            }
                        }
                    }

            }
            if(action == 3) {

                    if (element > size) {
                        printf("\n\nZle dane\n\n");
                    } else {
                        permutation(arrayToSort, size);

                        if (size <= 15) {
                            printArray(arrayToSort, size);
                        }
                        int number = select(arrayToSort, 0, size - 1, element, size);
                        printf("Wynik: %d\n", arrayToSort[number]);
                        if (size <= 15) {
                            sort(arrayToSort, 0, size - 1);
                            for(int i=0;i<size;i++){
                                if(i+1 == element) {
                                    printf("[%d] ", arrayToSort[i]);
                                }else{
                                    printf("%d ", arrayToSort[i]);
                                }
                            }
                        }
                    }


            }
            if(action == 4) {
                    if (element > size) {
                        printf("\n\nZle dane\n\n");
                    } else {

                        random(arrayToSort, size);

                        if (size <= 15) {
                            printArray(arrayToSort, size);
                        }

                        int number = select(arrayToSort, 0, size - 1, element, size);
                        printf("lol\n");
                        printf("Wynik: %d\n", arrayToSort[number]);
                        if (size <= 15) {
                            sort(arrayToSort, 0, size - 1);
                            for(int i=0;i<size;i++){
                                if(i+1 == element) {
                                    printf("[%d] ", arrayToSort[i]);
                                }else{
                                    printf("%d ", arrayToSort[i]);
                                }
                            }
                        }
                    }
            }

        if (action!=1 && action!=2 && action!=3 && action!=4){
            printf("Bledne dane");
            return 0;
        }

            size=100;


            for(int i=0;i<300;i++){

                int arrayToSort[size];
                int randSelectArray[size];
                int selectArray[size];

                comparesRS = 0 ;
                comparesS = 0;
                avgcomparesRS = 0;
                mincomparesRS = INT_MAX;
                maxcomparesRS = INT_MIN;
                avgcomparesS = 0;
                mincomparesS = INT_MAX;
                maxcomparesS = INT_MIN;

                random(arrayToSort,size);

                for(int k = 0; k<size; k++) {
                    randSelectArray[k] = arrayToSort[k];
                    selectArray[k] = arrayToSort[k];
                }
                int r=rand()*size/RAND_MAX;

                for(int j=0; j<100; j++) {
                    currcomparesS = 0;
                    currcomparesRS = 0;
                    randomizedSelect(randSelectArray,size,r,0,size-1);

                    select(selectArray, 0, size - 1, r, size);
                }

                avgcomparesRS = comparesRS/100;
                avgcomparesS = comparesS/100;

                fprintf(fileS,"%d %d %d %d\n",size, mincomparesS, maxcomparesS, avgcomparesS);
                fprintf(fileRS,"%d %d %d %d\n",size, mincomparesRS, maxcomparesRS, avgcomparesRS);
                //printf("%d\n",size);
                size+=100;
            }

    return 0;
}


