#include <iostream>
#include <string>
using namespace std;

int main(void){
    string result;
    string s = "abcdef";
    int numRows = 4;
    int totalStep = numRows*2-2;
    int step[2] = {0,0}; //0:left, 1:right;
    for(int j=0; j<numRows; j++){
        step[0] = ((totalStep - j*2) == 0) ? j*2 : totalStep - j*2;
        step[1] = (j*2 == 0) ? totalStep - j*2 : j*2;
        cout << "left = " << step[0] << ", right = " << step[1];
        int i=j;
        int ptr = 0;
        while(i<s.size()){
            result.push_back(s[i]);
            i += step[ptr];
            ptr = ptr ^ 0x01; //if 0 -> 1, if 1 -> 0
            cout << ", ptr = " << ptr;
            cout << "i = " << i << endl;
        }
    }
    cout << result << endl;
    return 0;
}


