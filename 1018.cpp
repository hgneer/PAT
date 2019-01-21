#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

const int MAX = 1044;
const int INF = 1000000000;

int capacityMax,numStations,problem,numRoads;
int bikes[MAX];
int station1,station2,Time;
int G[MAX][MAX];
int d[MAX];
bool vis[MAX] = {false};
vector<int> pre[MAX];
vector<int> tempPath,path;
int sendMin = INF,takebackMin = INF;

void Dijkstra(int s)
{
    fill(d,d+MAX,INF);
    d[s] = 0;
    for(int i = 0;i <= numStations;i++){
        int u = -1;
        int min = INF;
        for(int j = 0;j <= numStations;j++){
            if(vis[j] == false && d[j] < min){
                min = d[j];
                u = j;
            }
        }
        if(u == -1){
            return;
        }
        vis[u] = true;
        for(int j = 0;j <= numStations;j++){
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

void DFS(int e)
{
    if(e == 0){
        tempPath.push_back(e);
        int send = 0,takeback = 0;
        for(int i = tempPath.size() - 2;i >= 0;i--){
            int v = tempPath[i];
            if(bikes[v] >= 0){
                takeback += bikes[v];
            }else{
                if(takeback >= -bikes[v]){
                    takeback += bikes[v];
                }else{
                    send += -bikes[v] - takeback;
                    takeback = 0;
                }
            }
            /*
            if(bikes[v] >= 0){
                takeback += bikes[v]
            }else{
                if(takeback >= abs(bikes[v])){
                    takeback -= abs(bikes[v]);
                }else{
                    send += abs(bikes[v]) - takeback;
                    takeback = 0;
                }
            }
            */
        }
        if(send < sendMin){
            sendMin = send;
            takebackMin = takeback;
            path = tempPath;
        }else if(send == sendMin){
            if(takeback < takebackMin){
                takebackMin = takeback;
                path = tempPath;
            }
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
    scanf("%d %d %d %d",&capacityMax,&numStations,&problem,&numRoads);
    int middle = capacityMax/2;
    for(int i = 1;i <= numStations;i++){
        scanf("%d",&bikes[i]);
        bikes[i] -= middle;
    }
    fill(G[0],G[0]+MAX*MAX,INF);
    for(int i = 0;i < numRoads;i++){
        scanf("%d %d %d",&station1,&station2,&Time);
        G[station1][station2] = G[station2][station1] = Time;
    }

    Dijkstra(0);
    DFS(problem);

    printf("%d ",sendMin);
    for(int i = path.size() - 1;i >= 0;i--){
        printf("%d",path[i]);
        if(i != 0){
            printf("->");
        }
    }
    printf(" %d",takebackMin);

    return 0;
}

