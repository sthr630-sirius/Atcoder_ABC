#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int dfs(int now_v, vector<vector<int>> &g, vector<bool> &is_visited, vector<int> &path){
    is_visited[now_v] = true;
    path.push_back(now_v);

    cout << "--path--" << endl;
    for(auto v:path) cout << v+1 << ", ";
    cout << endl;

    for(auto next_v:g[now_v]){
        if(!is_visited[next_v]){
            dfs(next_v, g, is_visited, path);
        }
    }

    path.pop_back();

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

    for(int i=0; i<n; i++) sort(g[i].begin(), g[i].end());

    int now_v;
    vector<bool> is_visited(n, false);
    vector<int> path;
    now_v = 0;
    dfs(now_v, g, is_visited, path);

    return 0;
}