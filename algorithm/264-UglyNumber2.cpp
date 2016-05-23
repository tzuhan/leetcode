#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int nthUglyNumber(int n) {
    int i=0;
    std::vector<int> uglyNumberArray(n+1, 0);
    uglyNumberArray[0] = 1;
    std::vector<int>::iterator it_2, it_3, it_5;
    it_2 = it_3 = it_5 = uglyNumberArray.begin();

    while(i<n){
        i++;
        int t2 = *it_2 * 2;
        int t3 = *it_3 * 3;
        int t5 = *it_5 * 5;
        printf("%d, %d, %d\n", t2, t3, t5);
        if(t2<t3 && t2<t5){
            uglyNumberArray[i] = t2;
            it_2++;
        }
        if(t3<t2 && t3<t5){
            uglyNumberArray[i] = t3;
            it_3++;
        }
        if(t5<t2 && t5<t3){
            uglyNumberArray[i] = t5;
            it_5++;
        }
        if(t2 == t3 && t2<t5){
            uglyNumberArray[i] = t2;
            it_2++;
            it_3++;
        }
        if(t2 == t5 && t2<t3){
            uglyNumberArray[i] = t2;
            it_2++;
            it_5++;
        }
        if(t3 == t5 && t3<t2){
            uglyNumberArray[i] = t3;
            it_3++;
            it_5++;
        }
        if(t2 == t3 && t3 == t5){
            uglyNumberArray[i] = t2;
            it_2++;
            it_3++;
            it_5++;
        }
    }

    for(int j = 0; j<n+1 ;j++){
        std::cout << uglyNumberArray[j] << " ";
    }
    std::cout << endl;
}

int main(){
    nthUglyNumber(10);
    nthUglyNumber(11);
    nthUglyNumber(12);
    nthUglyNumber(13);
    nthUglyNumber(20);
    nthUglyNumber(50);
    return 0;
}
