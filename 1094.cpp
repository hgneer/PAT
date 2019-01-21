#include <iostream>

#include <cstring>

#include <queue>

#include <vector>

const int MAX = 10014;

using namespace std;



struct Node{

  vector<int> child;

  int depth;

}node[MAX];



int number,nonleaf;

int member[MAX] = {0};

int treedepth;

int maxmember = 0;

int requireddepth;



void layerorder(int root)

{

  queue<int> Queue;

  node[root].depth = 1;

  Queue.push(root);

  while(!Queue.empty()){

    int top = Queue.front();

    member[node[top].depth]++;

    if(node[top].depth > treedepth){

      treedepth = node[top].depth;

    }

    Queue.pop();

    for(int i = 0;i < (int)node[top].child.size();i++){

      node[node[top].child[i]].depth = node[top].depth + 1;

      Queue.push(node[top].child[i]);

    }

  }

}



int main()

{

  scanf("%d%d",&number,&nonleaf);

  int id,childnum,childid;

  for(int i = 1;i <= nonleaf;i++){

    scanf("%d %d",&id,&childnum);

    for(int j = 0;j < childnum;j++){

      scanf("%d",&childid);

      node[id].child.push_back(childid);

    }

  }



  layerorder(1);



  for(int i = 1;i <= treedepth;i++){

    if(member[i] > maxmember){

      maxmember = member[i];

      requireddepth = i;

    }

  }



  printf("%d %d",maxmember,requireddepth);





  return 0;

}




