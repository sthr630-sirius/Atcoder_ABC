#include<iostream>
#include<vector>
using namespace std;

void dfs(int now_v, vector<vector<int>>& g, vector<bool>& is_visited, vector<int>& dist){

    is_visited[now_v] = true;

    if(g[now_v].empty()){
        dist[now_v] = 0;
        return;
    }

    for(auto next_v:g[now_v]){
        if(!is_visited[next_v]) dfs(next_v, g, is_visited, dist);
        dist[now_v] = max(dist[now_v], dist[next_v]+1);
    }

    return;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    vector<bool> is_visited(n, false);
    vector<int> deg(n, 0);
    vector<int> dist(n, -1);
    
    int a, b;
    
    for(int i=0; i<m; i++){
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        deg[b]++;
    }

    int now_v = 0;

    for(int i=0; i<n; i++){
        if(deg[i]==0){
            now_v = i;
            break;
        }
    }

    dist[now_v] = 0;
    dfs(now_v, g, is_visited, dist);

    if(dist[now_v] == n-1){
        cout << "Yes" << endl;
        for(auto d:dist) cout << n-d << " ";
        cout << endl;
    }else{
        cout << "No" << endl;
    }
    
    return 0;
}