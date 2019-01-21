#include <iostream>

#include <cstring>

#include <cstdio>

#include <vector>

#include <queue>

const int MAX = 100014;

using namespace std;



struct Node{

  int data;

  int depth;

  vector<int> child;

}node[MAX];



int leaf[MAX] = {0};

int number,nonleafnum,nonleafid,childnum,childid;

int treedepth = -1;



void BFS(int root)

{

  queue<int> Queue;

  node[root].depth = 0;

  Queue.push(root);

  while(!Queue.empty()){

    int top = Queue.front();

    if(node[top].depth > treedepth){

      treedepth = node[top].depth;

    }

    if(node[top].child.size() == 0){

      leaf[node[top].depth]++;

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

  scanf("%d%d",&number,&nonleafnum);

  for(int i = 0;i < nonleafnum;i++){

    scanf("%d%d",&nonleafid,&childnum);

    for(int i = 0;i < childnum;i++){

      scanf("%d",&childid);

      node[nonleafid].child.push_back(childid);

    }

  }



  BFS(1);



  for(int i = 0;i <= treedepth;i++){

    if(i != treedepth){

      printf("%d ",leaf[i]);

    }else{

      printf("%d",leaf[i]);

    }

  }



  return 0;

}


