#include <iostream>
#include <cstdio>
using namespace std;

const int MAX = 10004;

int Count = 0;

int downCompare(int heap[],int low,int high,int banner)
{
    int i = low,j = i*2;

    if(banner == 1){
        while(j <= high){
            if(j + 1 <= high && heap[j+1] > heap[j]){
                j = j + 1;
            }
            if(heap[i] >= heap[j]){
                i = j;
                j = i*2;
            }else{
                return 0;
            }
        }
    }else{
        while(j <= high){
            if(j + 1 <= high && heap[j+1] < heap[j]){
                j = j + 1;
            }
            if(heap[i] <= heap[j]){
                i = j;
                j = i*2;
            }else{
                return 0;
            }
        }
    }

    return 1;
}

int compare(int heap[],int n,int banner)
{
    int flag = 1;

    for(int i = n/2;i >= 1;i--){
        flag = downCompare(heap,i,n,banner);
        if(flag == 0){
            return 0;
        }
    }

    return 1;
}

void postOrder(int heap[],int n,int root)
{
    if(root > n){
        return;
    }
    int left = root * 2;
    int right = left + 1;
    postOrder(heap,n,left);
    postOrder(heap,n,right);
    printf("%d",heap[root]);
    Count++;
    if(Count != n){
        printf(" ");
    }
}

int main()
{
    int treeNumber,keyNumber;
    int heap[MAX];

    scanf("%d%d",&treeNumber,&keyNumber);


    for(int i = 1;i <= treeNumber;i++){
        for(int j = 1;j <= keyNumber;j++){
            scanf("%d",&heap[j]);
        }
        if(compare(heap,keyNumber,1) == 1){
            printf("Max Heap\n");
        }else if(compare(heap,keyNumber,0) == 1){
            printf("Min Heap\n");
        }else{
            printf("Not Heap\n");
        }
        Count = 0;
        postOrder(heap,keyNumber,1);
        printf("\n");
    }

    return 0;
}

