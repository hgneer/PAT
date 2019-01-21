#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 100044;
const int INF = 1000000000;
const int P  = 1000019;
const int MOD = 1000000007;

struct Node{
    int first;
    int second;
    Node(int _first,int _second) : first(_first),second(_second) {}
};

int hashTable[MAX] = {0};
vector<int> input;
int numCoins,moneyToPay;
int value;
vector<Node> result;

bool cmp(Node a,Node b)
{
    return a.first < b.first;
}


int main()
{
    fill(hashTable,hashTable+MAX,0);
    scanf("%d %d",&numCoins,&moneyToPay);
    for(int i = 0;i < numCoins;i++){
        scanf("%d",&value);
        input.push_back(value);
        hashTable[value]++;
    }
    for(int i = 0;i < input.size();i++){
        if(2*input[i] == moneyToPay){
            if(hashTable[input[i]] >= 2){
                printf("%d %d",input[i],input[i]);
                return 0;
            }
        }else{
            if(hashTable[moneyToPay - input[i]] > 0){
                if(moneyToPay - input[i] > input[i]){
                    result.push_back(Node(input[i],moneyToPay - input[i]));
                }else{
                    result.push_back(Node(moneyToPay - input[i],input[i]));
                }
            }
        }
    }
    if(result.size() == 0){
        printf("No Solution");
    }else{
        sort(result.begin(),result.end(),cmp);
        printf("%d %d",result[0].first,result[0].second);
    }

    return 0;
}

