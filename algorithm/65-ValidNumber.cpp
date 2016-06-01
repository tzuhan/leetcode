#include <iostream>
using namespace std;
class Solution {
    public:
        bool isNumber(string s) {
            bool nonDigitExist = false, sciNoteExist = false; //Scientific notation
            bool pointExist = false, plusExist = false, minusExist = false;
            int i=0, j=s.size();
            while(s[i++]==' ');
            while(s[--j]==' ');
            for(;i<j;i++){
                if(!isdigit(s[i]) && s[i]!='e' && s[i]!='.' && s[i]!='-' && s[i]!='+') return false;
                switch(s[i]){
                    case 'e':
                        if(sciNoteExist) return false;
                        sciNoteExist = true;
                        break;
                    case '.':
                        if(pointExist || sciNoteExist) return false;
                        pointExist = true;
                        break;
                    case '-':
                        if(minusExist) return false;
                        minusExist = true;
                        break;
                    case '+':
                        if(plusExist) return false;
                        plusExist = true;
                        break;
                    case '1':
                    case '2':
                    case '3':
                    case '4':
                    case '5':
                    case '6':
                    case '7':
                    case '8':
                    case '9':
                        minusExist = true;
                        plusExist = true;
                        break;
                }
            }
            return true;
        }
};
int main(void){
    return 0;
}


