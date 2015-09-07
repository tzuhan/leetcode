#include <iostream>
int main(){
    using namespace std;
    double wages[3] = {10000.0, 20000.0, 30000.0,};
    short stacks[3] = {3, 2, 1};

    double * pw = wages;
    short * ps = &stacks[0];

    cout << "pw=" << pw << ", *pw=" << *pw << endl;
    pw += 1;
    cout << "pw=" << pw << ", *pw=" << *pw << endl;

    cout << "ps=" << ps << ", *ps=" << *ps << endl;
    ps += 1;
    
    cout << "ps=" << ps << ", *ps=" << *ps << endl;


    cout << "stacks[0] = " << stacks[0] << "s[1] = " << stacks[1] << endl;

    cout << "*stacks = " << *stacks << "*(stacks+1)=" << *(stacks+1) <<endl;
    
    cout << sizeof(wages) << endl;
    cout << sizeof(pw) << endl;
    cout << sizeof(ps) << endl;
    cout << sizeof(short *) << endl;
    return 0;
}

