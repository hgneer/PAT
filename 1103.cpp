#define _CRT_SECURE_NO_WARNING

#include <iostream>

#include <vector>

#include <cstdio>

#include <cmath>

using namespace std;



int maxn;

int N, K, P;

vector<int> fac,temp,ans;

int maxfacNumberSum = 0;



void DFS(int index,int nowK,int sum,int facNumberSum){

	if (nowK > K || sum > N)

		return;

	if (index == 0){

		if (nowK == K && sum == N && facNumberSum > maxfacNumberSum){

			maxfacNumberSum = facNumberSum;

			ans = temp;

		}

		return;

	}

	temp.push_back(index);

	DFS(index, nowK + 1, sum + fac[index], facNumberSum + index);

	temp.pop_back();

	DFS(index - 1, nowK, sum, facNumberSum);

}



int main()

{

	scanf("%d%d%d", &N, &K, &P);

	maxn = (int)(pow((double)N, 1.0 / P));

	for (int i = 0; i <= maxn; i++){

		fac.push_back(pow(i, P));

	}



	DFS(maxn, 0, 0, 0);

	if (!ans.empty()){

		printf("%d = ", N);

		vector<int>::iterator it = ans.begin();

		while (it != ans.end()){

			if (it != ans.end() - 1){

				printf("%d^%d + ", *it, P);

			}

			else{

				printf("%d^%d\n", *it, P);

			}

			it++;

		}

	}

	else{

		printf("Impossible\n");

	}



	return 0;

}


