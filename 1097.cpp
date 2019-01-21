#define _CRT_SECURE_NO_WARNING

#include <algorithm>

#include <iostream>

#include <cstdio>

#include <cmath>

const int MAX = 100014;

using namespace std;



struct Node{

	int address;

	int data;

	int next;

	int order;

}node[MAX];



bool isExisted[MAX];



bool cmp(Node first, Node second)

{

	return first.order < second.order;

}



int main()

{

	for (int i = 0; i < MAX; i++){

		node[i].order = 2 * MAX;

		isExisted[i] = false;

	}



	int entrance, number;

	scanf("%d%d", &entrance, &number);



	if (entrance == -1){

		return 0;

	}

	else{

		int address;

		for (int i = 0; i < number; i++){

			scanf("%d", &address);

			node[address].address = address;

			scanf("%d%d", &node[address].data, &node[address].next);

		}



		int validNumber = 0;

		int invalidNumber = 0;

		for (int i = entrance; i != -1; i = node[i].next){

			if (isExisted[abs(node[i].data)] == false){

				isExisted[abs(node[i].data)] = true;

				node[i].order = validNumber;

				validNumber++;

			}

			else{

				node[i].order = MAX + invalidNumber;

				invalidNumber++;

			}

		}



		number = validNumber + invalidNumber;

		sort(node, node + MAX, cmp);



		for (int i = 0; i < number; i++){

			printf("%05d %d ", node[i].address,node[i].data);

			if (i == validNumber - 1 || i == number - 1){

				printf("-1\n");

			}

			else{

				printf("%05d\n",node[i+1].address);

			}

		}



		return 0;

	}

}
