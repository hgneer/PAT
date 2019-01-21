#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

const int MAX = 1044;
const int INF = 1000000000;

int numCities,numHighways,start,destination;
int city1,city2,Distance,cost;
int G[MAX][MAX],c[MAX][MAX];

bool vis[MAX] = {false};
int d[MAX];
vector<int> pre[MAX];

vector<int> tempPath,path;

int totalDistance = 0;

void Dijkstra(int s)
{
    fill(d,d+MAX,INF);
    d[s] = 0;
    memset(vis,false,sizeof(vis));
    for(int i = 0;i < numCities;i++){

        int u = -1;
        int min = INF;

        for(int j = 0;j < numCities;j++){
            if(vis[j] == false && d[j] < min){
                min = d[j];
                u = j;
            }
        }
        if(u == -1){
            return;
        }
        vis[u] = true;
        for(int j = 0;j < numCities;j++){
            if(vis[j] == false && G[u][j] != INF){
                if(d[u] + G[u][j] < d[j]){
                    d[j] = d[u] + G[u][j];
                    pre[j].clear();
                    pre[j].push_back(u);
                }else if(d[u] + G[u][j] == d[j]){
                    pre[j].push_back(u);
                }
            }
        }
    }
}

int value = 0;
int valueMin = INF;

void DFS(int e)
{
    if(e == start){
        tempPath.push_back(e);
        value = 0;
        for(int i = tempPath.size() - 1;i > 0;i--){
            value += c[tempPath[i]][tempPath[i-1]];
        }
        if(value < valueMin){
            valueMin = value;
            path = tempPath;
        }
        tempPath.pop_back();
        return;
    }

    tempPath.push_back(e);
    for(int i = 0;i < pre[e].size();i++){
        DFS(pre[e][i]);
    }
    tempPath.pop_back();
}

int main()
{
    fill(G[0],G[0] + MAX*MAX,INF);
    fill(c[0],c[0] + MAX*MAX,INF);
    scanf("%d %d %d %d",&numCities,&numHighways,&start,&destination);
    for(int i = 0;i < numHighways;i++){
        scanf("%d %d %d %d",&city1,&city2,&Distance,&cost);
        G[city1][city2] = Distance;
        G[city2][city1] = Distance;
        c[city1][city2] = cost;
        c[city2][city1] = cost;
    }

    Dijkstra(start);
    DFS(destination);

    int i = path.size() - 1;
    for(i = path.size() - 1;i > 0;i--){
        totalDistance += G[path[i]][path[i - 1]];
        printf("%d ",path[i]);
    }
    printf("%d %d %d",path[i],totalDistance,valueMin);

    return 0;
}

