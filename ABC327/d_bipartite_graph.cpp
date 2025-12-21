#include<iostream>
#include<vector>
using namespace std;
void dfs(int now_v, vector<vector<int>>& g, vector<bool>& is_visited, vector<int>& parent, vector<int>& color, bool& is_ok){
    is_visited[now_v] = true;

    for(auto next_v:g[now_v]){
        if(next_v == parent[now_v]) continue;
        if(is_visited[next_v]){
            if(color[next_v] != (color[now_v]+1)%2) is_ok = false;
            continue;
        }

        color[next_v] = (color[now_v]+1)%2;
        parent[next_v] = now_v;
        dfs(next_v, g, is_visited, parent, color, is_ok);
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    vector<bool> is_visited(n, false);
    vector<int> parent(n), color(n, -1);
    vector<int> a(m), b(m);
    bool is_ok;
    for(int i=0; i<m; i++) {
        cin >> a[i]; a[i]--;
    }
    for(int i=0; i<m; i++) {
        cin >> b[i]; b[i]--;
    }
    for(int i=0; i<m; i++){
        g[a[i]].push_back(b[i]);
        g[b[i]].push_back(a[i]);
    }
    
    is_ok = true;

    for(int i=0; i<n; i++){
        if(is_visited[i]) continue;
        parent[i] = -1;
        color[i] = 0;
        dfs(i, g, is_visited, parent, color, is_ok);
    }

    if(is_ok) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}