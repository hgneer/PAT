#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

const int MAX = 100;
const int INF = 1000000000;

char original[MAX],typedOut[MAX];
bool hashTable[MAX] = {false};
string result;

int hashFunc(char c)
{
    if('A' <= c && c <= 'Z'){
        return c - 'A';
    }else if('a' <= c && c <= 'z'){
        return c - 'a' + 26;
    }else if('0' <= c && c <= '9'){
        return c - '0' + 52;
    }else if(c == '_'){
        return 63;
    }
}

int main()
{
    cin.getline(original,MAX);
    cin.getline(typedOut,MAX);
    int lenTypedOut = strlen(typedOut);
    int lenOriginal = strlen(original);
    for(int i = 0;i < lenTypedOut;i++){
        int Index = hashFunc(typedOut[i]);
        hashTable[Index] = true;
    }
    for(int i = 0;i < lenOriginal;i++){
        int Index = hashFunc(original[i]);
        if(hashTable[Index] == false){
            if('a' <= original[i] && original[i] <= 'z'){
                if(result.find(original[i] - 32) == string::npos){
                    result += original[i] - 32;
                }
            }else{
                if(result.find(original[i]) == string::npos){
                    result += original[i];
                }
            }
        }
    }
    cout << result;

    return 0;
}


