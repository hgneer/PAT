#include <iostream>

#include <cstdio>

#include <queue>

const int MAX = 1014;

using namespace std;



int num = 0;

int number;

int postArray[MAX], inArray[MAX];

struct Node{

	int data;

	Node* left = NULL;

	Node* right = NULL;

}node;



Node* create(int postL, int postR, int inL, int inR)

{

	if (postL <= postR){

		Node* root = new Node;

		root->data = postArray[postR];

		int k;



		for (k = inL; k <= inR; k++){

			if (inArray[k] == postArray[postR]){

				break;

			}

		}



		int number2 = k - inL;

		root->left = create(postL, postL + number2 - 1, inL, inL + number2 - 1);

		root->right = create(postL + number2, postR - 1, inL + number2 + 1, inR);

		return root;

	}

	else{

		return NULL;

	}

}



void layerorder(Node* root)

{

	queue<Node*> Queue;

	Queue.push(root);

	while (!Queue.empty()){

		Node* top = Queue.front();

		if (num < number - 1){

			printf("%d ", top->data);

		}

		else{

			printf("%d", top->data);

		}

		num++;

		Queue.pop();

		if (top->left){

			Queue.push(top->left);

		}

		if (top->right){

			Queue.push(top->right);

		}

	}

}



int main()

{

	scanf("%d", &number);



	for (int i = 1; i <= number; i++){

		scanf("%d", &postArray[i]);

	}

	for (int i = 1; i <= number; i++){

		scanf("%d", &inArray[i]);

	}



	Node* root = create(1, number, 1, number);

	layerorder(root);





	return 0;

}


