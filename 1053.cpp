#include <iostream>

#include <cstdio>

#include <cstring>

#include <vector>

#include <queue>

#include <algorithm>

const int MAX = 10014;

using namespace std;

int number,nonleaf,neededweight;

struct{

	int weight;

	vector<int> child;

}node[MAX];



int num = 0;

vector<int> track[MAX];

vector<int> nowtrack;



void preorder(int root,vector<int> nowtrack,int nowweight)

{

	nowweight += node[root].weight;

	nowtrack.push_back(node[root].weight);

	if (nowweight > neededweight){

		nowtrack.clear();

		return;

	}

	if (node[root].child.size() == 0){

		if (nowweight == neededweight){

			track[num++] = nowtrack;

		}

		nowtrack.clear();

		return;

	}

	else{

		for (int i = 0; i < node[root].child.size(); i++){

			preorder(node[root].child[i], nowtrack, nowweight);

		}

	}

}



void layerorder(int root)

{

	queue<int> Queue;

	Queue.push(root);

	while (!Queue.empty()){

		int top = Queue.front();

		printf("%d ", node[top].weight);

		Queue.pop();

		for (int i = 0; i < node[top].child.size(); i++){

			Queue.push(node[top].child[i]);

		}

	}

}



bool cmp(vector<int> a, vector<int> b)

{

	return a > b;

}



int main()

{

	scanf("%d%d%d", &number,&nonleaf,&neededweight);

	for (int i = 0; i < number; i++){

		scanf("%d", &node[i].weight);

	}



	int id, childnum, childid;

	for (int i = 0; i < nonleaf; i++){

		scanf("%d%d", &id, &childnum);

		for (int j = 0; j < childnum; j++){

			scanf("%d", &childid);

			node[id].child.push_back(childid);

		}

	}



	preorder(0,nowtrack,0);

	sort(track, track + num,cmp);

	for (int i = 0; i < num; i++)

	{

		int j;

		for (j = 0; j < track[i].size() - 1; j++){

			printf("%d ", track[i][j]);

		}

		printf("%d", track[i][j]);

		if (i != num - 1){

			printf("\n");

		}

	}



	return 0;

}
