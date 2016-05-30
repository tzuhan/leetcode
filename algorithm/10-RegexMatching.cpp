#include <iostream>
#include <string>
using namespace std;

bool isMatch(string s, string p) {
    int len_s = s.size();
    int len_p = p.size();
    int i = len_s-1, j;
    char last = '\0';
    for(j = len_p-1; j>=0;j--){
        if(i==len_s)
            break;
        char char_s = s[i];
        char char_p = p[j];
        if(char_p == '*'){
            if(!isalnum(last)){
                return false;
            }
            if(s[i]!=last){
                j++;
            }

        } else if(char_p == '.'){
            last = '.';
            j++;
        } else if(isalnum(char_p)){
            if(char_s!=char_p){
                return false;
            } else {
                last = char_p;
                j++;
            }
        }
        i++;
    }
    return (i == len_s && j == len_p);
}
int main(){
    std::string temp[] = {"a", "a*", "a.*", ".a"};
    std::string b = "aa";
    isMatch(b,temp[0]) ? std::cout << "aa, a" <<endl : "\n";
    isMatch(b,temp[1]) ? std::cout << "aa, a*" <<endl : "\n";
    isMatch(b,temp[2]) ? std::cout << "aa, a.*" <<endl : "\n";
    isMatch(b,temp[3]) ? std::cout << "aa, .a" <<endl : "\n";
    return 0;
}
