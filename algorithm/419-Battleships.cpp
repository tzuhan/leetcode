#include <iostream>
#include <vector>
using namespace std;
int countBattleships(vector<vector<char>>& board) {
    int m = board.size();
    int n = board[0].size();
    int num = 0;

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            bool four_dir_flag[] = {false, false, false, false}; //up right down left
            four_dir_flag[0] = (i-1<0)  ? true : (board[i-1][j] != 'X');
            four_dir_flag[1] = (j+1>=n) ? true : (board[i][j+1] != 'X');
            four_dir_flag[2] = (i+1>=m) ? true : (board[i+1][j] != 'X');
            four_dir_flag[3] = (j-1<0)  ? true : (board[i][j-1] != 'X');
            if(four_dir_flag[0] && four_dir_flag[1] && four_dir_flag[2] && four_dir_flag[3] && board[i][j] == 'X'){
                //isolate
                cout << "isolate" << endl;
                num++; 
            } else {
                cout << "non-isolate" << endl;
                //not isolate, must be vertical or horizontal
                if(four_dir_flag[3] && !four_dir_flag[1] && board[i][j] == 'X'){
                    num++;
                    //left edge of continual list. .XX.
                }
                if(four_dir_flag[0] && !four_dir_flag[2] && board[i][j] == 'X'){
                    num++;
                    //                               .
                    //upper edge of continual list   X
                    //                               X
                }
            }

        }
    }
    return num;
}

int main(void){
    vector<vector<char>> board = {{'X','.','.','X'}, {'.','.','.','X'}, {'.','.','.','X'}};
    cout << countBattleships(board) << endl;
    return 0;
}


