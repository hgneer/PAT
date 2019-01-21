#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 10004;
const int INF = 1000000000;

int numCities,numRoads,cityCurrent,citySave;
int person[MAX];
int city1,city2,length;

struct Node{
    int city;
    int length;
    Node(int _city,int _length) : city(_city),length(_length) {};
};

vector<Node> Adj[MAX];
bool vis[MAX] = {false};
int d[MAX],p[MAX],num[MAX];

void Dijkstra(int s)
{
    fill(d,d+MAX,INF);
    d[s] = 0;
    fill(p,p+MAX,0);
    p[s] = person[s];
    fill(num,num+MAX,0);
    num[s] = 1;
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
        for(int j = 0;j < Adj[u].size();j++){
            int v = Adj[u][j].city;
            if(vis[v] == false){
                if(d[u] + Adj[u][j].length < d[v]){
                    d[v] = d[u] + Adj[u][j].length;
                    p[v] = p[u] + person[v];
                    num[v] = num[u];
                }else if(d[u] + Adj[u][j].length == d[v]){
                    num[v] += num[u];
                    if(p[u] + person[v] > p[v]){
                        p[v] = p[u] + person[v];
                    }
                }
            }
        }
    }
}


int main()
{
    scanf("%d %d %d %d",&numCities,&numRoads,&cityCurrent,&citySave);
    for(int i = 0;i < numCities;i++){
        scanf("%d",&person[i]);
    }

    for(int i = 0;i < numRoads;i++){
        scanf("%d %d %d",&city1,&city2,&length);
        Adj[city1].push_back(Node(city2,length));
        Adj[city2].push_back(Node(city1,length));
    }

    Dijkstra(cityCurrent);

    printf("%d %d",num[citySave],p[citySave]);

    return 0;
}

