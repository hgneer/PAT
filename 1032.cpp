#include <iostream>

#include <string>

#include <cstdio>

const int MAX = 100014;



using namespace std;



struct Node{

	char data;

	int next;

	bool flag;

}nodetest[MAX];



int main()

{

	int firstinlet, secondinlet, number;

	scanf("%d %d %d", &firstinlet, &secondinlet, &number);

	int address, next;

	char data;



	for (int i = 0; i < MAX; i++){

		nodetest[i].flag = false;

	}



	for (int i = 0; i < number; i++){

		scanf("%d %c %d", &address, &data, &next);

		nodetest[address].data = data;

		nodetest[address].next = next;

	}



	for (int i = firstinlet; i != -1; i = nodetest[i].next){

		nodetest[i].flag = true;

	}



	int banner = -1;



	for (int i = secondinlet; i != -1; i = nodetest[i].next){

		if (nodetest[i].flag == 1){

			banner = i;

			break;

		}

	}



	if (banner != -1){

		printf("%05d\n", banner);

	} else{

		printf("-1\n");

	}



	return 0;

}
