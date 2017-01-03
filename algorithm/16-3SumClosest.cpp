#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
   Time Complexity: O(N^3) // can reduce to O(N^2*logN)
   Space Complexity: O(N)

   <Solution>
    Three number: a, b, c
    Target: t
    Distance: d
    if(d<0) => a+b+c < t => c < t-a-b
    else if(d>0) => a+b+c > t => c > t-a-b
    else => d==0, c == t-a-b
    1. sort numbers of input vector
    2. two pointers points to a(index i) and b(index j)
    3. from index k = j+1 to N, update minimun current distance value (min_dist)
    search where vector[k] turn from < t-a-b to > t-a-b => return min(v[k], v[k+1])
    else if v[k] all < t-a-b => return v[N-1]
    else if v[k] all > t-a-b => return v[j+1]
*/
void update_result(int &min_dist, vector<int> &result, auto i, auto j, auto k, int t){
    if(min_dist > abs(t-*i-*j-*k)){
        min_dist = abs(t-*i-*j-*k);
        result[0] = *i;
        result[1] = *j;
        result[2] = *k;
    }
}
int threeSumClosest(vector<int> v, int t){
    int size = v.size();
    if(size<=0) return -1;
    sort(v.begin(), v.end());
    int min_dist = abs(3*v[size-1] - t);
    vector<int> result(v.end()-3, v.end());
    for(auto i = v.begin(); i != v.end(); i++){
        for(auto j = i+1; j != v.end(); j++){
            for(auto k = j+1; k != v.end(); k++){ //can change to binary search
                if(*k < t - *i - *j){
                    if(distance(v.begin(), k) == size){
                        update_result(min_dist, result, i, j, k, t);
                        break;
                    } else if (*(k+1) >= t - *i - *j) {
                        update_result(min_dist, result, i, j, k, t);
                        update_result(min_dist, result, i, j, k+1, t);
                        break;
                    }
                    continue;
                } else {
                    if(distance(j, k) == 1){
                        update_result(min_dist, result, i, j, k, t);
                        cout << result[0] << ", " << result[1] << ", " << result[2] << endl;
                        return result[0] + result[1] + result[2];
                    }
                }
            }
        }
    }

    cout << result[0] << ", " << result[1] << ", " << result[2] << endl;
    return result[0] + result[1] + result[2];
}
int main(void){
    vector<int> input1{0,0,0,1,2,3};
    vector<int> input2{1,2,3,4,5};
    vector<int> input3{-1,12,-3,-4,5};

    int target;
    cin >> target;
    cout << "result" << threeSumClosest(input1, target) << endl;
    cout << "result" << threeSumClosest(input2, target) << endl;
    cout << "result" << threeSumClosest(input3, target) << endl;
    return 0;
}


