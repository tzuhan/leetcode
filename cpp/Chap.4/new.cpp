#include <iostream>
#include <string>
int main(void){
    using namespace std;
    /*
    struct fish{
        string kind;
        float weight;
        float length;
    };

    char actors[30] = "cheeseburger";
    short * betsie = new short[100];
    float * chunk = new float[13];
    long * dipsea = new long[64];
    enum response{NO = 0, Yes = 1, Maybe = 2};
    response r1 = NO;
    double ted = 23.5f;
    double *ptrted = &ted;


    int first5_odds[5] = {1, 3, 5, 7, 9};
    int sum = first5_odds[0] + first5_odds[4];
    int * idea = new int [3];
    *idea = 1;
    *(idea+1) = 2;
    *(idea+2) = 4;
    
    int n;
    cout << "input n=";
    cin >> n;
    int *array = new int [n];
    for(int i=0; i<n; i++){
        cin >> *(array+i);
    }
    for(int i=0; i<n; i++){
        cout << *(array+i) << endl;
    }
    cout << (int*) "helloworld";
    delete [] array;
    fish *f1 = new fish;
    fish **ptrf1 = &f1;

    f1->kind = "shark";
    (*ptrf1)->length = 22.34;
    (*ptrf1)->weight = 1000.3;
    
    cout << f1->kind << ", weight= " << (*ptrf1)->weight << ", length = " << (*ptrf1)->length <<endl;
    delete [] betsie;
    delete [] chunk;
    delete [] dipsea;
    delete [] idea;
    */

    char arr[30];
    string str;
    getline(cin, str);
    cin.getline(arr, 30);
    cout << "char: " << arr << endl;
    cout << "str: " << str <<endl;
    int x = 1;
    while(x++<5){
        cout << x << endl;
    }
    return 0;
}
