#include <iostream>
#include <cctype>
#include <vector>
using namespace std;

int main(void){
    string input;
    std::getline(cin, input);
    int n = input.size(), i;
    if(n<=0 || n>100) return -1;
    int word_len = 0;
    int temp_word = 0;
    int bracket_flag = 0;
    vector<int> words_len;
    while(i!=n){
       switch(input[i]){
           case '{':
               bracket_flag = 1;
               if(word_len!=0) words_len.push_back(word_len);
               temp_word = 0;
               word_len = 0;
               break;
           case '}':
               bracket_flag = 0;
               if(word_len>temp_word) temp_word = word_len;
               if(temp_word!=0) words_len.push_back(temp_word);
               word_len = 0;
               temp_word = 0;
               break;
           case '.':
           case ' ':
               if(word_len!=0) words_len.push_back(word_len);
               word_len = 0;
               break;
           case ',':
               if(temp_word > word_len) word_len = temp_word;
               temp_word = 0;
               break;
           default:
               if(isalpha(input[i])) {
                   if(bracket_flag)
                       temp_word++;
                   else
                       word_len++;
               }
               break;
       }
       i++;
    }
    if(word_len!=0) words_len.push_back(word_len);

    float result = 0.0;
    for(int i : words_len){
        result += i;
    }
    cout << result/words_len.size();
    
    return 0;
}


