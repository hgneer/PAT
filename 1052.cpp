#include <iostream>

#include <cstring>

#include <cstdio>

#include <vector>

#include <algorithm>

const int MAX = 100014;

using namespace std;



struct Node{

	int address;

	int key;

	int next;

	bool flag;

}node[MAX];



bool cmp(struct Node first, struct Node second)

{

	return !first.flag || !second.flag ? first.flag > second.flag : first.key < second.key;

}



int main()

{

	for (int i = 0; i < MAX; i++){

		node[i].flag = false;

	}



	int number, entrance;

	int address;



	scanf("%d%d", &number, &entrance);



	for (int i = 0; i < number; i++){

		scanf("%d ", &address);

		scanf("%d%d",&node[address].key, &node[address].next);

		node[address].address = address;

	}

	int count = 0;

	for (int i = entrance; i != -1; i = node[i].next){

		count++;

		node[i].flag = true;

	}



	if (count == 0){

		printf("0 -1");

	}

	else{

		sort(node, node + MAX, cmp);



		printf("%d %05d\n", count, node[0].address);

		for (int i = 0; i < count; i++){

			if (i != count - 1){

				printf("%05d %d %05d\n", node[i].address, node[i].key, node[i + 1].address);

			}

			else{

				printf("%05d %d -1\n", node[i].address, node[i].key);

			}

		}

	}





	return 0;

}
