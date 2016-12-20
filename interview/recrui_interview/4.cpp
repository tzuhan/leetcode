#include <iostream>
#include <string>
#include <limits>
#include <vector>
using namespace std;
/* recursive method not correct, cause the actual minimun not always ==  ∑local minimun
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
*/
int main(void){
    string s;
    cin >> s;
    int n = s.size();
    //the maximun value is 11466. 50 characters of 9:  999...99
    //the value of 9999..99 is 9*49+9 + 9*48+9 + ... +9*1+9 = 11466
    vector<vector<int>> matrix(n, vector<int>(n, 11467));
    if(n<=1 || n>50) return 0;
    //cout << recursive(s, 0, n-1);
    //matrix[i][j] meaning:
    //string s[i] ~ s[j], len = j-i+1;
    //left slice: i<=k <j, s[i],... s[k]||, s[j]
    for(int i=0;i<n;i++){
        matrix[i][i] = 0;
    }
    /* len: 
       0 1 2 3 4
       x 0 1 2 3
       x x 0 1 2
       x x x 0 1
       x x x x 0
    */
    for(int len=1; len<n; len++){
        for(int i=0;i+len<n;i++){
            int j = i+len;
            for(int k=i; k<j && k<n-1; k++){
                int temp = (s[k]-'0') * (k-i+1) + (s[k+1]-'0') * (j-k);
                cout << "val" <<matrix[i][k] + matrix[k+1][j] + temp << endl;
                cout << "m[i][j]" << matrix[i][j] <<endl;
                if (matrix[i][k] + matrix[k+1][j] + temp < matrix[i][j]){
                    matrix[i][j] = matrix[i][k] + matrix[k+1][j] + temp;
                }
            }
        }
    }

    cout << matrix[0][n-1] << endl;
    return 0;
}


