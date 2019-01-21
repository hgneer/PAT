#include <set>

#include <cstdio>

#include <vector>

#include <string>

#include <iostream>

#include <algorithm>

using namespace std;



const int MAX = 1044;

const int INF = 1000000000;



int numVertices, numEdges;

int vertice1, vertice2;

int numQueries;

int numDistinct, vertice;

int hashTable[MAX] = {false};

set<int> Adj[MAX];

set<string> sequences;



bool isClique(vector<int> vectorToBeTest)

{

	int low = 0;

	int high = vectorToBeTest.size() - 1;

	int i = low;

	int flag = 1;

	while (i <= high) {

		for (int j = low; j <= high; j++) {

			if (vectorToBeTest[i] == vectorToBeTest[j]) {

				continue;

			}

			else {

				if (Adj[vectorToBeTest[i]].find(vectorToBeTest[j]) == Adj[vectorToBeTest[i]].end()) {

					flag = 0;

					break;

				}

			}

		}

		i++;

	}

	if (flag) {

		return true;

	}

	else {

		return false;

	}

}



bool isMaximalClique(vector<int> vectorToBeTest)

{

	for (int i = 1; i <= numVertices; i++) {

		if (hashTable[i] == false) {

			int flag = 1;

			for (int j = 0; j < vectorToBeTest.size(); j++) {

				if (Adj[vectorToBeTest[j]].find(i) == Adj[vectorToBeTest[j]].end()) {

					flag = 0;

					break;

				}

			}

			if (flag == 1) {

				return false;

			}

		}

	}

	return true;

}



int main()

{

	scanf("%d %d", &numVertices, &numEdges);

	for (int i = 1; i <= numEdges; i++) {

		scanf("%d %d", &vertice1, &vertice2);

		Adj[vertice1].insert(vertice2);

		Adj[vertice2].insert(vertice1);

	}

	scanf("%d", &numQueries);

	for (int i = 1; i <= numQueries; i++) {

		scanf("%d", &numDistinct);

		vector<int> vectorToBeTest;

		vectorToBeTest.clear();

		fill(hashTable, hashTable + MAX, false);

		for (int j = 1; j <= numDistinct; j++) {

			scanf("%d", &vertice);

			hashTable[vertice] = true;

			vectorToBeTest.push_back(vertice);

		}

		if (isClique(vectorToBeTest) == false) {

			printf("Not a Clique\n");

		}else if(isMaximalClique(vectorToBeTest) == false){

			printf("Not Maximal\n");

		}

		else {

			printf("Yes\n");

		}

	}



	return 0;

}
