#include <iostream>
using namespace std;
//11 base notation
int main(void){
    int n;
    int base = 11;
    char alpha[11] = {'0','1','2','3','4','5','6','7','8','9','a'};
    int digit[9] = {0,0,0,0,0,0,0,0,0};
    int i = 0;
    cin >> n;

    while (n>0) {
        digit[i] = n%base;
        n = n/base;
        i++;
    }
    for (int j=i-1; j>=0; j--) {
        cout << alpha[digit[j]];
    }
    return 0;
}


