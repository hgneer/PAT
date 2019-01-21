#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

const int MAX = 1004;
const int INF = 1000000000;

int numCities,numRemaining,numToBeCheck;
int city1,city2;
int concern;
vector<int> Adj[MAX];
int father[MAX];
bool vis[MAX] = {false};

void init()
{
    for(int i = 1;i < MAX;i++){
        father[i] = i;
        vis[i] = false;
    }
}

int findFather(int x)
{
    int a = x;
    while(father[x] != x){
        x = father[x];
    }
    while(father[a] != a){
        int temp = a;
        a = father[a];
        father[temp] = x;
    }
    return x;
}

void Union(int x,int y)
{
    int faX = findFather(x);
    int faY = findFather(y);
    if(faX != faY){
        father[faX] = faY;
    }
}

int main()
{
    scanf("%d %d %d",&numCities,&numRemaining,&numToBeCheck);
    for(int i = 1;i <= numRemaining;i++){
        scanf("%d %d",&city1,&city2);
        Adj[city1].push_back(city2);
        Adj[city2].push_back(city1);
    }
    for(int i = 1;i <= numToBeCheck;i++){
        scanf("%d",&concern);
        init();
        for(int j = 1;j <= numCities;j++){
            for(int h = 0;h < Adj[j].size();h++){
                if(j == concern || Adj[j][h] == concern){
                    continue;
                }
                Union(j,Adj[j][h]);
            }
            vis[j] = false;
        }
        int num = 0;
        for(int j = 1;j <= numCities;j++){
            if(j == concern){
                continue;
            }
            int faJ = findFather(j);
            if(vis[faJ] == false){
                num++;
                vis[faJ] = true;
            }
        }
        printf("%d",num - 1);
        if(i != numToBeCheck){
            printf("\n");
        }
    }

    return 0;
}

