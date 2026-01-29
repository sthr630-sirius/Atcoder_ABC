#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void dfs(int now_v, vector<vector<int>>& g, vector<bool>& is_visited, vector<int>& parent, vector<vector<int>>& subtree, vector<int>& x, int k_max){
    is_visited[now_v] = true;
    for(auto next_v:g[now_v]){
        if(is_visited[next_v]) continue;
        parent[next_v] = now_v;
        dfs(next_v, g, is_visited, parent, subtree, x, k_max);
    }

    subtree[now_v].push_back(x[now_v]);
    sort(subtree[now_v].begin(), subtree[now_v].end(), greater());
    int subtree_size = subtree[now_v].size();

    if(now_v != 0){
        for(int i=0; i<min(subtree_size, k_max); i++){
            subtree[parent[now_v]].push_back(subtree[now_v][i]);
        }
    }
}

int main(){
    int n, q;
    cin >> n >> q;
    vector<int> x(n);
    for(int i=0; i<n; i++) cin >> x[i];
    vector<vector<int>> g(n);
    for(int i=0; i<n-1; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<pair<int, int>> query;
    int k_max = 0;
    for(int i=0; i<q; i++){
        int v, k;
        cin >> v >> k;
        v--;
        k_max = max(k_max, k);
        query.push_back({v, k});
    }

    vector<int> parent(n, -1);
    vector<bool> is_visited(n, false);
    vector<vector<int>> subtree(n);

    dfs(0, g, is_visited, parent, subtree, x, k_max);

    for(auto [v, k]:query) cout << subtree[v][k-1] << endl;

    return 0;
}