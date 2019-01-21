#include <set>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

const int MAX = 1000044;
const int INF = 1000000000;

int number,Index;
set<int> hashTable[MAX];

int main()
{
    scanf("%d",&number);
    if(number <= 0){
        return 1;
    }
    for(int i = 0;i < number;i++){
        scanf("%d",&Index);
        if(Index > 0){
            int id = Index%MAX;
            hashTable[id].insert(Index);
        }
    }
    for(int i = 1;i < MAX;i++){
        if(hashTable[i].find(i) == hashTable[i].end()){
            printf("%d",i);
            break;
        }
    }
    return 0;
}

