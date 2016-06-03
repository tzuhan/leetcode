#include <iostream>
using namespace std;

int main(void){
    int l1 = nums1.size(), l2=nums2.size();
    int s1 = 0, s2 = 0, e1 = l1, e2 = l2;
    if(l1 == 0 && l2 == 0) return 0;
    if(l1 == 0) return nums2[(s2+e2)/2];
    if(l2 == 0) return nums1[(s1+e1)/2];
    while((e1-s1)>1 && (e1-s1)>1){
        int m1 = nums1[(s1+e1)/2];
        int m2 = nums1[(s2+e2)/2];

        if(m1>=m2){
            e1 = (s1+e1)/2;
            s2 = (s2+e2)/2;
        } else if(m1<m2){
            s1 = (s1+e1)/2;
            e2 = (s2+e2)/2;
        }
    }
    if((l1+l2)%2 == 0){
        //return the mean of two mean
    } else {
        //return 1 number
        if(nums1[(s1+e1)/2] >= nums2[(s2+e2)/2]){
            int left = (s1+e1)/2 + (s2+e2)/2 + 1; //num2
            if(left == (l1+l2)/2) return nums1[(s1+e1)/2];
            else return nums1[(s1+e1)/2];
        }    
    }
    return 0;
}


