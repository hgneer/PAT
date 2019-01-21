#include <iostream>

#include <cstdio>

#include <vector>

#include <queue>

#include <algorithm>

const int MAX = 100014;

using namespace std;



struct Node{

	int data;

	int left;

	int right;

}node[MAX];

int number, leftchild, rightchild,data;

vector<int> sequence;



int num = 0;

void inorder(int root)

{

	if (root == -1){

		return;

	}

	inorder(node[root].left);

	node[root].data = sequence[num++];

	inorder(node[root].right);

}



int quantity = 0;

void levelorder(int root)

{

	queue<int> Queue;

	Queue.push(root);

	while (!Queue.empty()){

		int top = Queue.front();

		printf("%d", node[top].data);

		quantity++;

		if (quantity != number){

			printf(" ");

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







int main()

{

	scanf("%d", &number);

	for (int i = 0; i < number; i++){

		scanf("%d%d", &leftchild, &rightchild);

		node[i].left = leftchild;

		node[i].right = rightchild;

	}

	for (int i = 0; i < number; i++){

		scanf("%d", &data);

		sequence.push_back(data);

	}

	sort(sequence.begin(), sequence.end());



	inorder(0);

	levelorder(0);



	return 0;

}
