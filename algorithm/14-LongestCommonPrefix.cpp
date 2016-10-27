#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void){
    vector<string> strs2 = {"abcdefg", "abcd", "abce", "accdefg"};
    vector<string> strs = {"a"};
    int n = strs.size();
    string result;
    if(strs.size() == 0) cout << "empty strs";
    result = strs[0];
    int len = strs[0].size();
    for(std::string str : strs) {
        cout << "str: " << str << "len: " << str.size() << endl;
        if(len > str.size()){
        cout << "len: " << len << endl;
            len = str.size();
            result = str;
        }
    }
    for(std::string str : strs){
        for(int i=0;i<len;i++){
            if(str[i] != result[i]){
            cout << "i: " << i << endl;
            cout << str[i] << ", " << result[i] << endl;
                len = i;
                break;
            }
        }
    }
    cout << "len: " << len << endl;
    return 0;
}


