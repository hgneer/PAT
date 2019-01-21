#define _CRT_NO_SECURE_WARING

#include <iostream>

#include <cstdio>

#include <stack>

#include <algorithm>

const int MAX = 10004;

using namespace std;



int main()

{

	int capacity, length, testcases;

	int array[MAX];

	bool isvalid[MAX];

	fill(isvalid, isvalid + MAX,false);

	scanf("%d%d%d", &capacity, &length, &testcases);

	stack<int> check;

	for (int i = 0; i < testcases; i++){

		while (!check.empty()){

			check.pop();

		}

		for (int j = 1; j <= length; j++){

			scanf("%d", &array[j]);

		}



		int token = 1;

		int count = 0;

		int flag = 1;



		for (int j = 1; j <= length; j++){

			check.push(j);

			if (check.size() > capacity){

				flag = 0;

				break;

			}

			while ( !check.empty() && check.top() == array[token]){

				check.pop();

				token++;

			}

		}



		if (flag == 1 && check.empty()){

			isvalid[i] = true;

		}



	}



	for (int i = 0; i < testcases; i++){

		if (isvalid[i] == true){

			printf("YES\n");

		}

		else{

			printf("NO\n");

		}

	}



	return 0;

}




