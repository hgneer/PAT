#include <iostream>

#include <cstdio>

#include <vector>

#include <queue>

#include <algorithm>

const int MAX = 100014;

const int EXAMPLE = 4;

using namespace std;



struct Node{

	int data;

	int left;

	int right;

}node[MAX];



int number, data;

vector<int> sequence;



int num = 0;



int index = 0;

void inorder(int root)

{

	if (root == -1){

		return;

	}

	inorder(node[root].left);

	node[root].data = sequence[index++];

	inorder(node[root].right);

}



int main()

{

	if(scanf("%d", &number) != 1){

    printf("Input error!\n");

  }

	for (int i = 0; i < number; i++){

    if(scanf("%d", &data) != 1){

      printf("Input error!\n");

    }

		sequence.push_back(data);

	}

	sort(sequence.begin(), sequence.end());

  int example = 0;

	for (int i = 1; i <= number; i++){

		node[i].left = 2 * i;

		node[i].right = 2 * i + 1;

		if (2 * i > number)

			node[i].left = -1;

		if (2 * i + 1 > number)

			node[i].right = -1;

	}



	inorder(1);



	for (int i = 1; i <= number; i++){

    if(example < EXAMPLE){

      printf("%d", node[i].data);

    }

		if (i != number){

      if(example < EXAMPLE){

        printf(" ");

      }

		}

	}



	return 0;

}


