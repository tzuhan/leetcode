#include <iostream>
#include <vector>
#include <string>
using namespace std;
string intToRoman(int num) {
    char RomanAlphabet[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    int RomanDigit[7]     = {1,5,10,50,100,500,1000};
    int i = 6;
    string result;
    while(num>0 && i>=0){
        if(num/RomanDigit[i]>=1){
            result.append((int)num/RomanDigit[i], RomanAlphabet[i]);
            num-=(num/RomanDigit[i])*RomanDigit[i];
        }
        if(i>0){
            if(i%2==0){ // 10, 100, 1000, i& i-2
                if(num>=RomanDigit[i]-RomanDigit[i-2]){
                    result+=RomanAlphabet[i-2];
                    result+=RomanAlphabet[i];
                    num-=(RomanDigit[i]-RomanDigit[i-2]);
                }
            } else { // 5, 50, 500, i & i-1
                if(num>=RomanDigit[i]-RomanDigit[i-1]){
                    result+=RomanAlphabet[i-1];
                    result+=RomanAlphabet[i];
                    num-=(RomanDigit[i]-RomanDigit[i-1]);
                }
            }
        }
        i--;
    }
    return result;
}

int main(void){
    cout << intToRoman(40);
    return 0;
}


