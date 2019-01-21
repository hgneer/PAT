#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 4444;
const int INF = 1000000000;

int numHouses,numCandidates,numRoads,maxRange;
char end1[7],end2[7];
int integerEnd1,integerEnd2;
int length;
int bestLocation;
double minimum,average;

struct Node{
    int id;
    int length;
    Node(int _id,int _length) : id(_id),length(_length) {}
};

struct Result{
    int index;
    double minimum,average;
}result[MAX];

int num;
vector<Node> Adj[MAX];
int dist[MAX];
bool vis[MAX] = {false};


bool cmp(Result a,Result b)
{
    if(a.minimum != b.minimum){
        return a.minimum > b.minimum;
    }else if(a.average != b.average){
        return a.average < b.average;
    }else{
        return a.index < b.index;
    }
}

void Dijkstra(int s)
{
    fill(dist,dist+MAX,INF);
    dist[s] = 0;
    for(int i = 1;i <= num;i++){
        int u = -1,min = INF;
        for(int j = 1;j <= num;j++){
            if(dist[j] < min && vis[j] == false){
                u = j;
                min = dist[j];
            }
        }
        if(u == -1){
            return;
        }
        vis[u] = true;
        for(int j = 0;j < Adj[u].size();j++){
            int v = Adj[u][j].id;
            if(vis[v] == false && dist[u] + Adj[u][j].length < dist[v]){
                dist[v] = dist[u] + Adj[u][j].length;
            }
        }
    }
}

int getID(char str[])
{
    int id = 0;
    if(str[0] != 'G'){
        sscanf(str,"%d",&id);
        return id;
    }else{
        sscanf(str + 1,"%d",&id);
        return id + numHouses;
    }
}


int main()
{
    scanf("%d %d %d %d",&numHouses,&numCandidates,&numRoads,&maxRange);
    if(numHouses <= 0){
        printf("No solution");
        return 0;
    }
    num = numHouses + numCandidates;
    for(int i = 1;i <= numRoads;i++){
        scanf("%s %s %d",end1,end2,&length);
        integerEnd1 = getID(end1);
        integerEnd2 = getID(end2);
        Adj[integerEnd1].push_back(Node(integerEnd2,length));
        Adj[integerEnd2].push_back(Node(integerEnd1,length));
    }

    int k = 0;
    for(int i = 1;i <= numCandidates;i++){
        memset(vis,false,sizeof(vis));
        Dijkstra(i + numHouses);
        double mini = INF,sum = 0;
        int maxi = -1;
        for(int j = 1;j <= numHouses;j++){
            if(dist[j] < mini){
                mini = dist[j];
            }
            if(dist[j] > maxi){
                maxi = dist[j];
            }
            sum += dist[j];
        }
        if(maxi <= maxRange && maxi != -1){
            result[k].index = i;
            result[k].minimum = mini;
            result[k++].average = sum/numHouses;
        }
    }

    sort(result,result+k,cmp);

    if(k == 0 || result[0].minimum == INF){
        printf("No Solution");
    }else{
        printf("G%d\n",result[0].index);
        printf("%.1f %.1f",result[0].minimum,result[0].average);
    }

    return 0;
}

