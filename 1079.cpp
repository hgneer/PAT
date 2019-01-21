#define _CRT_NO_SECURE_WARNING

#include <iostream>

#include <cstdio>

#include <cstring>

#include <vector>

#include <cmath>

const int MAX = 100014;

using namespace std;



struct{

	int amount;

	vector<int> child;

}node[MAX];



int number;

double price,percentage,rate;

int childnum, childid,amount;

double sum = 0.0;



void preorder(int root,int num)

{

	if (node[root].child.size() == 0){

		sum = sum + price*pow(rate, num)*node[root].amount;

		return;

	}

	num += 1;

	for (int i = 0; i < node[root].child.size(); i++){

		preorder(node[root].child[i],num);

	}

}



int main()

{

	scanf("%d%lf%lf", &number, &price, &percentage);

	rate = 1.0 + percentage / 100;

	for (int i = 0; i < number; i++){

		scanf("%d", &childnum);

		if (childnum != 0){

			for (int j = 0; j < childnum; j++){

				scanf("%d", &childid);

				node[i].child.push_back(childid);

			}

		}

		else{

			scanf("%d", &amount);

			node[i].amount = amount;

		}

	}



	preorder(0,0);



	printf("%.1f", sum);





	return 0;

}
