#include<iostream>
#include<vector>
using namespace std;

void dfs(int now_v, vector<vector<int>>& g, vector<bool>& is_visited, vector<bool>& is_root){
    
    is_visited[now_v] = true;
    
    for(auto next_v:g[now_v]){
        is_root[next_v] = false;
        if(!is_visited[next_v]) dfs(next_v, g, is_visited, is_root);
    }

    return;
}

void dfs_dist(int now_v, vector<vector<int>>& g, vector<bool>& is_visited, vector<int>& dist, vector<int>& path){
    
    is_visited[now_v] = true;
    path.push_back(now_v);

    if(g[now_v].empty()){
        dist[now_v] = 0;
        return;
    }
    
    for(auto next_v:g[now_v]){
        if(!is_visited[next_v]){
            dfs_dist(next_v, g, is_visited, dist, path);
            dist[now_v] = max(dist[now_v], dist[next_v]+1);
        }
    }

    return;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    
    int a, b;
    
    for(int i=0; i<m; i++){
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
    }

    vector<bool> is_visited(n, false);
    vector<bool> is_root(n, true);

    
    for(int i=0; i<n; i++){
        if(!is_visited[i]) dfs(i, g, is_visited, is_root);
    }
    
    for(int i=0; i<n; i++) is_visited[i] = false;
    vector<int> dist(n, 0);
    vector<int> path;
    vector<int> ans(n, 0);
    int root_v;
    for(int i=0; i<n; i++){
        if(is_root[i]){
            root_v = i;
            break;
        }
        
        //dfs_dist(root_v, g, is_visited, dist, path);
    }

    /*
    if(dist[root_v] == n-1){
        cout << "Yes" << endl;
        for(int i=0; i<n; i++) ans[path[i]] = i;
        for(auto v:ans) cout << v+1 << " ";
        cout << endl;
        return 0;
    }else{
        cout << "No" << endl;
        return 0;
    }
    */
}