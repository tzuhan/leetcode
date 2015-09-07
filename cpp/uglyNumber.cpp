#include <iostream>

using namespace std;
bool isUgly(int num);

int main(void){
    cout << boolalpha << isUgly(1) << endl;
    cout << boolalpha << isUgly(12) << endl;
    cout << boolalpha << isUgly(1024) << endl;
    return 0;
}

bool isUgly(int num){

    if(num==0)
        return false;

    while(num%2==0){
        num/=2;
    }
    while(num%3==0){
        num/=3;
    }
    while(num%5==0){
        num/=5;
    }
    return (num==1);
}
