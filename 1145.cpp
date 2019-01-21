#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

const int MAX = 100044;
int hashTable[MAX] = {0};

int userSize,numInputs,numKeys;
int input,key;

int isPrime(int userSize)
{
    for(int i = 2;i * i <= userSize;i++){
        if(userSize%i == 0){
            return false;
        }
    }
    return true;
}

int main()
{
    scanf("%d %d %d",&userSize,&numInputs,&numKeys);
    fill(hashTable,hashTable+MAX,0);
    int TSize = userSize;
    while(!isPrime(TSize)){
        TSize++;
    }
    for(int i = 0;i < numInputs;i++){
        scanf("%d",&input);
        int flag = 0;
        for(int j = 0;j < TSize;j++){
            int Index = (input + j * j)%TSize;
            if(hashTable[Index] == 0){
                hashTable[Index] = input;
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            printf("%d cannot be inserted.\n",input);
        }
    }
    int num = 0;
    for(int i = 0;i < numKeys;i++){
        scanf("%d",&key);
        for(int j = 0;j <= TSize;j++){
            int Index = (key + j * j) % TSize;
            num++;
            if(hashTable[Index] == key || hashTable[Index] == 0){
                break;
            }
        }
    }
    printf("%.1f",(num * 1.0)/numKeys);

    return 0;
}

