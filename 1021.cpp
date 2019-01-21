#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 100004;
const int INF = 1000000000;

int number;
int node1,node2;
int result[MAX],result1[MAX],result2[MAX];
vector<int> Adj[MAX];
bool vis[MAX] = {false};
int num = 0;
int deepest = 0,test = 0,k1 = 0,k2 = 0;

int father[MAX];

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
    while(x != father[x]){
        x = father[x];
    }
    while(a != father[a]){
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

bool isExist(int result[],int n,int x)
{
    for(int i = 0;i < n;i++){
        if(result[i] == x){
            return true;
        }
    }
    return false;
}

void DFS1(int u,int depth,int origin)
{
    if(depth > deepest){
        deepest = depth;
        k1 = 0;
        if(!isExist(result1,k1,u)){
            result1[k1++] = u;
        }
    }else if(depth == deepest){
        if(!isExist(result1,k1,u)){
            result1[k1++] = u;
        }
    }
    vis[u] = true;
    for(int i = 0;i < Adj[u].size();i++){
        int v = Adj[u][i];
        if(vis[v] == false){
            DFS1(v,depth+1,origin);
        }
    }
}

void DFS2(int u,int depth,int origin)
{
    if(depth > deepest){
        deepest = depth;
        k2 = 0;
        if(!isExist(result2,k2,u)){
            result2[k2++] = u;
        }
    }else if(depth == deepest){
        if(!isExist(result2,k2,u)){
            result2[k2++] = u;
        }
    }
    vis[u] = true;
    for(int i = 0;i < Adj[u].size();i++){
        int v = Adj[u][i];
        if(vis[v] == false){
            DFS2(v,depth+1,origin);
        }
    }
}

int main()
{
    scanf("%d",&number);
    init();
    for(int i = 1;i < number;i++){
        scanf("%d %d",&node1,&node2);
        Union(node1,node2);
        Adj[node1].push_back(node2);
        Adj[node2].push_back(node1);
    }
    int num = 0;
    for(int i = 1;i <= number;i++){
        int faI = findFather(i);
        if(vis[faI] == false){
            num++;
            vis[faI] = true;
        }
    }
    if(num > 1){
        printf("Error: %d components",num);
    }else{
        memset(vis,false,sizeof(vis));
        DFS1(1,1,1);
        deepest = 0;
        memset(vis,false,sizeof(vis));
        DFS2(result1[0],1,result1[0]);
        int k = 0;
        for(int i = 0;i < k1;i++){
            if(!isExist(result,k,result1[i])){
                result[k++] = result1[i];
            }
        }
        for(int i = 0;i < k2;i++){
            if(!isExist(result,k,result2[i])){
                result[k++] = result2[i];
            }
        }
        sort(result,result+k);

        for(int i = 0;i < k;i++){
            printf("%d",result[i]);
            if(i != k-1){
                printf("\n");
            }
        }
    }

    return 0;
}

