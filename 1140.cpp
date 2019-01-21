#include <cmath>

#include <vector>

#include <cstdio>

#include <iostream>

using namespace std;



const int MAX = 100044;

const int INF = 1000000000;

const int P = 10000019;

const int MOD = 1000000007;

const double eps = 1e-8;

const double pi = acos(-1.0);



int D, number;

vector<int> origin,result;



vector<int> getSequence(vector<int> origin)

{

	vector<int> temp;

	int i = 0;

	int k = 1;

	for (i = 0; i < origin.size() - 1; i++) {

		if (origin[i + 1] == origin[i]) {

			k++;

		}

		else {

			temp.push_back(origin[i]);

			temp.push_back(k);

			k = 1;

		}

	}

	temp.push_back(origin[i]);

	temp.push_back(k);



	return temp;

}



int main()

{

	scanf("%d %d", &D, &number);



	origin.push_back(D);



	for (int i = 1; i < number; i++) {

		origin = getSequence(origin);

	}



	for (int i = 0; i < origin.size(); i++) {

		printf("%d", origin[i]);

	}



	return 0;

}
