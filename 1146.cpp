#include <vector>
#include <queue>
#include <cstdio>
#include <iostream>
using namespace std;

const int MAX = 1044;

int numVertices,numEdges;
int start,End;
int numQueries,element;
vector<int> toBeTest;
vector<int> Adj[MAX];
int inDegree[MAX],tempInDegree[MAX];
vector<int> result;

int main()
{
    scanf("%d %d",&numVertices,&numEdges);
    fill(inDegree,inDegree + MAX,0);
    for(int i = 0;i < numEdges;i++){
        scanf("%d %d",&start,&End);
        Adj[start].push_back(End);
        inDegree[End]++;
    }
    scanf("%d",&numQueries);
    for(int i = 0;i < numQueries;i++){
        for(int j = 1;j <= numVertices;j++){
            tempInDegree[j] = inDegree[j];
        }
        int flag = 1;
        for(int j = 1;j <= numVertices;j++){
            scanf("%d",&element);
            if(tempInDegree[element] != 0){
                flag = 0;
            }else{
                for(int k = 0;k < Adj[element].size();k++){
                    tempInDegree[Adj[element][k]]--;
                }
            }
        }
        if(flag == 0){
            result.push_back(i);
        }
    }
    for(int i = 0;i < result.size();i++){
        printf("%d",result[i]);
        if(i != result.size() - 1){
            printf(" ");
        }
    }

    return 0;
}

