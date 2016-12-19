#include <iostream>
#include <string>
#include <stack>
#include <limits>
#include <vector>
using namespace std;

int main(){
    int temp,top;
    int left_min = std::numeric_limits<int>::max();

    std::stack<int> left, right, right_min;

    //get input
    //add A: add A to the top of stack.
    //remove: remove the oldest element from the stack //the bottom one.
    //min: print out the current minimum.

    std::string command;
    while(cin>>command){
        if(command.compare((string)"add") == 0){
            cin >> temp;
            left_min = (left_min > temp) ? temp : left_min;
            left.push(temp);
            cout << "insert into stack:" << temp;
        } else if(command.compare((string)"remove") == 0){
            if(right.empty()){
                //push each element from left to right, remove the top one from right.
                //update right_min stack;
                while(!left.empty()){
                    temp = left.top();
                    left.pop();
                    right.push(temp);
                    top = (right_min.empty()) ? std::numeric_limits<int>::max() : right_min.top();
                    if(temp<top){
                        right_min.push(temp);
                    }
                }
                left_min = std::numeric_limits<int>::max();
            }
            if(!right.empty()){
                cout << right.top() << endl;
                if(!right_min.empty() && right.top() == right_min.top()){
                    right_min.pop();
                }
                right.pop();
            } else {
                cout << -1 << endl;
            }
        } else if(command.compare((string)"min") == 0){
            if(right_min.empty() || left_min < right_min.top()){
                if(left_min == std::numeric_limits<int>::max()){
                    cout << -1 << endl;
                } else {
                    cout << left_min <<endl;
                }
            } else {
                cout << right_min.top();
            }
        } else {
            break;
        }
    }

    //second way, use array
    //one to store string of value
    //one to store current min value.
    vector<int> value_vec, min_vec;
    while(!left.empty()){
        left.pop();
    }
    while(!right.empty()){
        right.pop();
    }
    while(!right_min.empty()){
        right_min.pop();
    }
    return 0;
}

