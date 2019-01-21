#include <iostream>

#include <cstdio>

#include <vector>

#include <cmath>

const int MAX = 100014;

using namespace std;



struct Node{

  int data;

  vector<int> child;

}node[MAX];



int number,childnum,childid;

double price,percentage;



int minIndex = MAX;

int num;



void preOrder(int root,int index)

{

  if(node[root].child.size() == 0){

    if(index < minIndex){

      minIndex = index;

      num = 1;

    }else if(index == minIndex){

      num++;

    }

    return;

  }else{

    for(int i = 0;i < (int)node[root].child.size();i++){

      preOrder(node[root].child[i],index+1);

    }

  }

}



int main()

{

  double rate;

  scanf("%d%lf%lf",&number,&price,&percentage);

  rate = 1 + percentage/100;



  for(int i = 0;i < number;i++){

    scanf("%d",&childnum);

    for(int j = 0;j < childnum;j++){

      scanf("%d",&childid);

      node[i].child.push_back(childid);

    }

  }



  preOrder(0,0);



  printf("%.4f %d",price*pow(rate,minIndex),num);



  return 0;

}






