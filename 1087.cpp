#include <map>
#include <vector>
#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

const int MAX = 1044;
const int INF = 1000000000;

int numCities,numRoutes;
string start;
string name;
string city1,city2;
int cost;
int numLeast = 0,ansCost = 0,ansHappiness = -1,ansAverage = -1;
map<string,int> stringToInt;
map<int,string> intToString;
bool vis[MAX] = {false};
int G[MAX][MAX];
int c[MAX],h[MAX],happiness[MAX];
vector<int> pre[MAX];
vector<int> tempPath,path;

int changeToInt(string str)
{
    map<string,int>::iterator it = stringToInt.find(str);
    if(it != stringToInt.end()){
        return it->second;
    }else{
        return -1;
    }
}

string changeToString(int id)
{
    map<int,string>::iterator it = intToString.find(id);
    if(it != intToString.end()){
        return it->second;
    }else{
        return NULL;
    }
}

void Dijkstra(int s)
{
    fill(c,c + MAX,INF);
    c[s] = 0;
    for(int i = 0;i < numCities;i++){
        int u = -1,min = INF;
        for(int j = 0;j < numCities;j++){
            if(c[j] < min && vis[j] == false){
                min = c[j];
                u = j;
            }
        }
        if(u == -1){
            return;
        }
        vis[u] = true;
        for(int v = 0;v < numCities;v++){
            if(vis[v] == false && G[u][v] != INF){
                if(c[u] + G[u][v] < c[v]){
                    c[v] = c[u] + G[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                }else if(c[u] + G[u][v] == c[v]){
                    pre[v].push_back(u);
                }
            }
        }
    }
}

void DFS(int e){
    if(e == 0){
        numLeast++;
        tempPath.push_back(e);
        int maxTemp = 0,averageTemp = 0;
        for(int i = 0;i < tempPath.size();i++){
            maxTemp += happiness[tempPath[i]];
        }
        averageTemp = maxTemp/(tempPath.size() - 1);
        if(maxTemp > ansHappiness){
            ansHappiness = maxTemp;
            ansAverage = averageTemp;
            path = tempPath;
        }else if(maxTemp == ansHappiness && averageTemp > ansAverage){
            ansAverage = averageTemp;
            path = tempPath;
        }
        tempPath.pop_back();
    }
    tempPath.push_back(e);
    for(int i = 0;i < pre[e].size();i++){
        DFS(pre[e][i]);
    }
    tempPath.pop_back();
}

int main()
{
    scanf("%d %d",&numCities,&numRoutes);
    cin >> start;
    stringToInt.insert(pair<string,int>(start,0));
    intToString.insert(pair<int,string>(0,start));
    happiness[0] = 0;
    for(int i = 1;i < numCities;i++){
        cin >> name >> happiness[i];
        stringToInt.insert(pair<string,int>(name,i));
        intToString.insert(pair<int,string>(i,name));
    }
    fill(G[0],G[0] + MAX*MAX,INF);
    for(int i = 1;i <= numRoutes;i++){
        cin >> city1 >> city2 >> cost;
        int id1 = changeToInt(city1);
        int id2 = changeToInt(city2);
        G[id1][id2] = G[id2][id1] = cost;
    }

    Dijkstra(0);
    DFS(changeToInt("ROM"));

    printf("%d %d %d %d\n",numLeast,c[changeToInt("ROM")],ansHappiness,ansAverage);
    for(int i = path.size() - 1;i >= 0;i--){
        cout << changeToString(path[i]);
        if(i != 0){
            printf("->");
        }
    }

    return 0;
}

