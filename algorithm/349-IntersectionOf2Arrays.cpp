#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int i,j = 0;
        std::vector<int> output;
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());
        int len1 = nums1.size();
        int len2 = nums2.size();
        if(len1 == 0 || len2 == 0) return output;
        
        while(i < len1){
            while(j < len2 && nums2[j]<nums1[i]){
                j++;
            }
            if(j < len2 && nums1[i] == nums2[j]){
                output.push_back(nums1[i]);
            }
            i++;
        }
        return output;
    }
};
int main(){
    std::vector<int> nums1{3,1,2};
    std::vector<int> nums2{1,1};
    std::cout << Solution::intersection(nums1, nums2);
    return 0;
}
