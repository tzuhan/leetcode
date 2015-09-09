#include <iostream>
#include <cmath>

using namespace std;

int trailingZeroes(int n);

int main(void){
    cout << trailingZeroes(5);
    return 0;
}
int trailingZeroes(int n) {
    int ratio = 5;
    int base = 5;
    int sum = 0;

    int limit = (int)ceil(log(n)/log(5));
    for(int i=1;i<=limit;i++){
        sum+=n/pow(5,i);
    }
    return sum;
}

