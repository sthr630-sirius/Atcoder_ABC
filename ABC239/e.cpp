#include<iostream>
#include<vector>
using namespace std;
void dfs(int now_v, vector<vector<int>>& g, vector<bool>& is_visited, vector<int>& parent, vector<int>& child_cnt){
    is_visited[now_v] = true;
    for(auto next_v:g[now_v]){
        if(is_visited[next_v]) continue;
        child_cnt[now_v]++;
        parent[next_v] = now_v;
        dfs(next_v, g, is_visited, parent, child_cnt);
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

    for(auto [v, k]:query) cout << "query --> k: " << k << " v: " << v << endl;
    cout << endl;

    vector<int> parent(n, -1), child_cnt(n, 0);
    vector<bool> is_visited(n, false);
    dfs(0, g, is_visited, parent, child_cnt);

    cout << "-----parent------" << endl;
    for(auto v:parent) cout << v << endl;
    cout << endl;
    cout << "-----child_cnt-------" << endl;
    for(auto c:child_cnt) cout << c << endl;
    cout << endl;

    return 0;
}