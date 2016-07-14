#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    vector<int> nums1{1,3,5,7};
    vector<int> nums2{-1,2,4,9};
    int l1 = nums1.size(), l2=nums2.size(), m1, m2;
    int s1 = 0, s2 = 0, e1 = l1-1, e2 = l2-1;
    if(l1 == 0 && l2 == 0) std::cout<< "0" << endl;
    if(l1 == 0) std::cout<< nums2[(s2+e2)/2];
    if(l2 == 0) std::cout<< nums1[(s1+e1)/2];
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
            return 0;
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


