#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main(void){
    std::vector<int> primes {2,7,11,13,19};
    int n = 15;
    int len = primes.size();
    std::vector<int> ptr(len,0);
    std::vector<int> uglyNumberArray(1, 1);
    int min_value, index;
    for(int i=0; i<n; i++){
        min_value = INT_MAX;
        index = 0;
        //find next element to add
        for(int j = 0; j<len; j++){
            if(min_value > uglyNumberArray[ptr[j]]*primes[j]){
                index = j;
                min_value = uglyNumberArray[ptr[j]]*primes[j];
            }
        }
        //add to uglyNumberArray
        uglyNumberArray.push_back(min_value);

        //move pointer
        for(int j = index; j<len; j++){
            if(min_value == uglyNumberArray[ptr[j]]*primes[j]){
                ptr[j]++;
            }
        }
    }
    std::cout << uglyNumberArray[n-1] << endl;
    return 0;
}


