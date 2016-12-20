#include <iostream>
#include <string>
#include <limits>
using namespace std;

int recursive(string s, int start, int end){
    static int value = 0;
    int min = numeric_limits<int>::max();
    int cut_t = start;
    if(start>=end) return 0;
    if(start==end-1){
        cout << "s, e" << start << ", " << end << endl;
        cout << "value " <<(s[start]-'0') + (s[end]-'0') <<endl;
        return (s[start]-'0') + (s[end]-'0');
    }
    for(int i=start; i<end;i++){
        if(min > ((s[i]-'0') * (i-start+1) + (s[i+1]-'0') * (end-i))){
            min = ((s[i]-'0') * (i-start+1) + (s[i+1]-'0') * (end-i));
            cut_t = i;
            cout << "cut_t" << cut_t << ",min " << min <<endl;
        }
    }
    return recursive(s,start, cut_t) + recursive(s,cut_t+1, end)+min;
}
int main(void){
    string s;
    cin >> s;
    int n = s.size();
    cout << recursive(s, 0, n-1);
    return 0;
}


