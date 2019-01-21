#include <iostream>

#include <stack>

#include <cstdio>

#include <cstring>

#include <string>

const int MAX = 10014;

using namespace std;



int preArray[MAX], inArray[MAX];

char option[9];



struct Node{

	int data;

	Node* left = NULL;

	Node* right = NULL;

}node;



int number;



Node* create(int preL, int preR, int inL, int inR)

{

	if (preL <= preR){

		Node* root = new Node;

		root->data = preArray[preL];

		int k;

		for (k = inL; k <= inR; k++)

		{

			if (inArray[k] == preArray[preL])

				break;

		}

		int num = k - inL;

		root->left = create(preL + 1, preL + num, inL, k - 1);

		root->right = create(preL + num + 1, preR, k + 1, inR);



		return root;

	}

	else{

		return NULL;

	}

}



int countnum = 0;



void postorder(Node* root)

{

	if (root == NULL){

		return;

	}

	postorder(root->left);

	postorder(root->right);

	if (countnum < number - 1){

		printf("%d ", root->data);

	}

	else{

		printf("%d", root->data);

	}

	countnum++;

}



int main()

{

	stack<int> Stack;

	scanf("%d", &number);

	int prenum = 0;

	int innum = 0;



	int temp;

	for (int i = 0; i < 2 * number; i++){

		scanf("%s", option);

		if (strcmp(option,"Push") == 0){

			scanf("%d", &temp);

			preArray[prenum++] = temp;

			Stack.push(temp);

		}

		else{

			if (!Stack.empty()){

				inArray[innum++] = Stack.top();

				Stack.pop();

			}

		}

	}



	Node* root = create(0, prenum - 1, 0, innum - 1);

	postorder(root);





	return 0;

}








