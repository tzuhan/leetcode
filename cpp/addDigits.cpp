#include <iostream>
using namespace std;
int main(void){
    int num=18888;
    if(num%9==0 && num!=0)
        cout << 9;
    else
        cout << num%9;
    return 0;
}
