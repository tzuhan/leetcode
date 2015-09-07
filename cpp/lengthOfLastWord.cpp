#include <iostream>
#include <string>
using namespace std;

int main(){
    const int NO_SPACE = -1;
    string s = " a ";
    if(s.empty() || s.length()==0)
        std::cout << 0;

    //remove trailing white spaces
    std::string space (" \t\f\v\n\r");
    std::string alphabets("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
    std::size_t index = s.find_last_not_of(space);
    cout<<"index:" << index << endl;

    if(index!=std::string::npos){
        s.erase(index+1);
    } else {
        s.clear();
    }
    
    cout << s << "<end here" << endl;

    std::string token;
    index = s.find_last_not_of(alphabets);
    int length = s.length();
    int i = length-1;
    for(i;i>=0;i--){
        if(s[i] == ' ')
            break;
    }
    cout<<"i:" << i <<endl;
    cout<<"length-i:" << length-i << endl;
    cout << "using index:" <<endl;
    if(index != std::string::npos){
        cout<<"index:" << index << endl;
        token = s.substr(index+1,string::npos);
        std::cout<< token.length() <<endl;
    }
    cout << "using i:" <<endl;
    token = s.substr(i+1,string::npos);
    std::cout<< token.length() <<endl;
    
    return 0;
}
