#include<iostream>
#include<vector>
#include<deque>
using namespace std;
int dfs(int now_p, vector<int>& a, vector<bool>& is_visited, deque<int>& path){
    is_visited[now_p] = true;
    path.push_back(now_p);

    int next_p;
    next_p = a[now_p];

    if(now_p != next_p) dfs(next_p, a, is_visited, path);

    return 0;
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) a[i]--;
    
    int now_p, next_p, end_p;
    vector<bool> is_visited(n, false);
    vector<int> ans(n, -1);

    for(int i=0; i<n; i++){
        now_p = i;
        deque<int> path;
        
        if(is_visited[now_p]) continue;

        dfs(now_p, a, is_visited, path);

        end_p = path.back();
        for(auto p:path) ans[p] = end_p;
    }

    for(auto ansi:ans) cout << ansi+1 << " ";
    cout << endl;

    return 0;

}