#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){
    int arr[] = {1, 7, 9, 17, 11, 13, 5, 3, 3};
    vector<int> input (arr);
    i=0; j=n-1;
    while(i!=j){
        auto it_i = lower_bound(uniq.begin(), uniq.end(), A[i]);
        auto it_j = lower_bound(uniq.begin(), uniq.end(), A[j]);
        if(abs(distance(it_i, it_j))!=1){
            j--;
            continue;
        }
        len = abs(i-j) > len ? abs(i-j) : len;
        i++;
    }
    i=0; j=n-1;
    while(i!=j){
        auto it_i = lower_bound(uniq.begin(), uniq.end(), A[i]);
        auto it_j = lower_bound(uniq.begin(), uniq.end(), A[j]);
        if(abs(distance(it_i, it_j))!=1){
            i++;
            continue;
        }
        len = abs(i-j) > len ? abs(i-j) : len;
        j--;
    }
    return 0;
}


