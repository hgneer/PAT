#include <iostream>

#include <cstdio>

using std::cin;

using std::cout;

using std::endl;



float respectively_receive[1001] = {0};

int i,term_number1,term_number2,exponents;

int n = 0;

float respectively;



void  func(int virable_1,float virable_2)

{

    respectively_receive[virable_1] += virable_2;

}



int main()

{

    cin >> term_number1;

    if (term_number1 >= 1 && term_number1 <= 10){

    for(i = 0;i < term_number1;i++){

        cin >> exponents >> respectively;

       if(exponents >= 0 && exponents <= 1000)

            func(exponents,respectively);

        else

            return 0;

        }

    }

    else

        return 0;

    cin >> term_number2;

    if (term_number2 >= 1 && term_number2 <= 10){

    for(i = 0;i < term_number2;i++){

        cin >> exponents >> respectively;

      if(exponents >= 0 && exponents <= 1000)

            func(exponents,respectively);

        else

            return 0;

        }

    }

    else

        return 0;

    for (i = 0;i < 1001;i++){

        if(respectively_receive[i] != 0)

            n++;

    }

    if(n > 0)

        cout << n << " ";

    else

        cout << 0;

    for(i = 1000;i >= 0 ;i--){

        if(respectively_receive[i] != 0){

            //cout << i << " ";

            printf("%d ",i);

            n--;

            if(n == 0)

                printf("%.1f",respectively_receive[i]);

            else

                printf("%.1f ",respectively_receive[i]);

        }

    }

    return 0;

}


