#include<iostream>
#include<vector>
using namespace std;
int dfs_tree(int now_v, int end_v, vector<vector<pair<int, int>>>& g, vector<bool>& is_visited, vector<int>& path, int sum_length, int ans){
    int next_v, length;
    
    is_visited[now_v] = true;
    path.push_back(now_v);

    if(now_v == end_v){
        ans = max(sum_length, ans);
        return ans;
    }

    for(auto gi:g[now_v]){
        next_v = gi.first;
        length = gi.second;
        if(is_visited[next_v]) continue;
        sum_length += length;
        ans = dfs_tree(next_v, end_v, g, is_visited, path, sum_length, ans);
        is_visited[next_v] = false;
        path.pop_back();
        sum_length -= length;
    }

    return ans;

}


int main(){
    int n, m;
    cin >> n >> m;
    int a, b, c;
    vector<vector<pair<int, int>>> g(n);
    vector<bool> is_visited(n, false);
    vector<int> path;
    int sum_length, ans;

    for(int i=0; i<m; i++){
        cin >> a >> b >> c;
        a--; b--;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }

    ans = 0;
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(i == j) continue;
            vector<bool> is_visited(n, false);
            vector<int> path;
            sum_length = 0;
            ans = dfs_tree(i, j, g, is_visited, path, sum_length, ans);
        }
    }

    cout << ans << endl;
    return 0;

}