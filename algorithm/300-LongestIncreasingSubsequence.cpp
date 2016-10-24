#include <iostream>
#include <vector>
#include <cstddef>
/* use dp to solve this problem
poor time complexity: n^2*/
using namespace std;
void printvector(vector<int> v){
    for(vector<int>::iterator it=v.begin(); it!= v.end(); it++){
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
        printvector(result_subsequence[i]);
        if(result_subsequence[longest_LIS_index].size() < result_subsequence[i].size()) longest_LIS_index = i;
    }
    return result_subsequence[longest_LIS_index];
}


int main(void){
    std::vector<int> input = {10,9,2,5,3,7,101,18};
    std::vector<int> input2 = {10,9,2,5,3,4};

    printvector(lengthOfLIS(input4));
    return 0;
}

