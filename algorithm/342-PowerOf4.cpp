#include <iostream>
using namespace std;

int main(){
    int input[] = {4,16,12,2,32,64};
    int size = 6, i=0;
    int mask = 0x55555555; //01010101010101010101010101010101;
    for(i=0;i<size;i++){
        if((input[i]>0) && 
           ((input[i] & (input[i] -1)) == 0) && //input[i] is the power of 2
           ((input[i] & mask) == input[i]))
           std::cout<< input[i] << endl;
    }
    return 0;
}
