#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print_path(vector<int> parent, vector<int> mango_no, vector<int> &mango_count, int j){
    //vector is pass by value?!!
    if(parent[j] == -1) return;
    print_path(parent, mango_no, mango_count, parent[j]);
    mango_count.push_back(mango_no[j]);
}
int main(void){
    int n, s, t;
    cin >> n >> s >> t;
    if (n<2 || n> 1000 || s<0 || s>n || t<0 || t>n) cout << -1;
    vector<vector<int>> map (n, vector<int>(n, 0));
    vector<int> mango_no (n, 0);
    vector<int> visited (n, 0);
    vector<int> dist (n, 1001);
    dist[s-1] = 0;
    vector<int> parent (n,-1);
    for(int i=0; i<n; i++){
        cin >> mango_no[i];
    }
    for(int i=0; i<n-1; i++){
        int x, y;
        cin >> x >> y;
        if (x>=1 && x-1<n && y>=1 && y-1<n) {
            map[x-1][y-1] = 1;
            map[y-1][x-1] = 1;
        }
    }
    if(s==t){
        cout << mango_no[s-1];
        return 0;
    }

    for(int i=0; i<n; i++){
        int current = -1;
        for(int j=0; j<n; j++){
            if(visited[j]) continue;
            if(current == -1 || dist[j] < dist[current]){
                current = j;
            }
        }
        visited[current] = 1;
        for(int j=0; j<n; j++){
            int path = (map[current][j] == 1) ? 1 : 1001;
            path = dist[current] + path;
            if(path < dist[j]){
                parent[j] = current;
                dist[j] = path;
            }
        }
    }
    vector<int> mango_count;
    print_path(parent, mango_no, mango_count, t-1);
    sort(mango_count.begin(), mango_count.end());
    if(mango_count.empty()){
        cout << -1;
        return 0;
    }
    int max = 1;
    int temp = mango_count[0];
    int temp_count=1;
    int max_no = temp;

    for(auto it=mango_count.begin()+1; it!=mango_count.end(); it++){
        if(*it==temp){
            temp_count++;
        } else {
            if(temp_count > max){
                max = temp_count;
                max_no = temp;
            }
            temp = *it;
            temp_count = 0;
        }
    }
    cout << max_no << endl;
    return 0;
}


