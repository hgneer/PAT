#define _CRT_SECURE_NO_WARING

#include <iostream>

#include <cstdio>

#include <queue>

const int MAXM = 1400;

const int MAXN = 140;

const int MAXL = 70;

using namespace std;



struct Node{

	int x, y, z;

}node;



int grossvolume = 0;

int M, N, L, T;

int X[6] = { 1, -1, 0, 0, 0, 0 };

int Y[6] = { 0, 0, 1, -1, 0, 0 };

int Z[6] = { 0, 0, 0, 0, 1, -1 };

bool inq[MAXM][MAXN][MAXL];

int region[MAXM][MAXN][MAXL];



bool judge(int x, int y, int z)

{

	if (x < 0 || x > M || y < 0 || y > N || z < 0 || z > L){

		return false;

	}

	if (inq[x][y][z] == true || region[x][y][z] == 0){

		return false;

	}

	return true;

}



void BFS(int x, int y, int z)

{

	node.x = x;

	node.y = y;

	node.z = z;

	queue<Node> Queue;

	inq[node.x][node.y][node.z] = true;

	Queue.push(node);

	int volume = 1;

	while (!Queue.empty()){

		Node top = Queue.front();

		Queue.pop();

		Node temp;

		for (int i = 0; i < 6; i++){

			temp.x = top.x + X[i];

			temp.y = top.y + Y[i];

			temp.z = top.z + Z[i];

			if (judge(temp.x, temp.y, temp.z)){

				volume += 1;

				inq[temp.x][temp.y][temp.z] = true;

				Queue.push(temp);

			}

		}

	}

	if (volume >= T){

		grossvolume += volume;

	}

}



int main()

{

	scanf("%d%d%d%d", &M, &N, &L, &T);

	for (int z = 0; z < L; z++){

		for (int x = 0; x < M; x++){

			for (int y = 0; y < N; y++){

				scanf("%d", &region[x][y][z]);

			}

		}

	}

	for (int z = 0; z < L; z++){

		for (int x = 0; x < M; x++){

			for (int y = 0; y < N; y++){

				if (judge(x, y, z)) BFS(x, y, z);

			}

		}

	}



	printf("%d\n", grossvolume);

	return 0;

}


