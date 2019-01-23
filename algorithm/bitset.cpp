#include <iostream>
#include <bitset>
const int option0 = 0;
const int option1 = 1;
const int option2 = 2;
const int option3 = 3;
const int option4 = 4;
const int option5 = 5;
const int option6 = 6;
const int option7 = 7;

using namespace std;

int main(void){
    std::bitset<8> flg(0b0001'1001);
    flg.set(option7);   //0b1001'1001
    flg.flip(option4);  //0b1000'1001
    flg.reset(option3); //0b1000'0001
    std::cout << "Bit 4 has value: " << flg.test(option4) << std::endl;
    std::cout << "Flg: " << flg << std::endl;
    return 0;
}


