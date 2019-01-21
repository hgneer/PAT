#include <set>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int MAX = 10044;
char beadsOwner[MAX],beadsEva[MAX];
int hashTable[MAX] = {0};

int hashFunc(char c)
{
    if('A' <= c && c <= 'Z'){
        return c - 'A';
    }else if('a' <= c && c <= 'z'){
        return c - 'a' + 26;
    }else if('0' <= c && c <= '9'){
        return c - '0' + 52;
    }
}

int main()
{
    fill(hashTable,hashTable+MAX,0);
    set<int> result;
    scanf("%s %s",beadsOwner,beadsEva);
    int lenOwner = strlen(beadsOwner);
    int lenEva = strlen(beadsEva);
    for(int i = 0;i < lenEva;i++){
        int Index = hashFunc(beadsEva[i]);
        hashTable[Index]++;
    }
    for(int i = 0;i < lenOwner;i++){
        int Index = hashFunc(beadsOwner[i]);
        if(hashTable[Index] > 0){
            hashTable[Index]--;
        }
    }
    int need = 0;
    for(int i = 0;i < lenEva;i++){
        int Index = hashFunc(beadsEva[i]);
        result.insert(Index);
    }
    for(set<int>::iterator it = result.begin();it != result.end();it++){
        need += hashTable[*it];
    }
    if(need == 0){
        printf("Yes %d",lenOwner - lenEva);
    }else{
        printf("No %d",need);
    }

    return 0;
}

