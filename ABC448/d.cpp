#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
int dfs(int now_v, vector<vector<int>> &g, vector<bool> &is_visited, vector<int> &number, vector<int> &path, set<int> &path_number, bool is_duplicated, vector<string> &ans){
    
    is_visited[now_v] = true;
    path.push_back(now_v);

    if(is_duplicated){
        ans[now_v] = "Yes";
    }else{
        auto iter = path_number.find(number[now_v]);
        if(iter == path_number.end()){
            path_number.insert(number[now_v]);
            ans[now_v] = "No";
        } else {
            is_duplicated = true;
            ans[now_v] = "Yes";
        }
    }

    for(auto next_v:g[now_v]){
        if(!is_visited[next_v]){
            dfs(next_v, g, is_visited, number, path, path_number, is_duplicated, ans);
        }
    }

    path.pop_back();
    path_number.erase(number[now_v]);

    return 0;

}

int main(){
    int n;
    cin >> n;
    vector<int> number(n);
    for(int i=0; i<n; i++) cin >> number[i];
    vector<vector<int>> g(n);
    for(int i=0; i<n-1; i++){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    //for(int i=0; i<n; i++) sort(g[i].begin(), g[i].end());

    int now_v;
    vector<bool> is_visited(n, false);
    vector<int> path;
    set<int> path_number;
    bool is_duplicated = false;
    vector<string> ans(n);
    now_v = 0;
    dfs(now_v, g, is_visited, number, path, path_number, is_duplicated, ans);

    for(auto ansi:ans) cout << ansi << " ";
    cout << endl;

    return 0;
}