#include <iostream>

#include <cstdio>

#include <cstring>

#include <string>

#include <queue>

#include <algorithm>

const int MAX = 40;

using namespace std;



struct Node{

	int data;

	int left;

	int right;

}node[MAX];

bool isroot[MAX] = { true };

int number;

int incount = 0;

int layercount = 0;



void inorder(int root){

	if (root == -1){

		return;

	}



	inorder(node[root].left);

	printf("%d", node[root].data);

	if (incount < number - 1){

		printf(" ");

		incount++;

	}

	inorder(node[root].right);

}



void layerorder(int root)

{

	queue<int> Queue;

	Queue.push(root);

	while (!Queue.empty()){

		int top = Queue.front();

		printf("%d", node[top].data);

		if (layercount < number - 1){

			printf(" ");

			layercount++;

		}

		Queue.pop();

		if (node[top].left != -1){

			Queue.push(node[top].left);

		}

		if (node[top].right != -1){

			Queue.push(node[top].right);

		}

	}

}



int stringToInt(char temp[]){

	int k;

	if (strcmp(temp,"-") != 0){

		sscanf(temp, "%d", &k);

	}

	else{

		k = -1;

	}

	return k;

}



int main()

{

	fill(isroot, isroot + MAX, true);



	scanf("%d", &number);

	if (number != 0){

		char left[10];

		char right[10];



		for (int i = 0; i < number; i++){

			scanf("%s%s", right, left);

			int intright = stringToInt(right);

			int intleft = stringToInt(left);



			node[i].data = i;

			node[i].left = intleft;

			node[i].right = intright;

			if (intright != -1){

				isroot[intright] = false;

			}

			if (intleft != -1){

				isroot[intleft] = false;

			}

		}





		int root;



		for (root = 0; root < number; root++){

			if (isroot[root] == true){

				break;

			}

		}



		layerorder(root);

		printf("\n");

		inorder(root);

	}



	return 0;

}
