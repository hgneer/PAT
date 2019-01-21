#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int MAX = 100044;
const int INF = 1000000000;
const int P = 10000019;
const int MOD = 1000000007;

char string1[MAX],string2[MAX];
bool hashTable[MAX] = {false};

int main()
{
    cin.getline(string1,MAX);
    cin.getline(string2,MAX);
    int lenString1 = strlen(string1);
    int lenString2 = strlen(string2);
    for(int i = 0;i < lenString2;i++){
        hashTable[string2[i]] = true;
    }
    for(int i = 0;i < lenString1;i++){
        if(hashTable[string1[i]] == false){
            printf("%c",string1[i]);
        }
    }

    return 0;
}

