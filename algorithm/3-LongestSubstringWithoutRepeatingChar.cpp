#include <iostream>
#include <string>
using namespace std;

int lengthOfLongestSubstring(string s) {
	int len = s.size(), max_value = 0;
	int** map = new int*[len];
	for(int i=0; i<len; i++){
		map[i] = new int[len];
	}
	for(int i=0; i<len; i++){
		for(int j=0; j<len; j++){
			int t = (i>0&&j>0) ? map[i-1][j-1] : 0 ;
			map[i][j] (s[i] == s[j]) ? 1 + t : 0 ;
		}
	}
	for(int i=0; i<len; i++){
		int pt1 = pt2 = 0;
		for(int j=0; j<len; j++){
			if(map[i][pt1]!=map[i][pt2])
		}
	}
	return max_value;
}
int main(){
	int i;
	string s = "abcabcbb";
	lengthOfLongestSubstring(s);

	return 0;
}

