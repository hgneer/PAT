#include <iostream>

#include <cstdio>

#include <algorithm>

#include <string>

#include <cstring>

using namespace std;



int N;



string change(string array,int &n)

{

    while(array[0] == '0' && array.size() > 0){

        array.erase(array.begin());

    }

    if(array[0] == '.'){

        array.erase(array.begin());

        while(array[0] == '0'){

            array.erase(array.begin());

            n--;

        }

    }else{

        while(array[n] != '.' && n < array.size()){

            n++;

        }

        if(n < array.size())

            array.erase(array.begin()+n);

    }

    if(array.size() == 0){

        n = 0;

    }

    int num = 0;

    int i = 0;

    string temp;

    while(i < N){

        if(num < array.size())

            temp += array[num++];

        else

            temp += '0';

        i++;

    }

    return temp;

}



int main()

{

    string array1,array2;

    while(scanf("%d",&N) != EOF){

        cin >> array1 >> array2;

        int n1,n2;

        n1 = n2 = 0;

        array1 = change(array1,n1);

        array2 = change(array2,n2);

        if(array1 == array2 && n1 == n2){

            cout << "YES 0." << array1 << "*10^" << n1 << endl;

        }else{

            cout << "NO 0." << array1 << "*10^" << n1 << " 0." << array2 << "*10^" << n2 << endl;

        }

    }



    return 0;

}


