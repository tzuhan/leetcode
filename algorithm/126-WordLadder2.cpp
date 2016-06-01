#include <iostream>
#include <string>
#include <new>
#include <queue>
#include <unordered_set>

using namespace std;

class Element {
	private:
		int distance;
		string str;
	public:
		Element();
		~Element();
		Element(int d, string s) {distance = d; str=s;}
		Element& operator=(const Element& rhs){distance = rhs.getDis(); str = rhs.getStr(); return *this;}
		string getStr() const {return str;}
		//overloading
		bool operator> (const Element& lhs, const Element& rhs){return (lhs.getDis() > rhs.getDis());};
		int getDis() const {return distance;}
};

class Solution {
	public:
		vector<vector<string> > findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
			unordered_set<string>::const_iterator ptr;
			priority_queue<Element, std::vector<Element>, std::greater<Element> > searchQueue;
            Element first = new Element(this->distanceOfTwoStr(beginWord, endWord), beginWord);
			searchQueue.push(first);
			int len = beginWord.size();
			if(len<=0) return NULL;
			vector<vector<string> > result;
			while(!searchQueue.empty()){
				string alterStr = searchQueue.top().getStr();
				int curDis = searchQueue.top().getDis();
				result.insert(alterStr);
				if(alterStr.compare(endWord) == 0) return result;
				searchQueue.pop();

				for(int i=0; i<alterStr.size(); i++){
					char temp = alterStr[i];
					for(int j='a'; j<='z'; j++){
						if(j!=temp){
							alterStr[i] = j;
							ptr = (*wordList).find(alterStr);
							if(ptr != (*wordList).end()){
								//insert it into priority queue
								int dis = this->distanceOfTwoStr(alterStr, endWord) + curDis;
								Element instance = new Element(dis, alterStr);
								searchQueue.push(instance);
								delete instance;
							}
						}
					}
				}
			}
		}
		int distanceOfTwoStr(string strA, string strB){
			int len = strA.size();
			int distance = 0;
			for(int i=0; i<len; i++){
				distance = (strA[i] == strB[i]) ? distance : distance + 1;//abs(strA[i]-strB[i]);
			}
		}
};

int main(){
	int i;
	Solution test;
	string beginWord = "hit";
	string endWord = "cog";
	unordered_set<string> wordList = {"hot", "dot", "dog", "lot", "log"};
	vector<string> result;
	result = test.findLadders(beginWord, ndWord, unordered_set<string> &wordList);
	for(int i=0; i<result.size(); i++){
		cout << result[i] << " ";
	}

	return 0;
}

