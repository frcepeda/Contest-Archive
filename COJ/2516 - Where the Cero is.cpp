// Accepted
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

#define MAXS 50000

char pattern[MAXS];
int s[MAXS] = {1};
int fail[MAXS];

int len;

int getN(int l){
    int i;
    for (i = 0; s[i] < l; i++);
    return i;
}

int putNumber(char *s, int i){
    char tmp[MAXS];
    int l = 0;
    while (i != 0){
        tmp[l++] = i % 10;
        i /= 10;
    }
    l--;
    for (i = 0; l >= 0; i++, l--)
        s[i] = '0' + tmp[l];
    return i;
}

int main(){
    int i, j;
    string str;

    pattern[0] = '0';
    for (i = j = 1; i < 1100; i++){
        j += putNumber(pattern+j, i);
        s[i] = j;
    }

    while (cin >> str){
        len = str.size();

        str = str + str;

        i = (int) str.find(pattern, 0, len);

        cout << getN(len) - getN(len - i) << endl;
    }
}
