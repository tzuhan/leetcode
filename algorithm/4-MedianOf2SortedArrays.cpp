#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	//can't do it myself, use this solution
	//https://discuss.leetcode.com/topic/16797/very-concise-o-log-min-m-n-iterative-solution-with-detailed-explanation/2
	int len1 = nums1.size();
	int len2 = nums2.size();
	if(len2>len1){
		return findMedianSortedArrays(nums2, nums1);
	}
	//add '#' between element [1,2,3] => [#, 1, #, 2, #, 3, #]
	//                  index: 0 1 2      0  1  2  3  4  5  6
	int head = 0, tail = len2*2; //start and end of nums2
	int int_max = numeric_limits<int>::max();
	int result = -1;
	while(head <= tail){
		int mid2 = (head+tail)/2;
		int mid1 = (len1+len2) - mid2;
		int L1 = (mid1 == 0) ? int_max : nums1[(mid1-1)/2];
		int L2 = (mid2 == 0) ? int_max : nums2[(mid2-1)/2];
		int R1 = (mid1 == len1*2) ? int_max : nums1[mid1/2];
		int R2 = (mid2 == len2*2) ? int_max : nums2[mid1/2];
		if(L1>R2){
			//search left of 0~L1 and right of R2~Len2
			head = mid2+1;
		} else if(L2>R1) {
			tail = mid2-1;
		} else {
			result = (max(L1, L2) + min(R1, R2))/2;
			break;
		}
	}
	return result;
}

int main(void){
	vector<int> nums1{1,3,5,7};
	vector<int> nums2{-1,2,4,9};
	vector<int> nums1{1,3,5,10,11,12,13};
	vector<int> nums2{-3,-1,0,2,4,8,9};
	int l1 = nums1.size(), l2=nums2.size(), m1, m2;
	int s1 = 0, s2 = 0, e1 = l1-1, e2 = l2-1;
	//find i at nums1 and j at nums2 which
	//  1. i+j = (l1+l2)/2 (i=i, j = (l1+l2)/2 -i)
	//  2. nums1[i-1] <= nums2[j]
	//  3.
	while((e1-s1)>1 || (e2-s2)>1){
		m1 = nums1[s1+(e1-s1)/2];
		m2 = nums2[s2+(e2-s2)/2];

		if(m1>m2){
			s2 = s2+(e2-s2)/2;
			e1 = s1+(e1-s1)/2;
		} else if(m1<m2){
			s1 = s1+(e1-s1)/2;
			e2 = s2+(e2-s2)/2;
		} else {
			std::cout << "m1 == m2" << m1 << endl;
			break;
		}
		std::cout << "iter: " << s1 << " " << e1 << " " << s2 << " " << e2 << " " << endl;
		std::cout << "m1: " << m1 << ", m2: " << m2 << endl;
	}

	if((l1+l2)%2 == 0){
		//return the mean of two mean
		std::cout << "n:" << (max(nums1[s1], nums2[s2]) + min(nums1[e1], nums2[e2]))/2 << endl;
	} else {
		int median_x = (l1+l2)/2;
		m1 = nums1[s1];
		m2 = nums2[s2];
		if(m1>m2){
			if((s1+s2+1) == median_x)
				std::cout << "m1: " << m1 << endl;
		} else {
			if((s1+s2+1) == median_x)
				std::cout << "m2: " << m2 << endl;
		}
	}
	return 0;
}


