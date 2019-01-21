#include <cstdio>

#include <cstring>

#include <iostream>

#include <string>

#include <algorithm>



using namespace std;



bool cmp(char a, char b)

{

	return a > b;

}



int inc(int number)

{

	char numberstring[7];

	sprintf(numberstring, "%04d", number);

	sort(numberstring, numberstring + 4);

	int numberinc;

	sscanf(numberstring, "%04d", &numberinc);

	return numberinc;

}



int dec(int number)

{

	char numberstring[7];

	sprintf(numberstring, "%04d", number);

	sort(numberstring, numberstring + 4, cmp);

	int numberdec;

	sscanf(numberstring, "%04d", &numberdec);

	return numberdec;

}



int main()

{

	int number = 0;

	scanf("%d",&number);

	int decnumber = dec(number);

	int incnumber = inc(number);

	int result = decnumber - incnumber;

	while (result != 6174 && result != 0)

	{

		printf("%04d - %04d = %04d\n", decnumber, incnumber, result);

		decnumber = dec(result);

		incnumber = inc(result);

		result = decnumber - incnumber;

	}

	printf("%04d - %04d = %04d\n", decnumber, incnumber, result);



	return 0;

}
