#include <iostream>
#include <vector>
using namespace std;

int main(void){
    int ints[] = {-1, 3, -4, 5, 1, -6, 2, 1};
                   //0  -1  2 -2  3   4 -2  0
    vector<int> A (ints, ints + sizeof(ints)/sizeof(int));
    // write your code in C++14 (g++ 6.2.0)
    int n = A.size();
    if(n<1) return -1;
    vector<long long> sum_array (n, 0);
    long long sum = 0;
    for(int i=0; i<n; i++){
        sum_array[i] = sum;
        sum += A[i];
        cout << sum_array[i] << ", " << A[i] << endl;
    }
    for(int i=0; i<n; i++){
        if(2 * sum_array[i] + A[i] == sum_array[n-1] + A[n-1]){
            cout << "equi:" << i;
            cout << "sum_array[i]:" << sum_array[i] << ", s_a[n-1]" << sum_array[n-1] << ", A[i]" << A[i] << endl;
        }
    }
    cout << -1;
    return 0;
}


