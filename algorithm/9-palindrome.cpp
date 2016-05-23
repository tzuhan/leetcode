#include <iostream>
using namespace std;

int main(){
    int p[] = {-2147483648, 0, 9, -1, 1001, 10501, 1};
    int rmdr = 0, base = 10;
    double temp = 0;
    for(int i = 0; i<7; i++){
        temp = 0;
        while(p[i]>temp){
            temp = temp*base +p[i]%base;
            p[i]/=base;
        }
        if(temp == (double)p[i] || temp == p[i]/10){
            std::cout << i << "\n";
        }
    }
    return 0;
}
