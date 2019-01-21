#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

int main()

{

    int a,b,c,d1,d2;

    int i = 0;

    int j = 0;

    char array[100];

    cin >> a >> b;

    if(a <= 1000000 && a >= -1000000 && b <= 1000000 && b >= -1000000){

        c = a + b;

        while(c != 0){

        d1 = c%10;

        c = c/10;

            d2 = fabs(d1);

        i++;

        array[100 - (i+j)] = d2 + '0';

        if(i%3 == 0 && c != 0){

            j++;

            array[100 - (i+j)] = ',';

        }

        }

        i = i + j - 1;

        cout << d1;

        for(i = 100 - i;i < 100;i++)

            cout << array[i];

    }

    else

        return 0;

    return 0;

}
