#include <map>
#include <vector>
#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

const int MAX = 2044;
const int INF = 1000000000;

map<string,int> stringToInt;
map<int,string> intToString;
map<string,int> Gang;
int number,threshold;
string str1,str2;
int numPerson = 0,w,weight[MAX] = {0};

struct Node{
    int id;
    int weight;

    Node(int _id,int _weight){
        id = _id;
        weight = _weight;
    }
};

vector<Node> Adj[MAX];
bool vis[MAX] = {false};

void DFS(int nowVisit,int &head,int &numMember,int &totalValue)
{
    numMember++;
    vis[nowVisit] = true;
    if(weight[nowVisit] > weight[head]){
        head = nowVisit;
    }
    for(int i = 0;i < Adj[nowVisit].size();i++){
        totalValue += Adj[nowVisit][i].weight;
        if(vis[Adj[nowVisit][i].id] == false){
            DFS(Adj[nowVisit][i].id,head,numMember,totalValue);
        }
    }
}

void DFSTravel()
{
    for(int i = 0;i < numPerson;i++){
        if(vis[i] == false){
            int nowVisit = i,head = i,numMember = 0,totalValue = 0;
            DFS(nowVisit,head,numMember,totalValue);
            if(numMember > 2 && totalValue > threshold){
                Gang[intToString[head]] = numMember;
            }
        }
    }
}

int change(string str)
{
    if(stringToInt.find(str) != stringToInt.end()){
        return stringToInt[str];
    }else{
        stringToInt[str] = numPerson;
        intToString[numPerson] = str;
        return numPerson++;
    }
}

int main()
{
    scanf("%d %d",&number,&threshold);

    for(int i = 0;i < number;i++){
        cin >> str1 >> str2 >> w;
        int id1 = change(str1);
        int id2 = change(str2);
        weight[id1] += w;
        weight[id2] += w;
        Adj[id1].push_back(Node(id2,w));
    }

    DFSTravel();

    cout << Gang.size() << endl;
    map<string,int>::iterator it;

    for(it = Gang.begin();it != Gang.end();it++){
        cout << it->first << " " << it->second << endl;
    }

    return 0;
}

