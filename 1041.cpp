#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

const int MAX = 100044;
const int INF = 1000000000;

int number,bet;
int hashTable[MAX];
vector<int> input;

int main()
{
    scanf("%d",&number);
    fill(hashTable,hashTable+MAX,0);
    for(int i = 0;i < number;i++){
        scanf("%d",&bet);
        input.push_back(bet);
        hashTable[bet]++;
    }
    for(int i = 0;i < input.size();i++){
        if(hashTable[input[i]] == 1){
            printf("%d",input[i]);
            return 0;
        }
    }
    printf("None");

    return 0;
}

