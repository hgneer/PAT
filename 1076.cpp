#include <queue>
#include <vector>
#include <cstdio>
#include <iostream>
using namespace std;

const int MAX = 10004;
const int INF = 1000000000;

struct Node{
    int id;
    int layer;
    Node(int _id,int _layer) : id(_id),layer(_layer) {};
};

int number,level;
int total,idol;
int k,id;
bool inq[MAX] = {false};
int test = 0,result = 0;
vector<Node> Adj[MAX];

void BFS(int s)
{
    queue<Node> q;
    Node start(s,0);
    q.push(start);
    inq[start.id] = true;
    result = 0;
    while(!q.empty()){
        Node u = q.front();
        if(u.layer >= level){
            return;
        }else{
            q.pop();
            for(int i = 0;i < Adj[u.id].size();i++){
                Node v = Adj[u.id][i];
                v.layer = u.layer + 1;
                if(inq[v.id] == false){
                    result++;
                    q.push(v);
                    inq[v.id] = true;
                }
            }
        }
    }
}

int main()
{
    scanf("%d %d",&number,&level);
    for(int i = 1;i <= number;i++){
        scanf("%d",&total);
        for(int j = 1;j <= total;j++){
            scanf("%d",&idol);
            Adj[idol].push_back(Node(i,0));
        }
    }
    scanf("%d",&k);
    for(int i = 1;i <= k;i++){
        scanf("%d",&id);

        for(int j = 1;j <= number;j++){
            inq[j] = false;
        }

        BFS(id);

        printf("%d",result);
        if(i != k){
            printf("\n");
        }
    }

    return 0;
}

