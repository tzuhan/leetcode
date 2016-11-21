#include <iostream>
#include <vector>

using namespace std;
int maxium_product_subarray(vector<int> &nums){
    int len = nums.size();
    if(len<=0) return 0;
    int maxProductCurrent = 1, max_all = 1;
    int head = 0, end = 0;
    for(int i=0; i<len; i++){
        if(nums[i]!=0){
            maxProductCurrent *= nums[i];
        } else if(nums[i] == 0){
            maxProductCurrent = 1;
            head = i+1;
            end = i+1;
        }
        if(max_all < maxProductCurrent){
            max_all = maxProductCurrent;
            end = i;
        }
    }
    
    cout << "head, end" << head << ", " << end << endl;
    return max_all;
    //return vector<int> result(nums.begin() + head, nums.begin() + end);
}
int main() {
	//code
	int t, n;
	cin >> t;
	for(int i = 0; i<t; i++){
	    cin >> n;
	    vector<int> temp(n);
	    for(int j=0; j<n; j++){
	        cin >> temp[j];
	    }
	    cout << maxium_product_subarray(temp);
	}
	return 0;
}
