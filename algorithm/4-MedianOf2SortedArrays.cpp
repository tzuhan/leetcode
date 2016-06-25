#include <iostream>
#include <vector>
#include <utility>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main(void){
    vector<int> nums1 = {1,3,5,10,11,12,13};
    vector<int> nums2 = {-3,-1,0,2,4,8,9};
    int l1 = nums1.size(), l2=nums2.size();
    int kth = (l1+l2)/2;
    bool isEven = (l1+l2)%2;
    int s1 = 0, s2 = 0, e1 = l1, e2 = l2;
    if(l1 == 0 && l2 == 0) return 0;
    if(l1 == 0) return nums2[(s2+e2)/2];
    if(l2 == 0) return nums1[(s1+e1)/2];
    bool flag = (nums1[(s1+e1)/2] >= nums2[(s1+e1)/2]) ? true : false;
    while((e1-s1)>1 || (e2-s2)>1){
        int m1 = nums1[(s1+e1)/2];
        int m2 = nums2[(s2+e2)/2];
        printf("m1 = %d, m2 = %d, flag=%d\n",m1,m2,flag);

        if(flag && (e1-s1)>1){
            printf("e1=%d,s1=%d\n",e1,s1);
            if(m1>=m2){
                e1 = (s1+e1)/2;
            } else {
                s1 = (s1+e1)/2;
            }
            printf("e1=%d,s1=%d\n",e1,s1);
        }
        if(!flag && (e2-s2)>1){
            printf("e2=%d,s2=%d\n",e2,s2);
            if(m2>=m1){
                e2 = (s2+e2)/2;
            } else {
                s2 = (s2+e2)/2;
            }
            printf("e2=%d,s2=%d\n",e2,s2);
        }
        flag = ~flag & 0x01;
    }
    printf("1s%d 2s%d 1e%d 2e%d\n",nums1[s1], nums2[s2], nums1[s1+1], nums2[s2+1]); 
    pair<int, int> result = make_pair(max(nums1[s1], nums2[s2]), min(nums1[s1+1], nums2[s2+1]));
    if((l1+l2)%2 == 0){
        //return the mean of two mean
        cout << "even, median of " << result.first << " " << result.second << "=" <<(result.first+result.second) / 2;
    } else {
        if(result.first<=result.second){
            cout << result.second;
        } else {
            cout << result.first;
        }
    }
    return 0;
}


