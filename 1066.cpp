#include <iostream>

#include <cstdio>

#include <vector>

using namespace std;



typedef struct Node{

	Node *left, *right;

	int value, height;

};



Node* newNode(int value)

{

	Node* root = new Node;

	root->left = root->right = NULL;

	root->value = value;

	root->height = 1;

	return root;

}



int max(int a, int b)

{

	if (a >= b) {

		return a;

	}else {

		return b;

	}

}



int getHeight(Node* root)

{

	if (root == NULL) {

		return 0;

	}else{

		return root->height;

	}

}





void updateHeight(Node* root)

{

	root->height = max(getHeight(root->left),getHeight(root->right)) + 1;

}



int getBalanceFactor(Node* root)

{

	return getHeight(root->left) - getHeight(root->right);

}



void L(Node* &root)

{

	Node *temp = root->right;

	root->right = temp->left;

	temp->left = root;

	updateHeight(root);

	updateHeight(temp);

	root = temp;

}



void R(Node* &root)

{

	Node* temp = root->left;

	root->left = temp->right;

	temp->right = root;

	updateHeight(root);

	updateHeight(temp);

	root = temp;

}



void insert(Node* &root, int value)

{

	if (root == NULL) {

		root = newNode(value);

		return;

	}

	else if (value < root->value) {

		insert(root->left, value);

		updateHeight(root);

		if (getBalanceFactor(root) == 2) {

			if (getBalanceFactor(root->left) == 1) {

				R(root);

			}

			else {

				L(root->left);

				R(root);

			}

		}

	}

	else {

		insert(root->right, value);

		updateHeight(root);

		if (getBalanceFactor(root) == -2) {

			if (getBalanceFactor(root->right) == -1) {

				L(root);

			}

			else {

				R(root->right);

				L(root);

			}

		}

	}

}



Node* create(vector<int> input) {

	int length = input.size();

	Node* root = NULL;

	for (int i = 0; i < length; i++) {

		insert(root, input[i]);

	}

	return root;

}



int main()

{

	int number,value;

	vector<int> input;

	scanf("%d", &number);

	for (int i = 0; i < number; i++) {

		scanf("%d", &value);

		input.push_back(value);

	}



	Node* root = create(input);





	printf("%d", root->value);



	return 0;

}
