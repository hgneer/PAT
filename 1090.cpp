#include <iostream>

#include <cstdio>

#include <cstring>

#include <queue>

#include <vector>

#include <cmath>

const int MAX = 100004;

using namespace std;



struct node{

  int depth;

  vector<int> child;

}node[MAX];



int treedepth = -1;

int number,father,root;

double price,percentage,rate;

int depth,num;



void BFS(int root)

{

  queue<int> Queue;

  Queue.push(root);

  while(!Queue.empty()){

    int top = Queue.front();

    if(node[top].depth > treedepth){

      treedepth = node[top].depth;

      num = 1;

    }else if(node[top].depth == treedepth){

      num++;

    }

    Queue.pop();

    for(int i = 0;i < node[top].child.size();i++){

      node[node[top].child[i]].depth = node[top].depth+1;

      Queue.push(node[top].child[i]);

    }

  }

}



int main()

{

  scanf("%d%lf%lf",&number,&price,&percentage);

  rate = 1+percentage/100;

  for(int i = 0;i < number;i++){

    scanf("%d",&father);

    if(father == -1){

      root = i;

    }else{

      node[father].child.push_back(i);

    }

  }



  BFS(root);



  printf("%.2f %d",price*pow(rate,treedepth),num);





  return 0;

}


