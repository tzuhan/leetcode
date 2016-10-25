#include <iostream>
#include <vector>
#include <cstddef>
#include <algorithm>
#include <utility>
/* use dp to solve this problem
poor time complexity: n^2*/
using namespace std;
void printvector(vector<pair<int, int>> v){
    for(auto it=v.begin(); it!= v.end(); it++){
        cout << it->first << " ";
    }
    cout << endl;
}
void printvector(vector<int> v){
    for(auto it=v.begin(); it!= v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}
vector<int> lengthOfLIS(vector<int> &nums) {
    int max_len = 0;
    if(nums.size() == 0) return vector<int>() ;
    vector<vector<int>> result_subsequence (nums.size());
    result_subsequence[0].push_back(nums[0]);

    int longest_LIS_index = 0;
    for(int i=1; i<nums.size(); i++){
        for(int j=0; j<i; j++){
            if(nums[j] < nums[i] && result_subsequence[i].size() < result_subsequence[j].size() ){
                cout << "i,j:" << i << "," << j << endl;
                result_subsequence[i] = result_subsequence[j];
            }
        }
        //append nums[i] after result_subsequence[i]
        result_subsequence[i].push_back(nums[i]);
        //printvector(result_subsequence[i]);
        if(result_subsequence[longest_LIS_index].size() < result_subsequence[i].size()) longest_LIS_index = i;
    }
    return result_subsequence[longest_LIS_index];
}
int lengthOfLIS2(vector<int> &nums) {
    //O(nlogn)
    if(nums.size() == 0) return 0;

    vector<pair<int,int>> len;
    //initialize
    vector<int> path(nums.size(), -1);

    int last_element_index = 0;
    for(int i = 0; i< nums.size(); i++){
        auto it = lower_bound (len.begin(), len.end(), make_pair(nums[i],i));//, [](auto a, auto b){return a.first < b.first;});
        if(it == len.end()) {//not found
            if (!len.empty()) {
                path[i] = len.back().second;
            }
            len.push_back(make_pair(nums[i],i));

        } else {
            if (it != len.begin()) {
                path[i] = (it - 1)->second;
            }
            *it =make_pair(nums[i],i);
        }
    }
    vector<int> result;
    int i = len.back().second;
    while(i>=0) {
        result.push_back(nums[i]);
        i = path[i];
    }
    std::reverse(result.begin(), result.end());
    printvector(result);
    return len.size();
}


int main(void){
    std::vector<int> input = {10,9,2,5,3,7,101,18};
    std::vector<int> input2 = {10,9,1,5,4,6,-1,0,11,2};

    //printvector(lengthOfLIS(input4));
    lengthOfLIS2(input2);
    return 0;
}

