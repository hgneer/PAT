#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
const int MAX = 10004;
using namespace std;

int *heap,n = 10;

int getResult = 0;
int flag = 0;

//插入排序
void insertSort(int array[],int test[],int n)
{
    for(int i = 2;i <= n;i++){
        int temp = array[i];
        int j = i;
        while(temp < array[j - 1] && j > 0){
            array[j] = array[j - 1];
            j--;
        }
        array[j] = temp;
        int h = 1;
        if(getResult == 0){
            while(array[h] == test[h] && h <= n){
                h++;
            }
            if(h == n+1){
                flag = 1;
                getResult = 1;
            }
        }else{
            return;
        }
    }
}

void downAdjust(int low,int high)
{
    int i = low,j = i*2;
    while(j <= high){
        if(j + 1 <= high && heap[j + 1] > heap[j]){
            j = j + 1;
        }
        if(heap[j] > heap[i]){
            swap(heap[j],heap[i]);
            i = j;
            j = i*2;
        }else{
            break;
        }
    }
}

void createHeap(int array[],int number)
{
    heap = array;
    n = number;

    for(int i = n/2;i >= 1;i--){
        downAdjust(i,n);
    }
}

//堆排序
void heapSort(int array[],int test[],int number)
{
    getResult = 0;
    createHeap(array,number);
    for(int i = n;i > 1;i--){
        swap(heap[i],heap[1]);
        downAdjust(1,i-1);
        int h = 1;
        if(getResult == 0){
            while(array[h] == test[h] && h <= n){
                h++;
            }
            if(h == n+1){
                getResult = 1;
            }
        }else{
            return;
        }
    }
}

int main()
{
    int number;
    int array[MAX],test[MAX],arrayMerge[MAX];
    scanf("%d",&number);

    for(int i = 1;i <= number;i++){
        scanf("%d",&array[i]);
        arrayMerge[i] = array[i];
    }
    for(int i = 1;i <= number;i++){
        scanf("%d",&test[i]);
    }

    insertSort(array,test,number);

    if(flag == 1){
        printf("Insertion Sort\n");
        for(int i = 1;i <= number;i++){
            printf("%d",array[i]);
            if(i != number){
                printf(" ");
            }
        }
    }else{
        heapSort(arrayMerge,test,number);

        printf("Heap Sort\n");
        for(int i = 1;i <= number;i++){
            printf("%d",arrayMerge[i]);
            if(i != number){
                printf(" ");
            }
        }
    }

    return 0;
}

