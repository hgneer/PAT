#include <algorithm>
#include <iostream>
#include <cstdio>

const int MAX = 10004;

using namespace std;

int father[MAX];
int isRoot[MAX];
int common[MAX];

void init(int n)
{
    for(int i = 1;i <= n;i++){
        father[i] = i;
    }
}

int findFather(int x)
{
    int temp = x;
    while(x != father[x]){
        x = father[x];
    }
    while(temp != father[temp]){
        int z = father[temp];
        father[temp] = x;
        temp = z;
    }
    return x;
}

void Union(int a,int b)
{
    int faA = findFather(a);
    int faB = findFather(b);
    if(faA != faB){
        father[faA] = faB;
    }
}

bool cmp(int a,int b)
{
    return a > b;
}

int main()
{
    int total,num,hobby;
    scanf("%d",&total);
    init(total);
    for(int i = 1;i <= total;i++){
        scanf("%d:",&num);
        for(int j = 0;j < num;j++){
            scanf("%d",&hobby);
            if(common[hobby] == 0){
                common[hobby] = i;
            }
            Union(i,findFather(common[hobby]));
        }
    }
    for(int i = 1;i <= total;i++){
        isRoot[i] = 0;
    }
    for(int i = 1;i <= total;i++){
        isRoot[findFather(i)]++;
    }

    int Count = 0;
    for(int i = 1;i <= total;i++){
        if(isRoot[i] != 0){
            Count++;
        }
    }
    sort(isRoot+1,isRoot+total+1,cmp);

    printf("%d\n",Count);
    for(int i = 1;i <= Count;i++){
        printf("%d",isRoot[i]);
        if(i != Count){
            printf(" ");
        }
    }

    return 0;
}


