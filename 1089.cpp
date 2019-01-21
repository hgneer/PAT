#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
const int MAX = 10004;
using namespace std;

int flag = 0;
int getResult = 0;

//插入排序
void insertSort(int array[],int n,int test[])
{
    for(int i = 2;i <= n;i++){
        int temp = array[i];
        int j = i;
        while(temp < array[j - 1] && j > 0){
            array[j] = array[j - 1];
            j--;
        }
        array[j] = temp;
        if(getResult == 0){
            int h = 1;
            while( array[h] == test[h] && h <= n){
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

void merge(int array[],int L1,int R1,int L2,int R2)
{
    int i = L1,j = L2;
    int temp[MAX];
    int k = 0;
    while(i <= R1 && j <= R2){
        if(array[i] <= array[j]){
            temp[k++] = array[i++];
        }else if(array[i] > array[j]){
            temp[k++] = array[j++];
        }
    }
    while(i <= R1){
        temp[k++] = array[i++];
    }
    while(j <= R2){
        temp[k++] = array[j++];
    }
    for(int h = 0;h < k;h++){
        array[L1 + h] = temp[h];
    }
}

//归并排序
void mergeSort(int array[],int n,int test[])
{
    getResult = 0;
    for(int step = 2;step / 2 <= n;step *= 2){
        for(int i = 1;i <= n;i += step){
            //sort(array+i,array+min(i+step,n+1));
            //上边是n+1是因为sort函数对区间左闭右开，下边则是自己写的
            //merge函数对区间是左闭右闭的缘故
            int mid = i + step / 2 - 1;
            if(mid + 1 <= n){
                merge(array,i,mid,mid + 1,min(i + step - 1,n));
            }
        }
        if(getResult == 0){
            int h = 1;
            while( array[h] == test[h] && h <= n){
                h++;
            }
            if(h == n + 1){
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

    insertSort(array,number,test);

    if(flag == 1){
        printf("Insertion Sort\n");
        for(int i = 1;i <= number;i++){
            printf("%d",array[i]);
            if(i != number){
                printf(" ");
            }
        }
    }else{
        printf("Merge Sort\n");
        mergeSort(arrayMerge,number,test);
        for(int i = 1;i <= number;i++){
            printf("%d",arrayMerge[i]);
            if(i != number){
                printf(" ");
            }
        }
    }

    return 0;
}

