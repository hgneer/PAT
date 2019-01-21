#include <iostream>

#include <cstdio>

#include <algorithm>

#include <cstring>

const int MAX = 100010;

using namespace std;



int main()

{

    char array[MAX];

    int arrayP[MAX];

    fill(arrayP,arrayP+MAX,0);



    int num = 0;

    char c;

    while(scanf("%c",&c) != EOF){

        array[num] = c;

        if(num > 0)

            arrayP[num] = arrayP[num - 1];



        if(array[num] == 'P')

            arrayP[num]++;

        num++;

    }

    int ans = 0;

    int numT = 0;



    for(int i = num - 1;i >= 0;i--){

        if(array[i] == 'T'){

            numT++;

        }else if(array[i] == 'A'){

                ans =  (ans + arrayP[i]*numT) % 1000000007;

        }

    }



    printf("%d\n",ans);



    return 0;

}


