#include <iostream>

#include <cstdio>

#include <cmath>

const int Max = 100004;



using namespace std;



struct primefac{

  int pri;

  int num;

}primefac[20];



int number = 0;



void prime(int n,int array[])

{

  for(int i = 2;i <= sqrt(n);i++){

    if((i%2 == 0 || i%3 == 0 || i%5 == 0 || i%7 == 0) && i != 2 && i != 3 && i != 5 && i != 7){

      continue;

    }else{

      array[number++] = i;

    }

  }

}



int main()

{

  int n,num = 0;

  int prime_array[Max];

  scanf("%d",&n);

  if(n != 1){

    int originaln = n;

    prime(n,prime_array);

    for(int i = 0;i < number;i++){

      if(n%prime_array[i] == 0){

        primefac[num].pri = prime_array[i];

        primefac[num].num = 0;

        while(n%prime_array[i] == 0){

          primefac[num].num++;

          n /= prime_array[i];

        }

        num++;

      }

    }

    if(n > 1){

      primefac[num].pri = n;

      primefac[num].num = 1;

      num++;

    }

    printf("%d=",originaln);

    for(int i = 0;i < num;i++){

      if(primefac[i].num > 1){

        printf("%d^%d",primefac[i].pri,primefac[i].num);

      }else if(primefac[i].num == 1){

        printf("%d",primefac[i].pri);

      }

      if(i != num - 1) printf("*");

    }

  }else{

    printf("1=1");

  }



  return 0;

}


